#include <iostream>
#include "Board.hpp"
#include "Puzzle.hpp"

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

	Puzzle puzzle(board_w, board_h);
	puzzle.randomize();
	puzzle.print();

	return 0;
}
