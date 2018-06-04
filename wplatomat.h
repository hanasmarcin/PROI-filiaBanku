#ifndef WPLATOMAT_H_INCLUDED
#define WPLATOMAT_H_INCLUDED
#include "stanowisko.h"
#include "klient.h"

class wplatomat
:public stanowisko
{
public:
    void wplata(klient &klient_wplatomatu, int nr_konta, double kwota);
};


#endif // WPLATOMAT_H_INCLUDED
