#include <iostream>

#ifndef M_PI
	#define M_PI 3.14159265358979323846264338
#endif

long double operator ""_pi(long double x) {
	return x * M_PI;
}
long double operator ""_pi(unsigned long long int x) {
	return (long double) x * M_PI;
}

long double operator ""_tau(long double x) {
	return x * M_PI * 2;
}
long double operator ""_tau(unsigned long long int x) {
	return (long double) x * M_PI * 2;
}

int main() {
	std::cout << 2_pi << " = " << 1_tau << " < " << 2.2e0_pi << " = " << 11e-1_tau << std::endl;
	// prints: 6.28319 = 6.28319 < 6.9115 = 6.9115
	return 0;
}