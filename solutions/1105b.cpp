#include <iostream>
#include <algorithm>

int main() {
	int n, k;
	std::cin >> n >> k;
	char last = ' '; // a non-letter
	int run = 0;
	int levels[26] = {0};

	for(int i = 0; i < n; i++) {
		char c;
		std::cin >> c;
		if(c == last) {
			run++;
			if(run == k) {
				levels[c - 'a']++;
				run = 0;
				last = ' ';
			}
		}
		else if(k == 1) {
			levels[c - 'a']++;
		}
		else {
			last = c;
			run = 1;
		}
	}

	std::cout << *std::max_element(levels, levels + 26) << std::endl;
}
