#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

std::vector<int> primes = {};

bool isPrime(int n) {
	return std::find(primes.begin(), primes.end(), n) != primes.end();
}

void sieve(int n) {
	bool flags[n + 1] = {0};
	for(int i = 2; i <= n; i++) {
		flags[i] = true;
	}
	for(int i = 2; i <= std::sqrt(n); i++) {
		if(flags[i]) {
			for(int j = i * i; j <= n; j += i) {
				flags[j] = false;
			}
		}
	}
	for(int i = 2; i <= n; i++) {
		if(flags[i]) {
			primes.push_back(i);
		}
	}
}

int main() {
	int i = 0;
	int n;
	std::cin >> n;
	sieve(n);
	while(n > 3) {
		for(int j : primes) {
			if(isPrime(n - j)) {
				n = n - j - j;
				i++;
				break; // out of for, not while
			}
		}
	}
	std::cout << i << std::endl;
	return 0;
}
