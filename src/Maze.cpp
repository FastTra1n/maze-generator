#include "Maze.h"
#include <iostream>

Maze::Maze(int w, int h) : width(w), height(h) {
	cells.resize(height, std::vector<Cell>(width));
	for (int row = 0; row < height; ++row)
	{
		for (int column = 0; column < width; ++column)
		{
			cells[row][column] = Cell(row, column);
		}
	}
}

int Maze::getWidth() const { return width; }
int Maze::getHeight() const { return height; }

Cell& Maze::getCell(int row, int column) { return cells[row][column]; }
const Cell& Maze::getCell(int row, int column) const { return cells[row][column]; }

void Maze::generate(IGeneratorStrategy& strategy)
{
	strategy.generate(*this);
}

std::vector<Cell> Maze::findPath(IPathFinderStrategy& strategy, Cell& start, Cell& end)
{
	return strategy.findPath(*this, start, end);
}

void Maze::display() const
{
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
            std::cout << "   ";
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