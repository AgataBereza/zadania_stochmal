#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

/*

Zadania 1.17 - 1.20 pomijamy, gdyby ktoœ chcia³ siê pobawiæ zmian¹ koloru wyœwietlanego tekstu s³u¿y do tego biblioteka <conio.h>
Przyk³ad: https://www.programmingsimplified.com/c/conio.h/textcolor
Dokumentacja: https://code-reference.com/c/conio.h/textcolor

*/

/*
	1.16 	Napisz program, który wczytuje tekst z klawiatury do zmiennej typu String (typ danych z turbo pascala - odpowiednik w ansi c to tablica znaków char[]),
			przy czym wszystkie litery zastêpuje ich wielkimi odpowiednikami.
			
	W celu odczytania typu ³añcuchowego (z angielskiego String = ³añcuch) a po Polsku - po prostu napisu u¿ywamy %s który mo¿emy nastêpnie przypisaæ do char[]
	
	#include <ctype.h> - biblioteka ta dostarcza nam narzêdzi s³u¿¹cych m.in. do operacji na tekœcie, znajdziemy tam potrzebn¹ nam funkcjê "toupper" zmieniaj¹c¹ litery na wielkie
	int toupper(int c); - funkcja toupper przyjmuje jako argument kod ASCII danego znaku i zwraca kod ASCII znaku powiêkszonego - typ danych integer
	
*/
void zad_1_16() {
	int i = 0, maksymalnaDlugoscNapisu = 2000;	// w C deklaruj¹c tablicê musimy podaæ jej rozmiar, dlatego te¿ przyjmujemy, ¿e tekst bêdzie mia³ maksymalnie 2000 znaków
	char twojNapis[maksymalnaDlugoscNapisu];	// tworzymy tablicê znaków, w któr¹ wpakujemy nasz odczytany napis zadaj¹c jej wy¿ej zdefiniowany rozmiar
	printf("Zapodaj jakimœ tekstem krótszym od %d znakow i wciœnij enter.\n", maksymalnaDlugoscNapisu);	
	scanf("%s", &twojNapis);					// Przypisujemy podany przez nas napis do tabicy o nazwie twojNapis
	char znakKoncaNapisu = '\0';				// Nie wiemy jak¹ d³ugoœæ ma nasz napis i ile obrotów ma pêtla, ale wiemy, ¿e ka¿dy napis koñczy siê tym znakiem
	while(twojNapis[i] != znakKoncaNapisu){		// wiêc pobieramy kolejne literki do momentu a¿ nie natkniemy siê na znak koñca napisu
		printf("%c", toupper(twojNapis[i]));	// drukujemy literkê po jej powiêkszeniu przy u¿yciu funkcji toupper
		i++;									// zwiêkszamy licznik o 1 aby pobraæ kolejn¹ literkê
	}
}


/*
	1.15 	Zmodyfikuj program 1.14, tak aby mo¿na by³o wprowadzaæ równie¿ liczby:
	c)		z czêœci¹ po kropce dziesiêtnej i wyk³adnikiem (litera E, znak i 2-cyfrowy wyk³adnik)
	
	W ansi C mamy wbudowany format do wyœwietlania licz w postaci wyk³adniczej, aby zmienn¹ typu double lub float wyœwietliæ w tej¿e notacji,
	wystarczy u¿yæ %e zamiast %f / %lf w funkcji printf()
	
	Przyk³ad:
	double liczba = 2.2;
	printf("%e",liczba); wydrukuje j¹ w notacji wyk³adniczej
			
*/
void zad_1_15_c() {
	int i, iloscPodanychLiczb = 0, maksymalnaIloscLiczb = 100;	//iloscPodanychLiczb - licznik, ktory posluzy do sprawdzenia, czy mamy jeszcze miejsce w tablicy, by dodac wiecej liczb
	double liczba;
	double liczby[maksymalnaIloscLiczb];						// tablica int, do której bêdziemy zapisywaæ odczytane liczby - mo¿e pomieœciæ 100 liczb
	char czyJuzKoniec = 'n';								// flaga mówi¹ca o tym, czy chcemy ju¿ zakoñczyæ podawanie kolejnych liczb
	while(czyJuzKoniec != 't'){								// pêtla, która bêdzie wykonywana dopuki flaga "czyJuzKoniec" bêdzie ustawiona na 'n' (nie), kiedy zmieni siê na 't' przerwie dzia³anie
		if(iloscPodanychLiczb == maksymalnaIloscLiczb-1){	// sprawdzenie czy ju¿ zape³niliœmy ca³¹ tablicê
			printf("Tablica zosta³a zape³niona. Nie mo¿na dodaæ ju¿ wiêcej liczb.\n");
			break;
		}
		printf("Podaj liczbê: \n");
		scanf("%lf", &liczba);
		liczby[iloscPodanychLiczb] = liczba;			//	zapis podanej liczby w tablicy
		iloscPodanychLiczb++;							// licznik dodanych do tablicy liczb
		
		printf("Czy chcesz ju¿ skoñczyæ wpisywanie? Wciœnij 't' dla tak. Dowolny klawisz by kontynuowaæ.\n");	// pytamy u¿ytkownika czy chcia³by ju¿ zakoñczyæ podawanie cyfr
		scanf(" %c", &czyJuzKoniec);							// przypisanie podanej przez u¿ytkownika odpowiedzi czy ju¿ koñczymy do zmiennej
	}
	printf("Ilosc podanych liczb: %d.\n", iloscPodanychLiczb);
	for(i = 0; i < iloscPodanychLiczb; i++){					//wydrukowanie wszystkich liczb dodanych do tablicy
		printf("%e ", liczby[i]);
	}
}

