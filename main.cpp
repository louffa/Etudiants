#include <iostream>
#include<windows.h>
#include<mysql.h>
#include <sstream>
#include<stdio.h>
#include <string>
#include"ETUDIANT.h"
#include"LOGER.h"
#include"BOURSIER.h"
#include"services.h"
#include"views.h"

using namespace std;
using namespace modeles;
using namespace services;
using namespace views;

int main()
{
    int choix, choix1, choix2;
    do
    {
        system("color 7f");
        choix = menuPrincipal();
        system("cls");
        switch(choix)
        {
            case 1:
                do
                {
                    choix1 = menuRessource();
                    system("cls");
                    switch(choix1)
                    {
                        case 1:
                            do
                            {
                                choix2 = menuBatiment();
                                system("cls");
                                switch(choix2)
                                {
                                    case 1:
                                        addBatiment();
                                        break;
                                    case 2:
                                        showBatiment();
                                        break;
                                    case 4:
                                        exit(EXIT_FAILURE);
                                        break;
                                }
                                if(choix2 != 3) system("pause");
                            }while(choix2 != 3);
                            break;
                        case 2:
                            do
                            {
                                choix2 = menuChambre();
                                system("cls");
                                switch(choix2)
                                {
                                    case 1:
                                        addChambre();
                                        break;
                                    case 2:
                                        showChambre();
                                        break;
                                    case 4:
                                        exit(EXIT_FAILURE);
                                        break;
                                }
                                if(choix2 != 3) system("pause");
                            }while(choix2 != 3);
                            break;
                        case 4:
                            exit(EXIT_FAILURE);
                            break;
                    }
                }while(choix1 != 3);
                break;
            case 2:
                do
                {
                    choix1 =menuEtudiant();
                    system("cls");
                    switch(choix1)
                    {
                        case 1:
                            add();
                            break;
                        case 2:
                            showLoger();
                            break;
                        case 3:
                            showBoursier();
                            break;
                        case 4:
                            showEtudiant();
                            break;
                        case 6:
                            exit(EXIT_FAILURE);
                            break;
                    }
                    if(choix1 != 5) system("pause");
                }while(choix1 != 5);
                break;
        }
    }while(choix != 3);
    return 0;
}
