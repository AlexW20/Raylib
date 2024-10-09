#ifndef SHAPE_H
#define SHAPE_H
#include "raylib.h"

class Square {
private:
	int x, y, width, height;
	Color c = WHITE;
public:
	Square(int x, int y, int w, int h, Color c);
	void draw();
};


#endif