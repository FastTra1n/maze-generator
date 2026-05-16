#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "Maze.h"
#include "KruskalGenerator.h"
#include "test_helpers.h"

TEST_CASE("¬се клетки в сгенерированном лабиринте св€заны", "[KruskalGenerator]") {
	Maze maze(5, 5);
	KruskalGenerator gen;

	maze.generate(gen);
	REQUIRE(allWallsConsistent(maze));
}

TEST_CASE(" оличество проходов в лабиринте удовлетвор€ет выражению", "[KruskalGenerator]") {
	Maze maze(5, 5);
	KruskalGenerator gen;

	maze.generate(gen);
	REQUIRE(countPassages(maze) == 5 * 5 - 1);
}

TEST_CASE("—генерированный лабиринт св€зный", "[KruskalGenerator]") {
	Maze maze(5, 5);
	KruskalGenerator gen;

	maze.generate(gen);
	REQUIRE(isConnected(maze));
}