/*
	1.15 	Zmodyfikuj program 1.14, tak aby mo¿na by³o wprowadzaæ równie¿ liczby:
	b)		zmiennoprzecinkowe (z czêœci¹ po kropce dziesiêtnej)
			
*/
void zad_1_15_b() {
	int i, iloscPodanychLiczb = 0, maksymalnaIloscLiczb = 100;	//iloscPodanychLiczb - licznik, ktory posluzy do sprawdzenia, czy mamy jeszcze miejsce w tablicy, by dodac wiecej liczb
	double liczba;
	double liczby[maksymalnaIloscLiczb];						// tablica int, do której bêdziemy zapisywaæ odczytane liczby - mo¿e pomieœciæ 100 liczb
	char czyJuzKoniec = 'n';								// flaga mówi¹ca o tym, czy chcemy ju¿ zakoñczyæ podawanie kolejnych liczb
	while(czyJuzKoniec != 't'){								// pêtla, która bêdzie wykonywana dopuki flaga "czyJuzKoniec" bêdzie ustawiona na 'n' (nie), kiedy zmieni siê na 't' przerwie dzia³anie
		if(iloscPodanychLiczb == maksymalnaIloscLiczb-1){	// sprawdzenie czy ju¿ zape³niliœmy ca³¹ tablicê
			printf("Tablica zosta³a zape³niona. Nie mo¿na dodaæ ju¿ wiêcej liczb.\n");
			break;
		}
		printf("Podaj liczbê: \n");
		scanf("%lf", &liczba);
		liczby[iloscPodanychLiczb] = liczba;			//	zapis podanej liczby w tablicy
		iloscPodanychLiczb++;							// licznik dodanych do tablicy liczb
		
		printf("Czy chcesz ju¿ skoñczyæ wpisywanie? Wciœnij 't' dla tak. Dowolny klawisz by kontynuowaæ.\n");	// pytamy u¿ytkownika czy chcia³by ju¿ zakoñczyæ podawanie cyfr
		scanf(" %c", &czyJuzKoniec);							// przypisanie podanej przez u¿ytkownika odpowiedzi czy ju¿ koñczymy do zmiennej
	}
	printf("Ilosc podanych liczb: %d.\n", iloscPodanychLiczb);
	for(i = 0; i < iloscPodanychLiczb; i++){					//wydrukowanie wszystkich liczb dodanych do tablicy
		printf("%lf ", liczby[i]);
	}
}

/*
	1.15 	Zmodyfikuj program 1.14, tak aby mo¿na by³o wprowadzaæ równie¿ liczby:
	a)		ujemne
			
*/
void zad_1_15_a() {
	int i, liczba, iloscPodanychLiczb = 0, maksymalnaIloscLiczb = 100;	//iloscPodanychLiczb - licznik, ktory posluzy do sprawdzenia, czy mamy jeszcze miejsce w tablicy, by dodac wiecej liczb
	char czyJuzKoniec = 'n';								// flaga mówi¹ca o tym, czy chcemy ju¿ zakoñczyæ podawanie kolejnych liczb
	int liczby[maksymalnaIloscLiczb];						// tablica int, do której bêdziemy zapisywaæ odczytane liczby - mo¿e pomieœciæ 100 liczb
	while(czyJuzKoniec != 't'){								// pêtla, która bêdzie wykonywana dopuki flaga "czyJuzKoniec" bêdzie ustawiona na 'n' (nie), kiedy zmieni siê na 't' przerwie dzia³anie
		if(iloscPodanychLiczb == maksymalnaIloscLiczb-1){	// sprawdzenie czy ju¿ zape³niliœmy ca³¹ tablicê
			printf("Tablica zosta³a zape³niona. Nie mo¿na dodaæ ju¿ wiêcej liczb.\n");
			break;
		}
		printf("Podaj liczbê: \n");
		scanf("%d", &liczba);
		liczby[iloscPodanychLiczb] = liczba;			//	zapis podanej liczby w tablicy
		iloscPodanychLiczb++;							// licznik dodanych do tablicy liczb
		
		printf("Czy chcesz ju¿ skoñczyæ wpisywanie? Wciœnij 't' dla tak. Dowolny klawisz by kontynuowaæ.\n");	// pytamy u¿ytkownika czy chcia³by ju¿ zakoñczyæ podawanie cyfr
		scanf(" %c", &czyJuzKoniec);							// przypisanie podanej przez u¿ytkownika odpowiedzi czy ju¿ koñczymy do zmiennej
	}
	printf("Ilosc podanych liczb: %d.\n", iloscPodanychLiczb);
	for(i = 0; i < iloscPodanychLiczb; i++){					//wydrukowanie wszystkich liczb dodanych do tablicy
		printf("%d ", liczby[i]);
	}
}

