#ifndef OBSLUGA_KASOWA_INTERFEJS_H_INCLUDED
#define OBSLUGA_KASOWA_INTERFEJS_H_INCLUDED
#include "klient.h"

class obsluga_kasowa_interfejs
{
    virtual void kasa_wplata(klient &klient, int nr_konta, double kwota)=0;
    virtual void kasa_wyplata(klient &klient, int nr_konta, double kwota)=0;
    virtual void przeniesienie_srodkow(klient &klient, int nr_konta_z, int nr_konta_do, double kwota)=0;
    virtual void przelew(klient &klient_z, int nr_konta_z, klient &klient_do, int nr_konta_do, double kwota)=0;
    virtual void oplac_rachunki(klient &klient, int nr_konta, double kwota)=0;
};

#endif // OBSLUGA_KASOWA_INTERFEJS_H_INCLUDED
