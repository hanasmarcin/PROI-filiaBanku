#ifndef OBSLUGA_KONTA_H_INCLUDED
#define OBSLUGA_KONTA_H_INCLUDED
#include <vector>
#include "stanowisko.h"
#include "klient.h"
#include "obsluga_konta_interfejs.h"

class obsluga_konta
:public virtual stanowisko, public obsluga_konta_interfejs
{
public:
    void zaloz_konto(klient &klient, double kwota);
    void zamknij_konto(klient &klient, int nr_konta);
};



#endif // OBSLUGA_KONTA_H_INCLUDED
