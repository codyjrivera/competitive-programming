#include <iostream>
#include <vector>

int main(void) {
	int maxPossible = (1 << 21) - 1;
	int n, q;
	std::cin >> n;
	int c[n];
	for(int i = 0; i < n; i++) {
		std::cin >> c[i];
	}
	std::cin >> q;
	for(int i = 0; i < q; i++) {
		int li, ri;
		std::cin >> li >> ri;

		std::vector<bool> reachable(maxPossible + 1, 0);
		std::vector<int> reachableVector = {0};
		int maxReachable = 0;
		for(int j = li - 1; j < ri; j++) {
			reachableVector.push_back(c[j]); // We can always reach this value by eating only here
			if(c[j] > maxReachable) {
				maxReachable = c[j];
			}
			for(int i = 0; i < reachableVector.size(); i++) { // can't use range-based for since we modify vector
				int reachableValue = reachableVector.at(i);
				int xord = reachableValue ^ c[j];
				if(reachable.at(xord)) {
					continue; // already reached
				}
				reachable.at(xord) = 1;
				if(xord > maxReachable) {
					maxReachable = xord;
					if(xord == maxPossible) {
						break;
					}
				}
				reachableVector.push_back(xord);
			}
			if(maxReachable == maxPossible) {
				break;
			}
		}

		std::cout << maxReachable << '\n';
	}
}