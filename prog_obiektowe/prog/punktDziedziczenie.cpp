#include <iostream>

using namespace std;

class punkt
{
private:
    int x;
    int y;

public:
    punkt(int px = 0, int py = 0) : x(px), y(py) {}
    void setX(int px) { x = px; }
    void setY(int py) { y = py; }
    int getX() { return x; }
    int getY() { return y; }
    void przesunWPozionie(int ile);
    void przesunWPionie(int ile);
    double getObwod() { return 0.0; }
    double getPole() { return 0.0; }
};
void punkt::przesunWPozionie(int ile)
{
    x += ile;
}
void punkt::przesunWPionie(int ile)
{
    y += ile;
}
////////////////////////
class kwadrat : public punkt
{
    int a;

public:
    kwadrat(int px = 0, int py = 0, int pa = 0) : punkt(px, py), a(pa) {}
    void setA(int pa) { a = pa; }
    int getA() { return a; }
    double getObwod();
    double getPole();
};

double kwadrat::getPole()
{
    return (double)a * a;
}
double kwadrat::getObwod()
{
    return (double)4 * a;
}
////////////////////////////////////////
class kolo : public kwadrat
{
public:
    kolo(int px, int py, int pa) : kwadrat(px, py, pa) {}
    double getObwod();
    double getPole();
};

double kolo::getObwod()
{
    return 3.14 * (getA() / 2) * (getA() / 2);
}
double kolo::getPole()
{
    return 3.14 * getA();
}

int main()
{
    kolo *p1 = new kolo(20, 40, 100);
    p1->przesunWPozionie(-10);
    cout << "(" << p1->getX() << "," << p1->getY() << ")"
         << " bok=" << p1->getA() << " pole=" << p1->getPole();
    delete p1;
    return 0;
}
