/**
Locuinta ( numeClient(sir de caractere de lungime variabila, NULL daca locuinta nu este inchiriata),
suprafataUtila(intreg), discount(float) );
Apartament (etaj(intreg)): public Locuinta
Casa : public Locuinta (suprafataCurte(intreg), nrEtaje(intreg) si suprafataEtaje(float*))

2p) Toate clasele vor conține constructori de inițializare, parametrizati si destructori.
(2p) Toate clasele vor conține constructori de copiere si operatorul = supraincarcat.
(1p) Operatorul >> să fie supraincarcat astfel incat citirea sa fie facuta din fisier.
(1p) Clasa Locuinta va contine o functie virtuala Afisare care va fi rescrisa corespunzator in clasele derivate.
(1p) Se va adauga la clasa Locuinta, metoda virtuala pura CalculChirie(X,Y) cu semnificatiile:
            X=valoare standard chirie/mp(intreg);
            Y=cu (1) / fara (0) luarea in considerare a discountului(intreg);
    Metoda adaugata va fi implementata in clasa Apartament dupa formula
            X * suprafataUtila * (1- Y * discount/100.0),
            respectiv in clasa Casa dupa formula
        X * (suprafataUtila + 0.2 * suprafataCurte) * (1 - Y * discount/100.0).
(2p) Functia main() va contine un “Demo” cu exemplificarea tuturor conceptelor implementate si este obligatorie
            parcurgerea unui vector de pointeri la Locuinta*, incarcat cu adrese de obiecte de tip Apartament si Casa.

Obs. 1. Oficiu – 1p
2. Timp de lucru – 1h15min
3. suprafataEtaje = vector care trebuie alocat dinamic. De exemplu, o casa cu 3 etaje, poate avea un
vector suprafataEtaje = {80.5 mp, 74.7 mp, 50 mp;}
*/

/**
Citirea se face face in felul urmator
'1' pentru Apartament
'2' pentru Casa

Se vor citi intai datele pentru campurile clasei Locuinta
Dupa se citesc campurile specifice clasei derivate
Numele trebuie sa fie singur pe linie
*/

