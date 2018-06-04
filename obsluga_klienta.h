#ifndef OBSLUGA_KLIENTA_H_INCLUDED
#define OBSLUGA_KLIENTA_H_INCLUDED
#include "obsluga_kasowa.h"
#include "obsluga_konta.h"
#include "pracownik.h"
#include "informacja.h"


class obsluga_klienta
: public obsluga_kasowa, public obsluga_konta, public informacja
{
public:
    pracownik *p_obslugujacy;
    obsluga_klienta(pracownik *obslugujacy): p_obslugujacy(obslugujacy) {}
};

#endif // OBSLUGA_KLIENTA_H_INCLUDED
