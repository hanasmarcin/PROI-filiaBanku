#include "bank.h"
#include <vector>
#include <fstream>

using namespace std;

bank::bank(int l_bankomatow, int l_wplatomatow, int l_okienek)
{
    bankomat b_temp;
    wplatomat w_temp;
    for (int i=0; i<l_bankomatow; i++) bankomaty.push_back(b_temp);
    for (int i=0; i<l_wplatomatow; i++) wplatomaty.push_back(w_temp);
    try {wczytaj_pracownikow(l_okienek);}
    catch (string w) {cout << w <<endl;}
}

void bank::wczytaj_pracownikow(int l_okienek)
{
    ifstream plik;
    plik.open("pracownicy.txt");
    if(plik.good())
    {
        string imie, nazwisko;

        for (int i=0; i<l_okienek; i++)
        {
            dodaj_pracownika_i_okienko(imie, nazwisko);
        }
    }
    else
    {
    	string w="Wystapil problem z plikiem.";
	plik.close();
        throw w;
    }
    plik.close();
}

bank::~bank()
{
    usun_kolejke(kolejka_bankomat);
    usun_kolejke(kolejka_wplatomat);
    usun_kolejke(kolejka_obsluga_klienta);
    klienci_ind.clear();
    klienci_biz.clear();
    pracownicy.clear();
    bankomaty.clear();
    wplatomaty.clear();
    okienka.clear();
    cout << "Usunieto dane banku"<<endl;
}

int bank::l_klientow(typ_klienta typ)
{
    if(typ==ind) return klienci_ind.size();
    else return klienci_biz.size();
}

void bank::dodaj_klienta_ind(string imie, string nazwisko, string pesel)
{
    int id_klienta=l_klientow(ind);
    klienci_ind.push_back(klient_indywidualny(imie, nazwisko, pesel, id_klienta));
}

void bank::dodaj_pracownika_i_okienko(string imie, string nazwisko)
{
    int id_stanowiska=okienka.size();
    pracownicy.insert(pracownicy.begin(), pracownik(imie, nazwisko, id_stanowiska));
    okienka.push_back(obsluga_klienta(&pracownicy.front()));
}

void bank::dodaj_klienta_biz(string imie, string nazwisko, string pesel, string nazwa_firmy, string n_nip)
{
    int id_klienta=l_klientow(biz);
    klienci_biz.push_back(klient_biznesowy(imie, nazwisko, pesel, id_klienta, nazwa_firmy, n_nip));
}

klient& bank::podaj_klienta(typ_klienta typ, int nr_klienta)
{
    if(typ==ind) return klienci_ind[nr_klienta];
    else return klienci_biz[nr_klienta];
}
