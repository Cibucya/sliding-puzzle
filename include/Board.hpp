#pragma once
#include <vector>
#include <cstddef>

class Board {
public:
	Board(size_t w, size_t h);

	[[nodiscard]] int at(size_t x, size_t y) const;
	[[nodiscard]] int& at(size_t x, size_t y);

	[[nodiscard]] int max_cell() const;

	void print() const;
	void randomize();

private:
	size_t width;
	size_t height;
	std::vector<int> grid;

	[[nodiscard]] size_t get_index(size_t x, size_t y) const;
}
