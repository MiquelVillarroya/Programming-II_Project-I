#include <iostream>
using namespace std;

class Rectangle {
private:
	int x, y;

public:
	Rectangle() : x(0), y(0) {}
	Rectangle(int x, int y) {
		this->x = x;
		this->y = y;
	}
	friend void Transpose(Rectangle* rect);
	void GetRect() {
		cout << x << " " << y << endl;
	}
	friend Rectangle operator+=(const Rectangle& rect, const Rectangle& rect2);
};

Rectangle operator+=(const Rectangle& rect, const Rectangle& rect2) {
	Rectangle r;
	r.x = rect.x + rect2.x;
	r.y = rect.y + rect2.y;
	return r;
}

 void Transpose(Rectangle* rect) {
	int temp = rect->x;
	rect->x = rect->y;
	rect->y = temp;
}

 class Vector3 {
 private:
	 int x, y, z;

 public:
	 Vector3(int x, int y, int z) {
		 this->x = x;
		 this->y = y;
		 this->z = z;
	 }

	 friend class Math;

	 //friend int Math::DotProduct(const Vector3& v1, const Vector3& v2);
 };

 class Math {
 public:
	 int DotProduct(const Vector3& v1, const Vector3& v2) {
		 return v1.x * v2.x;
	 }

	 Vector3 CrossProduct(const Vector3& v1, const Vector3& v2) {
		 Vector3 v(0, 0, 0);
		 v.x = v1.x * v2.x;
		 v.y = v1.y * v2.y;
		 v.z = v1.z * v2.z;
		 return v;
	 }
 };

int main() {

	Rectangle r(2, 3);
	Rectangle r2(10, 10);
	r.GetRect();
	Transpose(&r);
	r.GetRect();

	r += r2;
	r.GetRect();

	Vector3 v1(1,2,3);
	Vector3 v2(4,5,6);
	Math myMath;
	cout << myMath.DotProduct(v1, v2);
}