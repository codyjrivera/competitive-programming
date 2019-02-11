#include <iostream>

typedef long long int lli;

lli divisor(lli x) {
	for(lli i = 2; i < x/2+1; i++) {
		std::cout << "testing x=" << x <<" i=" << i << std::endl;
		if(x%i == 0) return x/i;
	}
	return x;
}

int main() {
	lli n, b;
	std::cin >> n >> b;
	lli zeros = 0;
	lli gd = divisor(b);
	std::cout << gd << std::endl;
	for(lli i = gd; i <= n; i *= gd) {
		std::cout << "i=" << i << " zeros=" << zeros << std::endl;
		zeros += n / i;
		std::cout << "i=" << i << " zeros=" << zeros << std::endl;
	}
	std::cout << zeros << std::endl;
	return 0;
}