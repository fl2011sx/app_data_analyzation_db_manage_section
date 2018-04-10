# coding: utf-8
from Database import Database
from MainFunctions import *

def test():
    db = Database("localhost", "root", "FLZdown1km$mysql!", "tpapp")
    us = UserProcess(db)
    us.bash_regist_user_by_xls()
    print(us.showUsers())
    # print(us.relevancy_user_pro(["sex", "age", "recharge"]))
    

if __name__ == "__main__":
    test()