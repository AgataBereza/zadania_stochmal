#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

/*

Zadania 1.17 - 1.20 pomijamy, gdyby kto� chcia� si� pobawi� zmian� koloru wy�wietlanego tekstu s�u�y do tego biblioteka <conio.h>
Przyk�ad: https://www.programmingsimplified.com/c/conio.h/textcolor
Dokumentacja: https://code-reference.com/c/conio.h/textcolor

*/

/*
	1.16 	Napisz program, kt�ry wczytuje tekst z klawiatury do zmiennej typu String (typ danych z turbo pascala - odpowiednik w ansi c to tablica znak�w char[]),
			przy czym wszystkie litery zast�puje ich wielkimi odpowiednikami.
			
	W celu odczytania typu �a�cuchowego (z angielskiego String = �a�cuch) a po Polsku - po prostu napisu u�ywamy %s kt�ry mo�emy nast�pnie przypisa� do char[]
	
	#include <ctype.h> - biblioteka ta dostarcza nam narz�dzi s�u��cych m.in. do operacji na tek�cie, znajdziemy tam potrzebn� nam funkcj� "toupper" zmieniaj�c� litery na wielkie
	int toupper(int c); - funkcja toupper przyjmuje jako argument kod ASCII danego znaku i zwraca kod ASCII znaku powi�kszonego - typ danych integer
	
*/
void zad_1_16() {
	int i = 0, maksymalnaDlugoscNapisu = 2000;	// w C deklaruj�c tablic� musimy poda� jej rozmiar, dlatego te� przyjmujemy, �e tekst b�dzie mia� maksymalnie 2000 znak�w
	char twojNapis[maksymalnaDlugoscNapisu];	// tworzymy tablic� znak�w, w kt�r� wpakujemy nasz odczytany napis zadaj�c jej wy�ej zdefiniowany rozmiar
	printf("Zapodaj jakim� tekstem kr�tszym od %d znakow i wci�nij enter.\n", maksymalnaDlugoscNapisu);	
	scanf("%s", &twojNapis);					// Przypisujemy podany przez nas napis do tabicy o nazwie twojNapis
	char znakKoncaNapisu = '\0';				// Nie wiemy jak� d�ugo�� ma nasz napis i ile obrot�w ma p�tla, ale wiemy, �e ka�dy napis ko�czy si� tym znakiem
	while(twojNapis[i] != znakKoncaNapisu){		// wi�c pobieramy kolejne literki do momentu a� nie natkniemy si� na znak ko�ca napisu
		printf("%c", toupper(twojNapis[i]));	// drukujemy literk� po jej powi�kszeniu przy u�yciu funkcji toupper
		i++;									// zwi�kszamy licznik o 1 aby pobra� kolejn� literk�
	}
}


/*
	1.15 	Zmodyfikuj program 1.14, tak aby mo�na by�o wprowadza� r�wnie� liczby:
	c)		z cz�ci� po kropce dziesi�tnej i wyk�adnikiem (litera E, znak i 2-cyfrowy wyk�adnik)
	
	W ansi C mamy wbudowany format do wy�wietlania licz w postaci wyk�adniczej, aby zmienn� typu double lub float wy�wietli� w tej�e notacji,
	wystarczy u�y� %e zamiast %f / %lf w funkcji printf()
	
	Przyk�ad:
	double liczba = 2.2;
	printf("%e",liczba); wydrukuje j� w notacji wyk�adniczej
			
*/
void zad_1_15_c() {
	int i, iloscPodanychLiczb = 0, maksymalnaIloscLiczb = 100;	//iloscPodanychLiczb - licznik, ktory posluzy do sprawdzenia, czy mamy jeszcze miejsce w tablicy, by dodac wiecej liczb
	double liczba;
	double liczby[maksymalnaIloscLiczb];						// tablica int, do kt�rej b�dziemy zapisywa� odczytane liczby - mo�e pomie�ci� 100 liczb
	char czyJuzKoniec = 'n';								// flaga m�wi�ca o tym, czy chcemy ju� zako�czy� podawanie kolejnych liczb
	while(czyJuzKoniec != 't'){								// p�tla, kt�ra b�dzie wykonywana dopuki flaga "czyJuzKoniec" b�dzie ustawiona na 'n' (nie), kiedy zmieni si� na 't' przerwie dzia�anie
		if(iloscPodanychLiczb == maksymalnaIloscLiczb-1){	// sprawdzenie czy ju� zape�nili�my ca�� tablic�
			printf("Tablica zosta�a zape�niona. Nie mo�na doda� ju� wi�cej liczb.\n");
			break;
		}
		printf("Podaj liczb�: \n");
		scanf("%lf", &liczba);
		liczby[iloscPodanychLiczb] = liczba;			//	zapis podanej liczby w tablicy
		iloscPodanychLiczb++;							// licznik dodanych do tablicy liczb
		
		printf("Czy chcesz ju� sko�czy� wpisywanie? Wci�nij 't' dla tak. Dowolny klawisz by kontynuowa�.\n");	// pytamy u�ytkownika czy chcia�by ju� zako�czy� podawanie cyfr
		scanf(" %c", &czyJuzKoniec);							// przypisanie podanej przez u�ytkownika odpowiedzi czy ju� ko�czymy do zmiennej
	}
	printf("Ilosc podanych liczb: %d.\n", iloscPodanychLiczb);
	for(i = 0; i < iloscPodanychLiczb; i++){					//wydrukowanie wszystkich liczb dodanych do tablicy
		printf("%e ", liczby[i]);
	}
}

