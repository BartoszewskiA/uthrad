#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <fstream>

using namespace std;
//---------------------------------------
class osoba
{
private:
    int Id;
    static int ile;
    string imie;
    string nazwisko;
    int rokUrodzenia;
    string normalizuj(string napis);
public:
    osoba(string im, string nazw, int wiek);
    int getWiek();
    string getImie(){return imie;}
    string getNazwisko(){return nazwisko;}
    int getId(){return Id;}
};

osoba::osoba(string im,string nazw,int wiek)
{
    Id=++ile;
    time_t aktualnyCzas;
    aktualnyCzas=time(NULL);
    tm * lokalnyCzas=localtime(&aktualnyCzas);
    imie=normalizuj(im);
    nazwisko=normalizuj(nazw);
    rokUrodzenia=lokalnyCzas->tm_year+1900 - wiek;
}

int osoba::getWiek()
{
        time_t aktualnyCzas;
        aktualnyCzas=time(NULL);
        tm * lokalnyCzas=localtime(&aktualnyCzas);
        return  lokalnyCzas->tm_year + 1900 - rokUrodzenia;
}

string osoba::normalizuj(string napis)
{
    napis[0]= toupper(napis[0]);
    for (int i=1;i<napis.length(); i++)
        napis[i]=tolower(napis[i]);
    return napis;
}

int osoba::ile=0;

//-------------------------------------------------------------
class baza
{
private:
    osoba * tab[100];
    int sp = 0;
    bool odczytzPliku();
public:
    baza();
    void wypisz();
    void dodajOsobe();
    void zapisDoPliku();
    ~baza();

};

baza::baza()
{
    odczytzPliku();
}

bool baza::odczytzPliku()
{
   string s1,s2,s3;
   int w;
   fstream plik;
   plik.open("baza.txt",ios::in);
   if (!plik.good())
   {
       return false;
   }
   else
    {
        while (!plik.eof())
        {
            getline(plik,s1);
            if (s1.length()>0)
            {
                getline(plik,s2);
                getline(plik,s3);
                w = atoi(s3.c_str());
                tab[sp++]=new osoba(s1,s2,w);
            }
        }
    }
   plik.close();
   return true;
}

void baza::wypisz()
{
    for (int i=0; i<sp; i++)
        cout<<tab[i]->getId()<<":"
            <<tab[i]->getImie()<<" "
            <<tab[i]->getNazwisko()<<" "
            <<tab[i]->getWiek()<<endl;
}

void baza::dodajOsobe()
{
    string s1,s2, s3;
    int w;
    cout<<"imie; ";
    getline(cin,s1);
    cout<<"nazwisko: ";
    getline(cin,s2);
    cout<<"nazwisko: ";
    getline(cin,s3);
    w = atoi(s3.c_str());
    tab[sp++]= new osoba(s1,s2,w);

}

void baza::zapisDoPliku()
{
    fstream plik;
    plik.open("baza.txt",ios::out);

    for (int i=0; i<sp; i++)
        plik<<tab[i]->getImie()<<endl
            <<tab[i]->getNazwisko()<<endl
            <<tab[i]->getWiek()<<endl;

    plik.close();
}

baza::~baza()
{
    for (int i=0; i<sp; i++)
        delete tab[i];
}
//--------------------------------------------
int main()
{
    baza uczniowie;
    uczniowie.wypisz();
    uczniowie.dodajOsobe();
    uczniowie.zapisDoPliku();
    return 0;
}
