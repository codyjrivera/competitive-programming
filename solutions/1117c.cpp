#include <iostream>
#include <deque>
#include <cmath>
#include <utility>
#include <string>
#include <vector>

using namespace std;

double distance(pair<int, int> a, pair<int, int> b) {
	return sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
}

int main() {
	int x1, y1, x2, y2, n;
	vector<char> s;
	cin >> x1 >> y1 >> x2 >> y2 >> n;
	string forecast;
	cin >> forecast;
	for(char c : forecast) {
		s.push_back(c);
	}
	int days = 0;
	pair<int, int> target = make_pair(x2, y2);
	deque<pair<int, int>> positions = {make_pair(x1, y1)};
	double mind = distance(positions.at(0), target);
	double startd = mind;
	while(++days) {
		for(pair<int, int> pos : positions) {
			pair<int, int> x, u, d, l, r;
			x = u = d = l = r = pos;
			double d0, dx, du, dd, dl, dr;
			d0 = dx = du = dd = dl = dr = distance(pos, target);
			if(d0 == 0) {
				cout << days - 1 << endl;
				return 0;
			}
			switch(s.at((days - 1)%n)) {
				case 'U':
				x = make_pair(pos.first, pos.second + 1);
				u = make_pair(pos.first, pos.second + 2);
				l = make_pair(pos.first - 1, pos.second + 1);
				r = make_pair(pos.first + 1, pos.second + 1);
				break;
				case 'D':
				x = make_pair(pos.first, pos.second - 1);
				d = make_pair(pos.first, pos.second - 2);
				l = make_pair(pos.first - 1, pos.second - 1);
				r = make_pair(pos.first + 1, pos.second - 1);
				break;
				case 'L':
				x = make_pair(pos.first - 1, pos.second);
				u = make_pair(pos.first - 1, pos.second + 1);
				d = make_pair(pos.first - 1, pos.second - 1);
				l = make_pair(pos.first - 2, pos.second);
				break;
				case 'R':
				x = make_pair(pos.first + 1, pos.second);
				u = make_pair(pos.first + 1, pos.second + 1);
				d = make_pair(pos.first + 1, pos.second - 1);
				r = make_pair(pos.first + 2, pos.second);
				break;
			}
			dx = distance(x, target);
			du = distance(u, target);
			dd = distance(d, target);
			dl = distance(l, target);
			dr = distance(r, target);
			if(dx < d0 && dx <= mind) {
				positions.push_back(x);
				mind = dx;
			}
			if(du < d0 && du <= mind) {
				positions.push_back(u);
				mind = du;
			}
			if(dd < d0 && dd <= mind) {
				positions.push_back(d);
				mind = dd;
			}
			if(dl < d0 && dl <= mind) {
				positions.push_back(l);
				mind = dl;
			}
			if(dr < d0 && dr <= mind) {
				positions.push_back(r);
				mind = dr;
			}
			while(distance(positions.at(0), target) > d0) {
				positions.pop_front();
			}
		}
		if(days >= n && mind = startd) {
			cout << "-1" << endl;
			return 0;
		}
	}
}