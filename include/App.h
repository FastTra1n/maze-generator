#ifndef APP_H
#define APP_H

#include "Maze.h"
#include "IGeneratorStrategy.h"
#include "IPathFinderStrategy.h"
#include <memory>
#include <optional>

class App {
public:
	App();
	~App() = default;

	void run();

private:
	std::unique_ptr<Maze> maze;
	std::unique_ptr<IGeneratorStrategy> generator;
	std::unique_ptr<IPathFinderStrategy> finder;

	int width, height;
	int startX, startY, endX, endY;
	std::vector<Cell> currentPath;
	std::optional<PathData> pathData;

	void showMenu();
	void handleCommand(int choice);
	void setMazeSize();
	void setGenerator();
	void setFinder();
	void setStartEndPoints();
	void findPath();
	void generate();
	void display();

	std::unique_ptr<IGeneratorStrategy> createGenerator(int generatorType);
	std::unique_ptr<IPathFinderStrategy> createFinder(int finderType);
};

#endif