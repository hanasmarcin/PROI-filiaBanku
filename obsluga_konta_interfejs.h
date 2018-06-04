#ifndef OBSLUGA_KONTA_INTERFEJS_H_INCLUDED
#define OBSLUGA_KONTA_INTERFEJS_H_INCLUDED

class obsluga_konta_interfejs
{
    virtual void zaloz_konto(klient &klient, double kwota)=0;
    virtual void zamknij_konto(klient &klient, int nr_konta)=0;
};

#endif // OBSLUGA_KONTA_INTERFEJS_H_INCLUDED
