#include <iostream>
#include <vector>
#include <climits>

int main() {
    int n;
    std::cin >> n;
	int ink[n];
	int minBlock = INT_MAX;
    for(int i = 0; i < n; i++) {
        std::cin >> ink[i];
		int endBlock = -1; // -1 if this pen is never depleted
		if(n % 7) {
			endBlock = ink[i] / 6 + !!(ink[i] % 6) - 1; // Last block before this pen runs out of ink
		}
		else {
			if(i % 7 != 6) {
				endBlock = ink[i] - 1;
			}
		}
		if(endBlock != -1 && endBlock < minBlock) {
			minBlock = endBlock;
		}
	}

	// Determine the state at the end of the minBlock.
	for(int i = 0; i < n; i++) {
		if(n % 7) {
			ink[i] -= minBlock * 6;
		}
		else {
			if(i % 7 != 6) {
				ink[i] -= minBlock;
			}
		}
	}

	// Calculate from the beginning of the minBlock.
    int x = 0;
    while(true) {
        if(x % 7 != 6) ink[x % n]--;
        if(ink[x % n] == 0) {
            std::cout << x % n + 1 << std::endl;
            break;
        }
		x++;
    }
    return 0;
}
