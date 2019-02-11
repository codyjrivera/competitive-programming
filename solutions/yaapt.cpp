#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

std::vector<int> a = {};
int m;

int beauty(int l, int r) {
	int b = 0;
	std::vector<int> modified = a;
	for(int i = 0; i <= m; i++) {
		auto max = std::max_element(modified.begin() + l, modified.end() + r);
		b += *max;
		*max = INT_MIN;
	}
	return b;
}

int main() {
	int n, k;
	std::cin >> n >> m >> k;
	int partitions[k];
	for(int i = 0; i < k; i++) {
		partitions[k] = i;
	}
	for(int i = 0; i < n; i++) {
		int ai;
		std::cin >> ai;
		a.push_back(ai);
	}
}