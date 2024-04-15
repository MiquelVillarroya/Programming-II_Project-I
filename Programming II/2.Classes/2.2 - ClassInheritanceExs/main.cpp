#pragma once
#include <iostream>
using namespace std;

class Building {
protected:
	string name;


public:

	//Building(){}

	Building(string name) {
		this->name = name;
	}

	string getName() const {
		return name;
	}
};

class Warehouse : public Building {
private:
	int wood, rocks, wheat;

public:
	Warehouse(string name, int wood, int rocks, int wheat) : Building(name) {
		//this->name = name;
		this->wood = wood;
		this->rocks = rocks;
		this->wheat = wheat;
	}

	void printResources() const {
		cout << "-- " << name << " --" << endl;
		cout << "Wood: " << wood << endl;
		cout << "Rocks: " << rocks << endl;
		cout << "Wheat: " << wheat << endl;
	}
};

class House : public Building {
private:
	int floors, inhabitants, servants;

public:
	House(string name, int floors, int inhabitants, int servants) : Building(name) {
		//this->name = name;
		this->floors = floors;
		this->inhabitants = inhabitants;
		this->servants = servants;
	}

	void printResources() const {
		cout << "-- " << name << " --" << endl;
		cout << "Num. floors:  " << floors << endl;
		cout << "Num. inhabitants:  " << inhabitants << endl;
		cout << "Num. servants:  " << servants << endl;
	}
};

class Temple : public Building {
private:
	string god;
	int priests;

public:
	Temple(string name, string god, int priests) : Building(name) {
		//this->name = name;
		this->god = god;
		this->priests = priests;
	}

	void printResources() const {
		cout << "-- " << name << " --" << endl;
		cout << "God: " << god << endl;
		cout << "Num. priests: " << priests << endl;
	}
};

void ex1() {
	Warehouse w("East Warehouse", 10, 20, 30);
	House h("Agripa's house", 2, 5, 10);
	Temple t("Mercury's Temple", "Mercury", 3);

	cout << "Warehouse name: " << w.getName() << endl << endl;

	w.printResources();
	h.printResources();
	t.printResources();

}

void printArray(int* vec) {

	for (int i = 0; i < 5; i++){
		cout << *(vec + i);
	}
	cout << endl;
}

void reverse(int* vec) {
	int aux[5];
	int* ptr = &aux[0];

	for (int i = 0; i < 5; i++) {
		*(ptr + i) = *(vec + 4 - i);
	}

	for (int i = 0; i < 5; i++) {
		*(vec + i) = *(ptr + i);
	}
	cout << endl;
}

void ex2() {
	int vec[5] = {5, 7, 3, 9, 3};
	printArray(&vec[0]);
	reverse(&vec[0]);
	printArray(&vec[0]);

}

int main() {
	ex1();
	cout << endl;

	ex2();
	cout << endl;
}



