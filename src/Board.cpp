#include "Board.hpp"
#include "AnsiColors.hpp"
#include <algorithm> // std::shuffle
#include <cmath>     // std::log10
#include <iomanip>   // std::setw
#include <iostream>
#include <numeric>   // std::iota
#include <random>    // std::mt19937
#include <stdexcept>
#include <string>
#include <vector>

Board::Board(size_t w, size_t h) : width(w), height(h), grid(w * h, 0) {}

// Returns an index of the cell (x, y)
// Throws std::out_of_range in case the coordinates are out of bonds.
// Decision to make the function throw instead of return -1 was to keep its
// size_t and the performance is not as critical in the project, so it is better
// to keep the code clean.
size_t Board::get_index(size_t x, size_t y) const {
	if (x >= width || y >= height) {
		throw std::out_of_range(
			"Board index (" + std::to_string(x) + ", " + std::to_string(y) +
			") out of bounds, width = " + std::to_string(width) +
			", height = " + std::to_string(height) + ")"
		);
	}
    return y * width + x;
}

// Returns a value of the cell at (x, y).
int Board::at(size_t x, size_t y) const {
	return grid[Board::get_index(x, y)];
}

// Returns a reference to the cell at (x, y).
int& Board::at(size_t x, size_t y) {
	return grid[Board::get_index(x, y)];
}

// Returns actual maximum value in the cell
int Board::max_cell() const {
	return *std::max_element(grid.begin(), grid.end());
}

// Returns max cell which should be in the board
int Board::expected_max_cell() const {
	return static_cast<int>(grid.size() - 1);
}

// TODO: Fix a bug when the function generates unsolvable board. Current
// implementation generates solvalble board only in ~50% situations
void Board::randomize() {
    std::iota(grid.begin(), grid.end(), 0);
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(grid.begin(), grid.end(), g);
}

void Board::print() const {
    int max_val = expected_max_cell();
    int cell_w = (max_val == 0) ? 1 : static_cast<int>(std::log10(max_val)) + 1;
    std::string border((cell_w + 1) * width + 3, '-');

    std::cout << border << "\n";
    for (size_t i = 0; i < height; ++i) {
        std::cout << "|";
        for (size_t j = 0; j < width; ++j) {
            int val = at(j, i);
            std::cout << " ";
            if (val == 0) {
                // White block for the empty space
                std::cout << ansi::white_bg << std::string(cell_w, ' ') << ansi::reset;
            } else {
                std::cout << std::setw(cell_w) << val;
            }
        }
        std::cout << " |\n";
    }
    std::cout << border << std::endl;
}
