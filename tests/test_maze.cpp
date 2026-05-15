#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "Maze.h"
#include "test_helpers.h"

TEST_CASE("Конструктор класса Maze корректно инициализирует сетку лабиринта", "[Maze]") {
	Maze m(10, 5);

	REQUIRE(m.getWidth() == 10);
	REQUIRE(m.getHeight() == 5);
	
	for (int y = 0; y < 5; ++y)
	{
		for (int x = 0; x < 10; ++x)
		{
			const Cell& c = m.getCell(x, y);
			REQUIRE(c.getX() == x);
			REQUIRE(c.getY() == y);
		}
	}
}

TEST_CASE("Метод getCell класса Maze корректно ссылается на нужную клетку", "[Maze]") {
	Maze m(10, 5);
	m.getCell(1, 1).breakWall(0);

	REQUIRE(m.getCell(1, 1).isWall(0) == false);
}

TEST_CASE("Метод generate класса Maze вызывается корректно", "[Maze]") {
	Maze m(10, 5);
	DummyGenerator dummy;

	m.generate(dummy);
	REQUIRE(m.getWidth() == 10);
	REQUIRE(m.getHeight() == 5);
}

TEST_CASE("Метод findPath класса Maze вызывается корректно", "[Maze]") {
	Maze m(10, 5);
	DummyFinder dummy;

	Cell& start = m.getCell(0, 0);
	Cell& end = m.getCell(9, 4);
	m.findPath(dummy, start, end);
	REQUIRE(m.getWidth() == 10);
	REQUIRE(m.getHeight() == 5);
}