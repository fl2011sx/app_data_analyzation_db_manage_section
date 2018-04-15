# coding: utf-8
from Database import Database
import pandas as pd
import numpy as np
import time
from scipy.interpolate import lagrange
from inspect import isfunction

#单元素元素转一维列表
def single_tumple_to_list(tum):
    result = []
    for ele in tum:
        result.append(ele[0])
    return result

#用户相关
class UserProcess:
    def __init__(self, database, userTableName = "users", propertiesName = "user_properties",\
                 pro_valName = "user_pro_val", operationName = "operation"):
        self.userTableName = userTableName
        self.pro_valName = pro_valName
        self.operationName = operationName
        if not isinstance(database, Database):
            return
        self.db = database
        properties = self.db.query("SELECT user_property FROM " + propertiesName)
        self.properties = single_tumple_to_list(properties)

#显示用户属性
    def showProperties(self):
        return self.properties

#拼接属性后显示用户信息
    def showUsers(self):
        columns = self.db.getTableColumnsName(self.userTableName)
        que = "SELECT DISTINCT "
        isFirst = True
        for col in columns:
            if not isFirst:
                que += ", "
            isFirst = False
            que += self.userTableName + "." + col + " AS " + col
        for pro in self.properties:
            que += ", PV_" + pro + ".user_pro_value AS " + pro
        que += " FROM " + self.userTableName
        for pro in self.properties:
            que += " LEFT JOIN " + self.pro_valName + " AS PV_" + pro + " ON " + self.userTableName + ".userid = PV_" +\
                   pro + ".userid AND PV_" + pro + ".user_property = \"" + pro + "\""
        que += " ORDER BY " + self.userTableName + ".userid ASC"
        result = self.db.query(que)
        data = pd.DataFrame(list(result), columns=columns + self.properties)
        print(que)
        return data

#新用户
    def new_users(self, howNew = 604800): #默认一周内为新用户
        now = int(time.time())
        someTimeBefore = now - howNew
        result = self.db.query("SELECT username FROM " + self.userTableName + " WHERE regist_time >= " + str(someTimeBefore))
        return result

#活跃用户
    def activity_users(self, howNew = 604800): #默认一周内登录的为活跃用户
        now = int(time.time())
        someTimeBefore = now = howNew
        result = self.db.query("SELECT DISTINCT " + self.userTableName + ".username FROM " + self.userTableName + ", " + self.operationName + " WHERE operatingtime >= " + str(someTimeBefore) + " and " + self.userTableName + ".userid = " + self.operationName + ".userid" )
        return result

##注册用户时间戳填补
    #拉格朗日数据填补算法
    @staticmethod
    def __fill_up(users_id_time, afterGetFillUp = None):
        users_id_time_new = []
        userid = []
        time = []
        for (id, ti) in users_id_time:
            if not ti == None:
                userid.append(id)
                time.append(ti)
        for (id, ti) in users_id_time:
            if ti == None:
                ti = lagrange(userid, time)(id)
                if afterGetFillUp != None and isfunction(afterGetFillUp):
                    afterGetFillUp(id, ti)
            users_id_time_new.append((id, ti))
        return tuple(users_id_time_new)

    def fill_up_time_users(self, isOperatingDatabase = False): #采用拉格朗日数据填补算法
        user_id_time = self.db.query("SELECT userid, regist_time FROM " + self.userTableName)
        if isOperatingDatabase:
            def afterFillUp(id, time):
                self.db.query("UPDATE " + self.userTableName + " SET regist_time = " + str(time) + " WHERE userid = " + str(id))
            self.__fill_up(user_id_time, afterFillUp)
            return
        return self.__fill_up(user_id_time)

