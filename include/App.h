#ifndef APP_H
#define APP_H

#include <memory>
#include "Maze.h"
#include "IGeneratorStrategy.h"
#include "IPathFinderStrategy.h"

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

	void showMenu();
	void handleCommand(int choice);
	void setMazeSize();
	void setGenerator();
	void setFinder();
	void generate();
	void display();

	std::unique_ptr<IGeneratorStrategy> createGenerator(int generatorType);
};

#endif