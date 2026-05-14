#include <iostream>
#include <vector>
#include <string>

class Board {
public:
	size_t board_size;
	std::vector<std::vector<int>> board;
	Board(int size)
		: board_size(size),
		  board(size, std::vector<int>(size, 0)) {
	}

	void print_board() {

	}
};

int main(int argc, char** argv) {
	int board_size = 4;
	if (argc >= 2) {
		try {
			board_size = std::stoi(argv[1]);
		}
		catch (const std::exception& e) {
			std::cout << "Error: Board size has to be an integer.\n";
			return 1;
		}
	}

	Board board(board_size);

	return 0;
}
