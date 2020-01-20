#ifndef SERVICES_H_INCLUDED
#define SERVICES_H_INCLUDED
#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>
#include<sstream>
#include"MysqlDB.h"
#include"ETUDIANT.h"
#include"LOGER.h"
#include"BOURSIER.h"
#include"BATIMENT.h"
#include"CHAMBRE.h"

using namespace std;
using namespace modeles;

namespace services
{
    MYSQL_RES* getAllEtudiants()
    {
        string sql = "SELECT * FROM etudiant E WHERE isEtu = 1";
        MysqlDB *db = new MysqlDB();
        return db->executeSelect(sql);
    }
    MYSQL_RES* getAllBoursier()
    {
        string sql = "SELECT E.id, E.nom, E.prenom,B.typeBourse,B.montant FROM boursier B, etudiant E WHERE idEtu = E.id";
        MysqlDB *db = new MysqlDB();
        return db->executeSelect(sql);
    }
    MYSQL_RES* getAllLoger()
    {
        string sql = "SELECT E.id, E.nom, E.prenom ,C.numCh, B.numBat FROM loger L, etudiant E, chambre C, batiment B WHERE L.idEtudiant = E.id AND L.idChambre = C.id AND C.idBat = B.id";
        MysqlDB *db = new MysqlDB();
        return db->executeSelect(sql);
    }
    void showBoursier()
    {
       // int i;
        BOURSIER* et;
        MYSQL_RES* res = getAllBoursier();
        MYSQL_ROW row;
        cout << "\n\t\t\tAFFICHAGE DES BOURSIERS\n" << endl;
        while(row = mysql_fetch_row(res))
        {
            try
            {
                int id = ((int)strtol(row[0], NULL, 10));
                int mnt = ((int)strtol(row[4], NULL, 10));
                et = new BOURSIER(id,row[1],row[2],mnt,row[3]);
                et->affiche();

            }
            catch(exception e)
            {

            }
        }
    }
    void showLoger()
    {
        //int i;
        LOGER* et;
        MYSQL_RES* res = getAllLoger();
        MYSQL_ROW row;
        cout << "\n\t\t\tAFFICHAGE DES LOGERS\n" << endl;

        while(row = mysql_fetch_row(res))
        {
            try
            {
                int id = ((int)strtol(row[0], NULL, 10));
                BATIMENT* bat = new BATIMENT(row[4],"","");
                CHAMBRE *ch = new CHAMBRE(row[3],0,bat);
                et = new LOGER(id,row[1],row[2],ch);
                et->affiche();

            }
            catch(exception e)
            {

            }
        }
    }
    void showEtudiant()
    {
        int i;
        ETUDIANT* et;
        MYSQL_RES* res = getAllEtudiants();
        MYSQL_ROW row;
        cout << "\n\t\t\tAFFICHAGE DES ETUDIANTS\n" << endl;
        while(row = mysql_fetch_row(res))
        {
            try
            {
                int id = ((int)strtol(row[0], NULL, 10));
                et = new ETUDIANT(id,row[1],row[2]);
                et->affiche();

            }
            catch(exception e)
            {

            }
        }
    }

    void addBatiment()
    {
        MysqlDB *db = new MysqlDB();
        string sql;
        MYSQL_ROW row;
        MYSQL_RES* res;
        int id = db->lastIdFor("batiment");
        cout << "\n\t\t\tAJOUT DE BATIMENT\n" << endl;
        BATIMENT * bat = new BATIMENT(id);
        bat->saisie();
        stringstream concat;
        concat<<"INSERT INTO batiment VALUES("<<id<<", '"<<bat->GetnumBat()<<"', '"<<bat->Getadresse()<<"', '"<<bat->Getnom()<<"' ) ";
        db->executeMAJ(concat.str());
        db->~MysqlDB();
    }
    void showBatiment()
    {
        MysqlDB *db = new MysqlDB();
        string sql;
        MYSQL_ROW row;
        MYSQL_RES* res;
        BATIMENT *b;
        cout << "\n\t\t\tLISTE DES BATIMENTS\n" << endl;
        sql = "SELECT * FROM batiment";
        res = db->executeSelect(sql.c_str());
        while(row = mysql_fetch_row(res))
        {
            b = new BATIMENT(row[1],row[2],row[3]);
            b->afficher();
        }
        db->~MysqlDB();
    }


