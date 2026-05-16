#include "Maze.h"
#include "DFSGenerator.h"
#include "AStarFinder.h"
#include "test_helpers.h"
#include <iostream>

int main() {
    Maze maze(10, 10);
    DFSGenerator gen;

    maze.generate(gen);
    if (!allWallsConsistent(maze) || countPassages(maze) != 99 || !isConnected(maze)) {
        std::cerr << "Ошибка генерации лабиринта." << std::endl;
        return 1;
    }
    
    Cell start = maze.getCell(0, 0);
    Cell end = maze.getCell(9, 9);
    AStarFinder astar;

    auto path = maze.findPath(astar, start, end);
    if (path.empty() || !isValidPath(maze, path, start, end)) {
        std::cerr << "Ошибка при нахождении оптимального пути." << std::endl;
        return 1;
    }
    std::cout << "Сценарий №1 пройден." << std::endl;
    return 0;
}