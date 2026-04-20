#include <Cell.h>

Cell::Cell(int x, int y) : x(x), y(y) {
	for (int i = 0; i < 4; i++) walls[i] = true;
}

int Cell::getX() const { return x; }
int Cell::getY() const { return y; }

bool Cell::isWall(int direction) const { 
	return walls[direction]; 
}
void Cell::breakWall(int direction) {
	walls[direction] = false;
}