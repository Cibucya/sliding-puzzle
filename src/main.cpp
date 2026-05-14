#include <iostream>
#include <vector>
#include <string>

class Board {
private:
	size_t width;
	size_t height;
	std::vector<int> grid;

public:
	Board(int width, int height)
		: width(width),
		  height(height),
		  grid(width * height, 0) {
	}

	auto at(int x, int y) {
		return grid[y * width + x];
	}

	void print_board() {
		std::string border(width + 2, '-');
		std::cout << border << '\n';

		for (int i = 0; i < height; ++i) {
			std::cout << "|";
			for (int j = 0; j < width; ++j) {
				int val = at(j, i);
				std::cout << (val == 0 ? ' ' : val);
			}
			std::cout << "|\n";
		}
		
		std::cout << border << '\n';
	}
};

void help() {
	std::cout << "Usage: ./sliding <board_width> <board_height>" << std::endl;
}

int main(int argc, char** argv) {
	int board_w = 0;
	int board_h = 0;
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

	Board board(board_w, board_w);

	return 0;
}
