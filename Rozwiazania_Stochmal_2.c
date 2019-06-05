#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
	2.29	Dysponujemy zestawem dowolnej iloœci banknotow o nomina³ach: 1, 2, 5, 10, 20, 50 i 100 z³.
			Podaæ, jak wyp³aciæ n z³ bior¹c najmniejsz¹ iloœæ banknotów.
			
			Pewnie mo¿na to zrobiæ lepiej, ja to zrobi³am ³opatologicznie.
			
*/
void zad_2_29() {
	int n, pomocnicza, suma=0;
	printf("Podaj liczbe naturalna n:\n");
	scanf("%d", &n);
	pomocnicza = n;
	while(suma != n){
		if(pomocnicza >= 100){
			suma+=100;
			pomocnicza-=100;
			printf("100, ");
			continue;
		} 
		if(pomocnicza >= 50){
			suma+=50;
			pomocnicza-=50;
			printf("50, ");
			continue;
		}
		if(pomocnicza >= 20){
			suma+=20;
			pomocnicza-=20;
			printf("20, ");
			continue;
		}
		if(pomocnicza >= 10){
			suma+=10;
			pomocnicza-=10;
			printf("10, ");
			continue;
		}
		if(pomocnicza >= 5){
			suma+=5;
			pomocnicza-=5;
			printf("5, ");
			continue;
		}
		if(pomocnicza >= 2){
			suma+=2;
			pomocnicza-=2;
			printf("2, ");
			continue;
		} else {
			suma+=1;
			pomocnicza-=1;
			printf("1, ");
			continue;
		}
	}	
}

/*
	2.28	Wyznacz pierwiastek kwadratowy z zadanej liczby A, stosuj¹c algorytm Herona.
			W pierwszym kroku przybli¿amy wartoœæ sqrt(A) liczb¹ a1. Jeœli a1< sqrtA), to A/a1 > sqrt(A),
			i na odwrót: jeœli a1 > sqrt(A), to A/a1 < sqrt(A). Zatem dok³adna wartoœæ pierwiastka le¿y miêdzy wartoœciami
			a1 i A/a1, wiêc kolejne przybli¿enie piarwiastka mo¿e byæ wziête jako œrednia arytmetyczna obu krañców przedzia³u:
			a2=(a1+A/a1)/2. Kolejne przybli¿enia mo¿emy zapisaæ jako an+1=(an+A/an)/2. W obliczeniach przyjmij dok³adnoœæ e np 10^(-6)
			rozumian¹ jako ró¿nicê miêdzy liczbami an i A/an.
			
*/
void zad_2_28() {
	double a, x, alternatywa, blad, epsilon; 
	printf("Podaj liczbe rzeczywista, z ktorej chcesz obliczyc pierwiastek kwadratowy: \n");
	scanf("%lf",&a);
	/*epsilon to bardzo mala liczba, im mniejsza tym dokladniejszy wynik uzyskujemy
	zapis 1e-15 jest rownoznaczny z 
	*/
	epsilon = 1e-15;
	x=1.0;
	do {
		x=(x+(a/x))/2.0;
	} while (fabs((x-(a/x))) >= x*epsilon);
	
	printf("Pierwiastek kwadratowy z liczby %lf wynosi %lf.\n",a,x);
	alternatywa=sqrt(a);
	blad=(fabs(alternatywa-x))/alternatywa;
	printf("Blad wzgledny wynosi %lf.\n",blad);	
}


int sumaDzielnikowWlasciwych(int liczba){
	int i, suma = 0;
	if(liczba == 1){
		return 1;
	}
	for(i=1; i<liczba; i++){
		if(liczba % i ==0){
			suma+=i;
		}
	}
	return suma;
}


/*
	2.27	Dana jest liczba naturana n. ZnaleŸæ wszystkie liczby naturalne k mniejsze od n,
			dla których suma podzielników k jest równa danej liczbie k.
			
			Liczba doskona³a – liczba naturalna, która jest sum¹ wszystkich swych dzielników w³aœciwych 
			(to znaczy od niej mniejszych). Najmniejsz¹ liczb¹ doskona³¹ jest 6, poniewa¿ 6 = 3 + 2 + 1. 
			Nastêpn¹ jest 28 (28 = 14 + 7 + 4 + 2 + 1), a kolejne to 496, 8128, 33550336, 8589869056 i 137438691328.
			
*/
void zad_2_27() {
	int n, k, suma;
	printf("Podaj liczbe naturalna n:\n");
	scanf("%d", &n);
	printf("Liczby mniejsze od n=%d, których suma podzielników jest równa samej tej liczbie to:\n",n);
	for(k=1; k<n; k++){
		suma = sumaDzielnikowWlasciwych(k);
		if(suma == k){
			printf("Liczba: %d.\n", k);
		}
	}	
}


//Jeœli liczba jest pierwsza to zwracamy 1, w przeciwnym wypadku 0
int jestPierwsza(int liczba){
	int i;
	for(i=2;i<liczba;i++){
		if(liczba % i == 0){
			return 0;
		}
	}
	return 1;
}

/*
	2.26	Dane s¹ 2 liczby naturalne a i b (b > a). ZnaleŸæ wszystkie liczby pierwsze miêdzy a i b.
			
*/
void zad_2_26() {
	int i, a, b;
	printf("Podaj liczbe naturalna a:\n");
	scanf("%d", &a);
	printf("Podaj liczbe naturalna b > a:\n");
	scanf("%d", &b);
	printf("Miêdzy liczbami a=%d i b=%d wystêpujê nastêpuj¹ce liczby pierwsze:\n",a,b);
	for(i=a+1; i<b; i++){
		if(jestPierwsza(i) == 1){
			printf("%d, ",i);
		}
	}	
}

/*
	2.25	Twierdzenie lagrange'a mówi, ¿e ka¿d¹ naturaln¹ liczbê n mo¿na zapisaæ za pomoc¹ sumy kwadratów
			4 liczb naturalnych (wraz z zerem): n = x^2 + y^2 + z^2 + t^2. ZnaleŸæ takie liczby dla zadanego n. 
			
*/
void zad_2_25() {
	int n, x=0, y=0, z=0, t=0;
	char czyZnaleziono = 'n';
	printf("Podaj liczbe naturalna:\n");
	scanf("%d", &n);
	for(x=0; x<=n; x++){
		for(y=0; y<=n; y++){
			for(z=0; z<=n; z++){
				for(t=0; t<=n; t++){
					if((x*x)+(y*y)+(z*z)+(t*t) == n){
						printf("n = %d = %d^2 + %d^2 + %d^2 + %d^2..\n", n, x, y, z, t);
						czyZnaleziono = 't';
						break;
					}
				}
			}
			
		}
	}
	if(czyZnaleziono == 'n'){
		printf("Nie znaleziono takiej liczby.\n");
	}	
}

