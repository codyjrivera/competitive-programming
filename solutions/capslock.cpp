#include <iostream>
#include <string>
#include <cctype>

int main() {
	std::string word, converted;
	std::cin >> word;
	converted += std::toupper(word[0]);
	for(int i = 1; i < word.length(); i++) {
		if(std::isupper(word[i])) {
			converted += std::tolower(word[i]);
		}
		else {
			std::cout << word;
			return 0;
		}
	}
	std::cout << converted;
	return 0;
}
