#include "Maze.h"
#include "KruskalGenerator.h"
#include "AStarFinder.h"
#include "test_helpers.h"
#include <iostream>

int main() {
    Maze maze(5, 5);
    KruskalGenerator gen;
    maze.generate(gen);

    Cell start(2, 2);
    Cell end(2, 2);
    AStarFinder astar;
    auto path = maze.findPath(astar, start, end);
    if (!path.empty() && path.size() == 1 && path[0].getX() == 2 && path[0].getY() == 2) {
        std::cout << "—ценарий є4 пройден." << std::endl;
        return 0;
    }
    else {
        std::cerr << "ќшибка: путь из клетки в саму себ€ не найден или некорректен." << std::endl;
        return 1;
    }
}