#include <iostream>
#include <cmath>
#include <cstdio>

double distance(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		double r1, r2, x, y;
		std::cin >> r1 >> r2 >> x >> y;

		long long int hits, tests;
		hits = tests = 0;

		double epsilon = r1 / 1500.0; 
		// 1500 is the maximum divisor that seems to result in an acceptable runtime

		for(double x1 = -r1; x1 <= r1; x1 += epsilon) {
			for(double y1 = -r1; y1 <= r1; y1 += epsilon) {
				if(distance(x1, y1, 0, 0) > r1 - r2) {
					// point is not a possible center for the new arena
					continue;
				}
				tests++;
				if(distance(x1, y1, x, y) < r2) {
					hits++;
				}
			}
		}

		double p = (double) hits / (double) tests;
		printf("%.2f\n", p);
	}
}
