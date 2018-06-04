#ifndef KLIENT_INDYWIDUALNY_H_INCLUDED
#define KLIENT_INDYWIDUALNY_H_INCLUDED
#include "klient.h"

class klient_indywidualny
: public klient
{
protected:
    //adres adr_zameldowania;
public:
    klient_indywidualny (string n_imie="A", string n_nazwisko="A", string n_pesel="00000000000", int id_klienta=0);
};

#endif // KLIENT_INDYWIDUALNY_H_INCLUDED
