#include <iostream>

using namespace std;

int main()
{
    int *tablica[10]; //STSTYCZNA tablia wskaxników
    int temp;
    for (int i=0; i<10;i++) //tworzymy zmienne dynamiczne
    {						//wskazniki do nich zapamietujemy w tablicy
        cout<<"Tab["<<i<<"]=";
        cin >> temp;
        tablica[i]=new int;
        *tablica[i]=temp;
    }
    for (int i=0;i<10;i++) //wypisujemy zawartość 
    {					   //zmiennych podczepionych pod tablice
        cout << *tablica[i] <<" ";
    }
    for (int i=0;i<10;i++) //usuwanie elementów
    {                      //podczepionych pod tablice
        delete tablica[i];
    }
    return 0;
}
