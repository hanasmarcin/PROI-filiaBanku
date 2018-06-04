#ifndef KLIENT_INTERFEJS_H_INCLUDED
#define KLIENT_INTERFEJS_H_INCLUDED
#include "typ_klienta.h"

class klient_interfejs
{
    virtual int liczba_kont()=0;
    virtual void dodaj_konto(double srodki)=0;
    virtual typ_klienta typ()=0;
    virtual int l_kont()=0;
    virtual double srodki_na_koncie(int nr_konta)=0;
};


#endif // KLIENT_INTERFEJS_H_INCLUDED
