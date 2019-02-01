#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

std::vector<int> primes = {};
std::vector<bool> flags = {};

bool isPrime(int n) {
	return flags.at(n);
}

void sieve(int n) {
	flags.push_back(false); // 0
	flags.push_back(false); // 1
	for(int i = 2; i <= n; i++) {
		flags.push_back(true);
	}
	for(int i = 2; i <= std::sqrt(n); i++) {
		if(flags.at(i)) {
			for(int j = i * i; j <= n; j += i) {
				flags.at(j) = false;
			}
		}
	}
	for(int i = 2; i <= n; i++) {
		if(flags.at(i)) {
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