/*
	1.14 	Napisz program, który pozwala wprowadziæ z klawiatury jedynie cyfry (nie reaguje na inne klawisze) i ci¹g tych cyfr (jako liczbê)
			przypisuje zmiennej typu WORD (typ danych w³aœciwy dla TurboPascala, odpowiednikiem w ansi c jest tablica znaków char[])
			
			Nie wiem jak rozwi¹zaæ to zadanie w C bez u¿ycia dynamicznej alokacji pamiêci, wiêc zak³¹dam, ¿e u¿ytkownik nie poda wiêcej ni¿ 100 cyfr
			
*/
void zad_1_14() {
	int i, cyfra, iloscPodanychCyfr = 0, maksymalnaIloscCyfr = 100, min = 0, max = 9;	//iloscPodanychCyfr - licznik, ktory posluzy do sprawdzenia, czy mamy jeszcze miejsce w tablicy, by dodac wiecej cyfr
	char czyJuzKoniec = 'n';								// flaga mówi¹ca o tym, czy chcemy ju¿ zakoñczyæ podawanie kolejnych cyfr
	int cyfry[maksymalnaIloscCyfr];							// tablica int, do której bêdziemy zapisywaæ odczytane cyfry - mo¿e pomieœciæ 100 cyfr
	while(czyJuzKoniec != 't'){								// pêtla, która bêdzie wykonywana dopuki flaga "czyJuzKoniec" bêdzie ustawiona na 'n' (nie), kiedy zmieni siê na 't' przerwie dzia³anie
		if(iloscPodanychCyfr == maksymalnaIloscCyfr-1){		// sprawdzenie czy ju¿ zape³niliœmy ca³¹ tablicê
			printf("Tablica zosta³a zape³niona. Nie mo¿na dodaæ ju¿ wiêcej cyfr.\n");
			break;
		}
		printf("Podaj cyfrê od 0 do 9: \n");
		scanf("%d", &cyfra);
		if(cyfra >= 0 && cyfra <= 9){						// sprawdzenie, czy pobrana cyfra znajduje siê w przedziale od 0 do 9
			cyfry[iloscPodanychCyfr] = cyfra;				// jesli tak zapisujemy cyfrê  w tablicy
			iloscPodanychCyfr++;							// licznik dodanych do tablicy cyfr
		}
		printf("Czy chcesz ju¿ skoñczyæ wpisywanie? Wciœnij 't' dla tak. Dowolny klawisz by kontynuowaæ.\n");	// pytamy u¿ytkownika czy chcia³by ju¿ zakoñczyæ podawanie cyfr
		scanf(" %c", &czyJuzKoniec);											// przypisanie podanej przez u¿ytkownika odpowiedzi czy ju¿ koñczymy do zmiennej
	}
	printf("Ilosc podanych cyfr: %d.\n", iloscPodanychCyfr);
	for(i = 0; i < iloscPodanychCyfr; i++){					//wydrukowanie wszystkich cyfr dodanych do tablicy
		printf("%d ", cyfry[i]);
	}
}

/*
	1.13	Wczytaj znak z klawiatury
	c)		wyœwietl kod ascii odczytanego znaku
				
*/
void zad_1_13_c() {
    int odczytanyZnak;			// deklaracja zmiennej typu int, do której przypiszemy kod ASCII odczytany z klawiatury za pomoc¹ funkcji getchar()
    printf("Wciœnij dowolny klawisz z klawiatury i potwierdŸ wciskaj¹c enter.\n");
    odczytanyZnak = getchar();	// przypisanie kodu wciœniêtego klawisza do zmiennej odczytanyZnak
    printf("Przeczytano znak o numerze %d i jest to %c.\n", odczytanyZnak, (char)odczytanyZnak);
}

/*
	1.13	Wczytaj znak z klawiatury
	b)		wyœwietl znak nastêpny po przeczytanym
				
*/
void zad_1_13_b() {
    int odczytanyZnak;			// deklaracja zmiennej typu int, do której przypiszemy kod ASCII odczytany z klawiatury za pomoc¹ funkcji getchar()
    printf("Wciœnij dowolny klawisz z klawiatury i potwierdŸ wciskaj¹c enter.\n");
    odczytanyZnak = getchar();	// przypisanie kodu wciœniêtego klawisza do zmiennej odczytanyZnak
    printf("Przeczytano znak o numerze %d i jest to %c, kolejny to: %c.", odczytanyZnak, (char)odczytanyZnak, (char)(odczytanyZnak+1)); // odczytanyZnak + 1 wyœwietli kolejny znak w tabeli ASCII
}


/*
	1.13	Wczytaj znak z klawiatury
	a)		okreœl czy by³a to litera
	
	W kodzie ASCII 65-90 litery wielkie, 97-122 litery ma³e
	int getchar(); - funkcja z biblioteki stdio.h, czyta jeden znak wciœniêty przez u¿ytkownika i zwraca go w postaci odpowiadaj¹cego kodu ASCII, zwracany typ liczbowy int
			
*/
void zad_1_13_a() {
    int odczytanyZnak;			// deklaracja zmiennej typu int, do której przypiszemy kod ASCII odczytany z klawiatury za pomoc¹ funkcji getchar()
    printf("Wciœnij dowolny klawisz z klawiatury i potwierdŸ wciskaj¹c enter.\n");
    odczytanyZnak = getchar();	// przypisanie kodu wciœniêtego klawisza do zmiennej odczytanyZnak
    if((odczytanyZnak >= 65 && odczytanyZnak <= 90) || (odczytanyZnak >= 97 && odczytanyZnak <= 122)){		// Sprawdzamy czy odczytany znak znajduje siê w przedzia³ach kodów ASCII odpowiednich dla liter
    	printf("Przeczytano znak o numerze %d i jest on liter¹ %c.", odczytanyZnak, (char)odczytanyZnak);	// zapis "(char)odczytanyZnak" oznacza, ¿e zmienn¹ typu int konwertujemy do typu char
	} else {
		printf("Dany znak nie jest liter¹.\n");
	}
}

