#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
	6.6		Oblicz przybli�on� warto�� podanych funkcji dla dowolnej liczby rzeczywistej na podstawie rozwini�cia w szereg Taylora.
			Obliczenia przerwij w momencie, gdy kolejny wyraz szeregu b�dzie mniejszy ni� e = 10^(-7). Kolejne wyrazy szeregu obliczaj rekurencyjnie,
			u�atwi to (czasem wr�cz umo�liwi) obliczenia:
	a)		sin(x) = (x/1!) - (x^3)/3! + (x^5)/5! - (x^7)/7!...
	
	
*/
double zad_6_6_a(double x) {
	double epsilon = 1.0/pow(10,7), wyraz=x*1.0/1, wynik = wyraz;
	int mnoznik = 2;
	while(wyraz > epsilon){
		wyraz = wyraz*(-x*x)/((mnoznik)*(mnoznik+1));
		wynik += wyraz;
		mnoznik += 2;
	}
	return wynik;
}

/*
	6.5		Dane s� macierze A i B oraz liczba rzeczywista c. Napisa� procedur� obliczaj�c�:
	d)		iloczyn A i B
	
	https://pl.wikipedia.org/wiki/Mno%C5%BCenie_macierzy
	http://www.naukowiec.org/zadania/matematyka/mnozenie-macierzy-zadanie-4_1345.html
	
	
*/
void zad_6_5_d(int m, int n, double A[m][n] , double B[m][n], double AB[m][n]) {
	int i,j,k, pomocnicza=0;
	for(i=0; i<m; i++){
		for(j=0;j<n;j++){
			for(k=0; k<m; k++){
				pomocnicza += A[i][k]*B[k][j];
			}
			AB[i][j]= pomocnicza;
			pomocnicza = 0;
		}
	}
}

void test_zad_6_5_d(){
	int i, j, m = 4, n = 4;
	double A[4][4]={{5,11,0,2},{13,9,4,6},{4,-1,4,-2},{1,-2,3,0}}; 	// definiujemy sobie pierwsza macierz
	double B[4][4]={{1,0,9,5},{-6,-1,2,1},{-2,-5,3,3},{1,5,9,0}}; 						// definiujemy druga macierz
	double AB[4][4];							// deklarujemy wynikowa macierz o tym samym rozmiarze co dwie poprzednie
	
	zad_6_5_d(m,n,A,B,AB);						// wywo�ujemy nasz� metod� mno��c� przez siebie dwie macierze
	
	for(i=0; i<m; i++){							// drukujemy wynikow� macierz w celu sprawdzenia poprawnosci dzia�ania programu	
		for(j=0; j<n; j++){
			printf("%lf ", AB[i][j]);
		}
		printf("\n");
	}
}

/*
	6.5		Dane s� macierze A i B oraz liczba rzeczywista c. Napisa� procedur� obliczaj�c�:
	c)		iloczyn A i liczby c
	
	
*/
void zad_6_5_c(int m, int n, double A[m][n] , double B[m][n], double AB[m][n], double c) {
	int i,j;
	for(i=0; i<m; i++){
		for(j=0;j<n;j++){
			AB[i][j]=A[i][j]*c;
		}
	}
}

void test_zad_6_5_c(){
	int i, j, m = 3, n = 3;
	double c = -1.13;
	double A[3][3]={{1,2,3},{4,5,6},{7,8,9}}; 	// definiujemy sobie pierwsza macierz
	double B[3][3]={{1,1,1},{1,1,1},{1,1,1}}; 	// definiujemy druga macierz
	double AB[3][3];							// deklarujemy wynikowa macierz o tym samym rozmiarze co dwie poprzednie
	
	zad_6_5_c(m,n,A,B,AB,c);					// wywo�ujemy nasz� metod� dodaj�c� do siebie dwie macierze
	
	for(i=0; i<m; i++){							// drukujemy sobie wynikow� macierz w celu sprawdzenia poprawnosci dzia�ania programu	
		for(j=0; j<n; j++){
			printf("%lf ", AB[i][j]);
		}
		printf("\n");
	}
}

