#pragma once

class Shape {

private:
	int width, height;
	float alpha;

public:
	Shape();
	Shape(int w, int h);
	virtual void setAlpha(float a);
	virtual void Resize(int w, int h);
	virtual float area();
	virtual void draw();
};

