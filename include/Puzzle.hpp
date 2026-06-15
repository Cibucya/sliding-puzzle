#pragma once
#include "Board.hpp"

class Puzzle {
private:
	Board board;

public:
	Puzzle(size_t w, size_t h);

	[[nodiscard]] int expected_max_cell() const;
	[[nodiscard]] size_t manhattan_dist(const size_t target) const;
	[[nodiscard]] size_t count_inversions() const;
	[[nodiscard]] bool is_solvable() const;

	void randomize();
};
