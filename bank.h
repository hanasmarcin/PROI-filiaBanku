#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "klient.h"
#include "klient_indywidualny.h"
#include "klient_biznesowy.h"
#include "bankomat.h"
#include "wplatomat.h"
#include "obsluga_klienta.h"

using namespace std;

class bank
{
private:
    void usun_kolejke( queue<klient*> &q )
    {
        queue<klient*> empty;
        swap( q, empty );
    }

protected:
    vector<klient_indywidualny> klienci_ind;
    vector<klient_biznesowy> klienci_biz;
    vector<pracownik> pracownicy;
    queue<klient*> kolejka_bankomat;
    queue<klient*> kolejka_wplatomat;
    queue<klient*> kolejka_obsluga_klienta;
    vector<bankomat> bankomaty;
    vector<wplatomat> wplatomaty;
    vector<obsluga_klienta> okienka;

public:
    bank(int l_bankomatow, int l_wplatomatow, int l_pracownikow);
    ~bank();

    int l_klientow(typ_klienta typ);
    void dodaj_klienta_ind(string imie, string nazwisko, string pesel);
    void dodaj_klienta_biz(string imie, string nazwisko, string pesel, string nazwa_firmy, string n_nip);
    void dodaj_pracownika_i_okienko(string imie, string nazwisko);
    void wczytaj_pracownikow(int l_pracownikow);
    klient& podaj_klienta(typ_klienta typ, int nr_klienta);


};


#endif // BANK_H_INCLUDED
