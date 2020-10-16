#include <iostream>

using namespace std;

class RGB
{
private:
    int R;
    int G;
    int B;

public:
    RGB(int r = 0, int g = 0, int b = 0) : R(r), G(g), B(b) {}
    int getR() { return R; }
    int getG() { return G; }
    int getB() { return B; }
    RGB operator-(RGB);
    void operator--();
    //funkcje zaprzyjaznione z klasa
    friend ostream &operator<<(ostream &, RGB);
    friend istream &operator>>(istream &, RGB);
    friend RGB operator+(RGB k1, RGB k2);
    friend void operator++(RGB &);
    friend bool operator>(RGB, RGB);
};

void RGB::operator--()
{
    if (R > 0)
        R--;
    if (G > 0)
        G--;
    if (B > 0)
        B--;
}

RGB RGB::operator-(RGB k)
{
    RGB temp;
    temp.R = R - k.R;
    temp.G = G - k.G;
    temp.B = B - k.B;
    if (temp.R < 0)
        temp.R = 0;
    if (temp.G < 0)
        temp.G = 0;
    if (temp.B < 0)
        temp.B = 0;
    return temp;
}

bool operator>(RGB k1, RGB k2)
{
    double srK1 = (k1.R + k1.G + k1.B) / 3.0;
    double srK2 = (k2.R + k2.G + k2.B) / 3.0;
    if (srK1 > srK2)
        return true;
    else
        return false;
}

void operator++(RGB &k1)
{
    if (k1.R < 255)
        k1.R++;
    if (k1.G < 255)
        k1.G++;
    if (k1.B < 255)
        k1.B++;
}

RGB operator+(RGB k1, RGB k2)
{
    RGB temp;
    temp.R = k1.R + k2.R;
    temp.G = k1.G + k2.G;
    temp.B = k1.B + k2.B;
    if (temp.R > 255)
        temp.R = 255;
    if (temp.G > 255)
        temp.G = 255;
    if (temp.B > 255)
        temp.B = 255;
    return temp;
}

ostream &operator<<(ostream &stm, RGB kolor)
{
    // stm<<"R:"<<kolor.getR()<<" "
    //   <<"G:"<<kolor.getG()<<" "
    //   <<"B:"<<kolor.getB()<<" ";

    stm << "R:" << kolor.R << " "
        << "G:" << kolor.G << " "
        << "B:" << kolor.B << " ";
    return stm;
}

int main()
{
    RGB kolor1(234, 30, 45), kolor2(255, 0, 250);
    //RGB wynik = kolor1+kolor2;
    //cout<<wynik;
    //--wynik;
    //cout<<endl<<wynik;
    if (kolor1 > kolor2)
        cout << "tak";
    else
        cout << "NIE";
    return 0;
}