/*
	2.24	Dana jest liczba naturalna n. Czy mo¿na j¹ przedstawiæ za pomoc¹ sumy kwadratów 3 liczb naturalnych:
			n = x^2 + y^2 + z^2, Jeœli mo¿na to:
	a)		znaleŸæ takie liczby x, y, z
	b)		znaleŸæ wszystkie takie trójki
	
	Uwaga: Program od razu znajduje wszystkie trójki liczb i na bie¿¹co wypisuje je na ekran
			
*/
void zad_2_24_ab() {
	int i, j, k, n, x=0, y=0, z=0;
	char czyZnaleziono = 'n';
	printf("Podaj liczbe naturalna:\n");
	scanf("%d", &n);
	for(i=0; i<=n; i++){
		x=i;
		for(j=0; j<=n; j++){
			y=j;
			for(k=0; k<=n; k++){
				if((x*x)+(y*y)+(z*z) == n){
					printf("n = %d = %d^2 + %d^2 + %d^2.\n", n, x, y, z);
					czyZnaleziono = 't';
					break;
				}
			}
			
		}
	}
	if(czyZnaleziono == 'n'){
		printf("Nie znaleziono takiej liczby.\n");
	}	
}

/*
	2.23	Dan¹ liczbê naturaln¹ n przedstawiæ w postaci sumy szeœcianów 2 liczb naturalnych x i y (x, y): n = x^3+y^3
			
*/
void zad_2_23() {
	int i, j, n, x=0, y=0;
	char czyZnaleziono = 'n';
	printf("Podaj liczbe naturalna:\n");
	scanf("%d", &n);
	for(i=0; i<=n; i++){
		x=i;
		for(j=0; j<=n; j++){
			y=j;
			if((x*x*x)+(y*y*y) == n){
				printf("n = %d = %d^3 + %d^3.\n", n, x, y);
				czyZnaleziono = 't';
				break;
			}
			
		}
	}
	if(czyZnaleziono == 'n'){
		printf("Nie znaleziono takiej liczby.\n");
	}	
}

/*
	2.22	Dana jest liczba naturalna n. Czy mozna j¹ zapisaæ za pomoc¹ sumy kwadratów 2 liczb naturalnych: n = x^2 + y^2?
			Jeœli mo¿na to:
	a)		znaleŸæ tak¹ parê liczb x i y
	b)		znaleŸæ wszystkie pary takich liczb
	
	Uwaga: Program od razu znajduje wszystkie pary liczb i na bie¿¹co wypisuje je na ekran
*/
void zad_2_22_ab() {
	int i, j, n, x=0, y=0;
	char czyZnaleziono = 'n';
	printf("Podaj liczbe naturalna:\n");
	scanf("%d", &n);
	for(i=0; i<=n; i++){
		x=i;
		for(j=0; j<=n; j++){
			y=j;
			if((x*x)+(y*y) == n){
				printf("Dla liczby n=%d znaleziono x=%d i y=%d.\n", n, x, y);
				czyZnaleziono = 't';
				break;
			}
			
		}
	}
	if(czyZnaleziono == 'n'){
		printf("Nie znaleziono takiej liczby.\n");
	}	
}


/*
	2.21	Oblicz przybli¿on¹ wartoœæ nieskoñczonych szeregów. Obliczenia przerwij w momencie,
			gdy wartoœæ bezwzglêdna kolejnego wyrazu szeregu bêdzie mniejsza od zadanej dok³adnoœci e=10^(-7)
	d)		suma od i=1 do nieskoñczonoœci (-2)^i/i! - w tym zadaniu nalezy zauwa¿yæ,
			ze kazdy kolejny wyraz to poprzedni wyraz pomno¿ony przez (-2/i) czyli np. i1=(-2.0)/i to i2=i1*((-2)/i)
*/
void zad_2_21_d() {
	int i = 1;
	double wyraz = 0, suma = 0, e=(1.0/pow(10,7));
	wyraz=pow(-2, i)/i;
	while(fabs(wyraz) > e){
		i++;
		wyraz = wyraz*((-2.0)/i);
		suma += wyraz;
		printf("suma %lf, wyraz %lf\n", suma, wyraz);

	}
	printf("Przybli¿ona suma to: %lf.\n", suma);
}

/*
	2.21	Oblicz przybli¿on¹ wartoœæ nieskoñczonych szeregów. Obliczenia przerwij w momencie,
			gdy wartoœæ bezwzglêdna kolejnego wyrazu szeregu bêdzie mniejsza od zadanej dok³adnoœci e=10^(-7)
	c)		suma od i=1 do nieskoñczonoœci 1/i(i+1)
*/
void zad_2_21_c() {
	int i = 1;
	double mianownik, suma = 0, wyraz = 1, e=(1.0/pow(10,7));
	while(fabs(wyraz) > e){
		mianownik = i*(i+1);
		wyraz = 1.0/mianownik;
		suma += wyraz;
		i++;
	}
	printf("Przybli¿ona suma to: %lf.\n", suma);
}

//Program pomocniczy licz¹cy silniê z liczby
int silnia(int n) {
	int i, silnia = 1;
	for(i = 1; i <= n; i++){
		silnia*=i;
	}
	return silnia;	
}

/*
	2.21	Oblicz przybli¿on¹ wartoœæ nieskoñczonych szeregów. Obliczenia przerwij w momencie,
			gdy wartoœæ bezwzglêdna kolejnego wyrazu szeregu bêdzie mniejsza od zadanej dok³adnoœci e=10^(-7)
	b)		suma od i=1 do nieskoñczonoœci (-1)^i/i!
*/
void zad_2_21_b() {
	int i = 1;
	double licznik, mianownik, suma = 0, wyraz = 1, e=(1.0/pow(10,7));
	while(fabs(wyraz) > e){
		licznik = pow((-1.0), i);
		mianownik = silnia(i);
		wyraz = licznik/mianownik;
		suma += wyraz;
		i++;
	}
	printf("Przybli¿ona suma to: %lf.\n", suma);
}

/*
	2.21	Oblicz przybli¿on¹ wartoœæ nieskoñczonych szeregów. Obliczenia przerwij w momencie,
			gdy wartoœæ bezwzglêdna kolejnego wyrazu szeregu bêdzie mniejsza od zadanej dok³adnoœci e=10^(-7)
	a)		suma od i=1 do nieskoñczonoœci 1/i^2
*/
void zad_2_21_a() {
	int i = 1;
	double suma = 0, wyraz = 1, e=(1.0/pow(10,7));
	while(fabs(wyraz) > e){
		wyraz = 1.0/(i*i);
		suma += wyraz;
		i++;
	}
	printf("Przybli¿ona suma to: %lf.\n", suma);
}

