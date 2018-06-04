#include "klient.h"


    int klient::liczba_kont() {return konta.size(); }

    void klient::dodaj_konto(double srodki)
    {
        konto nowe(liczba_kont()+1, srodki);

        konta.push_back(nowe);
    }

    typ_klienta klient::typ() { return typ_k; }

    int klient::l_kont()
    {
        return konta.size();
    }

    double klient::srodki_na_koncie(int nr_konta)
    {
        return konta[nr_konta].stan_konta();
    }

