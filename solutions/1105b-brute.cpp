#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	int level = 0;
    for(char c = 'a'; c <= 'z'; c++) {
		string sub = "";
		for(int x = 0; x < k; x++) {
			sub += c;
		}
		int charLevel = 0;
		int start = 0;
		while(start <= n - k * (level + 1) + 1) {
			if(s.substr(start, k) == sub) {
				start += k;
				charLevel++;
			}
			else {
				start++;
			}
		}
		if(charLevel > level) {
			level = charLevel;
		}
	}
	cout << level << '\n';
}
