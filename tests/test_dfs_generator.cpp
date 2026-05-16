#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "Maze.h"
#include "DFSGenerator.h"
#include "test_helpers.h"

TEST_CASE("¬се клетки в сгенерированном лабиринте св€заны", "[DFSGenerator]") {
	Maze maze(5, 5);
	DFSGenerator gen;

	maze.generate(gen);
	REQUIRE(allWallsConsistent(maze));
}

TEST_CASE(" оличество проходов в лабиринте удовлетвор€ет выражению", "[DFSGenerator]") {
	Maze maze(5, 5);
	DFSGenerator gen;

	maze.generate(gen);
	REQUIRE(countPassages(maze) == 5 * 5 - 1);
}

TEST_CASE("—генерированный лабиринт св€зный", "[DFSGenerator]") {
	Maze maze(5, 5);
	DFSGenerator gen;

	maze.generate(gen);
	REQUIRE(isConnected(maze));
}