#include<iostream>
#include "ETUDIANT.h"

using namespace modeles;


ETUDIANT::ETUDIANT()
{
    //ctor
}

ETUDIANT::ETUDIANT(string nom, string pnom)
{
    //ctor
    this->nom = nom;
    this->pnom = pnom;
}
ETUDIANT::ETUDIANT(int id, string nom, string pnom)
{
    //ctor
    this->id = id;
    this->nom = nom;
    this->pnom = pnom;
}

ETUDIANT::~ETUDIANT()
{
    //dtor
}

void ETUDIANT::saisie()
{
    cout << "\n\t SAISIR LE NOM DE L\'ETUDIANT : " ; cin >> nom;
    cout << "\t\t SAISIR LE PRENOM DE L\'ETUDIANT : " ; cin >> pnom;
}

void ETUDIANT::affiche()
{
    cout << "\n______________________________________________________________________\n" << endl;
    cout << "\n ---------------- Infos Etudiant ---------------------\n" << endl;
    cout << "\t\tID     : " << id << endl;
    cout << "\t\tNOM    : " << nom << endl;
    cout << "\t\tPRENOM : " << pnom << endl;
    cout << "\n______________________________________________________________________\n" << endl;
}
