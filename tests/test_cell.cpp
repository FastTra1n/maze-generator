#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "Cell.h"

TEST_CASE("Конструктор класса Cell инициализируется корректно", "[Cell]") {
	Cell c(3, 5);

	REQUIRE(c.getX() == 3);
	REQUIRE(c.getY() == 5);

	for (int dir = 0; dir < 4; ++dir)
	{
		REQUIRE(c.isWall(dir) == true);
	}
}

TEST_CASE("Метод breakWall у класса Cell удаляет конкретную стену", "[Cell]") {
	Cell c(3, 5);

	c.breakWall(0);
	REQUIRE(c.isWall(0) == false);
	REQUIRE(c.isWall(1) == true);
	REQUIRE(c.isWall(2) == true);
	REQUIRE(c.isWall(3) == true);
}

TEST_CASE("Разрушение нескольких стен", "[Cell]") {
	Cell c(3, 5);

	c.breakWall(1);
	c.breakWall(2);
	REQUIRE(c.isWall(0) == true);
	REQUIRE(c.isWall(1) == false);
	REQUIRE(c.isWall(2) == false);
	REQUIRE(c.isWall(3) == true);
}

TEST_CASE("Другие стены остаются неповреждёнными после ломания стены в конкретном направлении", "[Cell]") {
	Cell c(3, 5);

	c.breakWall(3);
	REQUIRE(c.isWall(0) == true);
	REQUIRE(c.isWall(1) == true);
	REQUIRE(c.isWall(2) == true);
}

TEST_CASE("Разрушение одной и той же стены дважды не имеет никакого эффекта", "[Cell]") {
	Cell c(3, 5);

	c.breakWall(0);
	bool before = c.isWall(0);
	c.breakWall(0);
	bool after = c.isWall(0);
	REQUIRE(before == false);
	REQUIRE(after == false);
}