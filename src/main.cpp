#include <iostream>
#include <vector>
#include <string>

class Board {
private:
	size_t width;
	size_t height;
	std::vector<int> grid;

public:
	Board(size_t w, size_t h)
		: width(w),
		  height(h),
		  grid(w * h, 0) {
	}

	int& at(size_t x, size_t y) {
		return grid[y * width + x];
	}

	int at(size_t x, size_t y) const {
		return grid[y * width + x];
	}

	void print_board() {
		// Multiply by 2 and add 3 to include separators
		std::string border(width * 2 + 3, '-');
		std::cout << border << '\n';

		for (size_t i = 0; i < height; ++i) {
			std::cout << "|";
			for (size_t j = 0; j < width; ++j) {
				int val = at(j, i);
				// Separator to make A by A grid look square and not rectangle
				std::cout << ' ';
				if (val == 0) std::cout << ' ';
				else std::cout << val;
			}
			std::cout << " |\n";
		}
		
		std::cout << border << '\n';
	}
};

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
	}

	Board board(board_w, board_h);
	board.print_board();

	return 0;
}
