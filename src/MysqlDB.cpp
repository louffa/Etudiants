#include "MysqlDB.h"
#include <iostream>
#include<windows.h>
#include<mysql.h>
#include <sstream>
#include<stdio.h>
#include <string>

using namespace std;

MysqlDB::MysqlDB()
{

}

MysqlDB::~MysqlDB()
{
    closeConnection();
    //dtor
}
void MysqlDB::connection()
{
    if(!conn)
    {
        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "localhost", "admin", "admin", "gestionetudiant", 0, NULL, 0);
    }
}
void MysqlDB::closeConnection()
{
    if(conn)
    {
        mysql_close(conn);
    }
}
int MysqlDB::executeMAJ(string sql)
{
    MysqlDB::connection();
    if(conn)
    return mysql_query(conn, sql.c_str());
}
MYSQL_RES* MysqlDB::executeSelect(string sql)
{
    MysqlDB::connection();
    if(conn)
    {

        int qstate = mysql_query(conn, sql.c_str());
        if(!qstate)
        {
            //system("pause");
            return mysql_store_result(conn);
        }
        else
            return NULL;
    }
}
MYSQL_RES* MysqlDB::executeSelect(string sql, string critere)
{
    MysqlDB::connection();
    if(conn)
    {
        ostringstream a;
        a.str("");
        a << sql.c_str() << " WHERE " << critere.c_str() ;
        sql = a.str();
        int qstate = mysql_query(conn, sql.c_str());
        if(!qstate)
        {
            //system("pause");
            return mysql_store_result(conn);
        }
        else
            return NULL;
    }
}
int MysqlDB::lastIdFor(string table)
{
    MYSQL_ROW row;
    string sql = "SELECT max(id) FROM "+table;
    MYSQL_RES *res = executeSelect(sql);
    while(row = mysql_fetch_row(res))
    {
        try
        {
            string test = row[0];
            long a = strtol(test.c_str(), NULL, 10);
            int x = (int)a;
            return x+1;
        }catch(exception e)
        {
            return 1;
        }
        //return ((int)(row[0]));
    }
}

