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
    def __init__(self, database, userTableName = "users", propertiesName = "user_properties", pro_valName = "user_pro_val", operationName = "operation"):
        self.userTableName = userTableName
        self.pro_valName = pro_valName
        self.operationName = operationName
        if not isinstance(database, Database):
            return
        self.db = database
        properties = self.db.query("SELECT user_property FROM " + propertiesName)
        self.properties = single_tumple_to_list(properties)
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
    #分析某一个属性的用户分布
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



    #分析某几个属性之间的关联度

