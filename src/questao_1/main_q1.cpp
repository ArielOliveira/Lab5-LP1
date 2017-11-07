/**
* @file	 	main_q1.cpp
* @brief	Questao_1 - LAB5
* @brief    Utilização de Iteradores Genéricos
* @author 	Ariel Oliveira (ariel.oliveira01@gmail.com)
* @since	31/10/2017
* @date		06/11/2017
*/

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;


/** 
* @brief    Função que recebe um Iterador genérico utilizando templates
* @param    InputIterator first
* @param	InputIterator last
* @return	template typename InputIterator
*/
template<typename InputIterator>
InputIterator closest2mean(InputIterator first, InputIterator last) {
	int avg = 0, count = 1;
	for (InputIterator it = first; it != last; it++) {
		avg += *it;
		count++;
	}
	avg /= count;
	InputIterator result = first;
	bool smaller = true;
	while (smaller) {
		if (*result < avg){
			smaller = true;
			result++;	
		} 
		else smaller = false;
	}

	return result;

}

int main() {
	vector<int> v { 1, 2, 3, 30, 40, 50 };
	auto result = closest2mean(v.begin(), v.end());
	cout << (*result) << endl;

	return 0;
}