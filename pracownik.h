#ifndef PRACOWNIK_H_INCLUDED
#define PRACOWNIK_H_INCLUDED
#include "osoba.h"

class pracownik
: public osoba
{
    int id_stanowiska;
public:
    pracownik(string n_imie, string n_nazwisko, int n_id=0): osoba(n_imie, n_nazwisko), id_stanowiska(n_id) {}
    //obsluga_klienta *p_stanowisko;

};

#endif // PRACOWNIK_H_INCLUDED
