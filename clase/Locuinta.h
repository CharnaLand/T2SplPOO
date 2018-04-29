#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <stdarg.h>


using namespace std;


class Locuinta
{
protected:
    char* numeClient;
    int suprafataUtila;
    float discout;
public:
    Locuinta(char* nume=NULL, int spUt=0, float dis=0): suprafataUtila(spUt),discout(dis)
    {///
        if(nume!=NULL)
        {
            numeClient=new char[strlen(nume)+1];
            strcpy(numeClient,nume);
        }
        else numeClient=NULL;
    }
    Locuinta(Locuinta& loc):Locuinta(loc.numeClient,loc.suprafataUtila,loc.discout){}
    ///
    ~Locuinta()
    {///
        if(numeClient!=NULL) delete[] numeClient;
        suprafataUtila=0;
        discout=0;
    }
    Locuinta& operator= (Locuinta& loc)
    {///
        if(loc.numeClient!=NULL)
            {
                numeClient=new char[strlen(loc.numeClient)+1];
                strcpy(numeClient,loc.numeClient);
            }
        else numeClient=NULL;
        suprafataUtila=loc.suprafataUtila;
        discout=loc.discout;
    }
    void virtual cit_fis(ifstream& f)
    {///
        char *vec;
        vec=new char[100];
        f.getline(vec,99);      ///CITIRE IN GOL
        f.getline(vec,99);
        numeClient=new char[strlen(vec)+1];
        strcpy(numeClient,vec);
        f>>suprafataUtila;
        f>>discout;
        delete[] vec;
    }
    void virtual Afisare()
    {///
        cout<<"Proprietarul locuintei este "<<numeClient<<".\n";
        cout<<"Ea are o suprafata utila de "<<suprafataUtila<<" mp";
        cout<<" iar discount-ul imobilului este in valoare de "<<discout<<".\n";
    }
    double virtual CalculChirie(int x, int y)=0;
    friend ifstream& operator>> (ifstream& f, Locuinta& loc);
    ///
};

ifstream& operator>> (ifstream& f, Locuinta& loc)
{
    loc.cit_fis(f);
    return f;
}
