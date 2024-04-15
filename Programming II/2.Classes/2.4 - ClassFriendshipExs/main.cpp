#include <iostream>
using namespace std;

class Item {
private:
	string name;

public:
	Item(const string iName) : name(iName) {}
	~Item() {}
	friend class Player;
};

class Player {
private:
	string name;
	unsigned short numLifes;
	bool invincible;
	bool* capabilities = new bool[3];
	bool* weapon = new bool[3];

public:
	Player(const string pName) : name(pName), numLifes(3), invincible(false){
		capabilities[0] = false;
		capabilities[1] = true;
		capabilities[2] = false;
		weapon[0] = false;
		weapon[1] = false;
		weapon[2] = false;
	}
	~Player() {
		delete[] capabilities;
		delete[] weapon;
	}

	void getName() const {
		cout << "Name: " << name << endl;
	}
	void PrintNumLifes() const {
		cout << "Life nº: " << numLifes << endl;
	}
	void PrintInvincible() const {
		cout << "Invincible: ";
		if (invincible) cout << "yes" << endl;
		else			cout << "no" << endl;
	}
	void PrintCapabilities() const {
		for (int i = 0; i < 3; i++) {
			if (capabilities[i] == true) cout << "Capability: " << i + 1 << endl;
		}
	}
	void PrintWeapon() const {
		for (int i = 0; i < 3; i++) {
			if (weapon[i] == true) cout << "Weapon: " << i + 1 << endl;
		}
	}
	bool operator==(const Player &p) const {
		if (this->name == p.name) return true;
		return false;
	}

	void useItem(const Item &item) {
		if (item.name == "One_Up") {
			numLifes++;
			if (numLifes > 99) numLifes = 99;
		}
		else if (item.name == "Mini_Mario") {
			capabilities[0] = true;
			capabilities[1] = false;
			capabilities[2] = false;
		}
		else if (item.name == "Super_Mario") {
			capabilities[0] = false;
			capabilities[1] = false;
			capabilities[2] = true;
		}
		else if (item.name == "Fire_Flower") {
			weapon[0] = true;
			weapon[1] = false;
			weapon[2] = false;
		}
		else if (item.name == "Ice_Flower") {
			weapon[0] = false;
			weapon[1] = true;
			weapon[2] = false;
		}
		else if (item.name == "Golden_Flower") {
			weapon[0] = false;
			weapon[1] = false;
			weapon[2] = true;
		}
	}

	friend void starTouched(Player &p);
};

void starTouched(Player &p) {
	p.invincible = true;
}

int main() {
	string name;
	cout << "Player name: ";
	cin >> name;
	Player p1(name);

	while (true) {
		string input;
		cout << "\"Quit\" for Exit, \"Star\" for Invincibility or introduce an item name" << endl;
		cin >> input;

		if (input == "Quit") break;
		else if (input == "Star") starTouched(p1);
		else {
			Item item(input);
			p1.useItem(item);
		}
		p1.getName();
		p1.PrintNumLifes(); 
		p1.PrintInvincible();
		p1.PrintCapabilities();
		p1.PrintWeapon();
		cout << endl;
	}

}