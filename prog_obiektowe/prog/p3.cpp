#include <iostream>

using namespace std;

struct osoba
{
    string imie;
    string nazwisko;
    int wiek;
};
int main()
{
    osoba * tab[4];//tablica wskaŸników
                   //do struktur typu "osoba"
    for (int i=0; i<4; i++) //wczytanie danych
    {
        tab[i] =  new osoba;
        cin>>tab[i]->imie;
        cin>>tab[i]->nazwisko;
        cin>>tab[i]->wiek;
    }
    for (int i=0; i<4; i++) //wypisanie tablicy
    {
        cout<<tab[i]->imie<<" "<<tab[i]->nazwisko
        <<" ("<<tab[i]->wiek<<")";
    }
    for (int i=0; i<4; i++)
    {        //usuniêcie struktur dynamicznych
        delete tab[i];
    }
    return 0;
}
