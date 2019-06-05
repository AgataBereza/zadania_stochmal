#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
	6.6		Oblicz przybli¿on¹ wartoœæ podanych funkcji dla dowolnej liczby rzeczywistej na podstawie rozwiniêcia w szereg Taylora.
			Obliczenia przerwij w momencie, gdy kolejny wyraz szeregu bêdzie mniejszy ni¿ e = 10^(-7). Kolejne wyrazy szeregu obliczaj rekurencyjnie,
			u³atwi to (czasem wrêcz umo¿liwi) obliczenia:
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
	6.5		Dane s¹ macierze A i B oraz liczba rzeczywista c. Napisaæ procedurê obliczaj¹c¹:
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
	
	zad_6_5_d(m,n,A,B,AB);						// wywo³ujemy nasz¹ metodê mno¿¹c¹ przez siebie dwie macierze
	
	for(i=0; i<m; i++){							// drukujemy wynikow¹ macierz w celu sprawdzenia poprawnosci dzia³ania programu	
		for(j=0; j<n; j++){
			printf("%lf ", AB[i][j]);
		}
		printf("\n");
	}
}

/*
	6.5		Dane s¹ macierze A i B oraz liczba rzeczywista c. Napisaæ procedurê obliczaj¹c¹:
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
	
	zad_6_5_c(m,n,A,B,AB,c);					// wywo³ujemy nasz¹ metodê dodaj¹c¹ do siebie dwie macierze
	
	for(i=0; i<m; i++){							// drukujemy sobie wynikow¹ macierz w celu sprawdzenia poprawnosci dzia³ania programu	
		for(j=0; j<n; j++){
			printf("%lf ", AB[i][j]);
		}
		printf("\n");
	}
}

/*
	6.5		Dane s¹ macierze A i B oraz liczba rzeczywista c. Napisaæ procedurê obliczaj¹c¹:
	b)		ró¿nicê tych macierzy 
	
	Macierze mo¿na do siebie dodawaæ tylko jeœli s¹ tego samego rozmiaru, Ÿród³o informacji:
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
	
	zad_6_5_b(m,n,A,B,AB,1);					// wywo³ujemy nasz¹ metodê dodaj¹c¹ do siebie dwie macierze
	
	for(i=0; i<m; i++){							// drukujemy sobie wynikow¹ macierz w celu sprawdzenia poprawnosci dzia³ania programu	
		for(j=0; j<n; j++){
			printf("%lf ", AB[i][j]);
		}
		printf("\n");
	}
}

/*
	6.5		Dane s¹ macierze A i B oraz liczba rzeczywista c. Napisaæ procedurê obliczaj¹c¹:
	a)		sumê tych macierzy 
	
	Macierze mo¿na do siebie dodawaæ tylko jeœli s¹ tego samego rozmiaru, Ÿród³o informacji:
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
	
	zad_6_5_a(m,n,A,B,AB,1);					// wywo³ujemy nasz¹ metodê dodaj¹c¹ do siebie dwie macierze
	
	for(i=0; i<m; i++){							// drukujemy sobie wynikow¹ macierz w celu sprawdzenia poprawnosci dzia³ania programu	
		for(j=0; j<n; j++){
			printf("%lf ", AB[i][j]);
		}
		printf("\n");
	}
}

/*
	6.4		Napisz funkcjê, która oblicza pole trójk¹ta zbudowanego z boków o d³ugosciach a, b, c.
			Jeœli taki trójk¹t nie istnieje, to wartoœæ funkcji niech przyjmuje wartoœæ -1;
			
			Z boków o danych d³ugoœciach a,b i c mo¿na utworzyæ trójk¹t gdy:
			a+b>c, a+c>b, b+c>a
*/
double zad_6_4(double a, double b, double c) {
	double p, pole;
	if(a+b>c && a+c>b && b+c>a){
		p = (a+b+c)*1.0/2;								// definiujemy sobie zmienn¹ pomocnicz¹ p równ¹ po³owie obwodu trójk¹ta, w celu wiêkszej czytelnoœci dzia³añ
		pole = sqrt(p*(p-a)*(p-b)*(p-c));			// obliczenie pola dowolnego trójk¹ta
		return pole;
	} else {
		return -1;
	}
}

/*
	6.3		Dane s¹ 2 liczby rzeczywste a i b. Napisz funkcjê obliczaj¹c¹:
	d)		œredni¹ geometryczn¹ z ich wartoœci bezwzglêdnych
	
	Œrednia geometryczna to pierwiastek stopnia równego iloœci liczb z iloczynu tych liczb
*/
double zad_6_3_d(double a, double b) {
	return sqrt(fabs(a)*fabs(b));
}

/*
	6.3		Dane s¹ 2 liczby rzeczywste a i b. Napisz funkcjê obliczaj¹c¹:
	c)		ich œredni¹ arytmetyczn¹	
*/
double zad_6_3_c(double a, double b) {
	return (a+b)/2;
}

/*
	6.3		Dane s¹ 2 liczby rzeczywste a i b. Napisz funkcjê obliczaj¹c¹:
	b)		maksymaln¹ wartoœæ z tych liczb		
*/
double zad_6_3_b(double a, double b) {
	return a > b ? a : b;
}

/*
	6.3		Dane s¹ 2 liczby rzeczywste a i b. Napisz funkcjê obliczaj¹c¹:
	a)		minimaln¹ wartoœæ z tych liczb		
*/
double zad_6_3_a(double a, double b) {
	return a < b ? a : b;
}

/*
	6.2		Napisaæ funkcjê wyznaczaj¹c¹ dla danej liczby naturalnej n:
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
	6.2		Napisaæ funkcjê wyznaczaj¹c¹ dla danej liczby naturalnej n:
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
	6.2		Napisaæ funkcjê wyznaczaj¹c¹ dla danej liczby naturalnej n:
	a)		jej wartoœæ bezwzglêdn¹		
*/
int zad_6_2_a(int liczba) {
	if(liczba < 0){
		return (0 - liczba);
	} else {
		return liczba;
	}
}

/*
	6.1		Napisaæ funkcjê, która okreœla czy zmienna znakowa jest liter¹ czy nie. Wykorzystaj j¹ w programie do usuwania z ci¹gów znaków
			wszystkich znaków nie bêd¹cych literami.
	
	W kodzie ASCII 65-90 litery wielkie, 97-122 litery ma³e
	int getchar(); - funkcja z biblioteki stdio.h, czyta jeden znak wciœniêty przez u¿ytkownika i zwraca go w postaci odpowiadaj¹cego kodu ASCII, zwracany typ liczbowy int
			
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
