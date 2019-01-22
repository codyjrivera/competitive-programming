#include <iostream>
#include <string>

int main() {
	std::string tableCard;
	std::cin >> tableCard;
	for(int i = 0; i < 5; i++) {
		std::string card;
		std::cin >> card;
		if(card[0] == tableCard[0] || card[1] == tableCard[1]) {
			std::cout << "YES\n";
			return 0;
		}
	}
	std::cout << "NO\n";
	return 0;
}
