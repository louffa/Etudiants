#ifndef ETUDIANT_H
#define ETUDIANT_H
#include<string>

using namespace std;

namespace modeles
{
    typedef enum
    {
        etudiant, loger, boursier
    }TYPE;
    class ETUDIANT
    {
        public:
            ETUDIANT();
            ETUDIANT(int id, string nom, string pnom);
            ETUDIANT(string nom, string pnom);
            virtual ~ETUDIANT();

            unsigned int Getid() { return id; }
            void Setid(unsigned int val) { id = val; }
            string Getnom() { return nom; }
            void Setnom(string val) { nom = val; }
            string Getpnom() { return pnom; }
            void Setpnom(string val) { pnom = val; }
            virtual void saisie();
            virtual void affiche();
            virtual char type() { return etudiant; }

        protected:
            unsigned int id;
            string nom;
            string pnom;
    };
};


#endif // ETUDIANT_H
