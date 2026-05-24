#include "Puzzle.hpp"
#include "Board.hpp"
#include <algorithm> // for std::shuffle
#include <numeric>   // for std::iota
#include <random>    // for std::mt19937

Puzzle::Puzzle(size_t w, size_t h) : puzzle(w, h) {}

// Returns max cell which should be in the puzzle
int Puzzle::expected_max_cell() const {
    return static_cast<int>(puzzle.size() - 1);
}

// TODO: Fix a bug when the function generates unsolvable board. Current
// implementation generates solvalble board only in ~50% situations
void Puzzle::randomize() {
    auto& board = puzzle.grid;
    std::iota(board.begin(), board.end(), 0);
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(board.begin(), board.end(), g);
}
