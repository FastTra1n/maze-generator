#include "Maze.h"
#include "DFSGenerator.h"
#include "KruskalGenerator.h"
#include "AStarFinder.h"
#include "test_helpers.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<std::pair<int, int>> sizes = { {5,5}, {10,10}, {15,15}, {100, 100}, {200, 200} };

    for (auto [w, h] : sizes) {
        Maze mazeDFS(w, h);
        DFSGenerator dfs;

        mazeDFS.generate(dfs);
        if (!isConnected(mazeDFS)) {
            std::cerr << "Ошибка: DFS-лабиринт не связен." << std::endl;
            return 1;
        }

        Maze mazeKruskal(w, h);
        KruskalGenerator kruskal;
        mazeKruskal.generate(kruskal);
        if (!isConnected(mazeKruskal)) {
            std::cerr << "Ошибка: Kruskal-лабиринт не связен." << std::endl;
            return 1;
        }

        Cell start(0, 0);
        Cell end(w - 1, h - 1);
        AStarFinder astar;
        auto path = mazeDFS.findPath(astar, start, end);
        if (path.empty() || !isValidPath(mazeDFS, path, start, end)) {
            std::cerr << "Ошибка при нахождении оптимального пути в DFS-лабиринте." << std::endl;
            return 1;
        }
    }

    std::cout << "Сценарий №3 пройден." << std::endl;
    return 0;
}