/*
	1.12 	Wyœwietl na ekranie kolejne znaki o kodach ASCII z zakresu 32-255. Obok podaj wartoœci kodów.
			
*/
void zad_1_12() {
	int i, min = 32, max = 255; 	// i licznik petli, min - pocz¹tek przedzia³u, max - koniec przedzia³u, min = 32, max = 255
	char biezacyZnak;
	for(i = min; i <= max; i++){	// pêtlê rozpoczynami od i = wartoœci minimalnej i iterujemy a¿ do osi¹gniêcia wawrtoœci maksymalnej zwiêkszaj¹c licznik o 1
		biezacyZnak = i;			// w celu zamiany liczby int reprezentuj¹cej znak ASCII przypisujemy j¹ do zmiennej typu char
		printf("Numer znaku %d, znak: %c \n", i, biezacyZnak);
	}
}

/*
	1.11 	Niech program wyœwietli napis "tak" lub "nie" w zale¿noœci od tego, czy naciœniêto klawisz <T> czy <N> (wielk¹ lub ma³¹ liter¹).
			Na pozosta³e klawisze nie powinien reagowaæ.
			
			Polecenie tego zadania jest nieco niejednoznaczne, bo pisz¹ o tym, by reagowaæ na przyciœniêcie klawiszy, a nie ka¿¹ wczytaæ zmiennej,
			samo wczytywanie klawiszy odbywa siê w oparciu o zmienne systemowe zale¿ne od systemu na jakim pracujemy a czysty jêzyk ansi c nie umo¿liwia takich interakcji
*/
void zad_1_11() {
	char wcisnietyKlawisz;
	printf("Wciœnij klawisz 't' lub 'T' dla tak albo 'n' lub 'N' dla nie.\nOperacjê zakoñcz wciœniêciem klawisza enter.\n");	
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
	1.10 	Wczytaj trzy liczby rzeczywiste i wyœwietl:
	b)		najmniejsz¹ sposród liczb
	
	Zadanie to zosta³o wykonane w sposób alternatywny do 1.10 a) w celu zobrazowania tego samego problemu, ale przy u¿yciu tablic.
*/
void zad_1_10_b() {
	int i, iloscLiczb = 3;				// i - licznik pêtli, iloscLiczb - ilosc liczb w tablicy
	double liczby[iloscLiczb];			// deklaracja tablicy o nazwie "liczby" o rozmiarze 3 = iloscLiczb i zawieraj¹cej typ danych double
	double aktualna, najmniejsza;		// aktualna - zmienna pomocnicza, do której bêdziemy przypisywaæ zmienne podane przez u¿ytkownika przed wpisaniem ich do tablicy
	printf("Podaj trzy liczby rzeczywiste z zakresu 2.3E-308 to 1.7E+308 w celu wykonania na nich obliczeñ:\nUWAGA! Aby format by³ poprawny do oddzielenia czêœci ca³kowitej od dziesiêtnej u¿yj znaku kropki, a nie przecinka.\n");
	for(i=0; i< iloscLiczb; i++){		// wype³nianie tablicy liczbami
		scanf("%lf", &aktualna);		// pobieranie liczby od u¿ytkownika i przypisywanie jej do zmiennej "aktualna"
		liczby[i] = aktualna;			// zapisywanie zmiennej "aktualna" pod i-tym indeksem w tablicy
	}
	najmniejsza = liczby[0];			//przypisujemy pierwsz¹ liczbê z tablicy jako najmniejsz¹, aby móc rozpocz¹æ porównywanie
	for(i=1; i < iloscLiczb-1; i++){	// skoro pierwsz¹ liczbê z tablicy ju¿ przypisaliœmy jako najmniejsz¹, to nie musimy jej porównywaæ samej ze sob¹, wiêc zaczynamy iteracjê od 1 (i = 1) a nie od 0
		aktualna = liczby[i];			// przypisujemy obecnie odczytywany element z tablicy do zmiennej aktualna (choæ moglibyœmy od razu porównywaæ liczby[i] < najmniejsza, nie ma to wiekszego znaczenia)
		if(aktualna < najmniejsza){
			najmniejsza = aktualna;
		}	
	}
	printf("Podane liczby to: a=%lf, b=%lf, c=%lf.\nNajmniejsza wynosi: %lf.\n",liczby[0],liczby[1],liczby[2], najmniejsza);	
}

/*
	1.10 	Wczytaj trzy liczby rzeczywiste i wyœwietl:
	a)		najwiêksz¹
	
	Zadanie to jako ze ma tylko 3 zmienne zostalo wykonane przy uzyciu 3 zmiennych, przy wiekszej ilosci wskazane byloby u¿yæ tablicy
	i analogicznie zmiennej pomocniczej o przykladowej nazwie "najwieksza", w celu wybrania najwiekszej trzeba by przeiterowaæ w pêtli po tablicy
*/
void zad_1_10_a() {
	double a, b, c, najwieksza;
	printf("Podaj trzy liczby rzeczywiste z zakresu 2.3E-308 to 1.7E+308 w celu wykonania na nich obliczeñ:\nUWAGA! Aby format by³ poprawny do oddzielenia czêœci ca³kowitej od dziesiêtnej u¿yj znaku kropki, a nie przecinka.\n");
	scanf("%lf", &a);
	scanf("%lf", &b);
	scanf("%lf", &c);
	najwieksza = a;		// Na poczatku zakladamy ze najwieksza = a, aby rozpoczac porownywanie
	if(b > najwieksza){
		najwieksza = b;	// jeœli b > najwieksza, to ono staje sie najwieksze
	} 
	if(c > najwieksza){
		najwieksza = c;	// jeœli c >  najwieksza, to ono staje sie najwieksze
	}
	printf("Podane liczby to: a=%lf, b=%lf, c=%lf.\nNajwiêksza wynosi: %lf.\n",a,b,c, najwieksza);	
}

