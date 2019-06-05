#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
	3.11	Dana jest macierz o rozmiarze n x m. Zak³adamy, ¿e nie wszystkie elementy s¹ równe zeru. Otrzymaæ now¹ macierz,
			której elementy s¹ równe elementom macierzy wyjœciowej podzielonym przez element macierzy o maksymalnej wartoœci bezwzglêdnej.
		
*/
void zad_3_11() {
	int i, j, n = 3, m = 4, max=0, liczba;
	double nowaLiczba;
	int tablica[n][m];				// deklarujemy rozmiar tablicy
	srand(time(NULL));				// inicjalizacja w celu u¿ycia funkcji rand()
	for(i=0; i<n; i++){
		for(j=0; j < m; j++){
			tablica[i][j] = rand();	// wype³niamy tablicê losowymi liczbami
			liczba = tablica[i][j];
			printf("%d ", liczba);
			max = abs(liczba)> max ? abs(liczba) : max;
		}
		printf("\n");
	}
	double nowa[n][m];
	for(i=0; i<n; i++){				//wypisujemy kolejne elementy z macierzy
		for(j=0; j < m; j++){
			nowaLiczba = (tablica[i][j])*1.0/max;
			printf("%lf ", nowaLiczba);
		}
		printf("\n");
	}
}



/*
	3.10	Dane s¹ liczby naturalne n i m oraz macierz o wybiarze n x m (n - liczba wierszy, m - liczba kolumn).
	b)		ZnaleŸæ œrednie arytmetyczne wyrazów w poszczególnych kolumnach	
	
	Dodanie biblioteki <time.h> pozwoli nam na inicjalizacjê niezbêdn¹ do generowania liczb losowych typu int przy u¿yciu funkcji rand()
	Sama funkcja rand() znajduje siê w bibliotece <stdlib.h>
		
*/
void zad_3_10_b() {
	int i, j, n = 3, m = 4, suma=0, liczba;
	int tablica[n][m];				// deklarujemy rozmiar tablicy
	srand(time(NULL));				// inicjalizacja w celu u¿ycia funkcji rand()
	for(i=0; i<n; i++){
		for(j=0; j < m; j++){
			tablica[i][j] = rand();	// wype³niamy tablicê losowymi liczbami
			printf("%d ", tablica[i][j]);
		}
		printf("\n");
	}
	for(i=0; i <m; i++){				//wypisujemy kolejne elementy z macierzy
		for(j=0; j < n; j++){
			liczba = tablica[j][i];	// tutaj zaszla najistotniejsza zmiana w stosunku do podpunktu a) teraz "i" to kolumny, a "j" to wiersze
			suma+=liczba;			// przy okazji sumujemy wartoœci w kolumnie
		}
		printf(" œrednia wartoœci w kolumnie nr %d to: %lf.\n",i, suma*1.0/n);	// na koniec ka¿dej kolumny obliczamy i drukujemy œredni¹
	}
}

/*
	3.10	Dane s¹ liczby naturalne n i m oraz macierz o wybiarze n x m (n - liczba wierszy, m - liczba kolumn).
	a)		ZnaleŸæ œrednie arytmetyczne wyrazów w poszczególnych wierszach	
	
	Dodanie biblioteki <time.h> pozwoli nam na inicjalizacjê niezbêdn¹ do generowania liczb losowych typu int przy u¿yciu funkcji rand()
	Sama funkcja rand() znajduje siê w bibliotece <stdlib.h>
	
*/
void zad_3_10_a() {
	int i, j, n = 3, m = 4, suma=0, liczba;
	int tablica[n][m];				// deklarujemy rozmiar tablicy
	srand(time(NULL));				// inicjalizacja w celu u¿ycia funkcji rand()
	for(i=0; i<n; i++){
		for(j=0; j < m; j++){
			tablica[i][j]= rand();	// wype³niamy tablicê losowymi liczbami
		}
	}
	for(i=0; i<n; i++){				//wypisujemy kolejne elementy z macierzy
		for(j=0; j < m; j++){
			liczba = tablica[i][j];
			printf("%d ", liczba);
			suma+=liczba;			// przy okazji sumujemy wartoœci w wierszu
		}
		printf(" œrednia wartoœci w danym wierszu to: %lf.\n", suma*1.0/m);	// na koniec ka¿dego wiersza obliczamy i drukujemy œredni¹
	}

}