/*
	1.15 	Zmodyfikuj program 1.14, tak aby mo�na by�o wprowadza� r�wnie� liczby:
	b)		zmiennoprzecinkowe (z cz�ci� po kropce dziesi�tnej)
			
*/
void zad_1_15_b() {
	int i, iloscPodanychLiczb = 0, maksymalnaIloscLiczb = 100;	//iloscPodanychLiczb - licznik, ktory posluzy do sprawdzenia, czy mamy jeszcze miejsce w tablicy, by dodac wiecej liczb
	double liczba;
	double liczby[maksymalnaIloscLiczb];						// tablica int, do kt�rej b�dziemy zapisywa� odczytane liczby - mo�e pomie�ci� 100 liczb
	char czyJuzKoniec = 'n';								// flaga m�wi�ca o tym, czy chcemy ju� zako�czy� podawanie kolejnych liczb
	while(czyJuzKoniec != 't'){								// p�tla, kt�ra b�dzie wykonywana dopuki flaga "czyJuzKoniec" b�dzie ustawiona na 'n' (nie), kiedy zmieni si� na 't' przerwie dzia�anie
		if(iloscPodanychLiczb == maksymalnaIloscLiczb-1){	// sprawdzenie czy ju� zape�nili�my ca�� tablic�
			printf("Tablica zosta�a zape�niona. Nie mo�na doda� ju� wi�cej liczb.\n");
			break;
		}
		printf("Podaj liczb�: \n");
		scanf("%lf", &liczba);
		liczby[iloscPodanychLiczb] = liczba;			//	zapis podanej liczby w tablicy
		iloscPodanychLiczb++;							// licznik dodanych do tablicy liczb
		
		printf("Czy chcesz ju� sko�czy� wpisywanie? Wci�nij 't' dla tak. Dowolny klawisz by kontynuowa�.\n");	// pytamy u�ytkownika czy chcia�by ju� zako�czy� podawanie cyfr
		scanf(" %c", &czyJuzKoniec);							// przypisanie podanej przez u�ytkownika odpowiedzi czy ju� ko�czymy do zmiennej
	}
	printf("Ilosc podanych liczb: %d.\n", iloscPodanychLiczb);
	for(i = 0; i < iloscPodanychLiczb; i++){					//wydrukowanie wszystkich liczb dodanych do tablicy
		printf("%lf ", liczby[i]);
	}
}

/*
	1.15 	Zmodyfikuj program 1.14, tak aby mo�na by�o wprowadza� r�wnie� liczby:
	a)		ujemne
			
*/
void zad_1_15_a() {
	int i, liczba, iloscPodanychLiczb = 0, maksymalnaIloscLiczb = 100;	//iloscPodanychLiczb - licznik, ktory posluzy do sprawdzenia, czy mamy jeszcze miejsce w tablicy, by dodac wiecej liczb
	char czyJuzKoniec = 'n';								// flaga m�wi�ca o tym, czy chcemy ju� zako�czy� podawanie kolejnych liczb
	int liczby[maksymalnaIloscLiczb];						// tablica int, do kt�rej b�dziemy zapisywa� odczytane liczby - mo�e pomie�ci� 100 liczb
	while(czyJuzKoniec != 't'){								// p�tla, kt�ra b�dzie wykonywana dopuki flaga "czyJuzKoniec" b�dzie ustawiona na 'n' (nie), kiedy zmieni si� na 't' przerwie dzia�anie
		if(iloscPodanychLiczb == maksymalnaIloscLiczb-1){	// sprawdzenie czy ju� zape�nili�my ca�� tablic�
			printf("Tablica zosta�a zape�niona. Nie mo�na doda� ju� wi�cej liczb.\n");
			break;
		}
		printf("Podaj liczb�: \n");
		scanf("%d", &liczba);
		liczby[iloscPodanychLiczb] = liczba;			//	zapis podanej liczby w tablicy
		iloscPodanychLiczb++;							// licznik dodanych do tablicy liczb
		
		printf("Czy chcesz ju� sko�czy� wpisywanie? Wci�nij 't' dla tak. Dowolny klawisz by kontynuowa�.\n");	// pytamy u�ytkownika czy chcia�by ju� zako�czy� podawanie cyfr
		scanf(" %c", &czyJuzKoniec);							// przypisanie podanej przez u�ytkownika odpowiedzi czy ju� ko�czymy do zmiennej
	}
	printf("Ilosc podanych liczb: %d.\n", iloscPodanychLiczb);
	for(i = 0; i < iloscPodanychLiczb; i++){					//wydrukowanie wszystkich liczb dodanych do tablicy
		printf("%d ", liczby[i]);
	}
}

