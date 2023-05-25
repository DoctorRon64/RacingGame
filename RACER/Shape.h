#pragma once

class Shape {

private:
	int width, height;
	float alpha;

public:
	Shape();
	Shape(int w, int h);
	void setAlpha(float a);
	float area();
	void draw();
};

