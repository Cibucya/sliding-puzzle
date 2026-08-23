#include <gtest/gtest.h>
#include "Puzzle.hpp"

TEST(PuzzleTest, RandomizeProducesSolvableAndUnsolvedBoard) {
	for (int n = 2; n <= 6; ++n) {
		for (int m = 2; m <= 6; ++m) {
			Puzzle puzzle(n, m);
			for (int i = 0; i < 100; ++i) {
				puzzle.randomize();
				EXPECT_TRUE(puzzle.solvable())
					<< "Randomize produced an unsolvable board on iteration " << i;
				EXPECT_FALSE(puzzle.solved())
					<< "Randomize produced an already-solved board on iteration " << i;
			}
		}
	}
}
