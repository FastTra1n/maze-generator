#include "AStarFinder.h"
#include "Maze.h"
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

struct Node {
	int x, y;
	double weight;
	bool operator > (const Node& other) const { return weight > other.weight; }
};

double heuristic(int x1, int y1, int x2, int y2) {
	return std::abs(x1 - x2) + std::abs(y1 - y2);
}

std::vector<Cell> AStarFinder::findPath(Maze& maze, Cell& start, Cell& end) {
	int width = maze.getWidth();
	int height = maze.getHeight();
	int startX = start.getX(), startY = start.getY();
	int endX = end.getX(), endY = end.getY();

	std::vector<std::vector<double>> gScore(height, std::vector<double>(width, INFINITY));
	std::vector<std::vector<std::pair<int, int>>> parent(height, std::vector<std::pair<int, int>>(width, {-1, -1}));
	std::vector<std::vector<bool>> closed(height, std::vector<bool>(width, false));

	gScore[startY][startX] = 0;

	std::priority_queue<Node, std::vector<Node>, std::greater<Node>> openSet;
	openSet.push({ startX, startY, heuristic(startX, startY, endX, endY) });

	const int dx[4]{ 0, 1, 0, -1 };
	const int dy[4]{ -1, 0, 1, 0 };

	while (!openSet.empty())
	{
		Node current = openSet.top();
		openSet.pop();
		int x = current.x, y = current.y;

		if (closed[y][x]) continue;
		closed[y][x] = true;

		if (x == endX && y == endY) break;

		for (int dir = 0; dir < 4; ++dir)
		{
			if (maze.getCell(x, y).isWall(dir)) continue;

			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= width || ny < 0 || ny >= height) continue;
			if (closed[ny][nx]) continue;

			double currentG = gScore[y][x] + 1; // Стоимость перемещения.
			if (currentG < gScore[ny][nx])
			{
				gScore[ny][nx] = currentG;
				parent[ny][nx] = { x, y };
				double h = heuristic(nx, ny, endX, endY);
				openSet.push({ nx, ny, currentG + h });
			}
		}
	}

	// Восстановление пути.
	std::vector<Cell> path;
	if (gScore[endY][endX] != INFINITY)
	{
		int x = endX, y = endY;
		while (!(x == startX && y == startY))
		{
			path.push_back(maze.getCell(x, y));
			auto p = parent[y][x];
			x = p.first;
			y = p.second;
		}
		path.push_back(maze.getCell(startX, startY));
		std::reverse(path.begin(), path.end());
	}
	return path;
}