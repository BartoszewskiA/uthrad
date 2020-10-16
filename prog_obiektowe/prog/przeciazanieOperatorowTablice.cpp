#include <iostream>

using namespace std;

class tablica
{
public:
    int n;
    int *tab;
    tablica(int ile)
    {
        n=ile;
        tab = new int[n];
    }
    ~tablica(){delete [] tab;}

    int& operator[](int i)
    {
        return tab[i];
    }

};


int main()
{
    tablica t1(10);

    t1[0] = 101;
    cout<<t1[0];

    return 0;
}
