#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> evenUpTo = {0, 0}, oddUpTo = {0};
	for(int i = 1; i <= n; i++) {
		int ai;
		cin >> ai;
		if(i%2) {
			oddUpTo.push_back(oddUpTo.back() + ai);
			oddUpTo.push_back(oddUpTo.back());
		}
		else {
			evenUpTo.push_back(evenUpTo.back() + ai);
			evenUpTo.push_back(evenUpTo.back());
		}
	}
	int good = 0;
	for(int i = 1; i <= n; i++) {
		int evens = evenUpTo.at(i - 1) + oddUpTo.back() - oddUpTo.at(i);
		int odds = oddUpTo.at(i - 1) + evenUpTo.back() - evenUpTo.at(i);
		good += evens == odds;
	}
	cout << good << endl;
}