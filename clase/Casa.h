#include "Apartament.h"


class Casa: public Locuinta
{
    int suprafataCurte;
    int nrEtaje;
    float* suprafataEtaj;
public:
    Casa(char* nume=NULL, int spUt=0, float dis=0,int supC=0,int nrE=0, ...):Locuinta(nume,spUt,dis),suprafataCurte(supC),nrEtaje(nrE)
    {/***/
        if(nrE>0)
        {
        suprafataEtaj=new float[nrE];
        va_list spet;
        va_start(spet,nrE);
        for(int i=0;i<nrE;i++)
            suprafataEtaj[i]=va_arg(spet,double);
        va_end(spet);
        }
        else suprafataEtaj=NULL;
    }
    /**
    Casa(int supC=0,int nrE=0, ...):suprafataCurte(supC),nrEtaje(nrE)
    {
        if(nrE>0)
        {
        suprafataEtaj=new float[nrE];
        va_list spet;
        va_start(spet,nrE);
        for(int i=0;i<nrE;i++)
            suprafataEtaj[i]=va_arg(spet,double);
        va_end(spet);
        }
        else suprafataEtaj=NULL;
    }*/
    Casa(Casa& cs):Locuinta(cs),suprafataCurte(cs.suprafataCurte),nrEtaje(cs.nrEtaje)
    {/***/
        if(nrEtaje>0)
        {
        suprafataEtaj=new float[nrEtaje];
        for(int i=0;i<nrEtaje;i++)
            suprafataEtaj[i]=cs.suprafataEtaj[i];
        }
        else suprafataEtaj=NULL;
    }
    ~Casa()
    {/***/
        if(suprafataEtaj!=NULL) delete[] suprafataEtaj;
        nrEtaje=0;
        suprafataCurte=0;
    }
    void Afisare()
    {/***/
        Locuinta::Afisare();
        cout<<"Casa are suprafata curtii de "<<suprafataCurte;
        cout<<" mp si "<<nrEtaje<<" etaje.";
        if(nrEtaje) cout<<"\nEtajele au suprafete de : "<<suprafataEtaj[0]<<" mp";
        for(int i=1;i<nrEtaje;i++)
            cout<<", "<<suprafataEtaj[i]<<" mp";
        cout<<".\n";

    }

        void cit_fis(ifstream& f)
    {
        Locuinta::cit_fis(f);

        f>>suprafataCurte;
        f>>nrEtaje;
        if(nrEtaje>0)
        {
        suprafataEtaj=new float[nrEtaje];
        for(int i=0;i<nrEtaje;i++)
            f>>suprafataEtaj[i];
        }
        else suprafataEtaj=NULL;
    }

    double CalculChirie(int x, int y);

    friend ifstream& operator>> (ifstream& f,Casa& cs);
};

double Casa::CalculChirie(int x, int y)
{
    return x*(suprafataUtila+0.2*suprafataCurte)*(1-y*discout/100);
}

ifstream& operator>> (ifstream& f,Casa& cs)
{
    cs.cit_fis(f);
    return f;
}
