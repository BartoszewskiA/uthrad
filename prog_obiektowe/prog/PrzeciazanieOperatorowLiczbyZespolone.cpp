#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;

class zespolona
{
public:
    int a;
    int b;
    zespolona(int A=0, int B=0):a(A),b(B) {}
    string wypisz();
    zespolona operator+(zespolona);
    void operator+=(zespolona);

};
string zespolona::wypisz()
{
    ostringstream bufor;
    bufor<<a;
    if (b>=0) bufor<<"+";
    bufor<<b<<"i";
    return bufor.str();
}

zespolona zespolona::operator+(zespolona z2)
{
    zespolona temp;
    temp.a=this->a+z2.a;
    temp.b=this->b+z2.b;
    return temp;
}

void zespolona::operator+=(zespolona z2)
{
    a=a+z2.a;
    b=b+z2.b;
}

ostream& operator<<(ostream& stm, zespolona z)
{
    stm<<z.a;
    if (z.b>=0) stm<<"+";
    stm<<z.b<<"i";
    return stm;
}

istream& operator>>(istream &stm, zespolona& z)
{
    string temp,strA="",strB="";
    int poz=0;
    stm>>temp;
    do
    {
        strA+=temp[poz];
        poz++;
    } while(temp[poz]!='+' && temp[poz]!='-' && poz< temp.length());
    z.a=atoi(strA.c_str());

    do
    {
        strB+=temp[poz];
        poz++;
    } while(temp[poz]!='i' && poz< temp.length());
    z.b=atoi(strB.c_str());

    return stm;

}

int main()
{

    zespolona z1(2,-5), z2(3,2), z3(0,0);
    //cout<<z3.wypisz()<<endl;

    cin>>z3;
    //cout<<z3.wypisz();
    cout<<z3;
    return 0;
}
