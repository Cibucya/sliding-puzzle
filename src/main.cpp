#include <algorithm> // std::shuffle
#include <cmath>     // std::log10
#include <iomanip>   // std::setw
#include <iostream>
#include <numeric>   // std::iota
#include <random>    // std::mt19937
#include <string>
#include <vector>

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

	int max_cell() {
		return width * height - 1;
	}

	void print_board() {
		int max_val = max_cell();
		// Get number of digits in max number
		int cell_w = (max_val == 0) ? 1 : static_cast<int>(std::log10(max_val)) + 1;

		// Add 3 to include paddings
		size_t border_len = (cell_w + 1) * width + 3;
		std::string border (border_len, '-');

		std::cout << border << '\n';

		for (size_t i = 0; i < height; ++i) {
			std::cout << "|";
			for (size_t j = 0; j < width; ++j) {
				int val = at(j, i);
				// Padding before the number
				std::cout << ' ';
				// \033[47m sets background to white, \033[0m resets
				if (val == 0) std::cout << "\033[47m\033[30m" << std::string(cell_w, ' ') << "\033[0m";
				else std::cout << std::setw(cell_w) << val;
			}
			std::cout << " |\n";
		}

		std::cout << border << '\n';
	}

	void randomize() {
		std::iota(grid.begin(), grid.end(), 0);

		std::random_device rd;
		std::mt19937 g(rd());

		std::shuffle(grid.begin(), grid.end(), g);
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
		return 1;
	}

	Board board(board_w, board_h);
	board.randomize();
	board.print_board();

	return 0;
}
