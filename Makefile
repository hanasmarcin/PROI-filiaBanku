start : a.out
	./a.out

a.out: main.o bank.o wplatomat.o symulacja.o osoba.o obsluga_konta.o obsluga_kasowa.o konto.o klient_indywidualny.o klient_biznesowy.o klient.o informacja.o bankomat.o
	g++ main.o bank.o wplatomat.o symulacja.o osoba.o obsluga_konta.o obsluga_kasowa.o konto.o klient_indywidualny.o klient_biznesowy.o klient.o informacja.o bankomat.o

main.o: main.cpp symulacja.h
	g++ -c -Wall main.cpp

bank.o: bank.cpp bank.h
	g++ -c -Wall bank.cpp

wplatomat.o: wplatomat.cpp wplatomat.h
	g++ -c -Wall wplatomat.cpp

symulacja.o: symulacja.cpp symulacja.h
	g++ -c -Wall symulacja.cpp

osoba.o: osoba.cpp osoba.h
	g++ -c -Wall osoba.cpp

obsluga_konta.o: obsluga_konta.h obsluga_konta.h
	g++ -c -Wall obsluga_konta.cpp

obsluga_kasowa.o: obsluga_kasowa.cpp obsluga_kasowa.h
	g++ -c -Wall obsluga_kasowa.cpp

konto.o: konto.cpp konto.h
	g++ -c -Wall konto.cpp

klient_indywidualny.o: klient_indywidualny.cpp klient_indywidualny.h
	g++ -c -Wall klient_indywidualny.cpp

klient_biznesowy.o: klient_biznesowy.cpp klient_biznesowy.h
	g++ -c -Wall klient_biznesowy.cpp

klient.o: klient.cpp klient.h
	g++ -c -Wall klient.cpp

informacja.o: informacja.cpp informacja.h
	g++ -c -Wall informacja.cpp

bankomat.o: bankomat.cpp bankomat.h
	g++ -c -Wall bankomat.cpp

clean:
	rm -f *.o
	rm -f *.out