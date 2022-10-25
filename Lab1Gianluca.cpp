#include <iostream>
#include <vector>
#include <string>

//funzione creata per testare il funzionamento di una variabile static
int stat();

//funzione che va a scrivere un vettore di int in una stringa per poi stamparla
void print(std::string, std::vector<int>);

//restituisce e stampa un vettore di numeri di fibonacci
std::vector<int> fibonacci(int, int, std::vector<int>, int);

//funzione per cercare il valore massimo di un int con segno
int MaxInt_fibonacci();

//ulteriore funzione print che ad argomento ha solo un vector che va a stampare
void print(std::vector<int> vec);

//funzione che conta e stampa quante volte è stata chiamata
void call_counter(void);

int glob = 4; //variabile glocale inizializzata
int glob2;

int main() {

	//prova di stampa hello world
	std::cout << "Hello world \n";


	{
		int a = 5; //variabile locale
		std::cout << a << "\n";
	}

	//inizializzo una variabile statica locale
	static int x = 5;

	//dichiaro una variabile locale
	static int y;


	//provo la variabile globale
	std::cout << glob << "\n";


	//provo la funzione print

	std::vector<int> vec;
	std::string stampa;

	for (int i = 0; i < 5; i++) {
		vec.push_back(i);
	}

	print(stampa, vec);

	//Provo la funzione che genera una vector con la sequenza di fibonacci

	std::vector<int> vec2;

	fibonacci(2, 3, vec2, 8);

	//cerco di capire quanto sia il numero massimo che ci sta in un int
	
	std::cout << "\n" << "Int massimo che trovo con la sequeza di fibonacci:  " << std::to_string(MaxInt_fibonacci()) << "\n";
	


	return 0;
}

int stat() {

	static int prova = 0;

	prova++;

	return prova;

}

void print(std::string stampa, std::vector<int> vec) {

	for (int i = 0; i < 5; i++) {

		stampa += std::to_string(vec[i]);

	}
	std::cout << stampa << "\n";
}

void print(std::vector<int> vec) {

	for (int i = 0; i < vec.size(); i++) {

		std::cout << vec[i] << " ";

	}
}

std::vector<int> fibonacci(int x, int y, std::vector<int> vec, int n) {

	vec.push_back(x);
	vec.push_back(y);

	for (int i = 0; i < n - 2; i++) {

		vec.push_back(vec[i] + vec[i + 1]);

	}

	print(vec);

	return vec;
}

int MaxInt_fibonacci() {
	int a = 1;
	int b = 2;
	int result = 1;

	while (true) {

		result = a + b;
		a = b;


		if (result < 0){

			return b;

		}


		b = result;

	}

	return b;
}

void call_counter(void) {

	static int a = 0;

	a++;

	std::cout << a;

	/*Lo scope della variabile che deve essere static è la sola funzione
		mentre la durata della memorizzazione è dal momento in cui viene chiamata la funzione
		fino al termine del programma*/

}