/*
	6.5		Dane s� macierze A i B oraz liczba rzeczywista c. Napisa� procedur� obliczaj�c�:
	b)		r�nic� tych macierzy 
	
	Macierze mo�na do siebie dodawa� tylko je�li s� tego samego rozmiaru, �r�d�o informacji:
	https://pl.wikipedia.org/wiki/Dodawanie_macierzy
	m - liczba wierszy, n - liczba kolumn
	
*/
void zad_6_5_b(int m, int n, double A[m][n] , double B[m][n], double AB[m][n], double c) {
	int i,j;
	for(i=0; i<m; i++){
		for(j=0;j<n;j++){
			AB[i][j]=A[i][j]-B[i][j];
		}
	}
}

void test_zad_6_5_b(){
	int i, j, m = 3, n = 3;
	double A[3][3]={{1,2,3},{4,5,6},{7,8,9}}; 	// definiujemy sobie pierwsza macierz
	double B[3][3]={{1,1,1},{1,1,1},{1,1,1}}; 	// definiujemy druga macierz
	double AB[3][3];							// deklarujemy wynikowa macierz o tym samym rozmiarze co dwie poprzednie
	
	zad_6_5_b(m,n,A,B,AB,1);					// wywo�ujemy nasz� metod� dodaj�c� do siebie dwie macierze
	
	for(i=0; i<m; i++){							// drukujemy sobie wynikow� macierz w celu sprawdzenia poprawnosci dzia�ania programu	
		for(j=0; j<n; j++){
			printf("%lf ", AB[i][j]);
		}
		printf("\n");
	}
}

/*
	6.5		Dane s� macierze A i B oraz liczba rzeczywista c. Napisa� procedur� obliczaj�c�:
	a)		sum� tych macierzy 
	
	Macierze mo�na do siebie dodawa� tylko je�li s� tego samego rozmiaru, �r�d�o informacji:
	https://pl.wikipedia.org/wiki/Dodawanie_macierzy
	m - liczba wierszy, n - liczba kolumn
	
*/
void zad_6_5_a(int m, int n, double A[m][n] , double B[m][n], double AB[m][n], double c) {
	int i,j;
	for(i=0; i<m; i++){
		for(j=0;j<n;j++){
			AB[i][j]=A[i][j]+B[i][j];
		}
	}
}

void test_zad_6_5_a(){
	int i, j, m = 3, n = 3;
	double A[3][3]={{1,2,3},{4,5,6},{7,8,9}}; 	// definiujemy sobie pierwsza macierz
	double B[3][3]={{1,1,1},{1,1,1},{1,1,1}}; 	// definiujemy druga macierz
	double AB[3][3];							// deklarujemy wynikowa macierz o tym samym rozmiarze co dwie poprzednie
	
	zad_6_5_a(m,n,A,B,AB,1);					// wywo�ujemy nasz� metod� dodaj�c� do siebie dwie macierze
	
	for(i=0; i<m; i++){							// drukujemy sobie wynikow� macierz w celu sprawdzenia poprawnosci dzia�ania programu	
		for(j=0; j<n; j++){
			printf("%lf ", AB[i][j]);
		}
		printf("\n");
	}
}

/*
	6.4		Napisz funkcj�, kt�ra oblicza pole tr�jk�ta zbudowanego z bok�w o d�ugosciach a, b, c.
			Je�li taki tr�jk�t nie istnieje, to warto�� funkcji niech przyjmuje warto�� -1;
			
			Z bok�w o danych d�ugo�ciach a,b i c mo�na utworzy� tr�jk�t gdy:
			a+b>c, a+c>b, b+c>a
*/
double zad_6_4(double a, double b, double c) {
	double p, pole;
	if(a+b>c && a+c>b && b+c>a){
		p = (a+b+c)*1.0/2;								// definiujemy sobie zmienn� pomocnicz� p r�wn� po�owie obwodu tr�jk�ta, w celu wi�kszej czytelno�ci dzia�a�
		pole = sqrt(p*(p-a)*(p-b)*(p-c));			// obliczenie pola dowolnego tr�jk�ta
		return pole;
	} else {
		return -1;
	}
}

