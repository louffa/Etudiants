#ifndef MYSQLDB_H
#define MYSQLDB_H
#include <iostream>
#include<windows.h>
#include<mysql.h>
#include <sstream>
#include<stdio.h>
#include <string>

using namespace std;

class MysqlDB
{
    public:
        MysqlDB();
        virtual ~MysqlDB();

        MYSQL* Getconn() { return conn; }
        void Setconn(MYSQL* val) { conn = val; }
        void connection();
        void closeConnection();
        int executeMAJ(string sql);
        MYSQL_RES* executeSelect(string sql);
        MYSQL_RES* executeSelect(string sql, string critere);
        int lastIdFor(string table);
    protected:

    private:
        MYSQL *conn;
};

#endif // MYSQLDB_H