/*
	1.14 	Napisz program, kt�ry pozwala wprowadzi� z klawiatury jedynie cyfry (nie reaguje na inne klawisze) i ci�g tych cyfr (jako liczb�)
			przypisuje zmiennej typu WORD (typ danych w�a�ciwy dla TurboPascala, odpowiednikiem w ansi c jest tablica znak�w char[])
			
			Nie wiem jak rozwi�za� to zadanie w C bez u�ycia dynamicznej alokacji pami�ci, wi�c zak��dam, �e u�ytkownik nie poda wi�cej ni� 100 cyfr
			
*/
void zad_1_14() {
	int i, cyfra, iloscPodanychCyfr = 0, maksymalnaIloscCyfr = 100, min = 0, max = 9;	//iloscPodanychCyfr - licznik, ktory posluzy do sprawdzenia, czy mamy jeszcze miejsce w tablicy, by dodac wiecej cyfr
	char czyJuzKoniec = 'n';								// flaga m�wi�ca o tym, czy chcemy ju� zako�czy� podawanie kolejnych cyfr
	int cyfry[maksymalnaIloscCyfr];							// tablica int, do kt�rej b�dziemy zapisywa� odczytane cyfry - mo�e pomie�ci� 100 cyfr
	while(czyJuzKoniec != 't'){								// p�tla, kt�ra b�dzie wykonywana dopuki flaga "czyJuzKoniec" b�dzie ustawiona na 'n' (nie), kiedy zmieni si� na 't' przerwie dzia�anie
		if(iloscPodanychCyfr == maksymalnaIloscCyfr-1){		// sprawdzenie czy ju� zape�nili�my ca�� tablic�
			printf("Tablica zosta�a zape�niona. Nie mo�na doda� ju� wi�cej cyfr.\n");
			break;
		}
		printf("Podaj cyfr� od 0 do 9: \n");
		scanf("%d", &cyfra);
		if(cyfra >= 0 && cyfra <= 9){						// sprawdzenie, czy pobrana cyfra znajduje si� w przedziale od 0 do 9
			cyfry[iloscPodanychCyfr] = cyfra;				// jesli tak zapisujemy cyfr�  w tablicy
			iloscPodanychCyfr++;							// licznik dodanych do tablicy cyfr
		}
		printf("Czy chcesz ju� sko�czy� wpisywanie? Wci�nij 't' dla tak. Dowolny klawisz by kontynuowa�.\n");	// pytamy u�ytkownika czy chcia�by ju� zako�czy� podawanie cyfr
		scanf(" %c", &czyJuzKoniec);											// przypisanie podanej przez u�ytkownika odpowiedzi czy ju� ko�czymy do zmiennej
	}
	printf("Ilosc podanych cyfr: %d.\n", iloscPodanychCyfr);
	for(i = 0; i < iloscPodanychCyfr; i++){					//wydrukowanie wszystkich cyfr dodanych do tablicy
		printf("%d ", cyfry[i]);
	}
}

/*
	1.13	Wczytaj znak z klawiatury
	c)		wy�wietl kod ascii odczytanego znaku
				
*/
void zad_1_13_c() {
    int odczytanyZnak;			// deklaracja zmiennej typu int, do kt�rej przypiszemy kod ASCII odczytany z klawiatury za pomoc� funkcji getchar()
    printf("Wci�nij dowolny klawisz z klawiatury i potwierd� wciskaj�c enter.\n");
    odczytanyZnak = getchar();	// przypisanie kodu wci�ni�tego klawisza do zmiennej odczytanyZnak
    printf("Przeczytano znak o numerze %d i jest to %c.\n", odczytanyZnak, (char)odczytanyZnak);
}

/*
	1.13	Wczytaj znak z klawiatury
	b)		wy�wietl znak nast�pny po przeczytanym
				
*/
void zad_1_13_b() {
    int odczytanyZnak;			// deklaracja zmiennej typu int, do kt�rej przypiszemy kod ASCII odczytany z klawiatury za pomoc� funkcji getchar()
    printf("Wci�nij dowolny klawisz z klawiatury i potwierd� wciskaj�c enter.\n");
    odczytanyZnak = getchar();	// przypisanie kodu wci�ni�tego klawisza do zmiennej odczytanyZnak
    printf("Przeczytano znak o numerze %d i jest to %c, kolejny to: %c.", odczytanyZnak, (char)odczytanyZnak, (char)(odczytanyZnak+1)); // odczytanyZnak + 1 wy�wietli kolejny znak w tabeli ASCII
}


/*
	1.13	Wczytaj znak z klawiatury
	a)		okre�l czy by�a to litera
	
	W kodzie ASCII 65-90 litery wielkie, 97-122 litery ma�e
	int getchar(); - funkcja z biblioteki stdio.h, czyta jeden znak wci�ni�ty przez u�ytkownika i zwraca go w postaci odpowiadaj�cego kodu ASCII, zwracany typ liczbowy int
			
*/
void zad_1_13_a() {
    int odczytanyZnak;			// deklaracja zmiennej typu int, do kt�rej przypiszemy kod ASCII odczytany z klawiatury za pomoc� funkcji getchar()
    printf("Wci�nij dowolny klawisz z klawiatury i potwierd� wciskaj�c enter.\n");
    odczytanyZnak = getchar();	// przypisanie kodu wci�ni�tego klawisza do zmiennej odczytanyZnak
    if((odczytanyZnak >= 65 && odczytanyZnak <= 90) || (odczytanyZnak >= 97 && odczytanyZnak <= 122)){		// Sprawdzamy czy odczytany znak znajduje si� w przedzia�ach kod�w ASCII odpowiednich dla liter
    	printf("Przeczytano znak o numerze %d i jest on liter� %c.", odczytanyZnak, (char)odczytanyZnak);	// zapis "(char)odczytanyZnak" oznacza, �e zmienn� typu int konwertujemy do typu char
	} else {
		printf("Dany znak nie jest liter�.\n");
	}
}

/*
	1.12 	Wy�wietl na ekranie kolejne znaki o kodach ASCII z zakresu 32-255. Obok podaj warto�ci kod�w.
			
*/
void zad_1_12() {
	int i, min = 32, max = 255; 	// i licznik petli, min - pocz�tek przedzia�u, max - koniec przedzia�u, min = 32, max = 255
	char biezacyZnak;
	for(i = min; i <= max; i++){	// p�tl� rozpoczynami od i = warto�ci minimalnej i iterujemy a� do osi�gni�cia wawrto�ci maksymalnej zwi�kszaj�c licznik o 1
		biezacyZnak = i;			// w celu zamiany liczby int reprezentuj�cej znak ASCII przypisujemy j� do zmiennej typu char
		printf("Numer znaku %d, znak: %c \n", i, biezacyZnak);
	}
}

