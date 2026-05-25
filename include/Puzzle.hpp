#pragma once
#include "Board.hpp"

class Puzzle {
public:
	Puzzle(size_t w, size_t h);

	Board board;

	[[nodiscard]] int expected_max_cell() const;
	[[nodiscard]] size_t manhattan_dist(const size_t target) const;

	void randomize();
};