/*
	3.9 Dokonaæ zamiany dowolnej liczby naturalnej n zapisanej w systemie dziesiêtnym na zapis dwójkowy, np. 17 = 10001
	
	w bibliotece <stdlib.h> znajduje siê funkcja atoi(), która pozwala zamieniæ ³añcuch znaków na liczbê
	int atoi( const char * str ); - funkcja atoi przyjmuje argument w postaci tablicy znaków i zwraca wartosæ int
	
	Zakres unsigned int w ansi co to 32 bity, a zatem liczbê mo¿na zapisaæ maksymalnie w 32 elementowej tablicy
	
	Przyk³ad: 2837 = 101100010101
	
*/
void zad_3_9() {
	int i=0, j, n, pomocnicza;
	int tablica[32];
	printf("Podaj liczbê naturaln¹ n: \n");
	scanf("%d", &n);
	printf("Liczbê n=%d w systemie binarnym mo¿emy zapisaæ jako: \n", n);
	while(n != 0){					// w tym miejscu wykonujemy algorytm zaprezentowany na zajêciach wstêp do programowania
		pomocnicza = n % 2;			// obliczamy resztê z dzielenia liczby przez 2
		n = n/2;					// nastêpnie dzielimy tê liczbê na 2	
		tablica[i] = pomocnicza;	// resztê zapisujemy w tablicy
		i++;						// zwiêkszamy o 1 indeks pod którym zapiszemy kolejn¹ liczbê
	}
	for(j=i-1; j>=0; j--){			// finalnie nasze "i" to iloœæ zapisanych w tablicy 0 i 1, s¹ zapisane w odwrotnej kolejnoœci
		printf("%d",tablica[j]);	// zatem aby odczytaæ liczbê iterujemy od ostatniego indeksu, gdzie coœ zapisalismy a¿ do 0
	}
}

/*
	3.8 Dana jest liczba naturalna n. Sprawdziæ ile ró¿nych cyfr znajduje siê w tej liczbie.
	
	Zak³¹damy, ¿e w tablicy pod i-tym indeksem bêdzie iloœæ cyfr "i" w podanej liczbie
*/
void zad_3_8() {
	int i, n, pomocnicza;
	int iloscCyfr[] = {0,0,0,0,0,0,0,0,0,0};
	printf("Podaj liczbê naturaln¹ n: \n");
	scanf("%d", &n);
	printf("W liczbie n=%d mamy nastêpuj¹ce iloœci cyfr: \n",n);
 	while(n != 0){
 		pomocnicza = n % 10;
 		iloscCyfr[pomocnicza]++;
 		n=n/10;
	}
	for(i=0; i<10; i++){
		printf("%d: %d\n",i,iloscCyfr[i]);
	}
}

/*
	3.7 ZnaleŸæ minimaln¹ i maksymaln¹ liczbê w tablicy n-elementowej.
	
	W tym zadaniu kompilator zg³asza ostrze¿enie, bo przypisujemy INFINITY do zmiennej typu int
*/
void zad_3_7() {
	int i, n, liczba, min=INFINITY, max=-INFINITY;
	printf("Podaj ile chcesz wprowadzic liczb ca³kowitych: \n");
	scanf("%d", &n);
	int liczby[n];				// inicjalizujemy tablicê o rozmiarze n podanym przez u¿ytkownika
	for(i=0; i< n; i++){
		printf("Podaj %d liczbe z %d.\n", i+1, n);
		scanf("%d", &liczba);	//dla czytelnoœci zczytan¹ od u¿ytkownika liczbê przypisujemy do zmiennej liczba
		if(liczba > max){
			max = liczba;
		}
		if(liczba < min){
			min = liczba;
		}
		liczby[i] = liczba;		// nastêpnie wstawiamy liczbê do tablicy pod indeksem i
	}
	printf("W ci¹gu max=%d, a min=%d.\n",max, min);
}

/*
	3.6 Dana jest naturalna liczba n oraz liczby ca³kowite a1, ...an. Podaæ jakie liczby i ile liczb o poszczególnych wartoœciach wystêpuje w ci¹gu.
*/
void zad_3_6() {
	int i, n = 10, dodatnie=0, ujemne=0, zera=0, liczba;
	int liczby[] = {-2, 5, 7, -3, 0, -12, 6, 7, 0, 9};
	for(i=0; i<n; i++){
		liczba = liczby[i];
		if(liczba > 0){
			dodatnie++;
			printf("%d - dodatnia\n",liczba);
		} else if(liczba < 0){
			ujemne++;
			printf("%d - ujemna\n",liczba);
		} else {
			zera++;
			printf("%d - zero\n",liczba);
		}
	}
	printf("W ci¹gu wystêpuje %d liczb dodatnich, %d ujemnych i %d zer.\n",dodatnie, ujemne, zera);
}