/*
	1.11 	Niech program wy�wietli napis "tak" lub "nie" w zale�no�ci od tego, czy naci�ni�to klawisz <T> czy <N> (wielk� lub ma�� liter�).
			Na pozosta�e klawisze nie powinien reagowa�.
			
			Polecenie tego zadania jest nieco niejednoznaczne, bo pisz� o tym, by reagowa� na przyci�ni�cie klawiszy, a nie ka�� wczyta� zmiennej,
			samo wczytywanie klawiszy odbywa si� w oparciu o zmienne systemowe zale�ne od systemu na jakim pracujemy a czysty j�zyk ansi c nie umo�liwia takich interakcji
*/
void zad_1_11() {
	char wcisnietyKlawisz;
	printf("Wci�nij klawisz 't' lub 'T' dla tak albo 'n' lub 'N' dla nie.\nOperacj� zako�cz wci�ni�ciem klawisza enter.\n");	
	scanf("%c", &wcisnietyKlawisz);		// zapisanie wcisnietej literki do zmiennej wcisnietyKlawisz
	if(wcisnietyKlawisz == 't' || wcisnietyKlawisz == 'T'){
		printf("tak\n");
	} else if(wcisnietyKlawisz == 'n' || wcisnietyKlawisz == 'N'){
		printf("nie\n");
	} else {
		printf("Niepoprawny input, fak ju :-P\n");
	}	
}

/*
	1.10 	Wczytaj trzy liczby rzeczywiste i wy�wietl:
	b)		najmniejsz� sposr�d liczb
	
	Zadanie to zosta�o wykonane w spos�b alternatywny do 1.10 a) w celu zobrazowania tego samego problemu, ale przy u�yciu tablic.
*/
void zad_1_10_b() {
	int i, iloscLiczb = 3;				// i - licznik p�tli, iloscLiczb - ilosc liczb w tablicy
	double liczby[iloscLiczb];			// deklaracja tablicy o nazwie "liczby" o rozmiarze 3 = iloscLiczb i zawieraj�cej typ danych double
	double aktualna, najmniejsza;		// aktualna - zmienna pomocnicza, do kt�rej b�dziemy przypisywa� zmienne podane przez u�ytkownika przed wpisaniem ich do tablicy
	printf("Podaj trzy liczby rzeczywiste z zakresu 2.3E-308 to 1.7E+308 w celu wykonania na nich oblicze�:\nUWAGA! Aby format by� poprawny do oddzielenia cz�ci ca�kowitej od dziesi�tnej u�yj znaku kropki, a nie przecinka.\n");
	for(i=0; i< iloscLiczb; i++){		// wype�nianie tablicy liczbami
		scanf("%lf", &aktualna);		// pobieranie liczby od u�ytkownika i przypisywanie jej do zmiennej "aktualna"
		liczby[i] = aktualna;			// zapisywanie zmiennej "aktualna" pod i-tym indeksem w tablicy
	}
	najmniejsza = liczby[0];			//przypisujemy pierwsz� liczb� z tablicy jako najmniejsz�, aby m�c rozpocz�� por�wnywanie
	for(i=1; i < iloscLiczb-1; i++){	// skoro pierwsz� liczb� z tablicy ju� przypisali�my jako najmniejsz�, to nie musimy jej por�wnywa� samej ze sob�, wi�c zaczynamy iteracj� od 1 (i = 1) a nie od 0
		aktualna = liczby[i];			// przypisujemy obecnie odczytywany element z tablicy do zmiennej aktualna (cho� mogliby�my od razu por�wnywa� liczby[i] < najmniejsza, nie ma to wiekszego znaczenia)
		if(aktualna < najmniejsza){
			najmniejsza = aktualna;
		}	
	}
	printf("Podane liczby to: a=%lf, b=%lf, c=%lf.\nNajmniejsza wynosi: %lf.\n",liczby[0],liczby[1],liczby[2], najmniejsza);	
}

/*
	1.10 	Wczytaj trzy liczby rzeczywiste i wy�wietl:
	a)		najwi�ksz�
	
	Zadanie to jako ze ma tylko 3 zmienne zostalo wykonane przy uzyciu 3 zmiennych, przy wiekszej ilosci wskazane byloby u�y� tablicy
	i analogicznie zmiennej pomocniczej o przykladowej nazwie "najwieksza", w celu wybrania najwiekszej trzeba by przeiterowa� w p�tli po tablicy
*/
void zad_1_10_a() {
	double a, b, c, najwieksza;
	printf("Podaj trzy liczby rzeczywiste z zakresu 2.3E-308 to 1.7E+308 w celu wykonania na nich oblicze�:\nUWAGA! Aby format by� poprawny do oddzielenia cz�ci ca�kowitej od dziesi�tnej u�yj znaku kropki, a nie przecinka.\n");
	scanf("%lf", &a);
	scanf("%lf", &b);
	scanf("%lf", &c);
	najwieksza = a;		// Na poczatku zakladamy ze najwieksza = a, aby rozpoczac porownywanie
	if(b > najwieksza){
		najwieksza = b;	// je�li b > najwieksza, to ono staje sie najwieksze
	} 
	if(c > najwieksza){
		najwieksza = c;	// je�li c >  najwieksza, to ono staje sie najwieksze
	}
	printf("Podane liczby to: a=%lf, b=%lf, c=%lf.\nNajwi�ksza wynosi: %lf.\n",a,b,c, najwieksza);	
}

