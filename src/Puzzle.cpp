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

	return (std::max(goal_x, x) - std::min(goal_x, x)) +
		   (std::max(goal_y, y) - std::min(goal_y, y));
}

// Counts the number of inversions in the board.
// An inversion is when a bigger number occurs before smaller one on the board
 size_t Puzzle::count_inversions() const {
	size_t inversions = 0;
	const auto& grid = board.grid;

	for (int i = 0; i < grid.size(); ++i) {
		if (grid[i] == 0) continue;
		for (int j = i + 1; j < grid.size(); ++j) {
			if (grid[j] == 0) continue;
			if (grid[i] > grid[j]) inversions++;
		}
	}

	return inversions;
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
