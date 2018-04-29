#include "Locuinta.h"

class Apartament: public Locuinta
{
    int etaj;
public:
    Apartament(char* nume=NULL, int spUt=0, float dis=0,int et=0):Locuinta(nume,spUt,dis),etaj(et){}
    Apartament(Apartament& ap):Locuinta(ap),etaj(ap.etaj){}
    ~Apartament() {etaj=0;}
    Apartament& operator= (Apartament& ap)
    {
        etaj=ap.etaj;
    }
    void cit_fis(ifstream& f)
    {
        Locuinta::cit_fis(f);
        f>>etaj;
    }
    void Afisare()
    {
        Locuinta::Afisare();
        cout<<"Apartamentul este situat la etajul "<<etaj<<".\n";
    }

    double CalculChirie(int x, int y);

    friend ifstream& operator>> (ifstream& f, Apartament& ap);
};

double Apartament::CalculChirie(int x, int y)
{
    return x*suprafataUtila*(1-y*discout/100);
}

ifstream& operator>> (ifstream& f, Apartament& ap)
{
    ap.cit_fis(f);
    return f;
}