/*
	6.3		Dane s� 2 liczby rzeczywste a i b. Napisz funkcj� obliczaj�c�:
	d)		�redni� geometryczn� z ich warto�ci bezwzgl�dnych
	
	�rednia geometryczna to pierwiastek stopnia r�wnego ilo�ci liczb z iloczynu tych liczb
*/
double zad_6_3_d(double a, double b) {
	return sqrt(fabs(a)*fabs(b));
}

/*
	6.3		Dane s� 2 liczby rzeczywste a i b. Napisz funkcj� obliczaj�c�:
	c)		ich �redni� arytmetyczn�	
*/
double zad_6_3_c(double a, double b) {
	return (a+b)/2;
}

/*
	6.3		Dane s� 2 liczby rzeczywste a i b. Napisz funkcj� obliczaj�c�:
	b)		maksymaln� warto�� z tych liczb		
*/
double zad_6_3_b(double a, double b) {
	return a > b ? a : b;
}

/*
	6.3		Dane s� 2 liczby rzeczywste a i b. Napisz funkcj� obliczaj�c�:
	a)		minimaln� warto�� z tych liczb		
*/
double zad_6_3_a(double a, double b) {
	return a < b ? a : b;
}

/*
	6.2		Napisa� funkcj� wyznaczaj�c� dla danej liczby naturalnej n:
	c)		znak		
*/
int zad_6_2_c(int liczba) {
	if(liczba < 0){
		return -1;
	} else if (liczba > 0){
		return 1;
	} else {
		return 0;
	}
}

/*
	6.2		Napisa� funkcj� wyznaczaj�c� dla danej liczby naturalnej n:
	b)		silnie		
*/
int zad_6_2_b(int liczba) {
	int i, silnia=1;
	if(liczba == 0){
		return silnia;
	}
	for(i=1; i<=liczba; i++){
		silnia*=i;
	}
	return silnia;
}

/*
	6.2		Napisa� funkcj� wyznaczaj�c� dla danej liczby naturalnej n:
	a)		jej warto�� bezwzgl�dn�		
*/
int zad_6_2_a(int liczba) {
	if(liczba < 0){
		return (0 - liczba);
	} else {
		return liczba;
	}
}

/*
	6.1		Napisa� funkcj�, kt�ra okre�la czy zmienna znakowa jest liter� czy nie. Wykorzystaj j� w programie do usuwania z ci�g�w znak�w
			wszystkich znak�w nie b�d�cych literami.
	
	W kodzie ASCII 65-90 litery wielkie, 97-122 litery ma�e
	int getchar(); - funkcja z biblioteki stdio.h, czyta jeden znak wci�ni�ty przez u�ytkownika i zwraca go w postaci odpowiadaj�cego kodu ASCII, zwracany typ liczbowy int
			
*/
int zad_6_1(char znak) {
    if((znak >= 65 && znak <= 90) || (znak >= 97 && znak <= 122)){
    	return 1;
	} else {
		return 0;
	}
}

int main(int argc, char *argv[]) {
	int i,j;
	//zad_6_1('1');
	//zad_6_2_a(-28);
	//zad_6_2_b(3);
	//zad_6_2_c(3);
	//zad_6_3_a(3.5, 4.12);
	//zad_6_3_b(3.5, 4.12);
	//zad_6_3_c(3.5, 4.12);
	//zad_6_3_d(3.5, 4.12);
	//zad_6_4(3.0, 4.0, 5.0);
	//test_zad_6_5_a();
	//test_zad_6_5_b();
	//test_zad_6_5_c();
	//test_zad_6_5_d();
	printf("%lf", zad_6_6_a(3.14));

	return 0;
}
