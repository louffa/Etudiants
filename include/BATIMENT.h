#ifndef BATIMENT_H
#define BATIMENT_H
#include<iostream>
using namespace std;

namespace modeles
{
    class BATIMENT
    {
        public:
            BATIMENT(int id);
            BATIMENT(string nom, string adresse, string numBat);
            virtual ~BATIMENT();

            string Getnom() { return nom; }
            void Setnom(string val) { nom = val; }
            string Getadresse() { return adresse; }
            void Setadresse(string val) { adresse = val; }
            string GetnumBat() { return numBat; }
            void SetnumBat(string val) { numBat = val; }
            unsigned int GetnbCh();
            void saisie();
            void afficher();
            string genererNumCh();
            unsigned int recupererNbCh();
            unsigned int getId();
        protected:

        private:
            string nom;
            string adresse;
            string numBat;
    };
};

#endif // BATIMENT_H
