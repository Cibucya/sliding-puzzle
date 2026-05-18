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

// TODO: Fix a bug when to the function can be passed very big x and small y, so
// that the resulting coordinate would be wrong.
// For example if the grid width = 1000 and height = 3, then
// get_index(2000, 1) would perfectly work even though there is no 2000 x value.
size_t Board::get_index(size_t x, size_t y) const {
    return y * width + x;
}

// Returns a value of the cell at (x, y).
// Throws std::out_of_range if coordinates are out of bounds.
// This intentional bounds checking catches programming errors early.
// If performance becomes critical (profiling shows this is a bottleneck),
// we can refactor to provide an unsafe at_unsafe() variant.
int Board::at(size_t x, size_t y) const {
	int idx = Board::get_index(x, y);
	if (idx >= grid.size()) {
		throw std::out_of_range("Board index (" + std::to_string(x) +
                                ", " + std::to_string(y) + ") out of bounds");
	}
	return grid[idx];
}

// Returns a reference to the cell at (x, y).
int& Board::at(size_t x, size_t y) {
	int idx = Board::get_index(x, y);
	if (idx >= grid.size()) {
		throw std::out_of_range("Board index (" + std::to_string(x) +
                                ", " + std::to_string(y) + ") out of bounds");
	}
	return grid[idx];
}

int Board::max_cell() const { return static_cast<int>(grid.size() - 1); }

void Board::randomize() {
    std::iota(grid.begin(), grid.end(), 0);
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(grid.begin(), grid.end(), g);
}

void Board::print() const {
    int max_val = max_cell();
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
