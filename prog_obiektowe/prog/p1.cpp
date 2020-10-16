#include <iostream>

using namespace std;
int zabierz(int nr, int *t);



int main()
{
    cout << "ile elementow ma miec tablica? ";
    int ile, ktory;
    cin >> ile;

    int *tab = new int[ile];
    int *p=tab;
    for (int i=0; i<ile;i++)
           *p++=i;
    p=tab;
    for (int i=0; i<ile;i++)
        cout << tab[i]<<" "<<endl;
    int ktory;
    cout << "podaj numer elementu ";
    cin >>ktory;

    cout << zabierz(ktory,tab);
    delete [] tab;
    return 0;
}

int zabierz(int nr,int *t)
//zwraca wartosc wskazanego elemetu 
//jednoczesnie ja zerujac
{
   int *wsk_p = t;
   int pom = *wsk_p;
   *wsk_p=0;
   return pom;
}



