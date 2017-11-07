/**
* @file	 	main_q3.cpp
* @brief	showprimos - LAB5
* @brief    Exemplo de utilização de Predicados\Functors
* @details 	Neste exemplo, pede-se a implementação de um functor
*			que retorne verdadeiro caso o número seja primo. Utilizando
*			a função find_if, da biblioteca algorithm, o programa deverá
*			imprimir todos os números primos de 1 até N
* @author 	Ariel Oliveira (ariel.oliveira01@gmail.com)
* @since	31/10/2017
* @date		06/11/2017
*/


#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::find_if;

#include <math.h>

class Primo {
	int n;

public:
	Primo(int number) :n(number) {}
	bool operator() (int n) const {
		if (n == 2) return true;
		if (n % 2 == 0) return false;
		int k = (int)sqrt(n);
		while (k > 2) {
			if (n % k == 0) return false;
			k--;
		}
		cout << n << " ";	
		return true;
	}
};

int main(int argc, char** argv) {
	vector<int> v;
	int n = atoi(argv[argc-1]);

	for (int i = 1; i <= n ; i++) {
		v.push_back(i);
	}

	auto it = v.begin();
	cout << "Numeros primos " << "[" << 1 << "-"  << n << "]: ";

	do {
			it = find_if(v.begin(), v.end(), Primo(*it));
			if (it != v.end()) {
				v.erase(it);
		}
	} while (it != v.end());

	cout << endl;

	return 0;
}