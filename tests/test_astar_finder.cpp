#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "Maze.h"
#include "DFSGenerator.h"
#include "AStarFinder.h"
#include "test_helpers.h"

TEST_CASE("AStarFinder находит оптимальный путь в сгенерированном лабиринте", "[AStarFinder]") {
	Maze maze(5, 5);
	DFSGenerator gen;
	AStarFinder finder;

	Cell start = maze.getCell(0, 0);
	Cell end = maze.getCell(4, 4);

	maze.generate(gen);
	std::vector<Cell> path = maze.findPath(finder, start, end);
	REQUIRE(!path.empty());
	REQUIRE(isValidPath(maze, path, start, end));
}