/*
	2.20 	Dana jest naturalna liczba n. ZnajdŸ:
	a)		liczbê jej cyfr
	b)		sumê jej cyfr
	c)		pierwsz¹ (najbardziej znacz¹c¹) cyfrê tej liczby
*/
void zad_2_20_abc() {
	int n, liczbaCyfr = 0, sumaCyfr=0, ostatnia;
	printf("Podaj liczbe naturalna:\n");
	scanf("%d", &n);
	
	printf("Dla danej liczby n=%d.\n", n);
	if(n == 0){
		printf("Podana liczba to 0. Suma cyfr to 0, liczba cyfr to 1, najbardziej znacz¹ca to 0.\n");
	} else {
		while(n != 0){				// jak wykonujemy operacje na typie int, to jeœli zostanie nam ostatnia liczba z zakresu 0-9, po podzieleniu przez 10 bedzie rowna zero
			liczbaCyfr++;			// przy ka¿dym obrocie pêtli zwiêkszamy iloœæ cyfr
			ostatnia = n % 10;		// ze wstêpu do programowania wiemy, ¿e aby uzyskaæ skrajnie praw¹ cyfrê nale¿y zwróciæ resztê z dzielenia przez 10
			sumaCyfr += ostatnia;	// skoro zwróciliœmy skrajnie praw¹, to teraz dodajemy j¹ do sumy cyfr
			n = n / 10;				// nasze "n" dzielimy przez 10, by w nastêpnej iteracji sprawdziæ co zosta³o
		}
		printf("Liczba cyfr to: %d, suma cyfr to: %d, najbardziej znacz¹ca cyfra to: %d.\n",liczbaCyfr,sumaCyfr,ostatnia);
	}
}

/*
	2.18/2.19  ZnajdŸ wszystkie dzielniki/dzielniki pierwsza podanej liczby naturalnej
	
*/
void zad_2_18() {
	int i, n;
	printf("Podaj pierwsz¹ liczbê naturaln¹ n:\n");
	scanf("%d", &n);
	printf("Kolejne podzielniki danej liczby n=%d to: \n", n);
	i = 2;
	while(n != 1){
		if(n % i == 0){
			n = n / i;
			printf("%d\n", i);
		} else {
			i++;
		}	
	}
}


// Jest to funkcja pomocnicza u¿ywana w zadaniu 2_17 w celu obliczenia NWD
int NWD(int a, int b){
	int i, max, nwd = 1;
	max = a < b ? a : b; 		// zapis ten oznacza, ¿e je¿eli a<b to do zmiennej max podstawiamy "a", w przeciwnym wypadku "b"
	for(i=1; i<=max; i++){		// iteracjê rozpoczynami od 1 poniewa¿ 0 nie interesuje nas jako dzielnik
		if(a%i==0 && b%i==0){	// je¿eli obie liczby dziel¹ siê przez "i" bez reszty, to znaczy, ¿e "i" jest ich dzielnikiem
			nwd=i;
		}
	}
	return nwd;	
}

/*
	2.17  	Wczytaj dwie liczby naturalne i znajdz:
	a)		najwiekszy wspolny dzielnik tych liczb (NWD)
	b)		najmniejsz¹ wspóln¹ wielokrotnoœæ tych liczb (NWW)
	
	Znaj¹c NWD mo¿na ³atwo obliczyæ NWW ze wzoru NWW(a,b)=a*b/NWD(a,b)
	
*/
void zad_2_17_ab() {
	int i, a, b, nww=0, nwd=1, pomocznicza;
	printf("Podaj pierwsz¹ liczbê naturln¹ a:\n");
	scanf("%d", &a);
	printf("Podaj drug¹ liczbê naturaln¹ b:\n");
	scanf("%d", &b);
	if(a == b){
		printf("Liczby a=%d i b=%d s¹ sobie równe wiêc ich s¹ ich w³asnymi NWW i NWD.\n",a,b);
	} else if (a==0 || b==0){
		printf("Co najmniej jedna z podanych liczb jest równa 0, wiêc nie maj¹ ani NWW ani NWD.\n");
	} else {
		nwd=NWD(a,b);
		nww=a*b/nwd;
		printf("Liczby a=%d i b=%d maj¹ NWD=%d i NWW=%d.\n",a,b,nwd,nww);
	}
	
}



/*
	2.16  SprawdŸ czy wczytane trzy liczby rzeczywise, dodatnie a,b,c mog¹ tworzyæ trójk¹t, tzn. czy spe³nione s¹ jednoczeœnie relacje:
		a<b+c, b<c+a, c<b+a
	
*/
void zad_2_16() {
	double a, b, c;
	printf("Podaj pierwsz¹ liczbê rzeczywist¹ a:\n");
	scanf("%lf", &a);
	printf("Podaj drug¹ liczbê rzeczywist¹ b:\n");
	scanf("%lf", &b);
	printf("Podaj trzeci¹ liczbê rzeczywist¹ c:\n");
	scanf("%lf", &c);
	if(a<b+c && b<c+a && c<b+a){
		printf("Podane liczby mog¹ utworzyc trójk¹t.\n");
	} else {
		printf("Nie da rady.\n");
	}
}


// Jest to funkcja pomocnicza u¿ywana w zadaniu 2_15 w celu obliczenia sumy dzielników danej liczby
int suma_dzielnikow(int liczba){
	int i, suma = 0;
	if(liczba == 1){
		return 1;
	}
	i = 2;
	while(liczba != 1){
		if(liczba % i == 0){
			suma+=i;
			liczba/=i;
		} else {
			i++;
		}
	}
	return suma;
}
		


/*
	2.15  	ZnajdŸ naturaln¹ liczbê nale¿¹c¹ do przedzia³u 1-10000, której suma podzielników jest maksymalna - co to s¹ podzielniki?
			W matematyce s¹ tylko dzielniki.
			
			UWAGA! 1 nie jest uznawana ani za liczbê pierwsz¹, ani z³o¿on¹ - nie wystêpuje w rozk³adzie na czynniki pierwsze
	
			Sprawdzator liczb pierwszych: https://calculla.pl/liczba_pierwsza
	
*/
void zad_2_15() {
	int i, min = 1, max = 10000, pomocnicza = 0, maksymalna = 0, liczba;
	for(i = min; i <= max; i++){
		pomocnicza = suma_dzielnikow(i);		// w tym wierszu wo³amy dodatkow¹ funkcjê "suma_dzielnikow", która oblicza nam sumê dzielników dla podanej liczby
		if(pomocnicza > maksymalna){			// je¿eli obliczona suma jest wiêksza ni¿ dotyczasowa,
			maksymalna = pomocnicza;			// to zastêujêmy dotychczasow¹ sumê
			liczba = i;							// a do zmiennej"liczba" przypisujemy aktualnie sprawdzan¹ liczbê: i
		}
	}
	printf("Liczba, która ma najwiêksz¹ sumê podzielników równ¹ %d to %d.\n", maksymalna, liczba);
}

