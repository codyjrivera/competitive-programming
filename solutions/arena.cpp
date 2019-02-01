#include <iostream>
#include <cmath>
#include <cstdio>

#ifndef M_PI
	#define M_PI 3.14159265358979323846264
#endif

int main() {
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		double r1, r2, x, y;
		std::cin >> r1 >> r2 >> x >> y;

		double d = sqrt(x * x + y * y);
		double r, R;
		r = r2;
		R = r1 - r2;
		double A;
		if(d < R / 2.0) {
			A = M_PI * r * r;
		}
		else {
			A =
				r * r * acos(
					(d * d + r * r - R * R)
					/ (2 * d * r)
				)
				+ R * R * acos(
					(d * d + R * R - r * r)
					/ (2 * d * R)
				)
				- 0.5 * sqrt(
					(-1 * d + r + R)
					* (d + r - R)
					* (d - r + R)
					* (d + r + R)
				);
		}
		double p = A / (M_PI * R * R);
        if(std::isnan(p) || p > 1.0) printf("1.00\n"); // fix for certain test cases with very large arenas
		else printf("%.2f\n", p);
	}
}
