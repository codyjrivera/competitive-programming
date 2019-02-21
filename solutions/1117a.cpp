#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> a;
	int n;
	int max = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int ai;
		cin >> ai;
		a.push_back(ai);
		if(ai > max) {
			max = ai;
		}
	}
	// Find longest run of max
	int inRow = 0;
	int maxInRow = 0;
	for(int n : a) {
		if(n == max) {
			inRow++;
			if(inRow > maxInRow) {
				maxInRow = inRow;
			}
		}
		else {
			inRow = 0;
		}
	}
	cout << maxInRow << endl;
}