/*
	2.14  SprawdŸ podzielnoœæ wczytanej liczby naturalnej n przez zadan¹ liczbê naturaln¹ k
	
*/
void zad_2_14() {
	int n, k;
	printf("Podaj liczbe naturalna n:\n");
	scanf("%d", &n);
	printf("Podaj liczbe naturalna k:\n");
	scanf("%d", &k);
	if(n % k == 0){
		printf("n=%d jest podzielne przez k=%d bez reszty.\n",n,k);
	} else {
		printf("n=%d nie jest podzielne przez k=%d bez reszty.\n",n,k);
	}
}

/*
	2.13 	Okreœl iloœæ setek w zadanej liczbie naturalnej n > 99
	
*/
void zad_2_13() {
	int liczba, pomocnicza;
	printf("Podaj liczbe naturalna n > 99:\n");
	scanf("%d", &liczba);
	pomocnicza = liczba/100;	// dzielimy liczbê przez 100 aby pozbyc sie dziesiatek i jednosci
	printf("Iloœæ setek w liczbie n=%d wynosi %d.\n",liczba, pomocnicza % 10); //aby uzyskac ilosc setek zwracamy reszte z dzielenia liczby pomocniczej / 10
}

/*
	2.12 	SprawdŸ czy wczytana liczba naturalna jest:
	a)		dodatnia
	b)		parzysta
	c)		podzielna przez 3
*/
void zad_2_12_abc() {
	int liczba;
	printf("Podaj liczbe naturalna:\n");
	scanf("%d", &liczba);
	
	// podpunkt a
	if(liczba > 0){
		printf("Liczba %d jest dodatnia.\n", liczba);
	} else {
		printf("Liczba %d nie jest dodatnia.\n", liczba);
	}
	
	//podpunkt b
	if(liczba % 2 == 0){
		printf("Liczba %d jest parzysta.\n", liczba);
	} else {
		printf("Liczba %d nie jest parzysta.\n", liczba);
	}
	
	//podpunkt c
	if(liczba % 3 == 0){
		printf("Liczba %d jest podzielna przez 3 bez reszty.\n", liczba);
	} else {
		printf("Liczba %d nie jest podzielna przez 3 bez reszty.\n", liczba);
	}
}

/*
	2.11 	Dana jest liczba naturalna n i rzeczywista x(jedna z nich lub obie w zale¿noœci od podpunktu). Oblicz:
	g)		1*2 + 2*3*4 + ... + n*(n-1)*...*2n	nie kumam tego zapisu

*/
void zad_2_11_g() {
	printf("Chwa³a œmia³kom co to zrobi¹.\n");
}

/*
	2.11 	Dana jest liczba naturalna n i rzeczywista x(jedna z nich lub obie w zale¿noœci od podpunktu). Oblicz:
	f)		sin x + sin^2 x + ... + sin^n x	
	
	aby rozwi¹zaæ to zadanie nale¿y u¿yæ doœæ mocno rozbudowanej sumy szeregu, wiêc sobie podarujê =)
	wiêcej informacji tutaj: http://mathworld.wolfram.com/TrigonometricPowerFormulas.html
*/
void zad_2_11_f() {
	printf("Chwa³a œmia³kom co to zrobi¹.\n");
}


/*
	2.11 	Dana jest liczba naturalna n i rzeczywista x(jedna z nich lub obie w zale¿noœci od podpunktu). Oblicz:
	e)		1/x + 1/x^2 + 1/x^4 + ... + 1/x^2n	
	
	Biblioteka <math.h> udostêpnia nam funkcjê pow(), która umo¿liwia podniesienie liczby do dowolnej potêgo
	double pow (double x, double y);  x - liczba podnoszona do potêgi, y - wyk³adnik potêgi, typ przyjmowanych/zwracanych danych to double.
*/
void zad_2_11_e() {
	int i, n;
	double x, wynik;
	printf("Podaj liczbe naturalna n:\n");
	scanf("%d", &n);
	printf("Podaj liczbe rzeczywista x:\n");
	scanf("%lf", &x);
	wynik = 1.0/x;
	for(i=1; i <= n; i++){
		wynik+=1.0/(pow(x,2*i));
	}
	printf("Dla n=%d oraz x=%lf wynikiem dzia³ania 1/x + 1/x^2 + 1/x^4 + ... + 1/x^2n jest %lf.\n",n,x,wynik);
}

/*
	2.11 	Dana jest liczba naturalna n i rzeczywista x(jedna z nich lub obie w zale¿noœci od podpunktu). Oblicz:
	d)		x(x+1)...(x+n-1)	 
*/
void zad_2_11_d() {
	int i, n;
	double x, wynik = 1;
	printf("Podaj liczbe naturalna n:\n");
	scanf("%d", &n);
	printf("Podaj liczbe rzeczywista x:\n");
	scanf("%lf", &x);
	for(i=0;i<n;i++){
		wynik*=(x+i);
	}
	printf("Dla n=%d oraz x=%lf wynikiem dzia³ania x(x+1)...(x+n-1) jest %lf.\n",n,x,wynik);
}

/*
	2.11 	Dana jest liczba naturalna n i rzeczywista x(jedna z nich lub obie w zale¿noœci od podpunktu). Oblicz:
	c)		n!	 
*/
void zad_2_11_c() {
	int i, n, wynik = 1;
	printf("Podaj liczbe naturalna n:\n");
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		wynik=wynik*i;
	}
	printf("Dla n=%d n!=%d.\n",n,wynik);
}

/*
	2.11 	Dana jest liczba naturalna n i rzeczywista x(jedna z nich lub obie w zale¿noœci od podpunktu). Oblicz:
	b)		x^n	 
*/
void zad_2_11_b() {
	int i, n;
	double x, wynik;
	printf("Podaj liczbe naturalna n:\n");
	scanf("%d", &n);
	printf("Podaj liczbe rzeczywista x:\n");
	scanf("%lf", &x);
	wynik = x;
	if(n==0){
		wynik=1;
	} else {
		for(i=1; i<n; i++){
		wynik*=x;
		}
	}
	printf("Dla n=%d i x=%lf, x^n=%lf.\n",n,x,wynik);
}

/*
	2.11 	Dana jest liczba naturalna n i rzeczywista x(jedna z nich lub obie w zale¿noœci od podpunktu). Oblicz:
	a)		2^n	 
*/
void zad_2_11_a() {
	int i, n, wynik = 2;
	printf("Podaj liczbe naturalna n:\n");
	scanf("%d", &n);
	if(n==0){
		wynik=1;
	} else {
		for(i=1; i<n; i++){
		wynik*=2;
		}
	}
	printf("Dla n=%d, 2^n=%d.\n",n,wynik);
}

