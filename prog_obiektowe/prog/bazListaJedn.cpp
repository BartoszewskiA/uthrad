#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

struct osoba
{
    int ID;
    string imie;
    string nazwisko;
    int wiek;
    osoba * nast;
} * baza = NULL;
int bazID = 0;

void dodajNaPocz(int id,string im, string naz, int w);
void wstawOsobe();
void wypisz();
int nadajID();
void usun();
void wyszukaj();
void zapiszDoPliku();

int main()
{

    int decyzja;

    while (1)
    {
        cout<<endl<<"   1-dodaj rekord;  2-wypisz baze"<<endl;
        cout<<"   3-wyszukaj;      4-Zapisz"<<endl;
        cout<<"   9-usun baze;     0-wyjscie"<<endl;
        cout<<"wybierz akcje: ";
        cin >>decyzja;
        switch (decyzja)
        {
            case 1: wstawOsobe(); break;
            case 2: wypisz(); break;
            case 3: wyszukaj(); break;
            case 4: zapiszDoPliku(); break;
            case 9: usun(); break;
            case 0: return 0;
        }
    }


    return 0;
}

void dodajNaPocz(int id,string im, string naz, int w)
{
    osoba * p = new osoba;
    p->ID = id;
    p->imie = im;
    p->nazwisko = naz;
    p->wiek=w;
    p->nast = baza;
    baza=p;
}

void wstawOsobe()
{
    string im,nazw;
    int w;
    cout <<"Podaj nazwisko: ";
    cin >> nazw;
    cout << "Podaj imie: ";
    cin >> im;
    cout << "podaj wiek: ";
    cin >> w;
    dodajNaPocz(nadajID(),im,nazw,w);
}

void wypisz()
{
    osoba *p  =baza;
    while(p)
    {
        cout<<"ID: "<<p->ID<<endl;
        cout<<"Nazwisko: "<<p->nazwisko<<endl;
        cout<<"Imie: "<<p->imie<<endl;
        cout<<"wiek: "<<p->wiek<<endl;
        cout<<"-------------------------------------------"<<endl;
        p=p->nast;
    }
}
int nadajID()
{
    return ++bazID;
}

void usun()
{
    osoba *p;
    while(baza)
    {
        p=baza;
        baza=baza->nast;
        delete p;
    }
}

void wyszukaj()
{
    string s;
    int w, wybor, f=0;
    cout<<"Wyszukujeszpo: 1-Nazwisku; 2-Imieniu; 3-wieku";
    cin>>wybor;
    switch (wybor)
    {
        case 1:     cout<< "podaj nazwisko: "; cin>>s; break;
        case 2:     cout<< "podaj imie: "; cin>>s; break;
        case 3:     cout<< "podaj wiek: "; cin>>w; break;
    }
    osoba *p =baza;
    while (p)
    {
        f=0;
        switch (wybor)
        {
            case 1: if (s.compare(p->nazwisko)==0) f=1; break;
            case 2: if (s.compare(p->imie)==0) f=1; break;
            case 3: if (w==p->wiek) f=1; break;
        }

        if (f)
        {
            cout<<"ID: "<<p->ID<<endl;
            cout<<"Nazwisko: "<<p->nazwisko<<endl;
            cout<<"Imie: "<<p->imie<<endl;
            cout<<"wiek: "<<p->wiek<<endl;
            cout<<"-------------------------------------------"<<endl;
        }
        p=p->nast;
    }
}

void zapiszDoPliku()
{
    fstream plik;
    plik.open("dane.txt",ios::out);
    osoba *p = baza;
    while (p)
    {
        plik<<p->ID<<endl;
        plik<<p->nazwisko<<endl;
        plik<<p->imie<<endl;
        plik<<p->wiek<<endl;
        p=p->nast;
    }

    plik.close();
}
