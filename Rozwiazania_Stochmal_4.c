#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
	Funkcja zwraca liczb� losow� z przedzia�u od "lower" do "upper"
	
	Standardowo random() zwraca liczb� od o do RAND_MAX = 32767, aby uzyska� ilo�� losowych liczb z zadanego zakresu od a do b,
	nale�y najpierw wykona� operacj�  rand() % upper - lower + 1, co zwroci liczb� z zakresu od 0 do upper - lower + 1,
	ale jako �e nasz przedzia� nie zaczyna si� od 0 tylko od "lower" to do wyniku nale�y doda� warto�� "lower"
*/
int randomFromRange(int lower, int upper) {
	return (rand() % (upper - lower + 1)) + lower; 
}

/*
	4.4	Prawdopodobie�stwo trafienia w tarcz� wynosi 0,5 (czyli fifty-fifty ;-) wi�c mo�emy wylosowa� 0 lub 1).
		Wyznacz na podstawie 10000 strza��w (wykorzystuj�c generator liczb losowych), jakie jest prawdopodobie�stwo:
	d)	nie trafienia ani razu przy oddaniu 10 strza��w
	
	1 - trafiona, 0 - nie trafiona
		
*/
void zad_4_4_c() {
	int i, n = 10000, licznik = 0, trafiona;
	double p = 0.0;
	srand(time(NULL));	// inicjalizacja randomizera
	for(i = 0; i < n; i++){
		trafiona = randomFromRange(0,1);
		if(trafiona == 1){
			licznik++;
		}
		if(i % 10 == 9){
			if(licznik == 0){
				p+=1.0/1000;
			}
			licznik = 0;
		}
	}
	printf("Na podstawie %d kolejnych strza��w prawdopodobie�stwo nie trafienia ani razu przy oddaniu 10 strza��w wynios�o: %lf\n", n, p);
}

/*
	4.4	Prawdopodobie�stwo trafienia w tarcz� wynosi 0,5 (czyli fifty-fifty ;-) wi�c mo�emy wylosowa� 0 lub 1).
		Wyznacz na podstawie 10000 strza��w (wykorzystuj�c generator liczb losowych), jakie jest prawdopodobie�stwo:
	c)	trafienia dok�adnie 10 razy
	
	1 - trafiona, 0 - nie trafiona
		
*/
void zad_4_4_c() {
	int i, n = 10000, licznik = 0, trafiona;
	double p = 0.0;
	srand(time(NULL));	// inicjalizacja randomizera
	for(i = 0; i < n; i++){
		trafiona = randomFromRange(0,1);
		if(trafiona == 1){
			licznik++;
		}
	}
	if(licznik == 10){
		p = 10.0/n;
	}
	printf("Na podstawie %d kolejnych strza��w prawdopodobie�stwo trafienia dok�adnie 10 razy wynios�o: %lf\n", n, p);
}

/*
	4.4	Prawdopodobie�stwo trafienia w tarcz� wynosi 0,5 (czyli fifty-fifty ;-) wi�c mo�emy wylosowa� 0 lub 1).
		Wyznacz na podstawie 10000 strza��w (wykorzystuj�c generator liczb losowych), jakie jest prawdopodobie�stwo:
	b)	trafienia dok�adnie 5 razy
	
	1 - trafiona, 0 - nie trafiona
		
*/
void zad_4_4_b() {
	int i, n = 10000, licznik = 0, trafiona;
	double p = 0.0;
	srand(time(NULL));	// inicjalizacja randomizera
	for(i = 0; i < n; i++){
		trafiona = randomFromRange(0,1);
		if(trafiona == 1){
			licznik++;
		}
	}
	if(licznik == 5){
		p = 5.0/n;
	}
	printf("Na podstawie %d kolejnych strza��w prawdopodobie�stwo trafienia dok�adnie 5 razy wynios�o: %lf\n", n, p);
}

/*
	4.4	Prawdopodobie�stwo trafienia w tarcz� wynosi 0,5 (czyli fifty-fifty ;-) wi�c mo�emy wylosowa� 0 lub 1).
		Wyznacz na podstawie 10000 strza��w (wykorzystuj�c generator liczb losowych), jakie jest prawdopodobie�stwo:
	b)	trafienia dok�adnie 5 razy
	
	1 - trafiona, 0 - nie trafiona
		
*/
void zad_4_4_a() {
	int i, n = 10000, licznik = 0, trafiona;
	double p = 0.0;
	srand(time(NULL));	// inicjalizacja randomizera
	for(i = 0; i < n; i++){
		trafiona = randomFromRange(0,1);
		if(trafiona == 1){
			licznik++;
		}
	}
	if(licznik >= 5){
		p = (licznik-4)*1.0/n;
	}
	printf("Na podstawie %d kolejnych strza��w prawdopodobie�stwo trafienia co najmniej 5 razy wynios�o: %lf\n", n, p);
}

