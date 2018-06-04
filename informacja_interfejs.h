#ifndef INFORMACJA_INTERFEJS_H_INCLUDED
#define INFORMACJA_INTERFEJS_H_INCLUDED
#include <fstream>

class informacja_interfejs
{
    virtual ostream& stan_kont(klient &klient_inf, ostream &os)=0;
};

#endif // INFORMACJA_INTERFEJS_H_INCLUDED