/*
	2.10 	Wyznacz pierwiastki dowolnego równania kwadratowego
	
			Równanie kwadratowe ma postaæ: ax^2 + bx + c = 0; a,b,c znane, x1, x2 - szukane
			
			delta = b^2 - 4ac
			x1 =(-b - sqrt(delta))/2a
			x2 =(-b + sqrt(delta))/2a		 
*/
void zad_2_10() {
	double a,b,c, delta,x1,x2;
	printf("Podaj wspó³czynnik a:\n");	
	scanf("%lf", &a);
	printf("Podaj wspó³czynnik b:\n");	
	scanf("%lf", &b);
	printf("Podaj wspó³czynnik c:\n");
	scanf("%lf", &c);
	delta=b*b-4*a*c;
	if(delta < 0){
		printf("Delta mniejsza od 0, sprzecznoœæ - równanie nie posiada pierwastków.\n");
	} else if (delta == 0){
		x1=x2=(-b*1.0)/(2*a);
		printf("Delta = 0, równanie ma jeden pierwiastek podwójny x1=x2=%lf.\n",x1);
	} else {
		x1=(-b-sqrt(delta))*1.0/(2*a);
		x2=(-b+sqrt(delta))*1.0/(2*a);
		printf("Delta > 0, równanie ma dwa pierwiastki x1=%lf, x2=%lf.\n",x1,x2);
	}
}

/*
	2.9 	Napisz program realizuj¹cy:
	b)		dzielenie 2 liczb naturalnych
			jeœli na komputerze mo¿liwe jest tylko dodawanie, odejmowanie i operacje logiczne typu sprawdzenia czy a=b, a>b lub a<b

			Liczby naturalne - liczby ca³kowite i dodatnie liczone od 0
			
			Zak³adamy, ¿e dzielimy pierwsz¹ liczbê przez drug¹: a/b
			Je¿eli operujemy na typach ca³kowitoliczbowych, to z góry mo¿emy za³o¿yæ, ¿e jeœli a=1 a b=2, a zatem a<b to wynikiem dzielenia a/b bêdzie 0
			
*/
void zad_2_9_b() {
	int i, a, b, pomocnicza, wynik = 0;				
	printf("Podaj pierwsz¹ liczbê:\n");	
	scanf("%d", &a);
	printf("Podaj drug¹ liczbê:\n");	
	scanf("%d", &b);
	if(a < b){
		printf("Wynikiem dzielenia a=%d / b=%d jest 0.\n",a,b);
	} else if(a==b){
		printf("Wynikiem dzielenia a=%d / b=%d jest 1, bo liczby s¹ sobie równe.\n",a,b);

	} else {
		pomocnicza = b;				// W zmiennej "pomocnicza" dodajemy do siebie kolejno "b" przez które dzielimy, dopóki jest ono mniejsze od "a"
		while(pomocnicza < a){
			pomocnicza+=b;			// w ka¿dym kolejnym obrocie pêtli do pomocniczej dodajemy b
			wynik++;				// wynik mówi nam o tym ile razy dodaliœmy do siebie "b" zanim przekroczyliœmy wartoœæ "a"
		}
		printf("Wynik dzielenia a=%d / b=%d = %d.\n",a,b,wynik);
	}	
}

/*
	2.9 	Napisz program realizuj¹cy:
	a)		mno¿enie 2 liczb naturalnych
			jeœli na komputerze mo¿liwe jest tylko dodawanie, odejmowanie i operacje logiczne typu sprawdzenia czy a=b, a>b lub a<b

			Liczby naturalne - liczby ca³kowite i dodatnie liczone od 0
			
			Mno¿enie liczb to inaczej ich dodawanie, np. 3*4 = 3+3+3+3, 2*5 = 2+2+2+2+2, mo¿emy wiêc za³o¿yæ,
			¿e druga z liczb bêdzie licznikiem pêtli.
			
*/
void zad_2_9_a() {
	int i,a,b, wynik = 0;				// Dobr¹ praktyk¹ jest inicjalizowaæ licznik/wynik konkretn¹ liczb¹ - w tym przypadku 0, unikniemy inicjalizacji losow¹ liczb¹
	printf("Podaj pierwsz¹ liczbê:\n");	
	scanf("%d", &a);
	printf("Podaj pierwsz¹ liczbê:\n");	
	scanf("%d", &b);
	for(i = 0; i < b; i++){
		wynik+=a;
	}
	printf("a=%d * b=%d = %d.\n",a,b,wynik);	
}

/*
	2.8 	Napisz program realizuj¹cy odejmowanie 2 liczb naturalnych, przy czym odjemnik jest mniejszy od odjemnej,
			jeœli na komputerze mo¿liwe jest tylko dodawanie i operacje logiczne typu sprawdzenia czy a=b, a>b lub a<b
			
			odjemna - liczba, od której odejmujemy liczbê
			odjemnik - liczba, któr¹ odejmujemy od odjemnej
			
			Liczby naturalne - liczby ca³kowite i dodatnie liczone od 0
			
			W tym zadaniu aby obliczyæ ró¿nicê wykorystamy pêtlê for i zmienn¹ ró¿nica,
			której wartoœæ bêdzie siê zwiêkszaæ o 1 za ka¿dym obrotem pêtli,
			dopóki mniejsza z liczb nie zrówna siê z wiêksz¹.
			
			W ten sposób przy wykorzystaniu dodawania obliczymy ró¿nicê 2 liczb.
			 
*/
void zad_2_8() {
	int i,a,b,roznica = 0;
	printf("Podaj pierwsz¹ liczbê naturaln¹ a:\n");	
	scanf("%d", &a);
	printf("Podaj drug¹ liczbê naturaln¹ b:\n");	
	scanf("%d", &b);
	if(a < b){
		for(i = a; i < b; i++){
			roznica++;
		}
		printf("Roznica w odejmowaniu b-a=%d, gdzie a=%d, a b=%d.\n",roznica,a,b);
	} else if (b < a){
			for(i = b; i < a; i++){
			roznica++;
		}
		printf("Roznica w odejmowaniu a-b=%d, gdzie a=%d, a b=%d.\n",roznica,a,b);
	} else {
		printf("Liczby s¹ sobie równe a=%d, b=%d.\n",a,b);
	}
}

/*
	2.7 	Wczytaj n kolejnych liczb rzeczywistych (double lub float) i oblicz:
	d)		sumê kwadratów tych liczb
		
*/
void zad_2_7_d() {
	int i, iloscLiczb;
	double liczba, sumaKwadratow = 0;
	printf("Podaj ile chcialbyœ wczytaæ liczb:\n");	
	scanf("%d", &iloscLiczb);
	for(i = 0; i < iloscLiczb; i++){
		printf("Podaj %d liczbê z %d liczb:\n", i+1, iloscLiczb);		
		scanf("%lf", &liczba);
		sumaKwadratow+=(liczba*liczba);
	}
	printf("Suma odwrotnoœci podanych liczb to: %lf.\n", sumaKwadratow);
}

