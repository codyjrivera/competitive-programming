#include <iostream>
#include <utility>
#include <vector>

int main() {
	int n, m;
	std::cin >> n >> m;
	int a[n];
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::pair<int, int> segments[m];
	for(int i = 0; i < m; i++) {
		int l, r;
		std::cin >> l >> r;
		segments[i] = std::make_pair(l, r);
	}

	int globalMinimum = 1000001;
	int globalMaximum = -1000001;
	int globalMaxdiff = 0;
	std::vector<int> usedSegments = {};
	for(int i = 0; i < n; i++) {
		if(a[i] < globalMinimum) {
			globalMinimum = a[i];
		}
		if(a[i] > globalMaximum) {
			globalMaximum = a[i];
		}
	}
	globalMaxdiff = globalMaximum - globalMinimum;
	
	std::vector<int> applicableSegments[n];
	for(int s = 0; s < m; s++) {
		for(int i = segments[s].first - 1; i < segments[s].second; i++) {
			applicableSegments[i].push_back(s);
		}
	}

	// TODO: something

	printf("%i\n%i\n", globalMaxdiff, usedSegments.size());
	for(int s : usedSegments) {
		std::cout << s << ' ';
	}
	std::cout << '\n';
}