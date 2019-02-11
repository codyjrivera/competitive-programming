#include <iostream>
#include <vector>

int movesToHomogenize(int square, std::vector<int> row) {
	// Change color to square on right: remove self
	int movesRight = row.size();
	if(square < row.size() - 1) {
		row.erase(row.begin() + square);
		movesRight = movesToHomogenize(square, row) + 1;
	}
	int movesLeft = row.size();
	if(square > 0) {
		row.erase(row.begin() + square--);
		movesLeft = movesToHomogenize(square, row) + 1;
	}
	std::cout << "left " << movesLeft << " right " << movesRight << std::endl;
	return movesRight > movesLeft ? movesLeft : movesRight;
}

int main() {
	int n;
	std::vector<int> row;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		int ci;
		std::cin >> ci;
		if(!row.size() || row.back() != ci) {
			row.push_back(ci);
		}
	}
	int minMoves = row.size() - 1;
	for(int square = 0; square < row.size(); square++) {
		int m = movesToHomogenize(square, row);
		std::cout << "m=" << m <<std::endl;
		if(m < minMoves) {
			minMoves = m;
		}
	}
	std::cout << minMoves << std::endl;
	return 0;
}