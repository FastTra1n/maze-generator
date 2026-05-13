#ifndef MAZE_H
#define MAZE_H

#include "Cell.h"
#include "IGeneratorStrategy.h"
#include "IPathFinderStrategy.h"
#include <vector>
#include <optional>

struct PathData {
	int startX, startY, endX, endY;
	std::vector<Cell> currentPath;
};

class Maze {
public:
	Maze(int width, int height);
	~Maze() = default;

	int getWidth() const;
	int getHeight() const;
	Cell& getCell(int x, int y);
	const Cell& getCell(int x, int y) const;

	void generate(IGeneratorStrategy& strategy);
	std::vector<Cell> findPath(IPathFinderStrategy& strategy, Cell& start, Cell& end);
	void display(std::optional<PathData> path) const;
	
private:
	int width, height;
	std::vector<std::vector<Cell>> cells;
};

#endif
