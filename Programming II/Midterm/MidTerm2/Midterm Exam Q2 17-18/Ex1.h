/* ----------------------------------------------------------------------- */
/*                          TYPE YOUR NAME HERE                            */
/* ----------------------------------------------------------------------- */
#ifndef EX1_H
#define EX1_H

// Enumerated type for roles
enum class Role {
	Priest,
	Rogue,
	Warrior,
	Mage,
	Druid,
	Hunter,
	Warlock,
	Shaman,
	Paladin,
	Last
};

// Enumerated type for factions
enum class Faction {
	Alliance,
	Horde
};

// Race base class /////////////////////////////////////////////////////
// TODO
class Race {
protected:
	Role* roles;

public:
	Race() : roles(nullptr){}
	virtual ~Race(){}
	bool acceptsRole(Role r) {
		
	}
	virtual const char* name() const = 0;
	virtual Faction faction() const = 0;
};

// Human child class ///////////////////////////////////////////////////
// TODO

class Human : public Race {
public:
	Human(){
		roles[0] = Role::Priest;
		roles[1] = Role::Rogue;
		roles[2] = Role::Warrior;
		roles[3] = Role::Mage;
		roles[4] = Role::Warlock;
		roles[5] = Role::Paladin;
		roles[6] = Role::Last;
	}
	const char* name() const override {
		return "Human";
	}
	Faction faction() const override {
		return Faction::Alliance;
	}
};

// NightElf child class ////////////////////////////////////////////////
// TODO

class NightElf : public Race {
public:
	NightElf() {
		roles[0] = Role::Priest;
		roles[1] = Role::Rogue;
		roles[2] = Role::Warrior;
		roles[3] = Role::Druid;
		roles[4] = Role::Hunter;
		roles[5] = Role::Last;
	}
	const char* name() const override {
		return "NightElf";
	}
	Faction faction() const override {
		return Faction::Alliance;
	}
};

// Orc child class /////////////////////////////////////////////////////
// TODO

class Orc : public Race {
public:
	Orc() {
		roles[0] = Role::Rogue;
		roles[1] = Role::Warrior;
		roles[2] = Role::Hunter;
		roles[3] = Role::Warlock;
		roles[4] = Role::Shaman;
		roles[5] = Role::Last;
	}
	const char* name() const override {
		return "Orc";
	}
	Faction faction() const override {
		return Faction::Horde;
	}
};

// Troll child class ///////////////////////////////////////////////////
// TODO

class Troll : public Race {
public:
	Troll() {
		roles[0] = Role::Priest;
		roles[1] = Role::Rogue;
		roles[2] = Role::Warrior;
		roles[3] = Role::Mage;
		roles[4] = Role::Hunter;
		roles[5] = Role::Shaman;
		roles[6] = Role::Last;
	}
	const char* name() const override {
		return "Troll";
	}
	Faction faction() const override {
		return Faction::Horde;
	}
};

#endif
