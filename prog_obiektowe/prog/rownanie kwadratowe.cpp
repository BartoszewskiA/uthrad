#include <iostream>
#include <cmath>

using namespace std;

class rownanieKwadratowe
{
private:
    int a, b, c;
    int delta;
    double x1, x2;
    int liczbaRozwiazan = -1;
    void wyliczDelte()
    {
        delta = b * b - 4 * a * c;
        if (delta < 0)
            liczbaRozwiazan = 0;
        else if (delta == 0)
            liczbaRozwiazan = 1;
        else
            liczbaRozwiazan = 2;
        if (a == 0)
            liczbaRozwiazan = -1;
    }
    void rozwiaz();

public:
    rownanieKwadratowe(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        wyliczDelte();
        rozwiaz();
    }
    void setA(int dana);
    void setB(int dana);
    void setC(int dana);
    double getX1();
    double getX2();
    int getLiczbaRozw();
    void podajWynik();
};
//--- metody zewnetrzne klasy ------

void rownanieKwadratowe::setA(int dana)
{
    a = dana;
    wyliczDelte();
    rozwiaz();
}
void rownanieKwadratowe::setB(int dana)
{
    b = dana;
    wyliczDelte();
    rozwiaz();
}
void rownanieKwadratowe::setC(int dana)
{
    c = dana;
    wyliczDelte();
    rozwiaz();
}
double rownanieKwadratowe::getX1()
{
    return x1;
}
double rownanieKwadratowe::getX2()
{
    return x2;
}
void rownanieKwadratowe::rozwiaz()
{
    if (liczbaRozwiazan >= 0)
    {
        if (delta > 0)
        {
            x1 = (-b - sqrt(delta)) / (2 * a);
            x2 = (-b + sqrt(delta)) / (2 * a);
        }
        else if (delta = 0)
        {
            x1 = x2 = (-b) / (2 * a);
        }
        else
        {
            x1 = x2 = 0;
        }
    }
}

int rownanieKwadratowe::getLiczbaRozw()
{
    return liczbaRozwiazan;
}

void rownanieKwadratowe::podajWynik()
{
    if (liczbaRozwiazan < 0)
    {
        cout << "To nie jest rownanie kwadtatowe";
    }
    else if (liczbaRozwiazan == 0)
    {
        cout << "Brak rozwiazan w zbiorze liczb rzeczywistych";
    }
    else if (liczbaRozwiazan == 1)
    {
        cout << "x0 = " << x1;
    }
    else
    {
        cout << "x1 = " << x1 << endl
             << "x2 = " << x2 << endl;
    }
}

//----------- koniec klasy---------------
int main()
{
    int x;
    rownanieKwadratowe k1(10, 5, 3), k2(-1, 3, 5);

    cout << "Rownanie ma " << k2.getLiczbaRozw() << " rozwiazan";
    k2.podajWynik();
    cout << endl
         << "-------------------------------------" << endl;

    cout << "Podaj a";
    cin >> x;
    k1.setA(x);
    cout << "Podaj b";
    cin >> x;
    k1.setB(x);
    cout << "Podaj c";
    cin >> x;
    k1.setC(x);

    cout << "Rownanie ma " << k1.getLiczbaRozw() << " rozwiazan";
    k1.podajWynik();
    return 0;
}
