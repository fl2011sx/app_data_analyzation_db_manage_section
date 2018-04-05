# coding: utf-8
from Database import Database
from MainFunctions import *

db = Database("localhost", "root", "FLZdown1km$mysql!", "tpapp")
us = UserProcess(db)
print(us.new_users())
test = db.query("SELECT * FROM users")
print(type(test[0][3]))
print(range(6))
us.fill_up_time_users()