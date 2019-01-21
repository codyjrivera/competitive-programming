#include <iostream>
#include <vector>
#include <climits>

int main() {
    int n;
	unsigned long long int minDay = ULLONG_MAX;
	int minPen = 0;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
		int ink;
        std::cin >> ink;

		unsigned long long int day = i;
		for(;;) {
			if(day % 7 == 6) {
				day += n;
				if(day % 7 == 6) {
					break; // pen is never used
				}
			}
			ink--;
			if(day >= minDay) {
				break; // pen is not the first to run out of ink
			}
			if(!ink) {
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
