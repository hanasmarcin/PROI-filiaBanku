#ifndef OBSLUGA_KASOWA_H_INCLUDED
#define OBSLUGA_KASOWA_H_INCLUDED
#include "obsluga_kasowa_interfejs.h"
#include "stanowisko.h"
#include "klient.h"

class obsluga_kasowa
:public virtual stanowisko, public obsluga_kasowa_interfejs
{
public:
    void kasa_wplata(klient &klient, int nr_konta, double kwota);
    void kasa_wyplata(klient &klient, int nr_konta, double kwota);
    void przeniesienie_srodkow(klient &klient, int nr_konta_z, int nr_konta_do, double kwota);
    void przelew(klient &klient_z, int nr_konta_z, klient &klient_do, int nr_konta_do, double kwota);
    void oplac_rachunki(klient &klient, int nr_konta, double kwota);
};



#endif // OBSLUGA_KASOWA_H_INCLUDED
