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
	int minDay = INT_MAX;
	int minPen = 0;
	for(int i = 0; i < n; i++) {
		int a = ink[i];
		int day = i;
		for(;;) {
			if(day % 7 == 6) {
				day += n;
				if(day % 7 == 6) {
					break; // pen is never used
				}
			}
			a--;
			if(day >= minDay) {
				break; // pen is not the first to run out of ink
			}
			if(!a) {
				minDay = day;
				minPen = i;
				break; // pen ran out of ink
			}
			day += n;
		}
    }
	std::cout << minPen + 1 << '\n';
    return 0;
}
