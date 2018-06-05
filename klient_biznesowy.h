#ifndef KLIENT_BIZNESOWY_H_INCLUDED
#define KLIENT_BIZNESOWY_H_INCLUDED
#include "klient.h"

class klient_biznesowy
: public klient
{
private:
	string nazwa_firmy;
	string nip;
public:

    klient_biznesowy (string n_imie="A", string n_nazwisko="A", string n_pesel="00000000000", int id_klienta=0, string n_nazwa_firmy="", string n_nip="");
};

#endif // KLIENT_BIZNESOWY_H_INCLUDED