/*
	4.3	Napisz program, kt�ry sprawdza na podstawie:
	b)	1000 rzut�w dwiema kostkami do gry, jakie jest prawdopodobie�stwo wyrzucenia dw�ch 6-tek
		
*/
void zad_4_3_b() {
	int i, n = 1000, licznik = 0, wylosowana1, wylosowana2;
	srand(time(NULL));	// inicjalizacja randomizera
	for(i = 0; i < n; i++){
		wylosowana1 = randomFromRange(1,6);
		wylosowana2 = randomFromRange(1,6);
		if(wylosowana1 == 6 && wylosowana2 == 6){
			licznik++;
		}
	}
	printf("Na podstawie %d kolejnych rzut�w dwiema kostkami prawdopodobie�stwo wyrzucenia dw�ch 6 wynios�o: %lf\n", n, (licznik*1.0/n));
}

/*
	4.3	Napisz program, kt�ry sprawdza na podstawie:
	a)	1000 rzut�w kostk� do gry, jakie jest prawdopodobie�stwo wyrzucenia 6
		
*/
void zad_4_3_a() {
	int i, n = 1000, licznik = 0, wylosowana;
	srand(time(NULL));	// inicjalizacja randomizera
	for(i = 0; i < n; i++){
		wylosowana = randomFromRange(1,6);
		if(wylosowana == 6){
			licznik++;
		}
	}
	printf("Na podstawie %d kolejnych rzut�w kostk� prawdopodobie�stwo wyrzucenia 6 wynios�o: %lf\n", n, (licznik*1.0/n));
}

/*
	4.2	Napisz program, kt�ry wy�wietli 50 kolejnych rzut�w kostk�
		
*/
void zad_4_2() {
	int i, n = 50;
	srand(time(NULL));	// inicjalizacja randomizera
	printf("%d kolejnych rzut�w kostk�:\n");
	for(i = 0; i < n; i++){
		printf("%d ", randomFromRange(1,6));
	}
}

/*
	4.1	Napisz program symuluj�cy rzut:
	b)	kostk� do gry
		
*/
int zad_4_1_b() {
	int wynik;
	srand(time(NULL));	// inicjalizacja randomizera
	return randomFromRange(1,6);
}


/*
	4.1	Napisz program symuluj�cy rzut:
	a)	monet� (0 - orzel, 1 - reszka)
	
	Dodanie biblioteki <time.h> pozwoli nam na inicjalizacj� niezb�dn� do generowania liczb losowych typu int przy u�yciu funkcji rand()
	Sama funkcja rand() znajduje si� w bibliotece <stdlib.h>. Funkcja ta zwraca kolejn� liczb� pseudolosow�.
	Aby ustawi� zarodek ci�gu liczb pseudolosowych, nale�y pos�u�y� si� funkcj� srand.
	Aby otrzyma� liczb� z mniejszego przedzia�u, nale�y pos�u�y� si� operatorem modulo (%) lub operacjami na liczbach rzeczywistych.
	
	np. liczba pseudolosowa z przedzia�u <0, 99> to  rand() % 100;
	
	zwracany typ danych  funkcji to char* czyli wska�nik na tablice znakow = �a�cuch = string

		
*/
char* zad_4_1_a() {
	int wynik;
	srand(time(NULL));	// inicjalizacja randomizera
	wynik = rand() % 2;	// % 2 spowoduje, ze bedziemy zwracac reszte z dzielenia wylosowanej liczby 2, czyli albo 0 albo 1
	return wynik == 0 ? "orzel" : "reszka";
}


int main(int argc, char *argv[]) {
	//printf("Wylosowano %s\n", zad_4_1_a());
	//printf("Wylosowano %d\n", zad_4_1_b());
	//zad_4_2();
	//zad_4_3_a();
	//zad_4_3_b();
	//zad_4_4_a();
	//zad_4_4_b();
	//zad_4_4_c();
	zad_4_4_d();
	return 0;
}
