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
		return true;
	}
};

int main(int argc, char** argv) {
	vector<int> v;
	int n = atoi(argv[argc-1]);

	for (int i = 1; i <= n ; i++) {
		v.push_back(i);
	}

	v.push_back(0);
	auto it = v.begin();
	cout << "Numeros primos " << "[" << 1 << "-"  << n << "]: ";

	do {
			it = find_if(v.begin(), v.end(), Primo(*it));
			if (it != v.end()) {
				cout << *it << " ";	
				v.erase(it);
		}
	} while (it != v.end());

	cout << endl;

	return 0;
}