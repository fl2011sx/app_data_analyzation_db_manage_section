# coding: utf-8
from Database import Database
from MainFunctions import *

db = Database("localhost", "root", "FLZdown1km$mysql!", "tpapp")
us = UserProcess(db)

test = us.distribution_user_pro("sex", groups=[10, 20, 30])
us.val_filtrate("age", ["sex"])
us.showUsers()


from sklearn.linear_model import LogisticRegression as LR
from sklearn.linear_model import RandomizedLogisticRegression as RLR

file = "/users/hubohao/Desktop/bankloan.xls"
data = pd.read_excel(file)
x = data.iloc[:, :8].as_matrix()
y = data.iloc[:, 8].as_matrix()

rlr = RLR()
rlr.fit(x, y)
sup = rlr.get_support()

lr = LR()
x1 = data[data.columns[:8][sup]].as_matrix()

lr.fit(x1, y)
print(lr.score(x1, y))

