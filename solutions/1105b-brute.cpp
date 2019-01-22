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
	for(int i = 0; i < 26; i++) {
		char c = 'a' + i;
		string sub = "";
		for(int x = 0; x < k; x++) {
			sub += c;
		}
		int charLevel = 0;
		for(int j = 0; j <= n - k * level + 1; j++) {
			int start = j;
			while(start <= n - k * (level + 1) + 1) {
				if(s.substr(start, k) == sub) {
					start += k;
					charLevel++;
				}
				else {
					start++;
				}
			}
			if(charLevel > level) level = charLevel;
			charLevel = 0;
		}
	}
	cout << level << '\n';
}
