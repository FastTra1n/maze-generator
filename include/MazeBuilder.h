#ifndef MAZEBUILDER_H
#define MAZEBUILDER_H

#include <memory>
#include <Maze.h>

class MazeBuilder {
public:
	MazeBuilder();

	MazeBuilder& setSize(int width, int height);
	std::unique_ptr<Maze> build();

private:
	int width, height;
};

#endif