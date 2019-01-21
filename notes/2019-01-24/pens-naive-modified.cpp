#include <iostream>
#include <vector>
#include <csignal>

std::vector<int> a;

void signalHandler(int signum) {
	std::cout << "a=[";
	for(auto v : a) {
		std::cout << v << ',';
	}
	std::cout << "]\n";
	exit(signum);
}

int main() {
	signal(SIGINT, signalHandler);
	signal(SIGTERM, signalHandler);
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
		int val;
        std::cin >> val;
		a.push_back(val);
    }
    unsigned long long int x = 0;
    while(true) {
        if(x % 7 != 6) a[x % n]--;
        if(a[x % n] == 0) {
            std::cout << x % n + 1 << std::endl;
            break;
        }
		x++;
    }
    return 0;
}
