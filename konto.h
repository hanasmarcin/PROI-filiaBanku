#ifndef KONTO_H_INCLUDED
#define KONTO_H_INCLUDED
#include "konto_interfejs.h"

class konto
:public konto_interfejs
{
private:
    int nr_konta;
    double srodki;
public:
    konto(int nr, double sr): nr_konta(nr), srodki(sr) {}

    void zabierz_srodki(double kwota);

    void dodaj_srodki(double kwota);

    double stan_konta();

};


#endif // KONTO_H_INCLUDED