/*
	3.5 Dana jest naturalna liczba n oraz liczby ca³kowite a1, ...an. Podaæ jaka liczba: dodatnia czy ujemna, wystêpuje pierwsza w ci¹gu.
		Jeœli ci¹g sk³ada siê z samych zer wyprowadziæ odpowiedni komunikat.
*/
void zad_3_5() {
	int n = 10;
	int liczby[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	if(liczby[0]>0){
		printf("Pierwsza liczba w ci¹gu jest dodatnia.\n");
	} else if(liczby[0]<0){
		printf("Pierwsza liczba w ci¹gu jest dujemna.\n");
	} else {
		printf("Pierwsza liczba w ci¹gu jest zerem.\n");
	}
}

/*
	3.4 Dana jest naturalna liczba n oraz liczby rzeczywiste a1, ...an. Wyprowadziæ te liczby na ekran w odwrotnej kolejnoœci
	
*/
void zad_3_4() {
	int n = 10, i;
	int liczby[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	for(i=n-1; i>=0; i--){
		printf("%d ", liczby[i]);
	}
}

/*
	3.3	Dane s¹ naturalne liczby a1, ....a10. Napisz fragment programu, który wprowadza na ekran w kolejnoœci: a2, ...,a10, a1
	
*/
void zad_3_3() {
	int n = 10, indeks=1, licznik;
	licznik = n;										//licznik pozwoli nam kontrolowaæ ile liczb ju¿ wypisaliœmy, ustawiamy jego wartoœæ na liczbê elementów
	int liczby[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	while(licznik > 0){									// dopuki licznik > 0 wypisujemy liczby
		printf(" %d ", liczby[indeks]);					// drukujemy liczbê spod danego indeksu zaczynaj¹c od 1
		indeks=(indeks+1) % n;							// zwiêkszamy wartoœæ indeksu i aby nie wyjœæ po za zakres tablicy dzielimy go przez liczbê elemetów
		licznik--;										// zabieg ten pozwala nam po osi¹gniêciu ostatniego elementu wróciæ do pierwszego
	}													// na konieæ zmniejszamy wartoœæ licznika, bo pozosta³o nam o 1 mniej liczbê do wypisania
}

/*
	3.2	Dana jest naturalna liczba n. Otrzymaæ macierz kwadratow¹ A o wymiarze n x n i elementach aij=1/(i+j)
	
	Pytanie: a co z dzieleniem przez 0 ??? -> i,j liczymy od 1
	
*/
void zad_3_2() {
	int i, j, n, liczba;
	printf("Podaj rozmiar macierzy kwaratowej n: \n");
	scanf("%d", &n);
	double macierz[n][n];				// inicjalizujemy macierz kwadratwa o rozmiarze nxn
	for(i=0; i<n; i++){					// iteracja po wierszach
		for(j = 0; j<n; j++){			// iteracja po kolumnach
			macierz[i][j]=1.0/(i+j+2);	// wype³nianie macierzy wed³ug wzoru
		}
	}
	
	for(i=0; i<n; i++){						// iteracja po wierszach
		for(j = 0; j<n; j++){				// iteracja po kolumnach
			printf(" %lf ", macierz[i][j]);	// drukowanie macierzy na ekran
		}
		printf("\n");						// po przejœciu przez wiersz przechodzimy do nowej linii
	}
}


/*
	3.1	WprowadŸ z klawiatury n liczb naturalnych i przypisz je kolejnym elementom tablicy.
*/
void zad_3_1() {
	int i, n, liczba;
	printf("Podaj ile chcesz wprowadzic liczb naturalnych: \n");
	scanf("%d", &n);
	int liczby[n];				// inicjalizujemy tablicê o rozmiarze n podanym przez u¿ytkownika
	for(i=0; i< n; i++){
		printf("Podaj %d liczbe z %d.\n", i+1, n);
		scanf("%d", &liczba);	//dla czytelnoœci zczytan¹ od u¿ytkownika liczbê przypisujemy do zmiennej liczba
		liczby[i] = liczba;		// nastêpnie wstawiamy liczbê do tablicy pod indeksem i
	}
}

int main(int argc, char *argv[]) {
	
	//zad_3_1();
	//zad_3_2();
	//zad_3_3();
	//zad_3_4();
	//zad_3_5();
	//zad_3_6();
	//zad_3_7();
	//zad_3_8();
	//zad_3_9();
	//zad_3_10_a();
	//zad_3_10_b();
	zad_3_11();
	
	return 0;
}
