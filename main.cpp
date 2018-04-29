#include "clase/Casa.h"


int main()
{
ifstream f ("date.in");
Locuinta** Lista;
int i,n,ce;
f>>n;
Lista=new Locuinta*[n+4];
for(i=0;i<n;i++)
{
    f>>ce;
    if(ce==1)
    {
        Lista[i]=new Apartament;
        f>>*(Lista[i]);
    }
    if(ce==2)
    {
        Lista[i]=new Casa;
        f>>*(Lista[i]);
    }
}

Lista[i]=new Apartament("Buzoianu Ionel",150,25.8,4);
Lista[i+1]=new Casa("Stirbeanu Stefan",800,30.0,350,3,163.4,148.9,137.7);
Lista[i+2]=new Apartament(*(Apartament*)Lista[i]);
Lista[i+3]=new Casa(*(Casa*)Lista[i+1]);
n+=2;

for(int i=0;i<n;i++)
    {
    Lista[i]->Afisare();
    cout<<"Chiria este in valoare de "<<Lista[i]->CalculChirie(150,1)<<" RON.\n";
    cout<<"\n";
    }

Apartament ap=*(Apartament*)Lista[i];
Casa cs=*(Casa*)Lista[i+1];
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
cout<<"Afisare copii realizate prin constructorul de copiere si prin operatorul de atribuire.\n\n";
Lista[n]->Afisare();
    cout<<"\n";
Lista[n+1]->Afisare();
    cout<<"\n";
ap.Afisare();
    cout<<"\n";
cs.Afisare();


f.close();
return 0;
}
