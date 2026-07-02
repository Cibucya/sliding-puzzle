#pragma once
#include "Board.hpp"
#include <cstddef>   // size_t

class Puzzle {
private:
	Board board;

public:
	Puzzle(size_t w, size_t h);

	[[nodiscard]] int expected_max_cell() const;
	[[nodiscard]] size_t manhattan_dist(const size_t target) const;
	[[nodiscard]] size_t count_inversions() const;
	[[nodiscard]] bool solvable() const;
	[[nodiscard]] bool solved() const;

	[[nodiscard]] size_t height() const;
	[[nodiscard]] size_t width() const;

	void randomize();
	void print() const;
};
