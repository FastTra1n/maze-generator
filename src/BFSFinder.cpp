#include "BFSFinder.h"
#include "Maze.h"
#include <queue>
#include <vector>
#include <algorithm>

std::vector<Cell> BFSFinder::findPath(Maze& maze, Cell& start, Cell& end) {
    int width = maze.getWidth();
    int height = maze.getHeight();
    int startX = start.getX(), startY = start.getY();
    int endX = end.getX(), endY = end.getY();

    std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));
    std::vector<std::vector<std::pair<int, int>>> parent(height, std::vector<std::pair<int, int>>(width, {-1, -1}));
    std::queue<std::pair<int, int>> q;

    q.push({ startY, startX });
    visited[startY][startX] = true;

    const int dx[4] = { 0, 1, 0, -1 };
    const int dy[4] = { -1, 0, 1, 0 };

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == endX && y == endY) break;
        for (int dir = 0; dir < 4; ++dir)
        {
            if (maze.getCell(x, y).isWall(dir)) continue;
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= width || ny < 0 || ny >= height) continue;
            if (!visited[ny][nx]) {
                visited[ny][nx] = true;
                parent[ny][nx] = { x, y };
                q.push({ nx, ny });
            }
        }
    }

    std::vector<Cell> path;
    if (visited[endY][endX]) {
        int y = endY, x = endX;
        while (!(x == startX && y == startY)) {
            path.push_back(maze.getCell(x, y));
            auto [px, py] = parent[y][x];
            x = px;
            y = py;
        }
        path.push_back(maze.getCell(startX, startY));
        std::reverse(path.begin(), path.end());
    }
    return path;
}