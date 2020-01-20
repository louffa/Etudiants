#ifndef LOGER_H
#define LOGER_H
#include"ETUDIANT.h"
#include"CHAMBRE.h"
#include<string>

using namespace std;

namespace modeles
{
    class LOGER : public ETUDIANT
    {
        public:
            LOGER();
            LOGER(string nom, string pnom, CHAMBRE* ch);
            LOGER(int id, string nom, string pnom, CHAMBRE* ch);
            virtual ~LOGER();
            void setCh(CHAMBRE *ch ){ this->ch = ch; }
            CHAMBRE* getChambre(){ return ch; }
            virtual void saisie();
            virtual void affiche();
            virtual char type() { return loger; }


        protected:

        private:
            CHAMBRE *ch;
    };
};


#endif // LOGER_H
