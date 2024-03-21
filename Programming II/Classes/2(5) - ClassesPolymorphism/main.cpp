#include <iostream>
using namespace std;

class Weapon {
public:
	virtual void DealDamage() {
		cout << "Damaged!" << endl;
	}
};

class Gun : public Weapon {
public:
	void DealDamage(int d){
		cout << "shot" << endl;
	}
};

class Knife : public Weapon {
public:
	void DealDamage() override {
		cout << "stab" << endl;
	}
};

class Animal {
public:
	virtual void Speak() = 0;
	virtual void Eat() = 0;
	virtual ~Animal() {
	}
};

class Dog : public Animal {
	int teeth;
public:
	void Speak() override{
		cout << "bark bark!" << endl;
	}
	void Eat() override {
		cout << "Sausage" << endl;
	}
};

class Cat : public Animal {
	int age;
public:
	void Speak() override {
		cout << "miauu!" << endl;
	}
	void Eat() override {
		cout << "Fishy fish" << endl;
	}

};

void Record(Animal* animal) {
	animal->Speak();
}

int main() {
	
	//Animal Exercise
	//Animal* animal = new Animal; --> Can't initiate because it is a pure virtual class.
	Animal* dog = new Dog;
	dog->Speak();
	dog->Eat();
	Animal* cat = new Cat;
	cat->Speak();
	cat->Eat();

	Animal** animals = new Animal*[3];

	animals[0] = new Cat;
	animals[1] = new Dog;
	animals[2] = new Cat;

	for (int i = 0; i < 3; i++) {
		Record(animals[i]);
		animals[i]->Eat();
	}

	delete dog;
	delete cat;
	delete[] animals;

	cout << endl;
	//Weapon example
	Knife* knife = new Knife;
	knife->DealDamage();

	Weapon* otherKnife = new Knife;
	otherKnife->DealDamage();

	Weapon* gun = new Gun;
	gun->DealDamage();
	
	delete knife;
	delete otherKnife;
	delete gun;

	return 0;
}