#ifndef CHAMBRE_H
#define CHAMBRE_H
#include"BATIMENT.h"

namespace modeles
{
    class CHAMBRE
    {
        public:
            CHAMBRE();
            CHAMBRE(string numCh, unsigned int nbrTotal, BATIMENT* bat);
            CHAMBRE(BATIMENT* bat);
            virtual ~CHAMBRE();

            unsigned int GetnbrTotal() { return nbrTotal; }
            void SetnbrTotal(unsigned int val) { nbrTotal = val; }
            string GetnumCh() { return numCh; }
            void SetnumCh(string val) { numCh = val; }
            BATIMENT* Getbatiment() { return batiment; }
            void Setbatiment(BATIMENT *val) { batiment = val; }

            void afficher();
            void saisie();
            unsigned int getId();
            unsigned int getNbrEt();

        protected:

        private:
            unsigned int nbrTotal;
            string numCh;
            BATIMENT *batiment;
    };
};

#endif // CHAMBRE_H
