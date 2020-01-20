#ifndef VIEWS_H_INCLUDED
#define VIEWS_H_INCLUDED
#include<iostream>
#include<cstdlib>

using namespace std;

namespace views
{
    int menuPrincipal()
    {
        system("cls");
        int choix;
        cout << "\n\t_______________________________________________________________________________\n" << endl;
        cout  << "\t\t\t\t\t MENU PRINCIPAL " << endl;
        cout << "\n\t\t\t\t 1 ---                 RESSOURCES \n" << endl;
        cout << "\t\t\t\t 2 ---                 ETUDIANTS \n" << endl;
        cout << "\t\t\t\t 3 ---                 QUITTER \n" << endl;
        do
        {
            cout << "\t\t VOTRE CHOIX : " ; cin >> choix;
        }while(choix <1 || choix > 3);
        return choix;
    }
    int menuRessource()
    {
        system("cls");
        int choix;
        cout << "\n*******************************************************************\n" << endl;
        cout  << "\t\t\t MENU RESSOURCE " << endl;
        cout << "\n\t\t 1 ---                BATIMENT \n" << endl;
        cout << "\t\t 2 ---                CHAMBRE \n" << endl;
        cout << "\t\t 3 ---                RETOUR \n" << endl;
        cout << "\t\t 4 ---                QUITTER \n" << endl;
        do
        {
            cout << "\t\t VOTRE CHOIX : " ; cin >> choix;
        }while(choix <1 || choix > 4);
        return choix;
    }
    int menuChambre()
    {
        system("cls");
        int choix;
        cout << "\n*******************************************************************\n" << endl;
        cout  << "\t\t MENU CHAMBRE " << endl;
        cout << "\n\t 1 ---                 AJOUTER \n" << endl;
        cout << "\t 2 ---                 LISTE DES CHAMBRES \n" << endl;
        cout << "\t 3 ---                 RETOUR \n" << endl;
        cout << "\t 4 ---                 QUITTER \n" << endl;
        do
        {
            cout << "\t\t VOTRE CHOIX : " ; cin >> choix;
        }while(choix <1 || choix > 4);
        return choix;
    }
    int menuBatiment()
    {
        system("cls");
        int choix;
        cout << "\n*******************************************************************\n" << endl;
        cout  << "\t\t MENU BATIMENT \n\n" << endl;
        cout << "\n\t 1 ---                AJOUTER \n" << endl;
        cout << "\t 2 ---                LISTE DES BATIMENTS \n" << endl;
        cout << "\t 3 ---                RETOUR \n" << endl;
        cout << "\t 4 ---                QUITTER \n" << endl;
        do
        {
            cout << "\t\t VOTRE CHOIX : " ; cin >> choix;
        }while(choix <1 || choix > 4);
        return choix;
    }
    int menuEtudiant()
    {
        system("cls");
        int choix;
        cout << "\n****************************************************************************************\n" << endl;
        cout << "\t\t 1 ---                   AJOUTER ETUDIANT \n" << endl;
        cout << "\t\t 2 ---                   SHOW LOGER \n" << endl;
        cout << "\t\t 3 ---                   SHOW BOURSIER \n" << endl;
        cout << "\t\t 4 ---                   SHOW ETUDIANTS \n" << endl;
        cout << "\t\t 5 ---                   RETOUR \n" << endl;
        cout << "\t\t 6 ---                   QUITTER \n\n" << endl;
        do
        {
            cout << "\t\t\t VOTRE CHOIX : " ; cin >> choix;
        }while(choix <1 || choix > 6);
        return choix;
    }
};

#endif // VIEWS_H_INCLUDED
