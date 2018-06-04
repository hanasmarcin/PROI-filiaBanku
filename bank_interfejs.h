#ifndef BANK_INTERFEJS_H_INCLUDED
#define BANK_INTERFEJS_H_INCLUDED
#include "typ_klienta.h"

class bank_interfejs
{
    virtual int l_klientow(typ_klienta typ)=0;
    virtual void dodaj_klienta_ind(string imie, string nazwisko, string pesel)=0;
    virtual void dodaj_klienta_biz(string imie, string nazwisko, string pesel, string nazwa_firmy, string n_nip)=0;
    virtual void dodaj_pracownika_i_okienko(string imie, string nazwisko)=0;
    virtual void wczytaj_pracownikow(int l_pracownikow)=0;
    virtual klient& podaj_klienta(typ_klienta typ, int nr_klienta)=0;
};

#endif // BANK_INTERFEJS_H_INCLUDED
