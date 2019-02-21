#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	deque<int> a;
	for(int i = 0; i < n; i++) {
		int ai;
		cin >> ai;
		a.push_back(ai);
	}
	sort(a.rbegin(), a.rend());
	int days = 0;
	int pages = 0;
	while(a.size()) {
		days++;
		int dayIndex = 0;
		// drink a coffee
		while(a.size() && dayIndex == 0 || (a.size() > 1 && a.at(0) - dayIndex > a.at(1))) {
			pages += a.front() - dayIndex;
			if(pages >= m) break;
			a.pop_front();
			dayIndex++;
		}
		// can finish today?
		int maxPages = 0;
		for(int coffee : a) {
			if(coffee - dayIndex <= 0) break;
			maxPages += coffee - dayIndex;
			dayIndex++;
		}
		if(maxPages + pages >= m) {
			pages = m;
			break;
		}
	}
	if(pages < m) {
		days = -1;
	}
	cout << days << endl;

}