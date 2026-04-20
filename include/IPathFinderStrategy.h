#ifndef IPATHFINDERSTRATEGY_H
#define IPATHFINDERSTRATEGY_H

#include <vector>
#include "Cell.h"

class Maze;

class IPathFinderStrategy {
public:
	virtual ~IPathFinderStrategy() = default;

	virtual std::vector<Cell> findPath(Maze& maze, Cell& start, Cell& end) = 0;
protected:
	IPathFinderStrategy() = default;
};

#endif