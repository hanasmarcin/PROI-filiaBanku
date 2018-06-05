#include "klient_biznesowy.h"

klient_biznesowy::klient_biznesowy (string n_imie, string n_nazwisko, string n_pesel, int id_klienta, string n_nazwa_firmy, string n_nip)
    : klient(n_imie, n_nazwisko, n_pesel, id_klienta), nazwa_firmy(n_nazwa_firmy), nip(n_nip)
{
    typ_k=biz;
}
