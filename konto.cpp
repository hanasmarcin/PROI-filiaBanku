#include "konto.h"

    void konto::zabierz_srodki(double kwota)
    {
        srodki-=kwota;
    }

    void konto::dodaj_srodki(double kwota)
    {
        srodki+=kwota;
    }

    double konto::stan_konta()
    {
        return srodki;
    }