/*
	1.9 	Wczytaj dwie liczby rzeczywiste i wy�wietl:
	b)		mniejsz� z nich
*/
void zad_1_9_b() {
	double a, b, mniejsza;
	printf("Podaj dwie liczby rzeczywiste z zakresu 2.3E-308 to 1.7E+308 w celu wykonania na nich oblicze�:\nUWAGA! Aby format by� poprawny do oddzielenia cz�ci ca�kowitej od dziesi�tnej u�yj znaku kropki, a nie przecinka.\n");
	scanf("%lf", &a);
	scanf("%lf", &b);
	if(a < b){
		mniejsza = a;
		printf("Podane liczby to: a=%lf i b=%lf.\n Mniejsza jest a=%lf.\n",a,b,a);
	} else if(b < a) {
		mniejsza = b;
		printf("Podane liczby to: a=%lf i b=%lf.\n Mniejsza jest b=%lf.\n",a,b,b);
	} else {
		printf("Podane liczby to: a=%lf i b=%lf.\n S� sobie r�wne.\n",a,b);
	}	
}

/*
	1.9 	Wczytaj dwie liczby rzeczywiste i wy�wietl:
	a)		wi�ksz� z nich
*/
void zad_1_9_a() {
	double a, b, wieksza;
	printf("Podaj dwie liczby rzeczywiste z zakresu 2.3E-308 to 1.7E+308 w celu wykonania na nich oblicze�:\nUWAGA! Aby format by� poprawny do oddzielenia cz�ci ca�kowitej od dziesi�tnej u�yj znaku kropki, a nie przecinka.\n");
	scanf("%lf", &a);
	scanf("%lf", &b);
	if(a > b){
		wieksza = a;
		printf("Podane liczby to: a=%lf i b=%lf.\n Wi�ksza jest a=%lf.\n",a,b,wieksza);
	} else if(b > a) {
		wieksza = b;
		printf("Podane liczby to: a=%lf i b=%lf.\n Wi�ksza jest b=%lf.\n",a,b,wieksza);
	} else {
		printf("Podane liczby to: a=%lf i b=%lf.\n S� sobie r�wne.\n",a,b);
	}	
}

/*
	1.8 	Zmodyfikuj program 1.7 tak aby najpierw wczytywa� ile b�dzie liczb, a nast�pnie wykonywa� podan� operacj� dla tej ilo�ci wprowadzonych liczb
*/
void zad_1_8() {
	int i, liczba, iloscLiczb;			// i - licznik p�tli do wprowadzenia danych, liczba - aktualnie wczytywana liczba
	printf("Podaj %d ilosc liczb do wprowadzenia:\n");	// komunikat m�wi�cy o tym, jaki rozmiar b�dzie mia�a nasza tablica
	scanf("%d", &iloscLiczb);			// przypisanie zczytanej liczby to zmiennej "iloscLiczb"
	int tablica[iloscLiczb];			// deklaracja tablicy o nazwie "tablica" o rozmiarze = iloscLiczb = 10 i zawieraj�cej liczby typu int
	for(i = 0; i < iloscLiczb; i++){	// p�tla s�u��ca wype�nieniu tablicy liczbami podanymi przez u�ytkownika
		printf("Podaj %d liczbe calkowita z %d:\n", i+1, iloscLiczb);	// komunikat m�wi�cy o tym, kt�r� liczb� z ilu aktualnie podajemy
		scanf("%d", &liczba);			// przypisanie zczytanej liczby to zmiennej "liczba"
		tablica[i] = liczba;			// zapisanie zaktualnej zmiennej "liczba" pod i-tym indeksem w tablicy
	}
	
	for(i = 0; i<iloscLiczb; i++){
		if(tablica[i] < 0){
			printf("%d ujemna\n", tablica[i]);
		} else if (tablica[i] > 0){
			printf("%d dodatnia\n", tablica[i]);
		} else {
			printf("%d zero\n", tablica[i]);
		}
	}
}

/*
	1.7 	Napisz program, kt�ry ��da wprowadzenia 10 liczb, a nast�pnie je wczytuje i wy�wietla na ekranie obok ka�dej liczby odpowiednie s�owo:
			"dodatnia", "ujemna", "zero".
*/
void zad_1_7() {
	int i, liczba, iloscLiczb = 10;		// i - licznik p�tli do wprowadzenia danych, liczba - aktualnie wczytywana liczba, iloscLiczb - rozmiar tablicy
	int tablica[iloscLiczb];			// deklaracja tablicy o nazwie "tablica" o rozmiarze = iloscLiczb = 10 i zawieraj�cej liczby typu int
	for(i = 0; i < iloscLiczb; i++){	// p�tla s�u��ca wype�nieniu tablicy liczbami podanymi przez u�ytkownika
		printf("Podaj %d liczbe calkowita z %d:\n", i+1, iloscLiczb);	// komunikat m�wi�cy o tym, kt�r� liczb� z ilu aktualnie podajemy
		scanf("%d", &liczba);			// przypisanie zczytanej liczby to zmiennej "liczba"
		tablica[i] = liczba;			// zapisanie zaktualnej zmiennej "liczba" pod i-tym indeksem w tablicy
	}
	
	for(i = 0; i<iloscLiczb; i++){
		if(tablica[i] < 0){
			printf("%d ujemna\n", tablica[i]);
		} else if (tablica[i] > 0){
			printf("%d dodatnia\n", tablica[i]);
		} else {
			printf("%d zero\n", tablica[i]);
		}
	}
}

