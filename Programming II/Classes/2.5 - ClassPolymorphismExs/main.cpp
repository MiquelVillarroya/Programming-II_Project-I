#pragma once
#include <iostream>
using namespace std;

class Pokemon {
protected:
	string name, type;
	unsigned int attack;

public:
	Pokemon(const string &pName) : name(pName), type("noType"), attack(10) {}
	string getName() {
		return name;
	}
	string getType() {
		return type;
	}
	virtual unsigned int damageAttack(Pokemon* const victim) = 0;
	virtual ~Pokemon(){}
};

class ElectricPokemon : public Pokemon {
public:
	ElectricPokemon(const string &pName) : Pokemon(pName){
		type = "Electric";
	}
	unsigned int damageAttack(Pokemon* const victim) override{
		if (victim->getType() == "Water") {
			return attack * 2;
		}
		else if (victim->getType() == "Grass") {
			return attack / 2;
		}
		return attack;
	}
};
class WaterPokemon : public Pokemon {
public:
	WaterPokemon(string pName) : Pokemon(pName) {
		type = "Water";
	}

	unsigned int damageAttack(Pokemon* const victim) override {
		if (victim->getType() == "Fire") {
			return attack * 2;
		}
		else if (victim->getType() == "Grass") {
			return attack / 2;
		}
		return attack;
	}
};
class GrassPokemon : public Pokemon {
public:
	GrassPokemon(string pName) : Pokemon(pName) {
		type = "Grass";
	}

	unsigned int damageAttack(Pokemon* const victim) override {
		if (victim->getType() == "Water") {
			return attack * 2;
		}
		else if (victim->getType() == "Fire") {
			return attack / 2;
		}
		return attack;
	}
};
class FirePokemon : public Pokemon {
public:
	FirePokemon(string pName) : Pokemon(pName) {
		type = "Fire";
	}

	unsigned int damageAttack(Pokemon* const victim) override {
		if (victim->getType() == "Grass") {
			return attack * 2;
		}
		else if (victim->getType() == "Water") {
			return attack / 2;
		}
		return attack;
	}
};

int main() {
	Pokemon* pikachu = new ElectricPokemon("Pikachu");
	Pokemon* bulbasaur = new GrassPokemon("Bulbasaur");
	Pokemon* charmander = new FirePokemon("Charmander");
	Pokemon* squirtle = new WaterPokemon("Squirtle");

	cout << "-- Damage Attacks --" << endl;
	cout << pikachu->getName() << " -> " << bulbasaur->getName()
		<<" = " << pikachu->damageAttack(bulbasaur) << " units\n";
	cout << bulbasaur->getName() << " -> " << squirtle->getName()
		<<" = " << bulbasaur->damageAttack(squirtle) << " units\n";
	cout << squirtle->getName() << " -> " << charmander->getName()
		<<" = " << squirtle->damageAttack(charmander) << " units\n";
	cout << charmander->getName() << " -> " << pikachu->getName()
		<<" = " << charmander->damageAttack(pikachu) << " units\n";

}