#include <iostream>

using namespace std;

class osoba
{
protected:
    string imie;
    string nazwisko;
    string uczelnia;
public:
    osoba() {imie=""; nazwisko=""; uczelnia="";}
    osoba(string im, string na, string u="UTH Rad."):imie(im), nazwisko(na), uczelnia(u) {}
    void virtual wypisz();
    string virtual getUczelnia()=0;
};

void osoba::wypisz()
{
   cout<<"-------------------------------------------------------"<<endl
       <<"Imie: \t\t"<<imie<<endl
       <<"Nazwisko: \t"<<nazwisko<<endl
       <<"Uczenia: \t"<<uczelnia<<endl;
}
//------------------------------------------------------------
class student : public osoba
{
protected:
  string kierunek;
public:
     student(string im, string na, string u="UTH Rad.", string k ="Informatyka")
        :osoba(im, na, u), kierunek(k) {}
     string getUczelnia() {return uczelnia;}
     void wypisz();
};

void student::wypisz()
{
       //cout<<"Imie: \t\t"<<imie<<endl
       //<<"Nazwisko: \t"<<nazwisko<<endl
       //<<"Uczenia: \t"<<uczelnia<<endl
       osoba::wypisz();
       cout<<"Kierunek: \t"<<kierunek<<endl;
}
//-------------------------------------------------------------
class wykladowca : public osoba
{
protected:
    string wydzial;
public:
    wykladowca(string im, string na, string u="UTH Rad.", string w ="WTEiI")
        :osoba(im, na, u), wydzial(w) {}
     string getUczelnia() {return uczelnia;}
     void wypisz();
};

void wykladowca::wypisz()
{
       osoba::wypisz();
       cout<<"Wydzial: \t"<<wydzial<<endl;
}
//-------------------------------------------------------------
int main()
{
    osoba *tab[5];
    tab[0] = new wykladowca("A", "B");
    tab[1] = new student("111111111", "11111111");
    tab[2] = new student("222222", "222222");
    tab[3] = new student("333333", "33333");
    tab[4] = new student("4444", "444444444444");

    for (int i=0; i<5; i++)
        tab[i]->wypisz();
    return 0;
}