    BATIMENT* searchBatimentById(int id)
    {
        MYSQL_ROW roww;
        MYSQL_RES* ress;
        BATIMENT* b;
        MysqlDB *dbb = new MysqlDB();
        ostringstream concat;
        concat<<"SELECT * FROM batiment WHERE id = "<<id<<" ";
        ress = dbb->executeSelect(concat.str());
        while(roww = mysql_fetch_row(ress))
        {
            b = new BATIMENT(roww[1],roww[2],roww[3]);
            return b;
        }
        return NULL;
    }

    void showChambre()
    {
        MysqlDB *db = new MysqlDB();
        string sql;
        MYSQL_ROW row;
        MYSQL_RES* res;
        CHAMBRE *b;
        cout << "\n\t\t\tLISTE DES CHAMBRES\n" << endl;
        sql = "SELECT * FROM chambre";
        res = db->executeSelect(sql.c_str());
        while(row = mysql_fetch_row(res))
        {
            string test = row[2];
            long a = strtol(test.c_str(), NULL, 10);
            string test2 = row[3];
            long a2 = strtol(test2.c_str(), NULL, 10);
            b = new CHAMBRE(row[1],(int)a,searchBatimentById((int)a2));
            b->afficher();
        }
    }
    void showChambre(BATIMENT *bat)
    {
        MysqlDB *db = new MysqlDB();
        string sql;
        MYSQL_ROW row;
        MYSQL_RES* res;
        CHAMBRE *b;
        cout << "\n\t\t\tLISTE DES CHAMBRES\n" << endl;
        stringstream concat;
        concat << "SELECT * FROM chambre WHERE idBat = "<<bat->getId();
        res = db->executeSelect(concat.str());
        while(row = mysql_fetch_row(res))
        {
            string test = row[2];
            long a = strtol(test.c_str(), NULL, 10);
            string test2 = row[3];
            long a2 = strtol(test2.c_str(), NULL, 10);
            b = new CHAMBRE(row[1],(int)a,searchBatimentById((int)a2));
            b->afficher();
        }
    }

