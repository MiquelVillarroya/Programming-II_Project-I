#include <iostream> // cout, endl...
#include <cmath> // sqrt
#include <cstdlib> // system
#include <cstring> // strcmp
using namespace std;

#include "Weapons.h"

const int NUM_ENEMIES = 10;
const int NUM_GRENADES = 4;
const int NUM_MISSILES = 3;

// Globals
bool ok = true;
const char *missileTargets[] = { "Tank 0", "Tank 0", "Boss 1" };
int iteration = 0;
int state[7][NUM_ENEMIES] = {
	{ 5, 5, 3, 10, 5, 20, 5, 5, 5, 10 },
	{ 5, 5, 0, 7, 2, 20, 5, 5, 5, 10 },
	{ 5, 5, 0, 7, 2, 20, 5, 3, 5, 8 },
	{ 5, 5, 0, 7, 2, 20, 5, 3, 5, 6 },
	{ 5, 5, 0, 7, 2, 10, 5, 3, 5, 6 },
	{ 5, 5, 0, 7, 2, 0, 5, 3, 5, 6 },
	{ 5, 5, 0, 7, 2, 0, 5, 3, 5, 0 }
};


// Macros
#define SET_ENEMY(ID, NAME, X, Y, LIFE) \
	enemies[ID].name = NAME; \
	enemies[ID].x = X; \
	enemies[ID].y = Y; \
	enemies[ID].life = LIFE;

#define SET_GRENADE(ID, X, Y, RADIUS, DAMAGE) \
	grenades[ID].x = X; \
	grenades[ID].y = Y; \
	grenades[ID].radius = RADIUS; \
	grenades[ID].damage = DAMAGE;

#define SET_MISSILE(ID, TARGET_NAME, DAMAGE) \
	missiles[ID].targetName = TARGET_NAME; \
	missiles[ID].damage = DAMAGE;


bool checkStateAtIteration(Enemy *enemies, int numEnemies, int iter)
{
	bool ok = true;
	//cout << "State at iteration " << iter << endl;
	for (int i = 0; i < numEnemies; ++i) {
		Enemy *enemyPtr = enemies + i;
		//cout << enemyPtr->name << " - " << enemyPtr->life << flush;
		if (enemyPtr->life == state[iteration][i]) {
			//cout << endl;
		}
		else {
			ok = false;
			//cout << " - ERROR" << endl;
		}
	}
	//if (ok) {
	//	cout << " - Everything is OK!" << endl;
	//}
	//else {
	//	cout << " - There are some ERRORS..." << endl;
	//}
	return ok;
}


int main(int argc, char **argv)
{
	// Initialize list of enemies
	Enemy enemies[NUM_ENEMIES];
	SET_ENEMY(0, "Enemy 0", 2, 2, 5);
	SET_ENEMY(1, "Enemy 1", 3, 15, 5);
	SET_ENEMY(2, "Enemy 2", 4, 12, 5);
	SET_ENEMY(3, "Boss 0", 4, 14, 10);
	SET_ENEMY(4, "Enemy 3", 6, 14, 5);
	SET_ENEMY(5, "Tank 0", 9, 9, 20);
	SET_ENEMY(6, "Enemy 4", 13, 4, 5);
	SET_ENEMY(7, "Enemy 5", 13, 6, 5);
	SET_ENEMY(8, "Enemy 6", 14, 3, 5);
	SET_ENEMY(9, "Boss 1", 14, 5, 10);

	Grenade grenades[NUM_GRENADES];
	SET_GRENADE(0, 5, 11, 2, 2);
	SET_GRENADE(1, 7, 13, 4, 3);
	SET_GRENADE(2, 14, 6, 2, 2);
	SET_GRENADE(3, 15, 5, 2, 2);

	SeekerMissile missiles[NUM_MISSILES];
	SET_MISSILE(0, "Tank 0", 10);
	SET_MISSILE(1, "Tank 0", 10);
	SET_MISSILE(2, "Boss 1", 6);

	for (int i = 0; i < NUM_GRENADES; ++i, ++iteration)
	{
		// Test damageEnemiesWithinReach()
		Grenade *grenadePtr = &grenades[i];
		damageEnemiesWithGrenade(grenadePtr, enemies, NUM_ENEMIES);
		bool stateOk = checkStateAtIteration(enemies, NUM_ENEMIES, iteration);
		if (stateOk) {
			cout << "damageEnemiesWithGrenade() - grenade " << i << " - OK" << endl;
		} else {
			cout << "damageEnemiesWithGrenade() - grenade " << i << " - ERROR" << endl;
		}
		
		cout << endl;
	}

	// Update state
	for (int i = 0; i < NUM_ENEMIES; ++i) {
		enemies[i].life = state[iteration - 1][i];
	}

	for (int i = 0; i < NUM_MISSILES; ++i, ++iteration)
	{
		// Test findTargetEnemy()
		SeekerMissile *missilePtr = &missiles[i];
		Enemy *targetEnemy = findTargetEnemy(missilePtr, enemies, NUM_ENEMIES);
		if (targetEnemy != nullptr && strcmp(targetEnemy->name, missileTargets[i]) == 0) {
			cout << "findTargetEnemy() - missile " << i << " - OK" << endl;
		} else {
			cout << "findTargetEnemy() - missile " << i << " - ERROR" << endl;
		}

		// Test damageTargetEnemy()
		if (targetEnemy != nullptr) { damageTargetEnemy(missilePtr, targetEnemy); }
		bool stateOk = checkStateAtIteration(enemies, NUM_ENEMIES, iteration);
		if (stateOk) {
			cout << "damageTargetEnemy() - missile " << i << " - OK" << endl;
		} else {
			cout << "damageTargetEnemy() - missile " << i << " - ERROR" << endl;
		}

		cout << endl;
	}

	system("pause");
	return 0;
}
