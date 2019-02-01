#include <iostream>

bool isPrime(int n) {
	for(int i = 2; i <= n / 2; i++) {
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int i = 0;
	int n;
	std::cin >> n;
	while(n > 3) {
		for(int j = 2; j <= n / 2; j++) {
			if(isPrime(j) && isPrime(n - j)) {
				n = n - j - j;
				i++;
				break; // out of for, not while
			}
		}
	}
	std::cout << i << std::endl;
	return 0;
}
