#ifndef INFORMACJA_H_INCLUDED
#define INFORMACJA_H_INCLUDED
#include "stanowisko.h"
#include "klient.h"
#include "informacja_interfejs.h"
#include <fstream>

using namespace std;

class informacja
:public virtual stanowisko, public informacja_interfejs
{
public:
    ostream& stan_kont(klient &klient_inf, ostream &os);
};

#endif // INFORMACJA_H_INCLUDED
