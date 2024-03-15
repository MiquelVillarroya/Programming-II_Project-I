#include <iostream>
using namespace std;

class Circle {
private:
	float x = 0, y = 0;
	float radius{ 99 };

public:
	Circle() : y(9) {
		y = 20;
		cout << "I am constructive " << x << endl;
		x = 0;
		y = 0;
		radius = 11;
	}
	Circle(float x, float y) : Circle() { //The Circle () sets the parameters to the stated at the private part
		this->x = x;
		this->y = y;
	}
	//Circle(const Circle& p) {
	//}
	Circle(const Circle& circle) { //classic copy constructor
		this->x = circle.x;
		this->y = circle.y;
		this->radius = circle.radius;

	}
	Circle(const Circle* circle) { //classic copy constructor
		this->x = circle->x;
		this->y = circle->y;
		this->radius = circle->radius;

	}
	~Circle() {	
		cout << "I am destructive " << x << " " << y << endl;
	}
	void SetX(int x_) {
		x = x_;
	}
	void SetY(int y_) {
		y = y_;
	}
	int GetX() {
		return x;
	}
	int GetY() {
		return y;
	}
	void Move(float x_, float y_) {
		x += x_;
		y += y_;
	}
	void ChangeSize(float m) {
		radius *= m;
	}


};

int main() {
	{
		Circle c;
		c.SetX(1);
		c.SetY(5);
	}

	Circle c2;
	c2.SetX(2);
	c2.SetY(5);

	c2.Move(0, 4);
	c2.ChangeSize(-2);
	cout << c2.GetX() << "/" << c2.GetY() << endl;

	Circle* ptrCircle = new Circle;
	ptrCircle->SetX(11);
	(*ptrCircle).SetY(12);
	
	Circle cc(&c2);
	Circle ccc(cc);

	delete ptrCircle;
	return 0;
}