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
	for (int row = 0; row < height; ++row)
	{
		for (int column = 0; column < width; ++column)
		{
			std::cout << (cells[row][column].isWall(0) ? "#" : " ");
		}
		std::cout << "\n";
	}
}