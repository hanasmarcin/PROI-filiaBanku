#include "bankomat.h"

void bankomat::wyplata(klient &klient_bankomatu, int nr_konta, double kwota)
{
    typ_klienta typ=klient_bankomatu.typ();

    if (typ==ind)
    {
        czas_nast_klienta+=4;
        klient_bankomatu.wolny_po_czasie+=4;
        if (kwota>klient_bankomatu.konta[nr_konta].stan_konta())
        {
            string w= " ma za malo srodkow na tym koncie.";
            throw w;
        }
        klient_bankomatu.konta[nr_konta].zabierz_srodki(kwota);
    }
    else //typ==biz
    {
        klient_bankomatu.konta[nr_konta].zabierz_srodki(kwota);
        czas_nast_klienta+=6;
        klient_bankomatu.wolny_po_czasie+=6;
    }
}