    BATIMENT* searchBatiment()
    {
        MysqlDB *db = new MysqlDB();
        string sql;
        MYSQL_ROW row;
        MYSQL_RES* res;
        string num;
        BATIMENT* b;
        showBatiment();
        do
        {
            cout << "\n\tNUM BAT : " ; cin >> num;
        }while(num == "");
        ostringstream concat;
        concat<<"SELECT * FROM batiment WHERE numBat = '"<<num<<"' ";
        res = db->executeSelect(concat.str());
        while(row = mysql_fetch_row(res))
        {
            b = new BATIMENT(row[1],row[2],row[3]);
            return b;
        }
        return NULL;
    }
    CHAMBRE* searchChambre()
    {
        MysqlDB *db = new MysqlDB();
        string sql;
        MYSQL_ROW row;
        MYSQL_RES* res;
        BATIMENT* bat = searchBatiment();
        string num;

        if(bat)
        {
            showChambre(bat);
            do
            {
                cout << "\n\tNUM CHAMBRE : " ; cin >> num;
            }while(num == "");
            stringstream concat;
            concat << "SELECT * FROM chambre WHERE numCh = '"<<num<<"' AND idBat = "<<bat->getId();
            //system("pause");
            res = db->executeSelect(concat.str());
            while(row = mysql_fetch_row(res))
            {
                //db->~MysqlDB();
                try
                {
                    long x= strtol(row[2], NULL, 10);
                    int a = (int)x;
                    CHAMBRE* ch = new CHAMBRE(row[1],a,bat);
                    db->~MysqlDB();
                    return ch;
                }
                catch(exception e)
                {
                    return NULL;
                }
            }
        }
        else
        {
            cout << "\nNUMERO INVALIDE ...\n" << endl ;
        }
        return NULL;
    }
    void addChambre()
    {
        MysqlDB *db = new MysqlDB();
        string sql;
        MYSQL_ROW row;
        MYSQL_RES* res;
        BATIMENT* bat = searchBatiment();
        if(bat)
        {
            bat->afficher();
            int id = db->lastIdFor("chambre");
            cout << "\n\t\t\tAJOUT DE CHAMBRE\n" << endl;
            CHAMBRE * ch = new CHAMBRE(bat);
            ch->saisie();
            stringstream concat;
            concat<<"INSERT INTO chambre VALUES("<<id<<", '"<<ch->GetnumCh()<<"', '"<<ch->GetnbrTotal()<<"', '"<<bat->getId()<<"' ) ";
            db->executeMAJ(concat.str());
        }
        else
        {
            cout << "\nNUMERO INVALIDE ...\n" << endl ;
        }
        db->~MysqlDB();
    }
    void add()
    {
        MysqlDB *db = new MysqlDB();
        string sql;
        MYSQL_ROW row;
        MYSQL_RES* res;
        char rep;
        ETUDIANT * et;
        string table;
        do
        {
            do
            {
                cin.ignore();
                cout << "\n\t\tSELECTIONNEZ LE TYE DU NOUVEAU ETUDIANT " << endl;
                cout << "\t\t  ETUDIANT (E) - BOURSIER (B) - LOGER(L)" << endl;
                cout << "\t\tVOTRE CHOIX : "; cin >> rep;
            }while(rep != 'E' && rep != 'B' && rep != 'L');
            if(rep == 'E')
            {
                et = new ETUDIANT();
                table = "etudiant";
            }
            if(rep == 'B')
            {
                et = new BOURSIER();
                table = "boursier";
            }
            if(rep == 'L')
            {
                et = new LOGER();
                table = "loger";
            }

            if(table != "loger")
            et->saisie();
            else
            {
                (dynamic_cast<LOGER*>(et))->setCh(searchChambre());
                if((dynamic_cast<LOGER*>(et))->getChambre())
                {
                    et->saisie();
                }
            }


            int id = db->lastIdFor("etudiant");
            stringstream concat, con;
            if(table == "etudiant")
                concat<<"INSERT INTO etudiant VALUES("<<id<<", '"<<et->Getnom()<<"', '"<<et->Getpnom()<<"', 1) ";
            else
                concat<<"INSERT INTO etudiant VALUES("<<id<<", '"<<et->Getnom()<<"', '"<<et->Getpnom()<<"', 0) ";
            db->executeMAJ(concat.str());


            if(table == "boursier")
            {

                int idBoursier = db->lastIdFor("boursier");
                con<<"INSERT INTO boursier VALUES("<<idBoursier<<" ,"<<id<<", '"<<(dynamic_cast<BOURSIER*>(et))->GettypeBourse() <<"', "<<(dynamic_cast<BOURSIER*>(et))->GetmntBourse()<<" ) ";
                db->executeMAJ(con.str());
            }
            if(table == "loger")
            {
                if((dynamic_cast<LOGER*>(et))->getChambre())
                {
                    int idLoger = db->lastIdFor("loger");
                    con<<"INSERT INTO loger VALUES("<<idLoger<<" ,"<<id<<", "<<(dynamic_cast<LOGER*>(et))->getChambre()->getId() <<" ) ";
                    db->executeMAJ(con.str());
                }
                else
                {
                    cout << "\nNUMERO DE CHAMBRE INEXISTNTE \n\n" << endl;
                }
            }
            //(*v).push_back(et);

            do
            {
                cin.ignore();
                cout << "\n\t\tUN AUTRE ETUDAINT ? [O/N] : "; cin >> rep;
            }while(rep != 'O' && rep != 'N' && rep != 'o' && rep != 'n');
        }while(rep == 'O' || rep == 'o');
        db->~MysqlDB();
    }
};


#endif // SERVICES_H_INCLUDED
