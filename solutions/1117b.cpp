#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	unsigned long long int n, m, k, h1, h2;
	cin >> n >> m >> k;
	h1 = h2 = 0;
	for(int i = 0; i < n; i++) {
		unsigned long long int h;
		cin >> h;
		if(h > h1) {
			h2 = h1;
			h1 = h;
		}
		else if(h > h2) {
			h2 = h;
		}
	}
	unsigned long long int maxh = 0;
	if(k == m) {
		cout << h1 * m << endl;
		return 0;
	}
	unsigned long long int happinessPerK = h1 * k + h2;
	maxh = (happinessPerK * (m/(k+1))) + (h1 * (m%(k+1)));
	cout << maxh << endl;
}