/*
	1.9 	Wczytaj dwie liczby rzeczywiste i wyœwietl:
	b)		mniejsz¹ z nich
*/
void zad_1_9_b() {
	double a, b, mniejsza;
	printf("Podaj dwie liczby rzeczywiste z zakresu 2.3E-308 to 1.7E+308 w celu wykonania na nich obliczeñ:\nUWAGA! Aby format by³ poprawny do oddzielenia czêœci ca³kowitej od dziesiêtnej u¿yj znaku kropki, a nie przecinka.\n");
	scanf("%lf", &a);
	scanf("%lf", &b);
	if(a < b){
		mniejsza = a;
		printf("Podane liczby to: a=%lf i b=%lf.\n Mniejsza jest a=%lf.\n",a,b,a);
	} else if(b < a) {
		mniejsza = b;
		printf("Podane liczby to: a=%lf i b=%lf.\n Mniejsza jest b=%lf.\n",a,b,b);
	} else {
		printf("Podane liczby to: a=%lf i b=%lf.\n S¹ sobie równe.\n",a,b);
	}	
}

/*
	1.9 	Wczytaj dwie liczby rzeczywiste i wyœwietl:
	a)		wiêksz¹ z nich
*/
void zad_1_9_a() {
	double a, b, wieksza;
	printf("Podaj dwie liczby rzeczywiste z zakresu 2.3E-308 to 1.7E+308 w celu wykonania na nich obliczeñ:\nUWAGA! Aby format by³ poprawny do oddzielenia czêœci ca³kowitej od dziesiêtnej u¿yj znaku kropki, a nie przecinka.\n");
	scanf("%lf", &a);
	scanf("%lf", &b);
	if(a > b){
		wieksza = a;
		printf("Podane liczby to: a=%lf i b=%lf.\n Wiêksza jest a=%lf.\n",a,b,wieksza);
	} else if(b > a) {
		wieksza = b;
		printf("Podane liczby to: a=%lf i b=%lf.\n Wiêksza jest b=%lf.\n",a,b,wieksza);
	} else {
		printf("Podane liczby to: a=%lf i b=%lf.\n S¹ sobie równe.\n",a,b);
	}	
}

