#include <iostream>
#include <string>

int main() {
	int x, y, z, a, b, c;
	std::cin >> x >> y >> z >> a >> b >> c;
	a -= x; // andrew eats some grapes
	if(a < 0) {
		std::cout << "NO" << std::endl;
		return 0;
	}
	z -= c; // michal eats all the black grapes
	if(z < 0) {
		z = 0;
	}
	std::string enough = a + b >= y + z ? "YES" : "NO";
	std::cout << enough << std::endl;
}