#include<iostream>
using namespace std;

class Vector3 {
public:
	int x, y, z;

	Vector3(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	bool operator==(const Vector3& vec) const {
		return this->x == vec.x && this->y == vec.y && this->z == vec.z;
	}
};

class Box {
private:
	int x, y, z;

public:
	void SetSize(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	void SetSize(const Vector3* v) {
		this->x = v->x;
		this->y = v->y;
		this->z = v->z;
	}
	void SetSize(const Box &box) {
		this->x = box.x;
		this->y = box.y;
		this->z = box.z;
	}

};


int main() {
	
	//Overloading operators
	Vector3 v1(1, 1, 1);
	Vector3 v2(2, 2, 2);
	Vector3 v3(2, 2, 2);

	if (v2 == v3) {
		cout << "they are the same" << endl;
	}
	else {
		cout << "they are NOT the same" << endl;
	}

	// Overloading function
	Box b1;
	b1.SetSize(1, 1, 1);

	Box b2;
	Vector3 v(9, 8, 7);
	b2.SetSize(&v);

	Box b3;
	b3.SetSize(b1);

	return 0;
}