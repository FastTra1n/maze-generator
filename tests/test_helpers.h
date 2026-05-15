#ifndef TESTHELPERS_H
#define TESTHELPERS_H

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

#endif