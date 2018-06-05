#include "symulacja.h"

int losuj(int a, int b)
{
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(a, b);
    int number =  dist( gen );
    return number;
}


string wyjatek_zajety="klient jest zajety.";

void symulacja::wczytaj_klientow()
{
    ifstream plik;
    plik.open("klienci.txt");
    if(plik.good())
    {
        int l_klientow_ind, l_klientow_biz, l_kont;
        string imie, nazwisko, pesel, nazwa_firmy, n_nip, tmp;

        plik >> l_klientow_ind >> l_klientow_biz;
        for (int i=0; i<l_klientow_ind; i++)
        {
            plik >> imie >> nazwisko >> pesel >> l_kont;
            dodaj_klienta_ind(imie, nazwisko, pesel);
            for (int k=0; k<l_kont; k++)
            {
                int srodki;
                plik >> srodki;
                podaj_klienta(ind, i).dodaj_konto(srodki);
            }
        }
        for (int i=0; i<l_klientow_biz; i++)
        {
            plik >> imie >> nazwisko >> pesel >> n_nip >> l_kont;
            getline(plik, tmp);
            getline(plik, nazwa_firmy);
            dodaj_klienta_biz(imie, nazwisko, pesel, nazwa_firmy, n_nip);
            for (int k=0; k<l_kont; k++)
            {
                int srodki;
                plik >> srodki;
                podaj_klienta(biz, i).dodaj_konto(srodki);

            }
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



void symulacja::przesun_kolejke_bankomat(int czas, ofstream &plik)
{
    for(unsigned int i=0; i<bankomaty.size(); i++)
    {
        if (kolejka_bankomat.empty()) break;
        if (bankomaty[i].czas_nast_klienta<=czas)
        {
            cout << "****WYPLATA w bankomacie nr: " << i << endl;
            plik << "****WYPLATA w bankomacie nr: " << i << endl;
            klient *p_obslugiwany=kolejka_bankomat.front();
            p_obslugiwany->wolny_po_czasie=czas;
            int l_nr_konta=losuj(0, p_obslugiwany->l_kont()-1);
            double l_kwota=10*losuj(2, 200);
            cout << "    Klient ";
            plik << "    Klient ";
            if (p_obslugiwany->typ()==ind){cout << "indywidualny "; plik << "indywidualny ";}
            else {cout << "biznesowy "; plik << "biznesowy ";}
            cout << *p_obslugiwany;
            plik << *p_obslugiwany;
            try
            {
                bankomaty[i].wyplata(*p_obslugiwany, l_nr_konta, l_kwota);
                cout << " wyplaca " << l_kwota << "zl z " << l_nr_konta << ". konta." << endl;
                plik << " wyplaca " << l_kwota << "zl z " << l_nr_konta << ". konta." << endl;
            }
            catch(string w)
            {
                cout << w << endl;
                plik << w << endl;
            }

            cout << "    Obecny stan tego konta: " << p_obslugiwany->srodki_na_koncie(l_nr_konta) << "zl" <<endl;
            plik << "    Obecny stan tego konta: " << p_obslugiwany->srodki_na_koncie(l_nr_konta) << "zl" <<endl;
            p_obslugiwany->w_kolejce=false;
            cout << "    Czas zakonczenia obslugi: "<< p_obslugiwany->wolny_po_czasie <<endl;
            plik << "    Czas zakonczenia obslugi: "<< p_obslugiwany->wolny_po_czasie <<endl;
            kolejka_bankomat.pop();
        }
    }
}

void symulacja::przesun_kolejke_wplatomat(int czas, ofstream &plik)
{
    for(unsigned int i=0; i<wplatomaty.size(); i++)
    {
        if (kolejka_wplatomat.empty()) break;
        if (wplatomaty[i].czas_nast_klienta<=czas)
        {
            cout << "***WPLATA we wplatomacie nr: " << i <<endl;
            plik << "***WPLATA we wplatomacie nr: " << i <<endl;
            klient *p_obslugiwany=kolejka_wplatomat.front();
            p_obslugiwany->wolny_po_czasie=czas;
            int l_nr_konta=losuj(0, p_obslugiwany->l_kont()-1);
            int l_kwota=10*losuj(2, 200);
            cout << "   Klient ";
            plik << "   Klient ";
            if (p_obslugiwany->typ()==ind){cout << "indywidualny "; plik << "indywidualny ";}
            else {cout << "biznesowy "; plik << "biznesowy ";}
            cout << *p_obslugiwany << " wplaca " << l_kwota << "zl na " << l_nr_konta << ". konto." << endl;
            plik << *p_obslugiwany << " wplaca " << l_kwota << "zl na " << l_nr_konta << ". konto." << endl;
            wplatomaty[i].wplata(*p_obslugiwany, l_nr_konta, l_kwota);
            cout << "   Obecny stan tego konta: " << p_obslugiwany->srodki_na_koncie(l_nr_konta) << "zl" <<endl;
            plik << "   Obecny stan tego konta: " << p_obslugiwany->srodki_na_koncie(l_nr_konta) << "zl" <<endl;
            p_obslugiwany->w_kolejce=false;
            cout << "   Czas zakonczenia obslugi: "<< p_obslugiwany->wolny_po_czasie <<endl;
            plik << "   Czas zakonczenia obslugi: "<< p_obslugiwany->wolny_po_czasie <<endl;
            kolejka_wplatomat.pop();
        }
    }
}

void symulacja::przesun_kolejke_obsluga_klienta(int czas, ofstream &plik)
{
    for(unsigned int i=0; i<okienka.size(); i++)
    {
        if (kolejka_obsluga_klienta.empty()) break;
        if (okienka[i].czas_nast_klienta<=czas)
        {
            klient *p_obslugiwany=kolejka_obsluga_klienta.front();
            //p_obslugiwany->wolny_po_czasie=czas;
            //int nr_operacji=losuj(3, 5);
            //int nr_operacji=3;
            /*while (p_obslugiwany->w_kolejce==true){*/int nr_operacji=losuj(1, 8);
            p_obslugiwany->wolny_po_czasie=czas;
            switch (nr_operacji)
            {
            case 1:
            {
                cout << "**WPLATA PRZY KASIE przy okienku nr " << i << endl;
                plik << "**WPLATA PRZY KASIE przy okienku nr " << i << endl;
                int l_nr_konta=losuj(0, p_obslugiwany->l_kont()-1);
                int l_kwota=10*losuj(2, 200);
                cout << "  Klient ";
                plik << "  Klient ";
                if (p_obslugiwany->typ()==ind){cout << "indywidualny "; plik << "indywidualny ";}
                else {cout << "biznesowy "; plik << "biznesowy ";}
                cout << *p_obslugiwany << " wplaca " << l_kwota << "zl na " << l_nr_konta << ". konto." << endl;
                plik << *p_obslugiwany << " wplaca " << l_kwota << "zl na " << l_nr_konta << ". konto." << endl;
                okienka[i].kasa_wplata(*p_obslugiwany, l_nr_konta, l_kwota);
                p_obslugiwany->w_kolejce=false;
                break;
            }
            case 2:
            {
                cout << "**WYPLATA PRZY KASIE przy okienku nr " << i << endl;
                plik << "**WYPLATA PRZY KASIE przy okienku nr " << i << endl;
                int l_nr_konta=losuj(0, p_obslugiwany->l_kont()-1);
                int l_kwota=10*losuj(2, 200);
                cout << "  Klient ";
                plik << "  Klient ";
                if (p_obslugiwany->typ()==ind){cout << "indywidualny "; plik << "indywidualny ";}
                else {cout << "biznesowy "; plik << "biznesowy ";}
                cout << *p_obslugiwany;
                plik << *p_obslugiwany;
                try
                {
                    okienka[i].kasa_wyplata(*p_obslugiwany, l_nr_konta, l_kwota);
                    cout << " wyplaca " << l_kwota << "zl z " << l_nr_konta << ". konta." << endl;
                    plik << " wyplaca " << l_kwota << "zl z " << l_nr_konta << ". konta." << endl;
                }
                catch(string w)
                {
                    cout << w << endl;
                    plik << w << endl;
                }

                p_obslugiwany->w_kolejce=false;
                break;
            }
            case 3:
            {
                cout << "**PRZENIESIENIE SRODKOW przy okienku nr " << i << endl;
                plik << "**PRZENIESIENIE SRODKOW przy okienku nr " << i << endl;
                if(p_obslugiwany->l_kont()<2)
                {
                    cout << "  Klient ma mniej niz 2 konta, wybiera inna akcje." <<endl;
                    plik << "  Klient ma mniej niz 2 konta, wybiera inna akcje." <<endl;
                    break;
                }
                int l_nr_konta_z=losuj(0, p_obslugiwany->l_kont()-1);
                int l_nr_konta_do=losuj(0, p_obslugiwany->l_kont()-1);
                while (l_nr_konta_do==l_nr_konta_z) l_nr_konta_do=losuj(0, p_obslugiwany->l_kont()-1);

                int l_kwota=losuj(1, 20000);
                cout << "  Klient ";
                plik << "  Klient ";
                if (p_obslugiwany->typ()==ind){cout << "indywidualny "; plik << "indywidualny ";}
                else {cout << "biznesowy "; plik << "biznesowy ";}
                cout << *p_obslugiwany << " przenosi " << l_kwota << "zl z " << l_nr_konta_z << ". konta na " << l_nr_konta_do <<". konto."<< endl;
                plik << *p_obslugiwany << " przenosi " << l_kwota << "zl z " << l_nr_konta_z << ". konta na " << l_nr_konta_do <<". konto."<< endl;
                okienka[i].przeniesienie_srodkow(*p_obslugiwany, l_nr_konta_z, l_nr_konta_do, l_kwota);
                p_obslugiwany->w_kolejce=false;
                break;
            }
            case 4:
            {
                cout << "**PRZELEW przy okienku nr " << i << endl;
                plik << "**PRZELEW przy okienku nr " << i << endl;
                int l_nr_konta_z=losuj(0, p_obslugiwany->l_kont()-1);
                int nr_klienta_do;
                typ_klienta typ_do=(typ_klienta)losuj(0, 1);
                if(typ_do==ind) nr_klienta_do=losuj(0, l_klientow(ind)-1);
                else nr_klienta_do=losuj(0, l_klientow(biz)-1);
                klient* p_klienta_do=&podaj_klienta(typ_do, nr_klienta_do);
                int l_nr_konta_do=losuj(0, p_klienta_do->l_kont()-1);

                int l_kwota=losuj(1, 20000);
                cout << "  Klient ";
                plik << "  Klient ";
                if (p_obslugiwany->typ()==ind){cout << "indywidualny "; plik << "indywidualny ";}
                else {cout << "biznesowy "; plik << "biznesowy ";}
                                cout << *p_obslugiwany;
                plik << *p_obslugiwany;
                try
                {
                    okienka[i].przelew(*p_obslugiwany, l_nr_konta_z, *p_klienta_do, l_nr_konta_do, l_kwota);
                    cout << " przelewa " << l_kwota << "zl dla osoby " << *p_klienta_do << endl;
                    plik << " przelewa " << l_kwota << "zl dla osoby " << *p_klienta_do << endl;
                }
                catch(string w)
                {
                    cout << w << endl;
                    plik << w << endl;
                }

                p_obslugiwany->w_kolejce=false;
                break;
            }
            case 5:
            {
                cout << "**OPLATA RACHUNKOW przy okienku nr " << i << endl;
                plik << "**OPLATA RACHUNKOW przy okienku nr " << i << endl;
                int l_nr_konta=losuj(0, p_obslugiwany->l_kont()-1);
                int l_kwota=losuj(1, 200);
                rodzaj_rachunku l_rachunek=(rodzaj_rachunku)losuj(0, 4);
                cout << "  Klient ";
                plik << "  Klient ";
                if (p_obslugiwany->typ()==ind){cout << "indywidualny "; plik << "indywidualny ";}
                else {cout << "biznesowy "; plik << "biznesowy ";}
                cout << *p_obslugiwany <<" oplaca rachunki za ";
                plik << *p_obslugiwany <<" oplaca rachunki za ";
                switch (l_rachunek)
                {
                    case prad:{
                        cout <<"prad";
                        plik <<"prad";
                        break;
                    }
                    case woda:{
                        cout <<"wode";
                        plik <<"wode";
                        break;
                    }
                    case gaz:{
                        cout <<"gaz";
                        plik <<"gaz";
                        break;
                    }
                    case telefon:{
                        cout <<"telefon";
                        plik <<"telefon";
                        break;
                    }
                    case internet:{
                        cout <<"internet";
                        plik <<"internet";
                        break;
                    }
                }
                cout << " o wysokosci "<< l_kwota <<"zl z konta "<< l_nr_konta << "."<<endl;
                plik << " o wysokosci "<< l_kwota <<"zl z konta "<< l_nr_konta << "."<<endl;
                okienka[i].oplac_rachunki(*p_obslugiwany, l_nr_konta, l_kwota);
                p_obslugiwany->w_kolejce=false;
                break;
            }
            case 6:
            {
                cout << "**ZALOZENIE KONTA przy okienku nr " << i << endl;
                plik << "**ZALOZENIE KONTA przy okienku nr " << i << endl;
                int l_kwota=losuj(100, 20000);
                cout << "  Klient ";
                plik << "  Klient ";
                if (p_obslugiwany->typ()==ind){cout << "indywidualny "; plik << "indywidualny ";}
                else {cout << "biznesowy "; plik << "biznesowy ";}
                cout << *p_obslugiwany <<" zaklada " << p_obslugiwany->l_kont()+1 <<". konto i wplaca na nie " << l_kwota <<"zl."<<endl;
                plik << *p_obslugiwany <<" zaklada " << p_obslugiwany->l_kont()+1 <<". konto i wplaca na nie " << l_kwota <<"zl."<<endl;
                okienka[i].zaloz_konto(*p_obslugiwany, l_kwota);
                p_obslugiwany->w_kolejce=false;
                break;
            }
            case 7:
            {
                cout << "**ZAMKNIECIE KONTA przy okienku nr " << i << endl;
                plik << "**ZAMKNIECIE KONTA przy okienku nr " << i << endl;
                if(p_obslugiwany->l_kont()<2)
                {
                    cout << "  Klient ma mniej niz 2 konta, wybiera inna akcje." <<endl;
                    plik << "  Klient ma mniej niz 2 konta, wybiera inna akcje." <<endl;
                    break;
                }
                int l_nr_konta=losuj(0, p_obslugiwany->l_kont()-1);
                cout << "  Klient ";
                plik << "  Klient ";
                if (p_obslugiwany->typ()==ind){cout << "indywidualny "; plik << "indywidualny ";}
                else {cout << "biznesowy "; plik << "biznesowy ";}
                cout << *p_obslugiwany <<" zamyka " << l_nr_konta <<". konto wyplacajac z niego " << p_obslugiwany->srodki_na_koncie(l_nr_konta) <<"zl."<<endl;
                plik << *p_obslugiwany <<" zamyka " << l_nr_konta <<". konto wyplacajac z niego " << p_obslugiwany->srodki_na_koncie(l_nr_konta) <<"zl."<<endl;
                okienka[i].zamknij_konto(*p_obslugiwany, l_nr_konta);
                p_obslugiwany->w_kolejce=false;
                break;
            }
                        case 8:
            {
                cout << "**SPRAWDZENIE STANU KONT przy okienku nr " << i << endl;
                plik << "**SPRAWDZENIE STANU KONT przy okienku nr " << i << endl;
                cout << "  Klient ";
                plik << "  Klient ";
                if (p_obslugiwany->typ()==ind){cout << "indywidualny "; plik << "indywidualny ";}
                else {cout << "biznesowy "; plik << "biznesowy ";}
                cout << *p_obslugiwany <<" ma nastepujace stany kont:" <<endl << "  ";
                plik << *p_obslugiwany <<" ma nastepujace stany kont:" <<endl << "  ";

                okienka[i].stan_kont(*p_obslugiwany, cout);
                cout << endl;
                okienka[i].stan_kont(*p_obslugiwany, plik);
                plik << endl;

                p_obslugiwany->w_kolejce=false;
                break;
            }
            }
            //cout << i <<" czypustakoniec: " << kolejka_obsluga_klienta.empty() <<endl;

            //cout << i <<" czypustakoniec: " << kolejka_obsluga_klienta.empty() <<endl;
            //}
            cout << "  Czas zakonczenia obslugi: "<< p_obslugiwany->wolny_po_czasie <<endl;
            plik << "  Czas zakonczenia obslugi: "<< p_obslugiwany->wolny_po_czasie <<endl;
            kolejka_obsluga_klienta.pop();
        }
    }
}


klient& symulacja::losuj_klienta(int czas)
{
    typ_klienta typ=(typ_klienta)losuj(0, 1);
    int id_klienta;
    if (typ==ind) id_klienta=losuj(0, l_klientow(ind)-1);
    else id_klienta=losuj(0, l_klientow(biz)-1);

    /*WERSJA 1:
    while (podaj_klienta(typ, id_klienta).wolny_po_czasie>czas || podaj_klienta(typ, id_klienta).w_kolejce)
    {
        if (typ==ind) id_klienta=losuj(0, l_klientow(ind)-1);
        else id_klienta=losuj(0, l_klientow(biz)-1);
    }
    return podaj_klienta(typ, id_klienta);

    WERSJA 2:
    */
    if (podaj_klienta(typ, id_klienta).wolny_po_czasie<=czas && !podaj_klienta(typ, id_klienta).w_kolejce) return podaj_klienta(typ, id_klienta);
    else throw wyjatek_zajety;

}

klient& symulacja::losuj_odbiorce(int czas, klient &obslugiwany)
{
    typ_klienta typ=(typ_klienta)losuj(0, 1);
    int id_klienta;
    if (typ==ind) id_klienta=losuj(0, l_klientow(ind)-1);
    else id_klienta=losuj(0, l_klientow(biz)-1);

    while (typ==obslugiwany.typ() && id_klienta==obslugiwany.id_klienta)
    {
        if (typ==ind) id_klienta=losuj(0, l_klientow(ind)-1);
        else id_klienta=losuj(0, l_klientow(biz)-1);
    }
    return podaj_klienta(typ, id_klienta);
}




void symulacja::test (int l_cykli)
{
    try {wczytaj_klientow();}
    catch (string w)
    {
        cout << w << endl;
    }
    ofstream log;
    log.open("filia_akcje.txt");
    if (!log.good())
    {
        cout << "Problem z plikiem zapisu.";
        return;
    }
    for (int czas=0; czas<l_cykli; czas++)
    {
        cout << "--------------------" << endl;
        log <<  "--------------------" << endl;
        cout << "CZAS: " << czas <<endl;
        log << "CZAS: " << czas <<endl;
        bool czy_przyjdzie=true;
        if (czy_przyjdzie)
        {
            klient *p_nowy;
            for (int j=0; j<2; j++)
            {
                try
                {
                    p_nowy=&losuj_klienta(czas);
                    cout << "PRZYCHODZI NOWY KLIENT: " << *p_nowy << endl;
                    log << "PRZYCHODZI NOWY KLIENT: " << *p_nowy << endl;
                    int kolejka=losuj(0, 2);
                    //int kolejka=2;
                    if (kolejka==0)
                    {
                        kolejka_bankomat.push(p_nowy);
                        p_nowy->w_kolejce=true;
                        cout << "Staje w kolejce do bankomatu" << endl;
                        log << "Staje w kolejce do bankomatu" << endl;
                    }
                    else if (kolejka==1)
                    {
                        kolejka_wplatomat.push(p_nowy);
                        p_nowy->w_kolejce=true;
                        cout << "Staje w kolejce do wplatomatu" << endl;
                        log << "Staje w kolejce do wplatomatu" << endl;
                    }
                    else
                    {
                        kolejka_obsluga_klienta.push(p_nowy);
                        p_nowy->w_kolejce=true;
                        cout << "Staje w kolejce do obslugi klienta" << endl;
                        log << "Staje w kolejce do obslugi klienta" << endl;
                    }

                }
                catch(string w)
                {
                    cout << "Wylosowany " << w <<endl;
                    log << "Wylosowany " << w <<endl;
                }
            }
        }
        przesun_kolejke_bankomat(czas, log);
        przesun_kolejke_wplatomat(czas, log);
        przesun_kolejke_obsluga_klienta(czas, log);
        cout << endl << "DLUGOSCI KOLEJEK DO: "<< endl;
        cout << "Bankomatu: "<< kolejka_bankomat.size() << endl;
        cout << "Wplatomatu: "<< kolejka_wplatomat.size() << endl;
        cout << "Obslugi klienta: "<< kolejka_obsluga_klienta.size() << endl;
        log << endl << "DLUGOSCI KOLEJEK DO: "<< endl;
        log << "Bankomatu: "<< kolejka_bankomat.size() << endl;
        log << "Wplatomatu: "<< kolejka_wplatomat.size() << endl;
        log << "Obslugi klienta: "<< kolejka_obsluga_klienta.size() << endl;

        sleep(3);
    }
    log.close();
    return;
}
