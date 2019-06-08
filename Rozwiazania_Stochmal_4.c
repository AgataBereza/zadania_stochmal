#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
	Funkcja zwraca liczbê losow¹ z przedzia³u od "lower" do "upper"
	
	Standardowo random() zwraca liczbê od o do RAND_MAX = 32767, aby uzyskaæ iloœæ losowych liczb z zadanego zakresu od a do b,
	nale¿y najpierw wykonaæ operacjê  rand() % upper - lower + 1, co zwroci liczbê z zakresu od 0 do upper - lower + 1,
	ale jako ¿e nasz przedzia³ nie zaczyna siê od 0 tylko od "lower" to do wyniku nale¿y dodaæ wartoœæ "lower"
*/
int randomFromRange(int lower, int upper) {
	return (rand() % (upper - lower + 1)) + lower; 
}

/*
	4.4	Prawdopodobieñstwo trafienia w tarczê wynosi 0,5 (czyli fifty-fifty ;-) wiêc mo¿emy wylosowaæ 0 lub 1).
		Wyznacz na podstawie 10000 strza³ów (wykorzystuj¹c generator liczb losowych), jakie jest prawdopodobieñstwo:
	d)	nie trafienia ani razu przy oddaniu 10 strza³ów
	
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
	printf("Na podstawie %d kolejnych strza³ów prawdopodobieñstwo nie trafienia ani razu przy oddaniu 10 strza³ów wynios³o: %lf\n", n, p);
}

/*
	4.4	Prawdopodobieñstwo trafienia w tarczê wynosi 0,5 (czyli fifty-fifty ;-) wiêc mo¿emy wylosowaæ 0 lub 1).
		Wyznacz na podstawie 10000 strza³ów (wykorzystuj¹c generator liczb losowych), jakie jest prawdopodobieñstwo:
	c)	trafienia dok³adnie 10 razy
	
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
	printf("Na podstawie %d kolejnych strza³ów prawdopodobieñstwo trafienia dok³adnie 10 razy wynios³o: %lf\n", n, p);
}

/*
	4.4	Prawdopodobieñstwo trafienia w tarczê wynosi 0,5 (czyli fifty-fifty ;-) wiêc mo¿emy wylosowaæ 0 lub 1).
		Wyznacz na podstawie 10000 strza³ów (wykorzystuj¹c generator liczb losowych), jakie jest prawdopodobieñstwo:
	b)	trafienia dok³adnie 5 razy
	
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
	printf("Na podstawie %d kolejnych strza³ów prawdopodobieñstwo trafienia dok³adnie 5 razy wynios³o: %lf\n", n, p);
}

/*
	4.4	Prawdopodobieñstwo trafienia w tarczê wynosi 0,5 (czyli fifty-fifty ;-) wiêc mo¿emy wylosowaæ 0 lub 1).
		Wyznacz na podstawie 10000 strza³ów (wykorzystuj¹c generator liczb losowych), jakie jest prawdopodobieñstwo:
	b)	trafienia dok³adnie 5 razy
	
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
	printf("Na podstawie %d kolejnych strza³ów prawdopodobieñstwo trafienia co najmniej 5 razy wynios³o: %lf\n", n, p);
}

/*
	4.3	Napisz program, który sprawdza na podstawie:
	b)	1000 rzutów dwiema kostkami do gry, jakie jest prawdopodobieñstwo wyrzucenia dwóch 6-tek
		
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
	printf("Na podstawie %d kolejnych rzutów dwiema kostkami prawdopodobieñstwo wyrzucenia dwóch 6 wynios³o: %lf\n", n, (licznik*1.0/n));
}

/*
	4.3	Napisz program, który sprawdza na podstawie:
	a)	1000 rzutów kostk¹ do gry, jakie jest prawdopodobieñstwo wyrzucenia 6
		
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
	printf("Na podstawie %d kolejnych rzutów kostk¹ prawdopodobieñstwo wyrzucenia 6 wynios³o: %lf\n", n, (licznik*1.0/n));
}

/*
	4.2	Napisz program, który wyœwietli 50 kolejnych rzutów kostk¹
		
*/
void zad_4_2() {
	int i, n = 50;
	srand(time(NULL));	// inicjalizacja randomizera
	printf("%d kolejnych rzutów kostk¹:\n");
	for(i = 0; i < n; i++){
		printf("%d ", randomFromRange(1,6));
	}
}

/*
	4.1	Napisz program symuluj¹cy rzut:
	b)	kostk¹ do gry
		
*/
int zad_4_1_b() {
	int wynik;
	srand(time(NULL));	// inicjalizacja randomizera
	return randomFromRange(1,6);
}


/*
	4.1	Napisz program symuluj¹cy rzut:
	a)	monet¹ (0 - orzel, 1 - reszka)
	
	Dodanie biblioteki <time.h> pozwoli nam na inicjalizacjê niezbêdn¹ do generowania liczb losowych typu int przy u¿yciu funkcji rand()
	Sama funkcja rand() znajduje siê w bibliotece <stdlib.h>. Funkcja ta zwraca kolejn¹ liczbê pseudolosow¹.
	Aby ustawiæ zarodek ci¹gu liczb pseudolosowych, nale¿y pos³u¿yæ siê funkcj¹ srand.
	Aby otrzymaæ liczbê z mniejszego przedzia³u, nale¿y pos³u¿yæ siê operatorem modulo (%) lub operacjami na liczbach rzeczywistych.
	
	np. liczba pseudolosowa z przedzia³u <0, 99> to  rand() % 100;
	
	zwracany typ danych  funkcji to char* czyli wskaŸnik na tablice znakow = ³añcuch = string

		
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
