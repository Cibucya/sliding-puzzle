#pragma once
#include <vector>

class Board {
public:
	Board(size_t w, size_t h);

	std::vector<int> grid;
	size_t width;
	size_t height;

	[[nodiscard]] size_t size() const;

	[[nodiscard]] size_t get_index(size_t x, size_t y) const;
	[[nodiscard]] int at(size_t x, size_t y) const;
	[[nodiscard]] int& at(size_t x, size_t y);

	[[nodiscard]] int max_cell() const;
	void print() const;

};
