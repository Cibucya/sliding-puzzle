#include "Puzzle.hpp"
#include "Board.hpp"
#include <algorithm> // for std::shuffle
#include <numeric>   // for std::iota
#include <random>    // for std::mt19937

Puzzle::Puzzle(size_t w, size_t h) : board(w, h) {}

// Returns max cell which should be in the puzzle
int Puzzle::expected_max_cell() const {
    return static_cast<int>(board.size() - 1);
}

// Returns the manhattan distance for specified elemnet target telling the
// distance the element is away from cell it needs to be in for solved state
size_t Puzzle::manhattan_dist(const size_t target) const {
	size_t x = 0;
	size_t y = 0;
	bool found = false;
	for (size_t i = 0; i < board.height && !found; ++i) {
		for (size_t j = 0; j < board.width; ++j) {
			if (board.at(j,i) == target) {
				x = j;
				y = i;
				found = true;
				break;
			}
		}
	}

	if (!found) {
		throw std::out_of_range(
				"Cell with value (" + std::to_string(target) + ") does not exist"
			);
	}

	size_t goal_x, goal_y;
	if (target == 0) {
		goal_x = board.width - 1;
		goal_y = board.height - 1;
	}
	else {
		goal_x = (target - 1) % board.width;
		goal_y = (target - 1) / board.width;
	}

	return abs(goal_x - x) + abs(goal_y - y);
}

// TODO: Fix a bug when the function generates unsolvable board. Current
// implementation generates solvalble board only in ~50% situations
void Puzzle::randomize() {
    auto& grid = board.grid;
    std::iota(grid.begin(), grid.end(), 0);
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(grid.begin(), grid.end(), g);
}
