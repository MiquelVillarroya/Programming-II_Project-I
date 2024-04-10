#include "Ex1.h"
#include "Ex2.h"
#include "Ex3.h"
#include "UnitTest.h"
#include <cstdlib>
using namespace std;

// Uncomment these lines in order to execute the tests
#define TEST_EX1
#define TEST_EX2
#define TEST_EX3

void unitTests();

int main()
{
	unitTests();
	system("pause");
	return 0;
}

void unitTests()
{
#ifdef TEST_EX1
	// Ex1.h ///////////////////////////////////////////////////////////
	Race *human = new Human;
	Race *elf = new NightElf;
	Race *orc = new Orc;
	Race *troll = new Troll;
	{ // name()
		const bool ok1 = human->name() == std::string("Human");
		const bool ok2 = elf->name() == std::string("NightElf");
		const bool ok3 = orc->name() == std::string("Orc");
		const bool ok4 = troll->name() == std::string("Troll");
		TEST("Ex1.h - Race::name()", ok1 && ok2 && ok3 && ok4);
	}
	{ // faction()
		const bool ok1 = human->faction() == Faction::Alliance;
		const bool ok2 = elf->faction() == Faction::Alliance;
		const bool ok3 = orc->faction() == Faction::Horde;
		const bool ok4 = troll->faction() == Faction::Horde;
		TEST("Ex1.h - Race::faction()", ok1 && ok2 && ok3 && ok4);
	}
	{ // acceptsRole()
		const bool ok1 = human->acceptsRole(Role::Priest) && human->acceptsRole(Role::Rogue) && human->acceptsRole(Role::Warrior) && human->acceptsRole(Role::Mage) && !human->acceptsRole(Role::Druid) && !human->acceptsRole(Role::Hunter) && human->acceptsRole(Role::Warlock) && !human->acceptsRole(Role::Shaman) && human->acceptsRole(Role::Paladin);
		const bool ok2 = elf->acceptsRole(Role::Priest) && elf->acceptsRole(Role::Rogue) && elf->acceptsRole(Role::Warrior) && !elf->acceptsRole(Role::Mage) && elf->acceptsRole(Role::Druid) && elf->acceptsRole(Role::Hunter) && !elf->acceptsRole(Role::Warlock) && !elf->acceptsRole(Role::Shaman) && !elf->acceptsRole(Role::Paladin);
		const bool ok3 = !orc->acceptsRole(Role::Priest) && orc->acceptsRole(Role::Rogue) && orc->acceptsRole(Role::Warrior) && !orc->acceptsRole(Role::Mage) && !orc->acceptsRole(Role::Druid) && orc->acceptsRole(Role::Hunter) && orc->acceptsRole(Role::Warlock) && orc->acceptsRole(Role::Shaman) && !orc->acceptsRole(Role::Paladin);
		const bool ok4 = troll->acceptsRole(Role::Priest) && troll->acceptsRole(Role::Rogue) && troll->acceptsRole(Role::Warrior) && troll->acceptsRole(Role::Mage) && !troll->acceptsRole(Role::Druid) && troll->acceptsRole(Role::Hunter) && !troll->acceptsRole(Role::Warlock) && troll->acceptsRole(Role::Shaman) && !troll->acceptsRole(Role::Paladin);
		TEST("Ex1.h - Race::acceptsRole()", ok1 && ok2 && ok3 && ok4);
	}
	delete orc;
	delete troll;
	delete human;
	delete elf;
#else
	std::cout << "\t!\tUncomment #define TEST_EX1 in main.cpp to test Ex1.h" << std::endl;
#endif

#ifdef TEST_EX2
	// Ex2.h ///////////////////////////////////////////////////////////
	{
		GameObject *objects = new GameObject[10];
		objects[0].setLayer(Layer::Background);
		objects[1].setLayer(Layer::Scene);
		objects[2].setLayer(Layer::Scene);
		objects[3].setLayer(Layer::Scene);
		objects[4].setLayer(Layer::Characters);
		objects[5].setLayer(Layer::Foreground);
		objects[6].setLayer(Layer::Foreground);
		objects[7].setLayer(Layer::Foreground);
		objects[8].setLayer(Layer::UserInterface);
		objects[9].setLayer(Layer::UserInterface);
		const bool ok1 = objects[0].layer() == Layer::Background;
		const bool ok2 = objects[1].layer() == Layer::Scene;
		const bool ok3 = objects[4].layer() == Layer::Characters;
		const bool ok4 = objects[5].layer() == Layer::Foreground;
		const bool ok5 = objects[8].layer() == Layer::UserInterface;
		TEST("Ex2.h - GameObject::setLayer() / GameObject::layer()", ok1 && ok2 && ok3 && ok4 && ok5);
		const bool cok1 = countGameObjectsInLayer(objects, 10, Layer::Background) == 1;
		const bool cok2 = countGameObjectsInLayer(objects, 10, Layer::Characters) == 1;
		const bool cok3 = countGameObjectsInLayer(objects, 10, Layer::Scene) == 3;
		const bool cok4 = countGameObjectsInLayer(objects, 10, Layer::Foreground) == 3;
		const bool cok5 = countGameObjectsInLayer(objects, 10, Layer::UserInterface) == 2;
		TEST("Ex2.h - countGameObjectsInLayer()", cok1 && cok2 && cok3 && cok4 && cok5);
		delete[] objects;
	}
#else
	std::cout << "\t!\tUncomment #define TEST_EX2 in main.cpp to test Ex2.h" << std::endl;
#endif

#ifdef TEST_EX3
	// Ex3.h ///////////////////////////////////////////////////////////
	{
		const vec3 nullvec;
		const vec3 i(1);
		const vec3 x(1, 0, 0);
		const vec3 y(0, 1, 0);
		const vec3 z(0, 0, 1);
		const vec3 xy(2, 2, 0);
		const vec3 xz(3, 0, 3);
		const vec3 yz(0, 4, 4);
		const bool ok1 = x * y == 0;
		const bool ok2 = x * i == 1;
		const bool ok3 = xy * i == 4;
		const bool ok4 = xz * i == 6;
		const bool ok5 = yz * i == 8;
		const bool ok6 = xz * yz == 12;
		TEST("Ex3.h - operator* / dot product", ok1 && ok2 && ok3 && ok4 && ok5 && ok6);
	}
#else
	std::cout << "\t!\tUncomment #define TEST_EX3 in main.cpp to test Ex3.h" << std::endl;
#endif

	PRINT_TEST_REPORT();
}
