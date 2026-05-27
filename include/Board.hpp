#pragma once
#include "Puzzle.hpp"
#include <vector>

class Board {
	// Puzzle class needs to be able to modify grid when shuffling the board.
	friend class Puzzle;

private:
	std::vector<int> grid;
	size_t width;
	size_t height;

public:
	Board(size_t w, size_t h);

	[[nodiscard]] size_t size() const;

	[[nodiscard]] size_t get_index(size_t x, size_t y) const;
	[[nodiscard]] int at(size_t x, size_t y) const;
	[[nodiscard]] int& at(size_t x, size_t y);

	[[nodiscard]] int max_cell() const;
	void print() const;
};
