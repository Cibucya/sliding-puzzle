#include "Puzzle.hpp"
#include "Board.hpp"
#include <algorithm> // for std::shuffle
#include <numeric>   // for std::iota
#include <random>    // for std::mt19937
#include <utility>   // for std::pair

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
	// Special case for blank space
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
// An inversion occurs is when a bigger number occurs before smaller one in the
// linear squence of the board (basically how many times a bigger number would
// occur before smaller one, if the board would be 1d array, reading from top to
// bottom, from left to right)
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

// Returns whether a puzzle is solvable or not
// Why this works: https://gemini.google.com/share/49203ca0a274
bool Puzzle::solvable() const {
	size_t inversions = count_inversions();

	// Odd width: solvable iff inversions are even
	if (board.width % 2 == 1) {
		return !(inversions % 2);
	}

	// Even width
	auto [x, y] = board.find_position(0);
	size_t blank_row_from_bottom = board.height - y;

	// Solvable iff (inversions + blank_row_from_bottom) is odd
	return (inversions + blank_row_from_bottom) % 2 != 0;
}

// Returns true if the function if the puzzle is in the solved state
bool Puzzle::solved() const {
	auto& grid = board.grid;
	if (grid[grid.size() - 1] != 0)
		return false;

	for (int i = 0; i < grid.size() - 1; ++i) {
		if (grid[i] != i + 1)
			return false;
	}

	return true;
}

size_t Puzzle::height() const {
	return board.height;
}

size_t Puzzle::width() const {
	return board.width;
}

// Randomizes the board into a solvable variation. Guarantees that returned
// board will not be in solved state.

// TODO: Optimize randomization seeding - currently creates std::random_device 
// on every randomize() call. Options:
// 1. Create a static std::mt19937 generator and seed it once at program start
// 2. Use std::mt19937 g(std::random_device{}()); for inline seeding
// 3. For better portability: seed from std::chrono::high_resolution_clock::now().time_since_epoch().count()
// Reference: Seeding std::mt19937 with rd() is slow on some systems.

// TODO: Consider removing std::random_device dependency for non-cryptographic use
// std::random_device may use weak entropy sources on some systems. 
// Better approach: seed std::mt19937 directly from system time via chrono.
// Example: auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
//          std::mt19937 g(seed);
void Puzzle::randomize() {
	do {
		auto& grid = board.grid;
		std::iota(grid.begin(), grid.end(), 0);
		std::random_device rd;
		std::mt19937 g(rd());
		std::shuffle(grid.begin(), grid.end(), g);

		if (!solvable()) {
			// Swap two non-zero element to fix parity
			auto first = grid.begin();
			while (*first == 0)
				first++;

			auto second = first + 1;
			while (*second == 0)
				second++;

			std::iter_swap(first, second);
		}
	} while (solved());
}

void Puzzle::print() const {
	board.print();
}
