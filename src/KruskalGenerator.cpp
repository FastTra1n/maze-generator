#include "KruskalGenerator.h"
#include "Maze.h"
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>

struct Edge {
	int x1, y1;
	int x2, y2;
	int dir;
};

class DSU {
public:
	DSU(int n) : parent(n) {
		for (int i = 0; i < n; i++) parent[i] = i;
	}

	int find(int x) {
		if (parent[x] == x) {
			return x;
		}
		parent[x] = find(parent[x]);
		return parent[x];
	}

	bool unite(int a, int b) {
		int rootA = find(a), rootB = find(b);
		if (rootA != rootB) {
			parent[rootA] = rootB;
			return true;
		}
		return false;
	}
private:
	std::vector<int> parent;
};

int cellIndex(int x, int y, int width) { return y * width + x; }

void KruskalGenerator::generate(Maze& maze) {
	int width = maze.getWidth();
	int height = maze.getHeight();
	int totalCells = width * height;

	std::vector<Edge> edges;

	// Направления: 0 - север, 1 - восток, 2 - юг, 3 - запад.
	const int dx[4] = { 0, 1, 0, -1 }; // Плюс - вперёд, минус - назад.
	const int dy[4] = { 1, 0, -1, 0 };
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			if (x + 1 < width) {
				Edge e;
				e.x1 = x; e.y1 = y;
				e.x2 = x+1; e.y2 = y;
				e.dir = 1;
				edges.push_back(e);
			}

			if (y + 1 < height) {
				Edge e;
				e.x1 = x; e.y1 = y;
				e.x2 = x; e.y2 = y+1;
				e.dir = 2;
				edges.push_back(e);
			}
		}
	}

	std::random_device rd;
	std::mt19937 gen(rd());
	std::shuffle(edges.begin(), edges.end(), gen);

	DSU dsu(totalCells);
	for (const Edge& e : edges)
	{
		int id1 = cellIndex(e.x1, e.y1, width);
		int id2 = cellIndex(e.x2, e.y2, width);
		if (dsu.find(id1) != dsu.find(id2)) {
			dsu.unite(id1, id2);
			Cell& cell1 = maze.getCell(e.x1, e.y1);
			Cell& cell2 = maze.getCell(e.x2, e.y2);
			if (e.dir == 1) { // Восток.
				cell1.breakWall(1);
				cell2.breakWall(3);
			} 
			else if (e.dir == 2) { // Юг.
				cell1.breakWall(2);
				cell2.breakWall(0);
			}
		}
	}
}