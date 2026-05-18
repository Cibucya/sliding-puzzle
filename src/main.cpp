#include <algorithm> // std::shuffle
#include <cmath>     // std::log10
#include <iomanip>   // std::setw
#include <iostream>
#include <numeric>   // std::iota
#include <random>    // std::mt19937
#include <string>
#include <vector>
#include "Board.hpp"

void help() {
	std::cout << "Usage: ./sliding <board_width> <board_height>" << std::endl;
}

int main(int argc, char** argv) {
	size_t board_w = 0;
	size_t board_h = 0;
	if (argc >= 3) {
		try {
			board_w = std::stoi(argv[1]);
			board_h = std::stoi(argv[2]);
		}
		catch (const std::exception& e) {
			help();
			return 1;
		}
	}
	else {
		help();
		return 1;
	}

	Board board(board_w, board_h);
	board.randomize();
	board.print();

	return 0;
}
