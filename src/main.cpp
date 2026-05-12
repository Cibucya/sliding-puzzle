#include <iostream>
#include <vector>

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

int main(void) {


	return 0;
}
