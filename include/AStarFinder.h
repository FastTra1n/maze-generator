#ifndef ASTARFINDER_H
#define ASTARFINDER_H

#include "IPathFinderStrategy.h"

class AStarFinder : public IPathFinderStrategy {
public:
	std::vector<Cell> findPath(Maze& maze, Cell& start, Cell& end) override;
};

#endif