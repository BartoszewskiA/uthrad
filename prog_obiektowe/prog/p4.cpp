#include <iostream>
#include <ctime>

using namespace std;

class osoba
{
    private:
      string imie;
      string nazwisko;
      int rokUrodzenia;
    public:
    void setImie(string kto) {
        imie = kto;
    }
    void setNazwisko(string kto) {
        nazwisko = kto;
    }
    string getImie() {
        return imie;
    }
    string getNazwisko() {
        return nazwisko;
    }
    int getRokUrodzenia() {
        return rokUrodzenia;
    }
     void podajWiek(int wiek);
};

int main()
{
    osoba pracownik1;
    string im, nazw;
    int w;
    cout<<"Podaj imie: ";       cin>>im;
    cout<<"Podaj nazwisko: ";   cin>>nazw;
    cout<<"Podaj wiek: ";       cin>>w;
    //pracownik1.imie = im;
    //powy¿sza operacje jest niedozwolna - pola s¹ prywatne
    pracownik1.setImie(im);
    pracownik1.setNazwisko(nazw);
    //pracownik1.setWiek(w);
    pracownik1.podajWiek(w);

    cout << pracownik1.getImie()<<" "
         << pracownik1.getNazwisko()<<" "
         << pracownik1.getRokUrodzenia();
    return 0;
}

void osoba::podajWiek(int wiek)
{
    time_t czas = time(NULL);
    tm * czaslokalny;
    czaslokalny=localtime(&czas);
    rokUrodzenia=(czaslokalny->tm_year+1900)-wiek;
}