/*
	2.7 	Wczytaj n kolejnych liczb rzeczywistych (double lub float) i oblicz:
	c)		sumê odwrotnoœci
	
	Dla pewnoœci, ¿e nie zgubimy czêœci dziesiêtnej przy obliczaniu odwrotnoœci dzielimy 1.0/liczbê a nie 1/liczbê
	
*/
void zad_2_7_c() {
	int i, iloscLiczb;
	double liczba, sumaOdwrotnosci = 0;
	printf("Podaj ile chcialbyœ wczytaæ liczb:\n");	
	scanf("%d", &iloscLiczb);
	for(i = 0; i < iloscLiczb; i++){
		printf("Podaj %d liczbê z %d liczb:\n", i+1, iloscLiczb);		
		scanf("%lf", &liczba);
		sumaOdwrotnosci+=1.0/liczba;
	}
	printf("Suma odwrotnoœci podanych liczb to: %lf.\n", sumaOdwrotnosci);
}

/*
	2.7 	Wczytaj n kolejnych liczb rzeczywistych (double lub float) i oblicz:
	b)		ich œredni¹ arytmetyczn¹
	
*/
void zad_2_7_b() {
	int i, iloscLiczb;
	double liczba, suma = 0;
	printf("Podaj ile chcialbyœ wczytaæ liczb:\n");	
	scanf("%d", &iloscLiczb);
	for(i = 0; i < iloscLiczb; i++){
		printf("Podaj %d liczbê z %d liczb:\n", i+1, iloscLiczb);		
		scanf("%lf", &liczba);
		suma+=liczba;
	}
	printf("Œrednia arytmetyczna podanych liczb to: %lf.\n", suma/iloscLiczb);
}

/*
	2.7 	Wczytaj n kolejnych liczb rzeczywistych (double lub float) i oblicz:
	a)		ich sumê
	
*/
void zad_2_7_a() {
	int i, iloscLiczb;
	double liczba, suma = 0;
	printf("Podaj ile chcialbyœ wczytaæ liczb:\n");	
	scanf("%d", &iloscLiczb);
	for(i = 0; i < iloscLiczb; i++){
		printf("Podaj %d liczbê z %d liczb:\n", i+1, iloscLiczb);		
		scanf("%lf", &liczba);
		suma+=liczba;
	}
	printf("Suma podanych liczb to: %lf.\n", suma);
}

/*
	2.6 	Wydrukuj tabliczkê mno¿enia w zakresie od 1 do 100
	
			Polecenie jest nieœcis³e, zak³adamy, ¿e bêdzie to tabliczka mno¿enia od 1 - 10 
			z wartoœciami koñcz¹cymi siê na 100.
			
			i - wiersz, j - kolumna
			
*/
void zad_2_6() {
	unsigned int i, j, min = 1, max = 10;
	for(i = 1; i <= 10; i++){				// Iterowanie po wierszach zaczynamy od 1, poniewa¿ nie interesuje nas 0
		for(j = 1; j <= 10; j++){			// z iterowaniem po kolumnach jest dok³adnie tak samo
			if(i == 1){						// je¿eli jesteœmy w 1-wszym wierszu, to nie chcemy mno¿yc, chcemy tylko wydrukowaæ kolejne liczby
				printf(" %d ", j);
			} else if (j == 1){				// je¿eli jesteœmy w 1-wszej kolumnie, to równie¿ nie chcemy mno¿yæ, tylko drukowaæ liczby
				printf(" %d ", i);
			} else {						// je¿eli jesteœmy w ka¿dym innym polu, to wykonujemy mno¿enie
				printf(" %d ", i*j);
			}
		}
		printf("\n");						// po przejœciu przez wszystkie kolumny w wierszu przechodzimy do nowej linii
	}
}

/*
	2.5 	Wczytaj n kolejnych liczb rzeczywistych (double lub float) i wybierz spoœród nich:
	b)		najmniejsz¹
	
	Biblioteka <math.h> umo¿liwia nam u¿ycie sta³ej +nieskoñczonoœæ lub -nieskoñczonoœæ,
	zapisujemy j¹ jako INFINITY (lub odpowiednio -INFINITY) i jest typu double
	
*/
void zad_2_5_b() {
	int i, iloscLiczb;
	double liczba, najmniejsza = INFINITY;				// pocz¹tkowo do zmiennej najmniejsza przypisujemy wartoœæ nieskoñczonoœæ, 
	printf("Podaj ile chcialbyœ wczytaæ liczb:\n");		// by mieæ z czym porównaæ pierwsz¹ odczytan¹ liczbê	
	scanf("%d", &iloscLiczb);
	for(i = 0; i < iloscLiczb; i++){
		printf("Podaj %d liczbê z %d liczb:\n", i+1, iloscLiczb);		
		scanf("%lf", &liczba);
		if(liczba  < najmniejsza){
			najmniejsza = liczba;
		}
	}
	printf("Najmniejsza liczba ze zbioru podanych liczb to %lf.\n", najmniejsza);
}

/*
	2.5 	Wczytaj n kolejnych liczb rzeczywistych (double lub float) i wybierz spoœród nich:
	a)		najwiêksz¹
	
	Biblioteka <math.h> umo¿liwia nam u¿ycie sta³ej +nieskoñczonoœæ lub -nieskoñczonoœæ,
	zapisujemy j¹ jako INFINITY (lub odpowiednio -INFINITY) i jest typu double
	
*/
void zad_2_5_a() {
	int i, iloscLiczb;
	double liczba, najwieksza = -INFINITY;				// pocz¹tkowo do zmiennej najwiêksza przypisujemy wartoœæ minus nieskoñczonoœæ, 
	printf("Podaj ile chcialbyœ wczytaæ liczb:\n");		// by mieæ z czym porównaæ pierwsz¹ odczytan¹ liczbê	
	scanf("%d", &iloscLiczb);
	for(i = 0; i < iloscLiczb; i++){
		printf("Podaj %d liczbê z %d liczb:\n", i+1, iloscLiczb);		
		scanf("%lf", &liczba);
		if(liczba  > najwieksza){
			najwieksza = liczba;
		}
	}
	printf("Najwiêksza liczba ze zbioru podanych liczb to %lf.\n", najwieksza);
}

