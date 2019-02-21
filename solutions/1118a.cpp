#include <iostream>

using namespace std;

int main() {
	int q;
	cin >> q;
	for(int i = 0; i < q; i++) {
		long long int n, a, b;
		cin >> n >> a >> b;
		if(b > 2 * a) {
			cout << a * n << endl;
		}
		else {
			cout << b * (n/2) + a * (n%2) << endl;
		}
	}
}