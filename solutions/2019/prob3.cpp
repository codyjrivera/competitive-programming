#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
	int c;
	cin >> c;
	ostringstream output;
	for(int i = 0; i < c; i++) {
		int n, q, r;
		cin >> n >> q >> r;
		int minRank = 100001;
		vector<int> numInRole = {0};
		vector<int> myRoles = {};
		for(int i = 0; i < n; i++) {
			numInRole.push_back(0);
		}
		for(int i = 0; i < r; i++) {
			int rank;
			cin >> rank;
			myRoles.push_back(rank);
		}
		sort(myRoles.begin(), myRoles.end());
		int ahead = 0;
		for(int i = 0; i < q; i++) {
			char type;
			cin >> type;
			int x;
			cin >> x;
			if(type == 'A') {
				int y;
				cin >> y;
				numInRole.at(x) += y;
				if(!myRoles.size() || x < myRoles.at(0)) ahead += x;
			}
			if(type == 'B') {
				int y;
				cin >> y;
				numInRole.at(x) -= y;
				if(!myRoles.size() || x < myRoles.at(0)) ahead -= x;
			}
			if(type == 'C') {
				myRoles.push_back(x);
				for(int r = x; r < myRoles.size() ? myRoles.at(0) : n + 1; r++) {
					ahead -= numInRole.at(r);
				}
				sort(myRoles.begin(), myRoles.end());
			}
			if(type == 'D') {
				myRoles.erase(find(myRoles.begin(), myRoles.end(), x));
				for(int r = x; r < myRoles.size() ? myRoles.at(0) : n + 1; r++) {
					ahead += numInRole.at(r);
				}
			}
			int minRole = n + 1;
			if(myRoles.size()) {
				minRole = myRoles.at(0);
			}
			output << ahead + 1 << endl;
		}
	}
	cout << output.str();
}