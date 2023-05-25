#pragma once

class Shape {

protected:
	int width, height;
	int lineThickness;
	float alpha;
	float xPos, yPos;

public:
	Shape(float x, float y, int w, int h, int line, float a);
	virtual void setAlpha(float a);
	virtual void setPosition(int x, int y);
	virtual void Resize(int w, int h);
	virtual void setLineThickness(int lineT);
	virtual float area();
	virtual void draw();
};

