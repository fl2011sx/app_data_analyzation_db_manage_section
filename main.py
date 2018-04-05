# coding: utf-8
from Database import Database
from MainFunctions import *

db = Database("localhost", "root", "FLZdown1km$mysql!", "tpapp")
us = UserProcess(db)

us.distribution_user_pro("sex", groups=[10, 20, 30])

