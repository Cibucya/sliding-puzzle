#include "Board.hpp"
#include "AnsiColors.hpp"
#include <algorithm> // std::shuffle
#include <cmath>     // std::log10
#include <iomanip>   // std::setw
#include <iostream>
#include <numeric>   // std::iota
#include <random>    // std::mt19937
#include <string>
#include <vector>

Board::Board(size_t w, size_t h) : width(w), height(h), grid(w * h, 0) {}

size_t Board::get_index(size_t x, size_t y) const {
    return y * width + x;
}

int Board::at(size_t x, size_t y) const { return grid[get_index(x, y)]; }
int& Board::at(size_t x, size_t y) { return grid[get_index(x, y)]; }

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
