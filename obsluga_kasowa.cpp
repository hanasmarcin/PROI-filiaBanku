#include "obsluga_kasowa.h"
void obsluga_kasowa::kasa_wplata(klient &klient, int nr_konta, double kwota)
{
    typ_klienta typ=klient.typ();
    klient.konta[nr_konta].dodaj_srodki(kwota);

    if (typ==ind) {czas_nast_klienta+=8; klient.wolny_po_czasie+=8;}
    else {czas_nast_klienta+=12; klient.wolny_po_czasie+=12;}
}

void obsluga_kasowa::kasa_wyplata(klient &klient, int nr_konta, double kwota)
{
    typ_klienta typ=klient.typ();
    klient.konta[nr_konta].zabierz_srodki(kwota);

    if (typ==ind)
    {
        czas_nast_klienta+=8;
        klient.wolny_po_czasie+=8;
        if (kwota>klient.konta[nr_konta].stan_konta())
        {
            string w= " ma za malo srodkow na tym koncie.";
            throw w;
        }
    }
    else {czas_nast_klienta+=12; klient.wolny_po_czasie+=12;}
}

void obsluga_kasowa::przeniesienie_srodkow(klient &klient, int nr_konta_z, int nr_konta_do, double kwota)
{
    typ_klienta typ=klient.typ();
    klient.konta[nr_konta_z].zabierz_srodki(kwota);
    klient.konta[nr_konta_do].dodaj_srodki(kwota);

    if (typ==ind) {czas_nast_klienta+=8; klient.wolny_po_czasie+=8;}
    else {czas_nast_klienta+=12; klient.wolny_po_czasie+=12;}
}

void obsluga_kasowa::przelew(klient &klient_z, int nr_konta_z, klient &klient_do, int nr_konta_do, double kwota)
{
    typ_klienta typ=klient_z.typ();

    if (typ==ind)
    {
        czas_nast_klienta+=8;
        klient_z.wolny_po_czasie+=8;
        if (kwota>klient_z.konta[nr_konta_z].stan_konta())
        {
            string w= " ma za malo srodkow na tym koncie.";
            throw w;
        }
    }
    else {czas_nast_klienta+=12; klient_z.wolny_po_czasie+=12;}
    klient_z.konta[nr_konta_z].zabierz_srodki(kwota);
    klient_do.konta[nr_konta_do].dodaj_srodki(kwota);
}

void obsluga_kasowa::oplac_rachunki(klient &klient, int nr_konta, double kwota)
{
    typ_klienta typ=klient.typ();
    klient.konta[nr_konta].zabierz_srodki(kwota+10);
    if (typ==ind) czas_nast_klienta+=2;
    else czas_nast_klienta+=3;

    if (typ==ind) {czas_nast_klienta+=8; klient.wolny_po_czasie+=8;}
    else {czas_nast_klienta+=12; klient.wolny_po_czasie+=12;}
}
