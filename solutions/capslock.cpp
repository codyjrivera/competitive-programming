#include <iostream>
#include <string>
#include <cctype>

int main() {
	std::string word, converted;
	std::cin >> word;
	if(std::isupper(word[0])) {
		converted += std::tolower(word[0]);
	}
	else {
		converted += std::toupper(word[0]);
	}
	for(int i = 1; i < word.length(); i++) {
		if(std::isupper(word[i])) {
			converted += std::tolower(word[i]);
		}
		else {
			std::cout << word << std::endl;
			return 0;
		}
	}
	std::cout << converted << std::endl;
	return 0;
}
