#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> p, l, r;

int f(int le, int re) {
	if(le > re) {
		return 0;
	}
	int min = INT_MAX;
	int m = 0;
	for(int i = le - 1; i < re; i++) {
		if(p.at(i) < min) {
			m = i + 1;
			min = p.at(i);
		}
	}
	cout << "(" << re << "-" << le << "+1) + " << f(le, m - 1) << " + " << f(m + 1, re) << endl;
	return re - le + 1 + f(le, m - 1) + f(m + 1, re);
}

int main() {
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; i++) {
		int pi;
		cin >> pi;
		p.push_back(pi);
	}
	for(int i = 0; i < q; i++) {
		int li;
		cin >> li;
		l.push_back(li);
	}
	for(int i = 0; i < q; i++) {
		int ri;
		cin >> ri;
		r.push_back(ri);
	}
	vector<int> results = {};
	for(int i = 0; i < q; i++) {
		results.push_back(f(l.at(i), r.at(i)));
	}
	for(int i = 0; i < q - 1; i++) {
		cout << results.at(i) << ' ';
	}
	cout << results.back() << endl;
}