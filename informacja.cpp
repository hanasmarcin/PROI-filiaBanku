#include "informacja.h"

ostream& informacja::stan_kont(klient &klient_inf, ostream& os)
{
    typ_klienta typ=klient_inf.typ();

    if (typ==ind)
    {
        for (int i=0; i<klient_inf.liczba_kont(); i++)
        {
            os << klient_inf.konta[i].stan_konta() << "zl ";
        }
        czas_nast_klienta+=4;
        klient_inf.wolny_po_czasie+=4;
    }
    else //typ==biz
    {
        for (int i=0; i<klient_inf.liczba_kont(); i++)
        {
            os << klient_inf.konta[i].stan_konta() << "zl ";
        }
        czas_nast_klienta+=6;
        klient_inf.wolny_po_czasie+=6;
    }
    return os;
}