/*
	2.4 	Oblicz przebyt¹ drogê w ruchu jednostajnym, jeœli znane s¹ wartoœci czasu (t) i prêdkoœci(v)
	
	droga - S = v * t, zak³adaj¹c kompatybilne jednostki


*/
void zad_2_4() {
	double t, v, S;
	printf("Podaj czas w sekundach t:\n");		
	scanf("%lf", &t);
	printf("Podaj prêdkoœæ w m/s v:\n");		
	scanf("%lf", &v);
	S = v * t;
	printf("Poruszaj¹c siê z prêdkoœci¹ v=%lf m/s przez t=%lf sekund przebêdziemy drogê S=%lf metrów.\n", v, t, S);
}

/*
	2.3 	Oblicz objêtoœæ:
	d) 		kuli
	
	Objêtoœæ kuli maj¹c dane r - promieñ: (4/3)*PI*r^3

*/
void zad_2_3_d() {
	double r, objetosc;
	printf("Podaj promieñ kuli r:\n");		
	scanf("%lf", &r);
	objetosc = (4.0/3)*M_PI*r*r*r;
	printf("Objetoœæ kuli o promieniu r=%lf jednostek wynosi %lf jednostek.\n", r, objetosc);
}

/*
	2.3 	Oblicz objêtoœæ:
	c) 		sto¿ka
	
	Objêtoœæ sto¿ka maj¹c dane r - promieñ podstawy i H - wysokoœæ: (1/3)*PI*r^2*H
	
	UWAGA! Jeœli wykonuj¹c dzielenie 1/3 nie napiszemy 1.0/3 to wynik z tego dzielenia bêdzie równy 0, gdy¿ potraktujemy liczby jako typ int
	1/3 = 0 reszta 3 -> 0

*/
void zad_2_3_c() {
	double r, H, objetosc;
	printf("Podaj promieñ podstawy sto¿ka r:\n");		
	scanf("%lf", &r);
	printf("Podaj wysokosc sto¿ka H:\n");		
	scanf("%lf", &H);
	objetosc = (1.0/3)*M_PI*r*r*H;			// 
	printf("Objetoœæ sto¿ka o promieniu r=%lf, wysokoœci H=%lf jednostek wynosi %lf jednostek.\n", r, H, objetosc);
}

/*
	2.3 	Oblicz objêtoœæ:
	b) 		prostopadloscianu
	
	Objêtoœæ prostopad³oœcianu: a*b*H

*/
void zad_2_3_b() {
	double a, b, H, objetosc;
	printf("Podaj d³ugoœæ krawedzi podstawy prostopadloscianu a:\n");		
	scanf("%lf", &a); 								// przypisanie do zmiennej "a" wartoœci podanej przez u¿ytkownika
	printf("Podaj d³ugoœæ krawedzi podstawy prostopadloscianu b:\n");		
	scanf("%lf", &b); 								// przypisanie do zmiennej "b" wartoœci podanej przez u¿ytkownika,
	printf("Podaj wysokosc prostopadloscianu H:\n");		
	scanf("%lf", &H); 								// przypisanie do zmiennej "b" wartoœci podanej przez u¿ytkownika,
	objetosc = a*b*H;										// obliczenie pola
	printf("Objetoœæ prostopadloscianu o bokach a=%lf, b=%lf, H=%lf jednostek wynosi %lf jednostek.\n", a, b, H, objetosc);
}

/*
	2.3 	Oblicz objêtoœæ:
	a) 		szeœcianu - dane jest d³ugoœæ boku

*/
void zad_2_3_a() {
	double a, objetosc;
	printf("Podaj d³ugoœæ boku szeœcianu a:\n");		
	scanf("%lf", &a); 								
	objetosc = a*a*a;			// obliczenie objetosci szescianu
	printf("Objetosc szescianu o boku a=%lf jednostek wynosi %lf jednostek.\n", a, objetosc);
}

/*
	2.2 	Oblicz pole powierzchni:
	d) 		okrêgu, gdy znany jest jego promieñ
	
	Pole ko³a - znaj¹c jego promien r  wynosi PI*r^2
	
	Dodanie biblioteki <math.h> umo¿liwi nam skorzystanie ze sta³ej PI, aby z niej skorzystaæ u¿ywamy sta³ej M_PI

*/
void zad_2_2_d() {
	double r, pole;								// u¿ywamy double, bo przyblizenie liczby PI jest zmiennoprzecinkowe
	printf("Podaj promieñ okrêgu r:\n");		
	scanf("%lf", &r); 								// przypisanie do zmiennej "r" wartoœci podanej przez u¿ytkownika
	pole = M_PI*r*r;								// obliczenie pola
	printf("Pole ko³a o promieniu r=%lf jednostek wynosi %lf jednostek.\n", r, pole);
}

/*
	2.2 	Oblicz pole powierzchni:
	c) 		prostok¹ta
	
	Pole prostok¹ta - znaj¹c jego d³ugoœæ boku 'a' oraz 'b' wynosi a*b

*/
void zad_2_2_c() {
	double a, b, pole;
	printf("Podaj d³ugoœæ boku a prostok¹ta:\n");		
	scanf("%lf", &a); 								// przypisanie do zmiennej "a" wartoœci podanej przez u¿ytkownika
	printf("Podaj d³ugoœæ boku b prostok¹ta:\n");		
	scanf("%lf", &b); 								// przypisanie do zmiennej "b" wartoœci podanej przez u¿ytkownika,
	pole = a*b;										// obliczenie pola
	printf("Pole prostok¹ta o bokach a=%lf, b=%lf jednostek wynosi %lf jednostek.\n", a, b, pole);
}

/*
	2.2 	Oblicz pole powierzchni:
	b) 		kwadratu - dana jest d³ugoœæ boku a
	
	Pole trójk¹ta - znaj¹c jego d³ugoœci boków 'a', 'b' i 'c', gdzie p - polowa obwodu tego¿ trójk¹ta p = (a + b + c)\2 wynosi:
	P = sqrt(p(p-a)(p-b)(p-c)) (wzór Herona), gdzie sqrt oznacza pierwiastek kwadratowt z wyra¿enia w nawiasie
	
	Dziêki u¿yciu biblioteki <math.h> mo¿emy u¿yæ funkcji sqrt(), która oblicza pierwiastek kwadratowy z danej liczby
	double sqrt(double x) - funkcja sqrt przyjmuje jako argument liczbê typu double i zwraca jako wynik liczbê typu double

*/
void zad_2_2_b() {
	double a, pole;								// u¿ywamy double, tak po prostu
	printf("Podaj d³ugoœæ boku kwadratu a:\n");		
	scanf("%lf", &a); 								
	pole = a*a;			// obliczenie pola dowolnego trójk¹ta
	printf("Pole kwadratu o boku a=%lf jednostek wynosi %lf jednostek.\n", a, pole);
}

