#ifndef BOURSIER_H
#define BOURSIER_H
#include"ETUDIANT.h"


namespace modeles
{
    class BOURSIER : public ETUDIANT
    {
        public:
            BOURSIER();
            BOURSIER(string nom, string pnom, int mntBourse, string typeBourse);
            BOURSIER(int id, string nom, string pnom, int mntBourse, string typeBourse);
            virtual ~BOURSIER();

             int GetmntBourse() { return mntBourse; }
            void SetmntBourse( int val) { mntBourse = val; }
             string GettypeBourse() { return typeBourse; }
            void SettypeBourse( string val) { typeBourse = val; }
            virtual void saisie();
            virtual void affiche();
            virtual char type() { return boursier; }

        protected:

        private:
             int mntBourse;
             string typeBourse;
    };
};

#endif // BOURSIER_H