/*
	1.8 	Zmodyfikuj program 1.7 tak aby najpierw wczytywa³ ile bêdzie liczb, a nastêpnie wykonywa³ podan¹ operacjê dla tej iloœci wprowadzonych liczb
*/
void zad_1_8() {
	int i, liczba, iloscLiczb;			// i - licznik pêtli do wprowadzenia danych, liczba - aktualnie wczytywana liczba
	printf("Podaj %d ilosc liczb do wprowadzenia:\n");	// komunikat mówi¹cy o tym, jaki rozmiar bêdzie mia³a nasza tablica
	scanf("%d", &iloscLiczb);			// przypisanie zczytanej liczby to zmiennej "iloscLiczb"
	int tablica[iloscLiczb];			// deklaracja tablicy o nazwie "tablica" o rozmiarze = iloscLiczb = 10 i zawieraj¹cej liczby typu int
	for(i = 0; i < iloscLiczb; i++){	// pêtla s³u¿¹ca wype³nieniu tablicy liczbami podanymi przez u¿ytkownika
		printf("Podaj %d liczbe calkowita z %d:\n", i+1, iloscLiczb);	// komunikat mówi¹cy o tym, któr¹ liczbê z ilu aktualnie podajemy
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
	1.7 	Napisz program, który ¿¹da wprowadzenia 10 liczb, a nastêpnie je wczytuje i wyœwietla na ekranie obok ka¿dej liczby odpowiednie s³owo:
			"dodatnia", "ujemna", "zero".
*/
void zad_1_7() {
	int i, liczba, iloscLiczb = 10;		// i - licznik pêtli do wprowadzenia danych, liczba - aktualnie wczytywana liczba, iloscLiczb - rozmiar tablicy
	int tablica[iloscLiczb];			// deklaracja tablicy o nazwie "tablica" o rozmiarze = iloscLiczb = 10 i zawieraj¹cej liczby typu int
	for(i = 0; i < iloscLiczb; i++){	// pêtla s³u¿¹ca wype³nieniu tablicy liczbami podanymi przez u¿ytkownika
		printf("Podaj %d liczbe calkowita z %d:\n", i+1, iloscLiczb);	// komunikat mówi¹cy o tym, któr¹ liczbê z ilu aktualnie podajemy
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
	1.6 	Wczytaj dwie liczby ca³kowite (np. typu int) i wyœwietl na ekranie wszystkie liczby znajduj¹ce siê miedzy nimi.
*/
void zad_1_6() {
	int i, n, a, b, mniejszaLiczba; // i - licznik pêtli, n - iloœæ liczb pomiêdzy a i b, a i b - wczytane liczby
	printf("Podaj dwie liczby ca³kowite z zakresu -2,147,483,648 do 2,147,483,647 w celu wyœwietlenia na ekran wszystkich liczb znajduj¹cych siê miêdzy nimi.\n");
	scanf("%d", &a);
	scanf("%d", &b);
	n = abs(a-b) - 1 ; 	// poniewa¿ liczba a mo¿e byæ mniejsza ni¿ b interesuje nas wartoœæ bezwzglêdna z ró¿nicy miêdzy tymi liczbami,
						// pomniejszamy wynik o 1 poniewa¿ przyk³adowo jeœli a = 5, a b = 3, to 5 - 3 = 2, a miêdzy 5 a 3 mamy tylko "4"
	if(a < b){			// sprawdzamy, która z liczb jest mniejsza, by wiedzieæ, od której zacz¹æ wypisywanie na ekran
		mniejszaLiczba = a;
	} else {
		mniejszaLiczba = b;
	}
	for(i = 0; i < n; i++){
		mniejszaLiczba = mniejszaLiczba + 1; 	// z ka¿dym obrotem pêtli zwiêkszamy liczbê o 1
		printf("%d ", mniejszaLiczba);			// wypisujemy na ekran bie¿¹c¹ liczbê
	}
}

/*
	1.5 	Wczytaj dwie liczby typu REAL (typ turbo pascala, zamieniamy na double lub float) i oblicz:
	c)		sumê ich odwrotnoœci, jeœli s¹ one obie ró¿ne od zera, lub wprowadŸ komunikat,
			¿e operacja nie jest mo¿liwa do wykonania, jeœli przynajmniej jedna z nich jest równa zeru.
*/
void zad_1_5_c() {
	double a, b;
	printf("Podaj dwie liczby rzeczywiste z zakresu 2.3E-308 to 1.7E+308 w celu wykonania na nich obliczeñ:\nUWAGA! Aby format by³ poprawny do oddzielenia czêœci ca³kowitej od dziesiêtnej u¿yj znaku kropki, a nie przecinka.\n");
	scanf("%lf", &a);
	scanf("%lf", &b);
	if(a == 0.0 || b==0){
		printf("Operacja nie jest mo¿liwa do wykonania, co najmniej jedna z podanych liczb jest równa zero.");
	} else {
		printf("Podane liczby to: a=%lf i b=%lf.\nWynik dzia³ania 1/a + 1/b=%lf.\n",a,b,((1/a)+(1/b)));
	}
}

/*
	1.5 	Wczytaj dwie liczby typu REAL (typ turbo pascala, zamieniamy na double lub float) i oblicz:
	b)		ich iloraz. Jeœi dzielnik bêdzie zerem, wprowadŸ tê informacjê na ekran.
*/
void zad_1_5_b() {
	double a, b;
	printf("Podaj dwie liczby rzeczywiste z zakresu 2.3E-308 to 1.7E+308 w celu wykonania na nich obliczeñ:\nUWAGA! Aby format by³ poprawny do oddzielenia czêœci ca³kowitej od dziesiêtnej u¿yj znaku kropki, a nie przecinka.\n");
	scanf("%lf", &a);
	scanf("%lf", &b);
	if(b==0 || b==0.0){
		printf("Liczba b, która jest dzielnikiem jest równa 0. Dzia³anie nie zgodne z zasadami matematyki.");
	} else {
		printf("Podane liczby to: a=%lf i b=%lf.\nWynik dzia³ania a/b=%lf.\n",a,b,a/b);
	}
}

/*
	1.5 	Wczytaj dwie liczby typu REAL (typ turbo pascala, zamieniamy na double lub float) i oblicz:
	a)		ich sumê, ró¿nicê, iloczyn (mno¿enie ;-))
*/
void zad_1_5_a() {
	double a, b;
	printf("Podaj dwie liczby rzeczywiste z zakresu 2.3E-308 to 1.7E+308 w celu wykonania na nich obliczeñ:\nUWAGA! Aby format by³ poprawny do oddzielenia czêœci ca³kowitej od dziesiêtnej u¿yj znaku kropki, a nie przecinka.\n");
	scanf("%lf", &a);
	scanf("%lf", &b);
	printf("Podane liczby to: a=%lf i b=%lf.\nSuma: %lf, Ró¿nica: a-b=%lf, b-a=%lf, Iloczyn: %lf.\n",a,b,a+b,a-b,b-a,a*b);
}


/*
	1.4 	Wczytaj liczbê typu REAL (liczby typu rzeczywistego, w ANSI C zmiennoprzecinkowe o dowolnym znaku czyli np. double) z klawiatury,
			a nastêpnie wydrukuj na ekranie:
	d)		odwrotnoœæ danej liczby, jeœli jest ró¿na od zera
*/
void zad_1_4_d() {
	double liczba;
	printf("Podaj liczbê rzeczywist¹ z zakresu 2.3E-308 to 1.7E+308 w celu jej wyœwietlenia:\nUWAGA! Aby format by³ poprawny do oddzielenia czêœci ca³kowitej od dziesiêtnej u¿yj znaku kropki, a nie przecinka.\n");
	scanf("%lf", &liczba);
	if(liczba == 0.0 || liczba == 0){
		printf("Liczba wynosi 0 i dla niej nie wykonujemy dzia³añ.");
	} else {
		printf("Wpisana przez u¿ytkownika liczba to: %lf a jej odwrotnoœæ to: %lf.\n", liczba, 1/liczba);
	}
}

/*
	1.4 	Wczytaj liczbê typu REAL (liczby typu rzeczywistego, w ANSI C zmiennoprzecinkowe o dowolnym znaku czyli np. double) z klawiatury,
			a nastêpnie wydrukuj na ekranie:
	c)		liczbê 2 razy wiêksz¹
*/
void zad_1_4_c() {
	double liczba;
	printf("Podaj liczbê rzeczywist¹ z zakresu 2.3E-308 to 1.7E+308 w celu jej wyœwietlenia:\nUWAGA! Aby format by³ poprawny do oddzielenia czêœci ca³kowitej od dziesiêtnej u¿yj znaku kropki, a nie przecinka.\n");
	scanf("%lf", &liczba);
	printf("Wpisana przez u¿ytkownika liczba to: %lf a liczba 2x wiêksza to: %lf.\n", liczba, 2*liczba);
}

/*
	1.4 	Wczytaj liczbê typu REAL (liczby typu rzeczywistego, w ANSI C zmiennoprzecinkowe o dowolnym znaku czyli np. double) z klawiatury,
			a nastêpnie wydrukuj na ekranie:
	b)		liczbê przeciwn¹ do danej
	
	#include <math.h> - dany import pozwoli nam na u¿ycie funkcji "fabs", która zwraca wartoœæ bezwzglêdn¹ z liczby double (abs dla typu int, fabsf dla typu float)
	double fabs(double);	jest to definicja u¿ycia funkcji "fabs", zwracanym typem danych jest double i przyjmuje ona jeden argument równie¿ typu double	
*/
void zad_1_4_b() {
	double liczba, liczbaPrzeciwna;
	printf("Podaj liczbê rzeczywist¹ z zakresu 2.3E-308 to 1.7E+308 w celu jej wyœwietlenia:\nUWAGA! Aby format by³ poprawny do oddzielenia czêœci ca³kowitej od dziesiêtnej u¿yj znaku kropki, a nie przecinka.\n");
	scanf("%lf", &liczba);
	if(liczba < 0){						// je¿eli odczytana liczba jest ujemna
		liczbaPrzeciwna = fabs(liczba); //	obliczamy wartoœæ bezwzglêdn¹ z liczby
	} else {
		liczbaPrzeciwna = -liczba;		// w przeciwnym wypadku zapisujemy dan¹ liczbê ze znakiem ujemnym
	}
	printf("Wpisana przez u¿ytkownika liczba to: %lf a wartoœæ do niej przeciwna to: %lf.\n", liczba, liczbaPrzeciwna);
}

/*
	1.4 	Wczytaj liczbê typu REAL (liczby typu rzeczywistego, w ANSI C zmiennoprzecinkowe o dowolnym znaku czyli np. double) z klawiatury,
			a nastêpnie wydrukuj na ekranie:
	a)		tê liczbê
		
*/
void zad_1_4_a() {
	double liczba;
	printf("Podaj liczbê rzeczywist¹ z zakresu 2.3E-308 to 1.7E+308 w celu jej wyœwietlenia:\nUWAGA! Aby format by³ poprawny do oddzielenia czêœci ca³kowitej od dziesiêtnej u¿yj znaku kropki, a nie przecinka.\n");
	scanf("%lf", &liczba);
	printf("Wpisana przez u¿ytkownika liczba to: %lf.\n", liczba);
}


/*
	1.3 	Wyœwietl na ekranie 32 gwiazdki "*" u³o¿one w szachownicê 8x8 pól, na przemian ze znakiem spacji
	
	char - liczba z zakresu od -128 to 127  lub 0 to 255 reprezentuj¹ca literê w kodzie ASCII, aby odczytaæ u¿ywamy symbolu %c
*/
void zad_1_3() {
	int i, j, n = 8;					// n - jest to liczba kolumn oraz liczba wierszy w szachownicy, i - licznik petli wierszy, j - licznik petli kolumn
	char nastepnyZnak;					// zmienna pomocnicza, do której bêdziemy przypisywaæ naprzemiennie '*' i spacje w zale¿noœci od po³o¿enia
	for(i = 0; i < n; i++){				// pêtle zewnêtrzna - iterowanie po wierszach
		if(i % 2 == 0){					// sprawdzenie, czy numer wiersza jest parzysty
			nastepnyZnak = '*';			// jeœli numer wiersza jest parzysty, to zaczynamy od '*'
		} else {
			nastepnyZnak = ' ';			// jeœli numer wiersza jest nieparzysty, to zaczynamy od spacji
		}
		for(j = 0; j < n; j++){			// pêtle wewnêtrzna - iterowanie po kolumnach
			printf("%c", nastepnyZnak);	// drukujemy aktualnie ustawiony znak
			if(nastepnyZnak == '*'){	// je¿eli aktualnie ustawiony znak to '*'
				nastepnyZnak = ' ';		// to kolejny znak ustawiamy na spacjê
			} else {
				nastepnyZnak = '*';		// w przeciwnym wypadku kolejny znak ustawiamy na gwiazdkê
			}	
		}
		printf("\n");					// po zakoñczeniu iteracji po kolumnach "drukujemy" znak nowej linii,
										//w celu unikniêcia wydrukowania wszystkiego ci¹giem w jednej linii
	}	
}


/*
	1.2 	Wyœwietl na ekranie:
	c) 		10 kolejnych liczb naturalnych i obok ich szeœciany
	
	#include <math.h> - dany import pozwoli nam na u¿ycie funkcji "pow", która podnosi liczbê do dowolnej potêgi
	double pow( double podstawa, double potega ); - jest to definicja u¿ycia funkcji "pow", zwracanym typem danych jest double
													i przyjmuje ona dwa argumenty "podstawa" i "potêga" równie¿ typu double.
	double - liczba zmiennoprzecinkowa z zakresu 2.3E-308 to 1.7E+308, aby odczytaæ u¿ywamy symbolu %lf (jest to skrót od large float, double = podwójny float, dlatego du¿y)
*/
void zad_1_2_c() {
	int i, iloscLiczb = 10;						// i - licznik pêtli, iloscLiczb = 10 - iloœæ liczb, które chcemy wyœwietliæ
	unsigned int pierwszaLiczba;				// deklaracja zmiennej, od której rozpoczniemy wyœwiatlanie liczb
	double szescianLiczby;						// deklaracja zmiennej, do której bêdziemy przypisywaæ szeœcian liczby
	double potega = 3;							// potêga, do której bêdziemy podnosiæ kolejne liczby, u¿ywamy typu double, bo taki typ przyjmuje funkcja "pow"
	printf("Podaj liczbê naturaln¹, od której ma zostaæ rozpoczête wyœwietlanie:\n");
	scanf("%u", &pierwszaLiczba); 				// przypisanie do zmiennej "pierwszaLiczba" wartoœci podanej przez u¿ytkownika,
												// znak "&" powoduje, ¿e odczytan¹ z klawiatury zmienn¹ zapiszemy pod adresem wczeœniej zadeklarowanej "pierwszaLiczba"
												// %u umo¿liwia nam odczytanie zmiennej typu "unsigned int"
	for(i = 0; i < iloscLiczb; i++){			// inicjalizacja pêtli for
		szescianLiczby = pow((double)(pierwszaLiczba), potega);	// zapis "(double)(pierwszaLiczba)" oznacza, ze "pierwszaLiczba" typu unsigned int zamieniamy na double
		printf("%u %u\n", pierwszaLiczba, (unsigned int)szescianLiczby);	// zapis "(unsigned int)szescianLiczby" oznacza, ¿e "szescianLiczby" typu double zamieniamy na unsigned int
		pierwszaLiczba = pierwszaLiczba + 1;	// tym razem w celu ³atwiejszego wykonywania dzia³añ na aktualnej liczbie z kazd¹ pêtl¹ dodajemy do niej 1
	}	
}


/*
	1.2 	Wyœwietl na ekranie:
	b) 		10 kolejnych liczb naturalnych i obok ich kwadraty
	
	"\n" - jest to znak przejœcia do kolejnej lini, w danym zadaniu spowoduje, ¿e pary liczb bêd¹ wyœwietlane zawsze w nowej linii
	
*/
void zad_1_2_b() {
	int i, iloscLiczb = 10;						// i - licznik pêtli, iloscLiczb = 10 - iloœæ liczb, które chcemy wyœwietliæ
	unsigned int pierwszaLiczba;				// deklaracja zmiennej, od której rozpoczniemy wyœwiatlanie liczb
	printf("Podaj liczbê naturaln¹, od której ma zostaæ rozpoczête wyœwietlanie:\n");
	scanf("%u", &pierwszaLiczba); 				// przypisanie do zmiennej "pierwszaLiczba" wartoœci podanej przez u¿ytkownika,
												// znak "&" powoduje, ¿e odczytan¹ z klawiatury zmienn¹ zapiszemy pod adresem wczeœniej zadeklarowanej "pierwszaLiczba"
												// %u umo¿liwia nam odczytanie zmiennej typu "unsigned int"
	for(i = 0; i < iloscLiczb; i++){			// inicjalizacja pêtli for
		printf("%u %u\n", pierwszaLiczba, pierwszaLiczba*pierwszaLiczba);	// aby zwiêkszyæ czytelnoœæ pary liczba i jej kwadrat bêd¹ wyœwietlane jedna pod drug¹
		pierwszaLiczba = pierwszaLiczba + 1;	// tym razem w celu ³atwiejszego wykonywania dzia³añ na aktualnej liczbie z kazd¹ pêtl¹ dodajemy do niej 1
	}	
}


/*
	1.2 	Wyœwietl na ekranie:
	a) 		10 kolejnych liczb naturalnych
	
	int - liczba z zakresu -2,147,483,648 do 2,147,483,647, aby odczytaæ u¿ywamy symbolu %d
	unsigned int - liczba z zakresu od 0 do 0 to 4,294,967,295, aby odczytaæ u¿ywamy symbolu %u
*/
void zad_1_2_a() {
	int i, iloscLiczb = 10;					// i - licznik pêtli, iloscLiczb = 10 - iloœæ liczb, które chcemy wyœwietliæ
	unsigned int pierwszaLiczba;			// deklaracja zmiennej, od której rozpoczniemy wyœwiatlanie liczb
	printf("Podaj liczbê naturaln¹, od której ma zostaæ rozpoczête wyœwietlanie:\n");
	scanf("%u", &pierwszaLiczba); 			// przypisanie do zmiennej "pierwszaLiczba" wartoœci podanej przez u¿ytkownika,
											// znak "&" powoduje, ¿e odczytan¹ z klawiatury zmienn¹ zapiszemy pod adresem wczeœniej zadeklarowanej "pierwszaLiczba"
											// %u umo¿liwia nam odczytanie zmiennej typu "unsigned int"
	for(i = 0; i < iloscLiczb; i++){		// inicjalizacja pêtli for
		printf("%u ", pierwszaLiczba + i);	// drukujemy pierwszaLiczba + aktualny licznik pêtli (i), aby bez nadpisywania zmiennej "pierwszaLiczba" wydrukowaæ kolejne wartoœci
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