/*
	1.6 	Wczytaj dwie liczby ca�kowite (np. typu int) i wy�wietl na ekranie wszystkie liczby znajduj�ce si� miedzy nimi.
*/
void zad_1_6() {
	int i, n, a, b, mniejszaLiczba; // i - licznik p�tli, n - ilo�� liczb pomi�dzy a i b, a i b - wczytane liczby
	printf("Podaj dwie liczby ca�kowite z zakresu -2,147,483,648 do 2,147,483,647 w celu wy�wietlenia na ekran wszystkich liczb znajduj�cych si� mi�dzy nimi.\n");
	scanf("%d", &a);
	scanf("%d", &b);
	n = abs(a-b) - 1 ; 	// poniewa� liczba a mo�e by� mniejsza ni� b interesuje nas warto�� bezwzgl�dna z r�nicy mi�dzy tymi liczbami,
						// pomniejszamy wynik o 1 poniewa� przyk�adowo je�li a = 5, a b = 3, to 5 - 3 = 2, a mi�dzy 5 a 3 mamy tylko "4"
	if(a < b){			// sprawdzamy, kt�ra z liczb jest mniejsza, by wiedzie�, od kt�rej zacz�� wypisywanie na ekran
		mniejszaLiczba = a;
	} else {
		mniejszaLiczba = b;
	}
	for(i = 0; i < n; i++){
		mniejszaLiczba = mniejszaLiczba + 1; 	// z ka�dym obrotem p�tli zwi�kszamy liczb� o 1
		printf("%d ", mniejszaLiczba);			// wypisujemy na ekran bie��c� liczb�
	}
}

/*
	1.5 	Wczytaj dwie liczby typu REAL (typ turbo pascala, zamieniamy na double lub float) i oblicz:
	c)		sum� ich odwrotno�ci, je�li s� one obie r�ne od zera, lub wprowad� komunikat,
			�e operacja nie jest mo�liwa do wykonania, je�li przynajmniej jedna z nich jest r�wna zeru.
*/
void zad_1_5_c() {
	double a, b;
	printf("Podaj dwie liczby rzeczywiste z zakresu 2.3E-308 to 1.7E+308 w celu wykonania na nich oblicze�:\nUWAGA! Aby format by� poprawny do oddzielenia cz�ci ca�kowitej od dziesi�tnej u�yj znaku kropki, a nie przecinka.\n");
	scanf("%lf", &a);
	scanf("%lf", &b);
	if(a == 0.0 || b==0){
		printf("Operacja nie jest mo�liwa do wykonania, co najmniej jedna z podanych liczb jest r�wna zero.");
	} else {
		printf("Podane liczby to: a=%lf i b=%lf.\nWynik dzia�ania 1/a + 1/b=%lf.\n",a,b,((1/a)+(1/b)));
	}
}

/*
	1.5 	Wczytaj dwie liczby typu REAL (typ turbo pascala, zamieniamy na double lub float) i oblicz:
	b)		ich iloraz. Je�i dzielnik b�dzie zerem, wprowad� t� informacj� na ekran.
*/
void zad_1_5_b() {
	double a, b;
	printf("Podaj dwie liczby rzeczywiste z zakresu 2.3E-308 to 1.7E+308 w celu wykonania na nich oblicze�:\nUWAGA! Aby format by� poprawny do oddzielenia cz�ci ca�kowitej od dziesi�tnej u�yj znaku kropki, a nie przecinka.\n");
	scanf("%lf", &a);
	scanf("%lf", &b);
	if(b==0 || b==0.0){
		printf("Liczba b, kt�ra jest dzielnikiem jest r�wna 0. Dzia�anie nie zgodne z zasadami matematyki.");
	} else {
		printf("Podane liczby to: a=%lf i b=%lf.\nWynik dzia�ania a/b=%lf.\n",a,b,a/b);
	}
}

/*
	1.5 	Wczytaj dwie liczby typu REAL (typ turbo pascala, zamieniamy na double lub float) i oblicz:
	a)		ich sum�, r�nic�, iloczyn (mno�enie ;-))
*/
void zad_1_5_a() {
	double a, b;
	printf("Podaj dwie liczby rzeczywiste z zakresu 2.3E-308 to 1.7E+308 w celu wykonania na nich oblicze�:\nUWAGA! Aby format by� poprawny do oddzielenia cz�ci ca�kowitej od dziesi�tnej u�yj znaku kropki, a nie przecinka.\n");
	scanf("%lf", &a);
	scanf("%lf", &b);
	printf("Podane liczby to: a=%lf i b=%lf.\nSuma: %lf, R�nica: a-b=%lf, b-a=%lf, Iloczyn: %lf.\n",a,b,a+b,a-b,b-a,a*b);
}


/*
	1.4 	Wczytaj liczb� typu REAL (liczby typu rzeczywistego, w ANSI C zmiennoprzecinkowe o dowolnym znaku czyli np. double) z klawiatury,
			a nast�pnie wydrukuj na ekranie:
	d)		odwrotno�� danej liczby, je�li jest r�na od zera
*/
void zad_1_4_d() {
	double liczba;
	printf("Podaj liczb� rzeczywist� z zakresu 2.3E-308 to 1.7E+308 w celu jej wy�wietlenia:\nUWAGA! Aby format by� poprawny do oddzielenia cz�ci ca�kowitej od dziesi�tnej u�yj znaku kropki, a nie przecinka.\n");
	scanf("%lf", &liczba);
	if(liczba == 0.0 || liczba == 0){
		printf("Liczba wynosi 0 i dla niej nie wykonujemy dzia�a�.");
	} else {
		printf("Wpisana przez u�ytkownika liczba to: %lf a jej odwrotno�� to: %lf.\n", liczba, 1/liczba);
	}
}

/*
	1.4 	Wczytaj liczb� typu REAL (liczby typu rzeczywistego, w ANSI C zmiennoprzecinkowe o dowolnym znaku czyli np. double) z klawiatury,
			a nast�pnie wydrukuj na ekranie:
	c)		liczb� 2 razy wi�ksz�
*/
void zad_1_4_c() {
	double liczba;
	printf("Podaj liczb� rzeczywist� z zakresu 2.3E-308 to 1.7E+308 w celu jej wy�wietlenia:\nUWAGA! Aby format by� poprawny do oddzielenia cz�ci ca�kowitej od dziesi�tnej u�yj znaku kropki, a nie przecinka.\n");
	scanf("%lf", &liczba);
	printf("Wpisana przez u�ytkownika liczba to: %lf a liczba 2x wi�ksza to: %lf.\n", liczba, 2*liczba);
}

