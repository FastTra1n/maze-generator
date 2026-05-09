#include "DFSGenerator.h"
#include "Maze.h"
#include <stack>
#include <vector>
#include <random>
#include <iostream>

void DFSGenerator::generate(Maze& maze) {
	int width = maze.getWidth();
	int height = maze.getHeight();

	std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));
	
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distX(0, width - 1);
	std::uniform_int_distribution<int> distY(0, height - 1);
	int startX = distX(gen);
	int startY = distY(gen);

	std::stack<std::pair<int, int>> backtrack;
	backtrack.push({ startX, startY });
	visited[startY][startX] = true;

	// Направления: 0 - север, 1 - восток, 2 - юг, 3 - запад.
	const int dx[4] = { 0, 1, 0, -1 }; // Плюс - вперёд, минус - назад.
	const int dy[4] = { -1, 0, 1, 0 };
	const int opposite[4] = { 2, 3, 0, 1 }; // Противоположное направление.

	while (!backtrack.empty())
	{
		int x = backtrack.top().first;
		int y = backtrack.top().second;
		
		std::vector<int> neighbors;
		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx >= 0 && nx < width && ny >= 0 && ny < height && !visited[ny][nx]) {
				neighbors.push_back(dir);
			}
		}

		if (!neighbors.empty())
		{
			std::uniform_int_distribution<int> distN(0, neighbors.size() - 1);
			int chosenDir = neighbors[distN(gen)];
			int nx = x + dx[chosenDir];
			int ny = y + dy[chosenDir];

			Cell& current = maze.getCell(x, y);
			Cell& next = maze.getCell(nx, ny);
			current.breakWall(chosenDir);
			next.breakWall(opposite[chosenDir]);

			visited[ny][nx] = true;
			backtrack.push({ nx, ny });
		}
		else {
			backtrack.pop();
		}
	}
}