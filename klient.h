#ifndef KLIENT_H_INCLUDED
#define KLIENT_H_INCLUDED
#include <string>
#include <vector>
#include "konto.h"
#include "osoba.h"
#include "klient_interfejs.h"

using namespace std;

class klient
: public osoba, public klient_interfejs
{
protected:
    string pesel;
    typ_klienta typ_k;
public:
    //typ_klienta typ;
    int id_klienta;
    int wolny_po_czasie;
    bool w_kolejce;

    vector<konto> konta;

    klient(string n_imie="A", string n_nazwisko="A", string n_pesel="00000000000", int id_klienta=0)
    : osoba(n_imie, n_nazwisko), pesel(n_pesel), wolny_po_czasie(0), w_kolejce(false) {}

    int liczba_kont();

    void dodaj_konto(double srodki);

    typ_klienta typ();
    int l_kont();

    double srodki_na_koncie(int nr_konta);
};







#endif // KLIENT_H_INCLUDED
