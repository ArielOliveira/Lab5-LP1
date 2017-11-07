/**
* @file	 	main_q2.cpp
* @brief	Questao_2 - LAB5
* @brief    Exemplo de função que recebe um container genérico, utilizando
*			seus respectivos iteradores através de templates
* @author 	Ariel Oliveira (ariel.oliveira01@gmail.com)
* @since	31/10/2017
* @date		06/11/2017
*/

#include <iostream>
using std::cout;
using std::endl;

#include <set>
using std::set;

#include <vector>
using std::vector;


/** 
* @brief    Função que recebe uma referência de um Container genérico através de templates
* @param    TContainer& collection
* @param	const char* label=""
* @param	const char separator= ' '
* @return	void
*/
template<typename TContainer>
void print_elements(const TContainer& collection, const char* label="", const char separator=' ') {
	cout << label << " ";
	for (typename TContainer::const_iterator it = collection.begin(); it !=collection.end(); it++) {
		cout << *it;
		if (*it != *collection.end()) {
			cout << separator;
		}
	}
	cout << endl;
}

int main() {
	set<int> numeros;
	numeros.insert(3);
	numeros.insert(1);
	numeros.insert(4);
	numeros.insert(1);
	numeros.insert(2);
	numeros.insert(5);
	print_elements(numeros, "Set: ");
	print_elements(numeros, "CSV Set: ", ';');
}
