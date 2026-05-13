#include "Maze.h"
#include <iostream>
#include <optional>

Maze::Maze(int w, int h) : width(w), height(h) {
	cells.resize(height, std::vector<Cell>(width));
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			cells[y][x] = Cell(x, y);
		}
	}
}

int Maze::getWidth() const { return width; }
int Maze::getHeight() const { return height; }

Cell& Maze::getCell(int x, int y) { return cells[y][x]; }
const Cell& Maze::getCell(int x, int y) const { return cells[y][x]; }

void Maze::generate(IGeneratorStrategy& strategy)
{
	strategy.generate(*this);
}

std::vector<Cell> Maze::findPath(IPathFinderStrategy& strategy, Cell& start, Cell& end)
{
	return strategy.findPath(*this, start, end);
}

void Maze::display(std::optional<PathData> path) const {
    std::vector<std::vector<char>> cellChar(height, std::vector<char>(width, ' '));

    if (path.has_value()) {
        const PathData& data = path.value();
        if (data.startX >= 0 && data.startX < width && data.startY >= 0 && data.startY < height)
            cellChar[data.startY][data.startX] = 'S';
        
        if (data.endX >= 0 && data.endX < width && data.endY >= 0 && data.endY < height)
            cellChar[data.endY][data.endX] = 'E';
        
        for (const Cell& cell : data.currentPath) {
            int x = cell.getX(), y = cell.getY();
            if ((x == data.startX && y == data.startY) || (x == data.endX && y == data.endY))
                continue;
            if (x >= 0 && x < width && y >= 0 && y < height)
                cellChar[y][x] = '*';
        }
    }

    for (int x = 0; x < width; ++x) {
        std::cout << "+";
        if (cells[0][x].isWall(0))
            std::cout << "---";
        else
            std::cout << "   ";
    }
    std::cout << "+\n";

    for (int y = 0; y < height; ++y) {
        std::cout << "|";
        for (int x = 0; x < width; ++x) {
            std::cout << ' ' << cellChar[y][x] << ' ';
            if (cells[y][x].isWall(1))
                std::cout << "|";
            else
                std::cout << " ";
        }
        std::cout << "\n";

        for (int x = 0; x < width; ++x) {
            std::cout << "+";
            if (cells[y][x].isWall(2))
                std::cout << "---";
            else
                std::cout << "   ";
        }
        std::cout << "+\n";
    }
}