#include "Maze.h"
#include "KruskalGenerator.h"
#include "BFSFinder.h"
#include "test_helpers.h"
#include <iostream>

int main() {
    Maze maze(12, 12);
    KruskalGenerator gen;
    maze.generate(gen);

    if (!isConnected(maze)) {
        std::cerr << "Ошибка: лабиринт не связен." << std::endl;
        return 1;
    }

    Cell start(0, 0);
    Cell end(11, 11);
    BFSFinder bfs;
    auto path = maze.findPath(bfs, start, end);

    if (path.empty() || !isValidPath(maze, path, start, end)) {
        std::cerr << "Ошибка при попытке нахождения оптимального пути." << std::endl;
        return 1;
    }

    std::cout << "Сценарий №2 пройден." << std::endl;
    return 0;
}