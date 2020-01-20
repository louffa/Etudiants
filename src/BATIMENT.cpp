#include "BATIMENT.h"
#include "MysqlDB.h"
#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>
#include<sstream>

using namespace modeles;
using namespace std;

BATIMENT::BATIMENT(int id)
{
    ostringstream a;
    a.str("");
    a << "BAT000" << id;
    this->numBat = a.str();
}

BATIMENT::BATIMENT(string numBat, string adresse, string nom)
{
    this->numBat = numBat;
    this->nom = nom;
    this->adresse = adresse;
}

BATIMENT::~BATIMENT()
{

    //dtor
}

void BATIMENT::saisie()
{
    cout << "\t\t SAISIR LE NUMERO DU BATIMENT    : " << numBat << endl;
    cout << "\t\t SAISIR L'ADRESSE DU BATIMENT   : " ; cin >> adresse;
    cout << "\t\t SAISIR LE NOM DU BATIMENT    : " ; cin >> nom;
}

void BATIMENT::afficher()
{
    cout << "\n______________________________________________________________________\n" << endl;
    cout << "\n ----------------- Info Batiment ------------------\n" << endl;
    cout << "\t \t NUMERO DU BATIMENT    : " << numBat << endl;
    cout << "\t \t ADRESSE DU BATIMENT   : " << adresse << endl;
    cout << "\t \t NOM DU BATIMENT       : " << nom << endl;
    cout << "\t \t NOMBRE DE CHAMBRES    : " << GetnbCh() << endl;
    cout << "\n______________________________________________________________________\n" << endl;
}

string BATIMENT::genererNumCh()
{
    ostringstream a;
    a.str("");
    a << "CH000" << (GetnbCh() + 1);
    return a.str();
}

unsigned int BATIMENT::GetnbCh()
{
    MysqlDB * db = new MysqlDB();
    MYSQL_RES *res;
    MYSQL_ROW row;
    ostringstream concat;
    concat<<"SELECT count(*) FROM chambre C,batiment B WHERE idBat = B.id AND numBat = '"<<numBat<<"' ";
    res = db->executeSelect(concat.str());
    while(row = mysql_fetch_row(res))
    {
        string test = row[0];
        long a = strtol(test.c_str(), NULL, 10);
        int x = (int)a;
        return x;
    }
    return 0;
}
unsigned int BATIMENT::getId()
{
    MysqlDB * db = new MysqlDB();
    MYSQL_RES *res;
    MYSQL_ROW row;
    ostringstream concat;
    concat<<"SELECT id FROM batiment B WHERE numBat = '"<<numBat<<"' ";
    res = db->executeSelect(concat.str());
    while(row = mysql_fetch_row(res))
    {
        string test = row[0];
        long a = strtol(test.c_str(), NULL, 10);
        int x = (int)a;
        return x;
    }
    return 0;
}

