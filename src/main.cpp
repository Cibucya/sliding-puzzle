#include <iostream>
#include "argparse/argparse.hpp"
#include "Board.hpp"
#include "Puzzle.hpp"

int main(int argc, char** argv) {
	argparse::ArgumentParser program("sliding", "1.0");
	program.add_argument("width")
		.help("Set board width")
		.scan<'u', std::size_t>();
	program.add_argument("height")
		.help("Set board height")
		.scan<'u', std::size_t>();

	try {
		program.parse_args(argc, argv);

		auto board_w = program.get<std::size_t>("width");
		auto board_h = program.get<std::size_t>("height");
		if (board_w < 2) throw std::runtime_error("Width must be >= 2");
		if (board_h < 2) throw std::runtime_error("Height must be >= 2");

		Puzzle puzzle(board_w, board_h);
		puzzle.randomize();
		puzzle.print();
	} catch (const std::exception& err) {
		std::cerr << err.what() << std::endl;
		std::cerr << program;
		return 1;
	}

	return 0;
}
