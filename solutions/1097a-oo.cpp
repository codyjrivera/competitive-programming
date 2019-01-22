#include <iostream>

class Card {
public:
	bool operator==(const Card& c) {
		return rank == c.rank || suit == c.suit;
	}
	friend std::istream& operator>>(std::istream& in, Card& c) {
		in >> c.rank >> c.suit;
	}
private:
	char rank, suit;
};

int main() {
	Card tableCard;
	std::cin >> tableCard;
	for(int i = 0; i < 5; i++) {
		Card card;
		std::cin >> card;
		if(card == tableCard) {
			std::cout << "YES\n";
			return 0;
		}
	}
	std::cout << "NO\n";
	return 0;
}
