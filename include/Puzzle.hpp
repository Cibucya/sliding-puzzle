#pragma once
#include "Board.hpp"
#include <cstddef> // for size_t

class Puzzle {
public:
	Puzzle(size_t w, size_t h);

	Board puzzle;

	[[nodiscard]] int expected_max_cell() const;

	void randomize();
};
