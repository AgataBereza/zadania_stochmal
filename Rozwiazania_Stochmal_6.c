#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
	//zad_6_1('1');
	//zad_6_2_a(-28);
	//zad_6_2_b(3);
	//zad_6_2_c(3);
	//zad_6_3_a(3.5, 4.12);
	//zad_6_3_b(3.5, 4.12);
	//zad_6_3_c(3.5, 4.12);
	//zad_6_3_d(3.5, 4.12);
	//zad_6_4(3.0, 4.0, 5.0);
	return 0;
}
