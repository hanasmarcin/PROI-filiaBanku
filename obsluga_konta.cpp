#include "obsluga_konta.h"

void obsluga_konta::zaloz_konto(klient &klient, double kwota)
{
    //typ_klienta typ=klient.typ();
    int nr_konta=klient.konta.size();

    klient.konta.push_back(konto(nr_konta, kwota));
    czas_nast_klienta+=10;
    klient.wolny_po_czasie+=10;
}
void obsluga_konta::zamknij_konto(klient &klient, int nr_konta)
{
    //typ_klienta typ=klient.typ();
    klient.konta.erase(klient.konta.begin()+nr_konta);
    czas_nast_klienta+=10;
    klient.wolny_po_czasie+=10;
}