/*
	1.4 	Wczytaj liczb� typu REAL (liczby typu rzeczywistego, w ANSI C zmiennoprzecinkowe o dowolnym znaku czyli np. double) z klawiatury,
			a nast�pnie wydrukuj na ekranie:
	b)		liczb� przeciwn� do danej
	
	#include <math.h> - dany import pozwoli nam na u�ycie funkcji "fabs", kt�ra zwraca warto�� bezwzgl�dn� z liczby double (abs dla typu int, fabsf dla typu float)
	double fabs(double);	jest to definicja u�ycia funkcji "fabs", zwracanym typem danych jest double i przyjmuje ona jeden argument r�wnie� typu double	
*/
void zad_1_4_b() {
	double liczba, liczbaPrzeciwna;
	printf("Podaj liczb� rzeczywist� z zakresu 2.3E-308 to 1.7E+308 w celu jej wy�wietlenia:\nUWAGA! Aby format by� poprawny do oddzielenia cz�ci ca�kowitej od dziesi�tnej u�yj znaku kropki, a nie przecinka.\n");
	scanf("%lf", &liczba);
	if(liczba < 0){						// je�eli odczytana liczba jest ujemna
		liczbaPrzeciwna = fabs(liczba); //	obliczamy warto�� bezwzgl�dn� z liczby
	} else {
		liczbaPrzeciwna = -liczba;		// w przeciwnym wypadku zapisujemy dan� liczb� ze znakiem ujemnym
	}
	printf("Wpisana przez u�ytkownika liczba to: %lf a warto�� do niej przeciwna to: %lf.\n", liczba, liczbaPrzeciwna);
}

/*
	1.4 	Wczytaj liczb� typu REAL (liczby typu rzeczywistego, w ANSI C zmiennoprzecinkowe o dowolnym znaku czyli np. double) z klawiatury,
			a nast�pnie wydrukuj na ekranie:
	a)		t� liczb�
		
*/
void zad_1_4_a() {
	double liczba;
	printf("Podaj liczb� rzeczywist� z zakresu 2.3E-308 to 1.7E+308 w celu jej wy�wietlenia:\nUWAGA! Aby format by� poprawny do oddzielenia cz�ci ca�kowitej od dziesi�tnej u�yj znaku kropki, a nie przecinka.\n");
	scanf("%lf", &liczba);
	printf("Wpisana przez u�ytkownika liczba to: %lf.\n", liczba);
}


/*
	1.3 	Wy�wietl na ekranie 32 gwiazdki "*" u�o�one w szachownic� 8x8 p�l, na przemian ze znakiem spacji
	
	char - liczba z zakresu od -128 to 127  lub 0 to 255 reprezentuj�ca liter� w kodzie ASCII, aby odczyta� u�ywamy symbolu %c
*/
void zad_1_3() {
	int i, j, n = 8;					// n - jest to liczba kolumn oraz liczba wierszy w szachownicy, i - licznik petli wierszy, j - licznik petli kolumn
	char nastepnyZnak;					// zmienna pomocnicza, do kt�rej b�dziemy przypisywa� naprzemiennie '*' i spacje w zale�no�ci od po�o�enia
	for(i = 0; i < n; i++){				// p�tle zewn�trzna - iterowanie po wierszach
		if(i % 2 == 0){					// sprawdzenie, czy numer wiersza jest parzysty
			nastepnyZnak = '*';			// je�li numer wiersza jest parzysty, to zaczynamy od '*'
		} else {
			nastepnyZnak = ' ';			// je�li numer wiersza jest nieparzysty, to zaczynamy od spacji
		}
		for(j = 0; j < n; j++){			// p�tle wewn�trzna - iterowanie po kolumnach
			printf("%c", nastepnyZnak);	// drukujemy aktualnie ustawiony znak
			if(nastepnyZnak == '*'){	// je�eli aktualnie ustawiony znak to '*'
				nastepnyZnak = ' ';		// to kolejny znak ustawiamy na spacj�
			} else {
				nastepnyZnak = '*';		// w przeciwnym wypadku kolejny znak ustawiamy na gwiazdk�
			}	
		}
		printf("\n");					// po zako�czeniu iteracji po kolumnach "drukujemy" znak nowej linii,
										//w celu unikni�cia wydrukowania wszystkiego ci�giem w jednej linii
	}	
}


