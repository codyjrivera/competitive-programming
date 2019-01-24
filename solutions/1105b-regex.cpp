#define _GLIBCXX_REGEX_STATE_LIMIT 200000 // To increase the regex state limit imposed by g++

#include <iostream>
#include <regex>
#include <sstream>

int main() {
	int n, k;
	std::string s;
	std::cin >> n >> k >> s;

	int maxLevel = 0;
	for(char c = 'a'; c <= 'z'; c++) {
		std::ostringstream exprStream;
		exprStream << c << '{' << k << '}';
		std::regex expr(exprStream.str());
		int charLevel = std::distance(std::sregex_iterator(s.begin(), s.end(), expr), std::sregex_iterator());
		if(charLevel > maxLevel) {
			maxLevel = charLevel;
		}
	}

	std::cout << maxLevel << std::endl;
}
