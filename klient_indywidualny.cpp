#include "klient_indywidualny.h"

klient_indywidualny::klient_indywidualny (string n_imie, string n_nazwisko, string n_pesel, int id_klienta)
    : klient(n_imie, n_nazwisko, n_pesel, id_klienta)
{
    typ_k=ind;
}
