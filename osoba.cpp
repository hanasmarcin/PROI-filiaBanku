#include "osoba.h"

ostream & operator<< (ostream &wyjscie, const osoba &os)
{
    return wyjscie << os.imie << " " << os.nazwisko;
}
