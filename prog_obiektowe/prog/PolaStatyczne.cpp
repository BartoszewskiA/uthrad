#include <iostream>

using namespace std;

class osoba
{
private:
    int Id;
    string imie;
    static int ile;
public:
    osoba()
    {
        Id = ++ile;
        cout<<"imie: ";
        getline(cin,imie);
    }
    void wypisz()
    {
        cout<<Id<<" : "<<imie<<endl;
    }
    ~osoba()
    {
        cout<<"element "<<Id<<" usunieto"<<endl;
    }
};
const int n=3;
int osoba::ile =0;


int main()
{
    osoba *tab[n];
    for (int i=0; i<n;i++)
        tab[i] = new osoba();
    for(int i=0; i<n; i++)
        tab[i]->wypisz();
    for (int i=0; i<n;i++)
        delete tab[i];
    return 0;
}
