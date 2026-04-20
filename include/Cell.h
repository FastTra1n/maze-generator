#ifndef CELL_H
#define CELL_H

class Cell {
public:
	Cell(int x = 0, int y = 0);
	~Cell() = default;

	int getX() const;
	int getY() const;

	bool isWall(int direction) const;
	void breakWall(int direction);
private:
	int x, y;
	bool walls[4];
};

#endif