#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
