#include "wplatomat.h"

void wplatomat::wplata(klient &klient_wplatomatu, int nr_konta, double kwota)
{
    typ_klienta typ=klient_wplatomatu.typ();

    if (typ==ind)
    {
        klient_wplatomatu.konta[nr_konta].dodaj_srodki(kwota);
        czas_nast_klienta+=3;
        klient_wplatomatu.wolny_po_czasie+=3;
    }
    else //typ==biz
    {
        klient_wplatomatu.konta[nr_konta].dodaj_srodki(kwota);
        czas_nast_klienta+=5;
        klient_wplatomatu.wolny_po_czasie+=5;
    }
}
