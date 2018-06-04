#ifndef BANKOMAT_H_INCLUDED
#define BANKOMAT_H_INCLUDED
#include "stanowisko.h"
#include "klient.h"

class bankomat
:public stanowisko
{
public:
    void wyplata(klient &klient_bankomatu, int nr_konta, double kwota);
};

#endif // BANKOMAT_H_INCLUDED