/*
	2.2 	Oblicz pole powierzchni:
	a) 		dowolnego trójk¹ta - dane s¹ jego d³ugoœci boków
	
	Pole trójk¹ta - znaj¹c jego d³ugoœci boków 'a', 'b' i 'c', gdzie p - polowa obwodu tego¿ trójk¹ta p = (a + b + c)\2 wynosi:
	P = sqrt(p(p-a)(p-b)(p-c)) (wzór Herona), gdzie sqrt oznacza pierwiastek kwadratowt z wyra¿enia w nawiasie
	
	Dziêki u¿yciu biblioteki <math.h> mo¿emy u¿yæ funkcji sqrt(), która oblicza pierwiastek kwadratowy z danej liczby
	double sqrt(double x) - funkcja sqrt przyjmuje jako argument liczbê typu double i zwraca jako wynik liczbê typu double

*/
void zad_2_2_a() {
	double a, b, c, p, pole;						// u¿ywamy double, bo w operacji pierwiastkowania spodziewamy siê wyników zmiennoprzecinkowych
	printf("Podaj d³ugoœæ boku trójk¹ta a:\n");		
	scanf("%lf", &a); 								
	printf("Podaj d³ugoœæ boku trójk¹ta b:\n");		
	scanf("%lf", &b); 
	printf("Podaj d³ugoœæ boku trójk¹ta c:\n");		
	scanf("%lf", &c); 
	p = (a+b+c)/2;								// definiujemy sobie zmienn¹ pomocnicz¹ p równ¹ po³owie obwodu trójk¹ta, w celu wiêkszej czytelnoœci dzia³añ
	pole = sqrt(p*(p-a)*(p-b)*(p-c));			// obliczenie pola dowolnego trójk¹ta
	printf("Pole dowolnego trójk¹ta o bokach a=%lf, b=%lf, c=%lf jednostek wynosi %lf jednostek.\n", a, b, c, pole);
}


/*
	2.1 	Oblicz obwód:
	d) 		okrêgu, gdy znany jest jego promieñ
	
	Obwód okrêgu - znaj¹c jego promien r  wynosi 2*PI*r
	
	Dodanie biblioteki <math.h> umo¿liwi nam skorzystanie ze sta³ej PI, aby z niej skorzystaæ u¿ywamy sta³ej M_PI

*/
void zad_2_1_d() {
	double r, obwod;								// u¿ywamy double, bo przyblizenie liczby PI jest zmiennoprzecinkowe
	printf("Podaj promieñ okrêgu r:\n");		
	scanf("%lf", &r); 								// przypisanie do zmiennej "r" wartoœci podanej przez u¿ytkownika
	obwod = 2*M_PI*r;								// obliczenie obwodu
	printf("Obwód okrêgu o promieniu r=%lf jednostek wynosi %lf jednostek.\n", r, obwod);
}

/*
	2.1 	Oblicz obwód:
	c) 		prostok¹ta
	
	Obwód prostok¹ta - znaj¹c jego d³ugoœæ boku 'a' oraz 'b' wynosi 2*(a+b)

*/
void zad_2_1_c() {
	unsigned int a, b, obwod;						// u¿ywamy unsigned int, bo d³ugoœæ boku ani obwód nie mog¹ byæ ujemne
	printf("Podaj d³ugoœæ boku a prostok¹ta:\n");		
	scanf("%u", &a); 								// przypisanie do zmiennej "a" wartoœci podanej przez u¿ytkownika
	printf("Podaj d³ugoœæ boku b prostok¹ta:\n");		
	scanf("%u", &b); 								// przypisanie do zmiennej "b" wartoœci podanej przez u¿ytkownika,
	obwod = 2*(a+b);								// obliczenie obwodu
	printf("Obwód prostok¹ta o bokach a=%u, b=%u jednostek wynosi %u jednostek.\n", a, b, obwod);
}

/*
	2.1 	Oblicz obwód:
	b) 		kwadratu
	
	Obwód kwadratu - znaj¹c jego d³ugoœæ boku 'a' wynosi  4*a

*/
void zad_2_1_b() {
	unsigned int a, obwod;							// u¿ywamy unsigned int, bo d³ugoœæ boku ani obwód nie mog¹ byæ ujemne
	printf("Podaj d³ugoœæ kwadratu a:\n");		
	scanf("%u", &a); 								// przypisanie do zmiennej "a" wartoœci podanej przez u¿ytkownika,
	obwod = 4*a;									// obliczenie obwodu
	printf("Obwód kwadratu o boku a=%u jednostek wynosi %u jednostek.\n", a, obwod);
}


/*
	2.1 	Oblicz obwód:
	a) 		trójk¹ta równobocznego
	
	Obwód trójk¹ta równobocznego - znaj¹c jego d³ugoœæ boku 'a' wynosi 3*a

*/
void zad_2_1_a() {
	unsigned int a, obwod;							// u¿ywamy unsigned int, bo d³ugoœæ boku ani obwód nie mog¹ byæ ujemne
	printf("Podaj d³ugoœæ boku trójk¹ta a:\n");		
	scanf("%u", &a); 								// przypisanie do zmiennej "a" wartoœci podanej przez u¿ytkownika,
	obwod = 3*a;									// obliczenie obwodu
	printf("Obwód trójk¹ta równobocznego o boku a=%u jednostek wynosi %u jednostek.\n", a, obwod);
}

int main(int argc, char *argv[]) {
	//zad_2_1_a();
	//zad_2_1_b();
	//zad_2_1_c();
	//zad_2_1_d();
	//zad_2_2_a();
	//zad_2_2_b();
	//zad_2_2_c();
	//zad_2_2_d();
	//zad_2_3_a();
	//zad_2_3_b();
	//zad_2_3_c();
	//zad_2_3_d();
	//zad_2_4();
	//zad_2_5_a();
	//zad_2_5_b();
	//zad_2_6();
	//zad_2_7_a();
	//zad_2_7_b();
	//zad_2_7_c();
	//zad_2_7_d();
	//zad_2_8();
	//zad_2_9_a();
	//zad_2_9_b();
	//zad_2_10();
	//zad_2_11_a();
	//zad_2_11_b();
	//zad_2_11_c();
	//zad_2_11_d();
	//zad_2_11_e();
	//zad_2_11_f();
	//zad_2_11_g();
	//zad_2_12_abc();
	//zad_2_13();
	//zad_2_14();
	//zad_2_15();
	//zad_2_16();
	//zad_2_17_ab();
	//zad_2_18(); // zadanie 2.19 zostaje pominiête, w zwi¹zku z brakiem jasnej definicji jaka jest ró¿nica miêdzy podzielnikiem, a podzielnikiem pierwszym
	//zad_2_20_abc();
	//zad_2_21_a();
	//zad_2_21_b();
	//zad_2_21_c();
	//zad_2_21_d();
	//zad_2_22_ab();
	//zad_2_23();
	//zad_2_24_ab();
	//zad_2_25();
	//zad_2_26();
	//zad_2_27();
	//zad_2_28();
	zad_2_29();



	return 0;
}
