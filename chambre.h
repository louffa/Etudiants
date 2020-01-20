#ifndef CHAMBRE_H
#define CHAMBRE_H


class CHAMBRE
{
    public:
        CHAMBRE();
        virtual ~CHAMBRE();

        string GetnumCh() { return numCh; }
        void SetnumCh(string val) { numCh = val; }
        unsigned int Getnbr() { return nbr; }
        void Setnbr(unsigned int val) { nbr = val; }
        BATIMENT Getbatiment() { return batiment; }
        void Setbatiment(BATIMENT val) { batiment = val; }

    protected:

    private:
        string numCh;
        unsigned int nbr;
        BATIMENT batiment;
};

#endif // CHAMBRE_H
