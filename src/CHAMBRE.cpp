#include "CHAMBRE.h"
#include "BATIMENT.h"
#include "MysqlDB.h"
#include<iostream>

using namespace modeles;
using namespace std;

CHAMBRE::CHAMBRE()
{
    //ctor
}

CHAMBRE::CHAMBRE(BATIMENT* bat)
{
    this->batiment = bat;
}

CHAMBRE::CHAMBRE(string numCh, unsigned int nbrTotal, BATIMENT* bat)
{
    this->numCh = numCh;
    this->nbrTotal = nbrTotal;
    this->batiment = bat;
}
CHAMBRE::~CHAMBRE()
{
    //dtor
}

void CHAMBRE::saisie()
{
    numCh = batiment->genererNumCh();
    cout << "\t\t SAISIR NUMERO DE LA CHAMBRE           : " << numCh << endl;
    do
    {
        cout << "\t\t SAISIR LE NOMBRE TOTAL D\'ETUDIANT   : " ; cin >> nbrTotal;
    }while(nbrTotal <= 0);
}

void CHAMBRE::afficher()
{
    cout << "\n______________________________________________________________________\n" << endl;
    cout << "\n ------------------- Infos Chambre --------------------\n" << endl;
    cout << "\t \t NUMERO DE LA CHAMBRE  : " << numCh << endl;
    cout << "\t \t NOMBRE TOTAL D\'ETUDIANTS   : " << nbrTotal << endl;
    cout << "\t \t NOMBRE ACTUEL D\'ETUDIANTS  : " << getNbrEt() << endl;
    cout << "\n______________________________________________________________________\n" << endl;
}
unsigned int CHAMBRE::getId()
{
    MysqlDB * db = new MysqlDB();
    MYSQL_RES *res;
    MYSQL_ROW row;
    ostringstream concat;
    concat<<"SELECT id FROM chambre WHERE idBat = '"<<batiment->getId()<<"' AND numCh = '"<<numCh<<"' ";
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

unsigned int CHAMBRE::getNbrEt()
{
    MysqlDB * db = new MysqlDB();
    MYSQL_RES *res;
    MYSQL_ROW row;
    ostringstream concat;
    concat<<"SELECT count(*) FROM loger WHERE idChambre = "<<this->getId()<<" ";
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
