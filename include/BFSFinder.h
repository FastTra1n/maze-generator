#ifndef BFSFINDER_H
#define BFSFINDER_H

#include "IPathFinderStrategy.h"

class BFSFinder : public IPathFinderStrategy {
public:
	std::vector<Cell> findPath(Maze& maze, Cell& start, Cell& end) override;
};

#endif