##用户群体分析
    # 分析某一个属性的用户分布
    # pro-要分析的属性名称
    # cal_values-分析所有的值
    # groups-分析区间值
    def distribution_user_pro(self, pro, cal_values = False, groups = None):
        if not pro in self.properties:
            return
        if cal_values:
            vals = self.db.query("SELECT DISTINCT user_pro_value FROM " + self.pro_valName + " WHERE user_property = \"" + pro + "\"")
            values = single_tumple_to_list(vals)
            cal = {}
            for val in values:
                count = self.db.query("SELECT COUNT(userid) FROM " + self.pro_valName + " WHERE user_pro_value = \"" + val + "\"")
                cal[val] = count[0][0]
            return cal
        if groups != None and isinstance(groups, list) and len(groups):
            cal = {}
            que = "SELECT COUNT(userid) FROM " + self.pro_valName + " WHERE user_pro_value < " + str(groups[0])
            count = self.db.query(que)
            cal["<" + str(groups[0])] = count[0][0]
            for i in range(len(groups) - 1):
                (left, right) = (groups[i], groups[i + 1])
                que = "SELECT COUNT(userid) FROM " + self.pro_valName + " WHERE user_pro_value >= " + str(left) + " AND user_pro_value < " + str(right)
                count = self.db.query(que)
                section = str(groups[i]) + "-" + str(groups[i + 1])
                cal[section] = count[0][0]
            que = "SELECT COUNT(userid) FROM " + self.pro_valName + " WHERE user_pro_value > " + str(groups[len(groups) - 1])
            count = self.db.query(que)
            cal[">=" + str(groups[len(groups) - 1])] = count[0][0]
            return cal

    # 获取用户的某些属性切片(至少2个)
    def __matrix_user_pro(self, pros):
        if not isinstance(pros, list):
            return
        if len(pros) < 2:
            return
        que = "SELECT DISTINCT "
        isFirstPro = True
        for pro in pros:
            if not pro in self.properties:
                return
            if not isFirstPro:
                que += ", "
            isFirstPro = False
            que += "pv_" + pro + ".user_pro_value AS " + pro
        que += " FROM " + self.userTableName
        for pro in pros:
            que += ", " + self.pro_valName + " AS pv_" + pro
        que += " WHERE "
        isFirstPro = True
        for pro in pros:
            if not isFirstPro:
                que += " AND "
            isFirstPro = False
            que += "pv_" + pro + ".userid = " + self.userTableName + ".userid"
            que += " AND pv_" + pro + ".user_property = \"" + pro + "\""

        res = self.db.query(que)
        data = pd.DataFrame(np.int64(res))
        data.columns = pros
        return data

    #分析某几个属性之间的关联度
    # pros-要分析的属性，数量至少为2
    # 默认采用Pearson相关系数矩阵
    # 所有属性必须是数值型
    def relevancy_user_pro(self, pros):
        if not isinstance(pros, list):
            return
        if len(pros) < 2:
            return
        data = self.__matrix_user_pro(pros)
        return data.corr()

    #0-1属性因变量的自变量筛选
    # 采用逻辑分析算法
    # dp_var 0-1属性的因变量对应属性名称， id_vars自变量属性名称列表(至少2个)
    # 所有属性必须是数值型
    def val_filtrate(self, dp_var, id_vars):
        if not isinstance(dp_var, str):
            return
        if not isinstance(id_vars, list):
            return
        if len(id_vars) < 2:
            return
        id_vars.append(dp_var)
        data = self.__matrix_user_pro(id_vars)
        x = data[data.columns[:len(data.columns) - 1]]
        y = data[data.columns[len(data.columns) - 1]]
        from sklearn.linear_model import RandomizedLogisticRegression
        rlr = RandomizedLogisticRegression()
        rlr.fit(x.as_matrix(), y.as_matrix())
        x1_col = x.columns[rlr.get_support()]
        print(x1_col)

    ##通过Excel表格批量注册用户
    #关于注册时间的处理：
    #                    useRealTime = True, use_RealTime = False
    #表格里有regist_time   实际时间                表格时间
    #表格里没有regist_time  实际时间                 NULL
    def bash_regist_user_by_xls(self, xlsRoot, note = None, useRealTime = True):
        #xlsRoot = "/users/hubohao/Desktop/test.xlsx"
        data = pd.read_excel(xlsRoot)
        for row_index in range(len(data)):
            row = data.loc[row_index]
            for col in data.columns:
                from time import time as tm
                time = tm()
                if "regist_time" in col and not useRealTime:
                    time = row[col]
                if not "regist_time" in col and not useRealTime:
                    time = None
                print(col)
                if col == "regist_time":
                    continue
                if col == "username":
                    #registUser
                    que = "INSERT INTO " + self.userTableName + "(username"
                    if (time != None):
                        que += ", regist_time"
                    if (note != None):
                        que += ", note"
                    que += ") VALUES(\"" + str(row["username"]) + "\""
                    if (time != None):
                        que += ", " + str(time)
                    if (note != None):
                        que += ", \"" + note + "\""
                    que += ")"
                    print(que)
                    self.db.query(que)
                else:
                    #addProperties
                    que = "INSERT INTO " + self.pro_valName + "(userid, user_property, user_pro_value) SELECT userid, \"" \
                          + str(col) + "\", \"" + str(row[col]) + "\" FROM " + self.userTableName + " WHERE username = \"" + str(row["username"]) + "\""
                    print(que)
                    self.db.query(que)

##辅助方法
#绘制条形图
def draw_bar_chart(data, x_title = None, title = "", width = 0.5, gap = 0.1, color = "blue", grid = False, save_root = None, show = False):
    print("--------")
    print(data, x_title, title, width, gap, color, grid, save_root, show)
    print("--------")
    import matplotlib.pyplot as plt
    if x_title == None:
        x_title = range(len(data))
    fig = plt.figure(1)
    ax1 = plt.subplot(111)
    x_bar = map(lambda x: x * (width + gap), range(len(data)))
    rect = ax1.bar(left=x_bar, height=data, width=width, color=color)

    for ele in rect:
        x = ele.get_x()
        h = ele.get_height()
        ax1.text(x + width / 2, h + 0.1, str(h), ha="center")
    
    x_mark = map(lambda x: x + width / 2, x_bar)
    
    ax1.set_xticks(x_mark)  # x轴每隔多少进行标点
    ax1.set_xticklabels(x_title)
    ax1.set_title(title)
    ax1.grid(grid)  # 显示网格
    if save_root != None and isinstance(save_root, str):
        plt.savefig(save_root)
    if show:
        plt.show()

draw_bar_chart([2.0, 5.8, 4.0], None, '', 0.5, 0.1, 'blue', False, '/Users/hubohao/Desktop/test.png', True)
