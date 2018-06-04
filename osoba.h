#ifndef OSOBA_H_INCLUDED
#define OSOBA_H_INCLUDED
#include <string>
#include <iostream>

using namespace std;

class osoba
{
private:
    string imie;
    string nazwisko;
protected:
    osoba(string n_imie="", string n_nazwisko="")
    : imie(n_imie), nazwisko(n_nazwisko) {}
public:
    friend ostream & operator<< (ostream &wyjscie, const osoba &os);
};

#endif // OSOBA_H_INCLUDED