/*
	1.2 	Wy�wietl na ekranie:
	c) 		10 kolejnych liczb naturalnych i obok ich sze�ciany
	
	#include <math.h> - dany import pozwoli nam na u�ycie funkcji "pow", kt�ra podnosi liczb� do dowolnej pot�gi
	double pow( double podstawa, double potega ); - jest to definicja u�ycia funkcji "pow", zwracanym typem danych jest double
													i przyjmuje ona dwa argumenty "podstawa" i "pot�ga" r�wnie� typu double.
	double - liczba zmiennoprzecinkowa z zakresu 2.3E-308 to 1.7E+308, aby odczyta� u�ywamy symbolu %lf (jest to skr�t od large float, double = podw�jny float, dlatego du�y)
*/
void zad_1_2_c() {
	int i, iloscLiczb = 10;						// i - licznik p�tli, iloscLiczb = 10 - ilo�� liczb, kt�re chcemy wy�wietli�
	unsigned int pierwszaLiczba;				// deklaracja zmiennej, od kt�rej rozpoczniemy wy�wiatlanie liczb
	double szescianLiczby;						// deklaracja zmiennej, do kt�rej b�dziemy przypisywa� sze�cian liczby
	double potega = 3;							// pot�ga, do kt�rej b�dziemy podnosi� kolejne liczby, u�ywamy typu double, bo taki typ przyjmuje funkcja "pow"
	printf("Podaj liczb� naturaln�, od kt�rej ma zosta� rozpocz�te wy�wietlanie:\n");
	scanf("%u", &pierwszaLiczba); 				// przypisanie do zmiennej "pierwszaLiczba" warto�ci podanej przez u�ytkownika,
												// znak "&" powoduje, �e odczytan� z klawiatury zmienn� zapiszemy pod adresem wcze�niej zadeklarowanej "pierwszaLiczba"
												// %u umo�liwia nam odczytanie zmiennej typu "unsigned int"
	for(i = 0; i < iloscLiczb; i++){			// inicjalizacja p�tli for
		szescianLiczby = pow((double)(pierwszaLiczba), potega);	// zapis "(double)(pierwszaLiczba)" oznacza, ze "pierwszaLiczba" typu unsigned int zamieniamy na double
		printf("%u %u\n", pierwszaLiczba, (unsigned int)szescianLiczby);	// zapis "(unsigned int)szescianLiczby" oznacza, �e "szescianLiczby" typu double zamieniamy na unsigned int
		pierwszaLiczba = pierwszaLiczba + 1;	// tym razem w celu �atwiejszego wykonywania dzia�a� na aktualnej liczbie z kazd� p�tl� dodajemy do niej 1
	}	
}


/*
	1.2 	Wy�wietl na ekranie:
	b) 		10 kolejnych liczb naturalnych i obok ich kwadraty
	
	"\n" - jest to znak przej�cia do kolejnej lini, w danym zadaniu spowoduje, �e pary liczb b�d� wy�wietlane zawsze w nowej linii
	
*/
void zad_1_2_b() {
	int i, iloscLiczb = 10;						// i - licznik p�tli, iloscLiczb = 10 - ilo�� liczb, kt�re chcemy wy�wietli�
	unsigned int pierwszaLiczba;				// deklaracja zmiennej, od kt�rej rozpoczniemy wy�wiatlanie liczb
	printf("Podaj liczb� naturaln�, od kt�rej ma zosta� rozpocz�te wy�wietlanie:\n");
	scanf("%u", &pierwszaLiczba); 				// przypisanie do zmiennej "pierwszaLiczba" warto�ci podanej przez u�ytkownika,
												// znak "&" powoduje, �e odczytan� z klawiatury zmienn� zapiszemy pod adresem wcze�niej zadeklarowanej "pierwszaLiczba"
												// %u umo�liwia nam odczytanie zmiennej typu "unsigned int"
	for(i = 0; i < iloscLiczb; i++){			// inicjalizacja p�tli for
		printf("%u %u\n", pierwszaLiczba, pierwszaLiczba*pierwszaLiczba);	// aby zwi�kszy� czytelno�� pary liczba i jej kwadrat b�d� wy�wietlane jedna pod drug�
		pierwszaLiczba = pierwszaLiczba + 1;	// tym razem w celu �atwiejszego wykonywania dzia�a� na aktualnej liczbie z kazd� p�tl� dodajemy do niej 1
	}	
}


/*
	1.2 	Wy�wietl na ekranie:
	a) 		10 kolejnych liczb naturalnych
	
	int - liczba z zakresu -2,147,483,648 do 2,147,483,647, aby odczyta� u�ywamy symbolu %d
	unsigned int - liczba z zakresu od 0 do 0 to 4,294,967,295, aby odczyta� u�ywamy symbolu %u
*/
void zad_1_2_a() {
	int i, iloscLiczb = 10;					// i - licznik p�tli, iloscLiczb = 10 - ilo�� liczb, kt�re chcemy wy�wietli�
	unsigned int pierwszaLiczba;			// deklaracja zmiennej, od kt�rej rozpoczniemy wy�wiatlanie liczb
	printf("Podaj liczb� naturaln�, od kt�rej ma zosta� rozpocz�te wy�wietlanie:\n");
	scanf("%u", &pierwszaLiczba); 			// przypisanie do zmiennej "pierwszaLiczba" warto�ci podanej przez u�ytkownika,
											// znak "&" powoduje, �e odczytan� z klawiatury zmienn� zapiszemy pod adresem wcze�niej zadeklarowanej "pierwszaLiczba"
											// %u umo�liwia nam odczytanie zmiennej typu "unsigned int"
	for(i = 0; i < iloscLiczb; i++){		// inicjalizacja p�tli for
		printf("%u ", pierwszaLiczba + i);	// drukujemy pierwszaLiczba + aktualny licznik p�tli (i), aby bez nadpisywania zmiennej "pierwszaLiczba" wydrukowa� kolejne warto�ci
	}	
}

int main(int argc, char *argv[]) {
	//zad_1_2_a();
	//zad_1_2_b();
	//zad_1_2_c();
	//zad_1_3();
	//zad_1_4_a();
	//zad_1_4_b();
	//zad_1_4_c();
	//zad_1_4_d();
	//zad_1_5_a();
	//zad_1_5_b();
	//zad_1_5_c();
	//zad_1_6();
	//zad_1_7();
	//zad_1_8();
	//zad_1_9_a();
	//zad_1_10_a();
	//zad_1_10_b();
	//zad_1_11();
	//zad_1_12();
	//zad_1_13_a();
	//zad_1_13_b();
	//zad_1_13_c();
	//zad_1_14();
	//zad_1_15_a();
	//zad_1_15_b();
	//zad_1_15_c();
	//zad_1_16();
	return 0;
}
