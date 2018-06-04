#ifndef SYMULACJA_H_INCLUDED
#define SYMULACJA_H_INCLUDED
#include <ctime>
#include <random>
#include <string>
#include <fstream>
#include <unistd.h>
#include "bank.h"


typedef enum {prad, woda, gaz, telefon, internet} rodzaj_rachunku;

using namespace std;


class symulacja
    :public bank
{
public:
    symulacja(int l_bankomatow, int l_wplatomatow, int l_okienek): bank(l_bankomatow, l_wplatomatow, l_okienek) {}
    ~symulacja() {}
    void wczytaj_klientow();
    void wczytaj_pracownikow(int l_okienek);
    void przesun_kolejke_bankomat(int czas, ofstream &plik);
    void przesun_kolejke_wplatomat(int czas, ofstream &plik);
    void przesun_kolejke_obsluga_klienta(int czas, ofstream &plik);
    klient& losuj_klienta(int czas);
    klient& losuj_odbiorce(int czas, klient &obslugiwany);
    void test (int l_cykli);
};




#endif // SYMULACJA_H_INCLUDED
