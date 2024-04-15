#pragma once
#include <iostream>
using namespace std;

class Bird{

protected:
	int numberOfEggs = 0;

public:
	const char* name;
	bool canFly = true;

};

class FlyingBird : public Bird {
	void Fly() {
	}
};

class Penguin : public Bird{

public:
	Penguin() {
		canFly = false;
		numberOfEggs++;
	}
	unsigned int swimSpeed;
	void Swim() {

	}
};

class Ingredient {
protected:
	float weight;

public:
	float GetWeight() const {
		return weight;
	}
};

class Sugar : public Ingredient {

public:
	Sugar() {
		weight = 200;
	}
};

class Egg : public Ingredient{

public:
	Egg() {
		weight = 180;
	}
};

class Flour : public Ingredient{

public:
	Flour() {
		weight = 300;
	}
};

class Food {

protected:
	float weight;
};

class Cake : public Food {
private:	
	Ingredient* sugar;
	Ingredient* egg;
	Ingredient* flour;

public:
	Cake() {
		sugar = new Sugar();
		egg = new Egg();
		flour = new Flour();
	}

	~Cake() {
		delete sugar;
		delete egg;
		delete flour;
	}

	void Mix() {
		weight += sugar->GetWeight();
		weight += egg->GetWeight();
		weight += flour->GetWeight();
	}

	void Bake() {
		weight *= 0.95;
	}

	float GetWeight() {
		return weight;
	}
};

class Cheesecake : public Cake {

};

class Creature {
private:
	int hp = 95;

public:
	int ApplyDamage(int damage) {
		hp -= damage;
		return damage / 10;
	}
	int GetHP() {
		return hp;
	}
};

class Pokemon : public Creature{
private:
	int ad = 10;

public:
	void DealDamage(Creature* objective) {
		int thorns = objective->ApplyDamage(ad);
		ApplyDamage(thorns);
	}
};

class Person {
public:
	int iq;

	Person(int iq) {
		this->iq = iq;
	}
};

class Teacher : public Person {
public:
	Teacher(int iq) : Person(iq) {
		this->iq = 99;
	}
};

int main() {
	
	//Person test (Constructor / Destructor)
	Teacher teacher (3);
	cout << teacher.iq << endl << endl;

	//Pokemon test
	Creature Sasel;
	Pokemon Infernape;

	cout << Infernape.GetHP() << endl;
	cout << Sasel.GetHP() << endl;
	Infernape.DealDamage(&Sasel);
	cout << Sasel.GetHP()<< endl;
	cout << Infernape.GetHP() << endl << endl;

	//Penguin test
	Penguin pingu;
	Cake MyCake;

	//Cake test
	cout << MyCake.GetWeight() << endl;
	
	MyCake.Mix();
	MyCake.Bake();

	cout <<  MyCake.GetWeight()<< endl;
}

//Make a battle of several pokemon that can deal and receive damage