#include <iostream>
#include <vector>

int main() {
    int n;
	std::vector<int> a;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
		int val;
        std::cin >> val;
		a.push_back(val);
    }
    int x = 0;
    while(true) {
        if(x % 7 != 6) a[x % n]--;
        if(a[x % n] == 0) {
            std::cout << x % n + 1 << std::endl;
            break;
        }
		x++;
    }
    return 0;
}
