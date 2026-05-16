#include "test_helpers.h"
#include "Maze.h"
#include <cmath>
#include <set>
#include <queue>

bool wallsMatch(const Cell& a, const Cell& b, int dir) {
	int opposite = (dir + 2) % 4;
	return a.isWall(dir) == b.isWall(opposite);
}

bool allWallsConsistent(const Maze& maze) {
	for (int y = 0; y < maze.getHeight(); ++y)
	{
		for (int x = 0; x < maze.getWidth(); ++x)
		{
			const Cell& c = maze.getCell(x, y);

			if (x + 1 < maze.getWidth()) {
				if (!wallsMatch(c, maze.getCell(x + 1, y), 1)) {
					return false;
				}
			}
			if (y + 1 < maze.getHeight()) {
				if (!wallsMatch(c, maze.getCell(x, y + 1), 2)) {
					return false;
				}
			}
		}
	}
	return true;
}

int countPassages(const Maze& maze) {
	int passages = 0;
	for (int y = 0; y < maze.getHeight(); ++y)
	{
		for (int x = 0; x < maze.getWidth(); ++x)
		{
			const Cell& c = maze.getCell(x, y);

			if (x + 1 < maze.getWidth() && !c.isWall(1)) ++passages;
			if (y + 1 < maze.getHeight() && !c.isWall(2)) ++passages;
		}
	}
	return passages;
}

bool isConnected(const Maze& maze) {
	int w = maze.getWidth(), h = maze.getHeight();
	std::vector<std::vector<bool>> visited(h, std::vector<bool>(w, false));
	std::queue<std::pair<int, int>> q;

	q.push({ 0, 0 });
	visited[0][0] = true;

	int visitedCount = 0;
	while (!q.empty()) {
		auto [cx, cy] = q.front(); q.pop();
		++visitedCount;

		const int dx[4] = { 0, 1, 0, -1 };
		const int dy[4] = { -1, 0, 1, 0 };
		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cx + dx[dir];
			int ny = cy + dy[dir];
			if (nx >= 0 && nx < w &&
				ny >= 0 && ny < h &&
				!maze.getCell(cx, cy).isWall(dir) &&
				!visited[ny][nx]) {
				visited[ny][nx] = true;
				q.push({ nx, ny });
			}
		}
	}
	return visitedCount == w * h;
}

bool isValidPath(const Maze& maze, const std::vector<Cell>& path, const Cell& start, const Cell& end) {
	if (path.empty()) return false;
	if (path.front().getX() != start.getX() || path.front().getY() != start.getY()) return false;
	if (path.back().getX() != end.getX() || path.back().getY() != end.getY()) return false;
	for (int i = 0; i < path.size() - 1; ++i)
	{
		int dx = path[i + 1].getX() - path[i].getX();
		int dy = path[i + 1].getY() - path[i].getY();
		if (abs(dx) + abs(dy) != 1) return false;
	}

	std::set<std::pair<int, int>> seen;
	for (auto& c : path)
	{
		if (!seen.insert({ c.getX(), c.getY() }).second) return false;
	}
	return true;
}