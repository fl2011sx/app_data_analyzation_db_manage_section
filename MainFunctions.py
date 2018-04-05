# coding: utf-8
from Database import Database
import pandas as pd
import numpy as np
import time
from scipy.interpolate import lagrange

#用户相关
class UserProcess:
    def __init__(self, database, userTableName = "users", propertiesName = "user_properties", pro_valName = "user_pro_val", operationName = "operation"):
        self.userTableName = userTableName
        self.pro_valName = pro_valName
        self.operationName = operationName
        if not isinstance(database, Database):
            return
        self.db = database
        properties = self.db.query("SELECT * FROM " + propertiesName)
        self.properties = []
        for row in properties:
            self.properties.append(row[0])

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
            users_id_time_new.append((id, ti))
        return tuple(users_id_time_new)



    def fill_up_time_users(self, isOperatingDatabase = False): #采用拉格朗日数据填补算法
        user_id_time = self.db.query("SELECT userid, regist_time FROM " + self.userTableName)
        test = self.__fill_up(user_id_time)
        print(test)

        return


