/* ----------------------------------------------------------------------- */
/*                         MIQUEL VILLARROYA MARTÍ                         */
/* ----------------------------------------------------------------------- */

#ifndef CLASSES_H
#define CLASSES_H


// TO DO: Implement the base class Battalion here
class Battalion {
protected:
	const char* name;

public:
	Battalion(const char* pname) : name(pname){}

	const char* getName() const {
		return name;
	}

	virtual const int combatValue() const = 0;
};

// TO DO: Implement the derived class Infantry here
class Infantry : public Battalion {
private:
	const int bayonetSoldiers, musketSoldiers;

public:
	Infantry(const char* name, const int bay, const int musk) : Battalion(name),
	bayonetSoldiers(bay), musketSoldiers(musk) {}
	
	const int combatValue() const override {
		return bayonetSoldiers * 1 + musketSoldiers * 2;
	}
};


// TO DO: Implement the derived class Chivalry here

class Chivalry : public Battalion {
private:
	const int lightChivalry, heavyChivalry;

public:
	Chivalry(const char* name, const int light, const int heavy) : Battalion(name),
		lightChivalry(light), heavyChivalry(heavy) {}

	const int combatValue() const override {
		return lightChivalry * 3 + heavyChivalry * 4;
	}
};

// TO DO: Implement the derived class Artillery here

class Artillery : public Battalion {
private:
	const int mortars, cannons;

public:
	Artillery(const char* name, const int mort, const int can) : Battalion(name),
		mortars(mort), cannons(can) {}

	const int combatValue() const override {
		return mortars * 5 + cannons * 6;
	}
};

const char* victoryInBattlefield(const Battalion* const div1, const Battalion* const div2)
{
	// TO DO: introduce the code of the function here
	if (div1->combatValue() > div2->combatValue()) return div1->getName();
	else if (div1->combatValue() < div2->combatValue()) return div2->getName();
	else return "Same combat value";
}


#endif // CLASSES_H