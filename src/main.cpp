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
	puzzle.board.print();
	int dist = puzzle.manhattan_dist(0);
	std::cout << "Manhattan distance: " << dist << '\n';

	std::cout << "\nChanging board...\n";
	auto& board = puzzle.board;
	for (int i = 0; i < board.height; ++i) {
		for (int j = 0; j < board.width; ++j) {
			if (board.at(j,i) == 0) {
				std::swap(board.at(j, i), board.at(board.width-1, board.height-1));
			}
		}
	}
	std::cout << "New board:\n";
	puzzle.board.print();

	dist = puzzle.manhattan_dist(0);
	std::cout << "Manhattan distance: " << dist << '\n';

	return 0;
}
