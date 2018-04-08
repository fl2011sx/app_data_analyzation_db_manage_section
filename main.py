# coding: utf-8
from Database import Database
from MainFunctions import *

db = Database("localhost", "root", "FLZdown1km$mysql!", "tpapp")
us = UserProcess(db)
us.bash_regist_user_by_xls(note="bash1")
print(us.showUsers())
