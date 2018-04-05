# coding: utf-8
import pymysql as mysql
class Database:
    def __init__(self, addr, user, psw, dbName):
        self.dbName = dbName;
        self.db = mysql.Connect(addr, user, psw, dbName)
        self.cur = self.db.cursor()
    def query(self, cmd):
        self.cur.execute(cmd)
        result = self.cur.fetchall()
        return result
    def getTableColumnsName(self, tableName):
        result = self.query("select COLUMN_NAME from information_schema.COLUMNS where table_name =\"" + tableName + "\" and table_schema = \"" + self.dbName + "\"")
        list = []
        for row in result:
            list.append(row[0])
        return list
    def __del__(self):
        self.db.close()
