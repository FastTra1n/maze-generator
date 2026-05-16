#ifndef TESTHELPERS_H
#define TESTHELPERS_H

#include <set>
#include <queue>
#include "IGeneratorStrategy.h"
#include "IPathFinderStrategy.h"

class DummyGenerator : public IGeneratorStrategy {
public:
	void generate(Maze& maze) override {}
};

class DummyFinder : public IPathFinderStrategy {
public:
	std::vector<Cell> findPath(Maze& maze, Cell& start, Cell& end) override { return {}; }
};

bool wallsMatch(const Cell& a, const Cell& b, int dir);

bool allWallsConsistent(const Maze& maze);

int countPassages(const Maze& maze);

bool isConnected(const Maze& maze);

bool isValidPath(const Maze& maze, const std::vector<Cell>& path, const Cell& start, const Cell& end);
#endif