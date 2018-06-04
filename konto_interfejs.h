#ifndef KONTO_INTERFEJS_H_INCLUDED
#define KONTO_INTERFEJS_H_INCLUDED

class konto_interfejs
{
    virtual void zabierz_srodki(double kwota)=0;
    virtual void dodaj_srodki(double kwota)=0;
    virtual double stan_konta()=0;
};

#endif // KONTO_INTERFEJS_H_INCLUDED
