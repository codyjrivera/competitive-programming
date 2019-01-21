#include <iostream>
#include <climits>
#include <csignal>

unsigned long long int minDay = ULLONG_MAX;
int minPen = 0;
int ink = 0;
unsigned long long int day = 0;
int i = 0;

void signalHandler(int signum) {
	std::cout << "i=" << i << "; minPen=" << minPen << "; ink=" << ink << "; minDay=" << minDay << "; day=" << day << '\n';
	exit(signum);
}

int main() {
	signal(SIGINT, signalHandler);
	signal(SIGTERM, signalHandler);
    int n;
    std::cin >> n;
    for(; i < n; i++) {
        std::cin >> ink;
		day = i;
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
