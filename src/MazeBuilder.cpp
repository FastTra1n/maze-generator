#include "MazeBuilder.h"
#include <iostream>

MazeBuilder::MazeBuilder() : width(0), height(0) {}

MazeBuilder& MazeBuilder::setSize(int w, int h) {
	width = w;
	height = h;
	return *this;
}

std::unique_ptr<Maze> MazeBuilder::build() {
	return std::make_unique<Maze>(width, height);
}