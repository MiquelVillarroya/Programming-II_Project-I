/* ----------------------------------------------------------------------- */
/*                         INSERT YOUR NAME HERE                           */
/* ----------------------------------------------------------------------- */

#ifndef WEAPONS_H
#define WEAPONS_H

/** Definition of an enemy unit. */
struct Enemy
{
	const char *name; /**< Enemy name. */
	float x; /**< X coordinate. */
	float y; /**< Y coordinate. */
	int life; /**< Life units. */
};

/**
 * Definition of a Grenade.
 * Grenades explode at a certain position, damaging all
 * enemies within a certain radius.
 */
struct Grenade
{
	float x; /**< X coordinate. */
	float y; /**< Y coordinate. */
	float radius; /**< Damage radius. */
	int damage; /**< Damage units. */
};

/**
* Definition of a SeekerMissile.
* These missiles search and damage a specific target enemy.
*/
struct SeekerMissile
{
	const char *targetName; /**< Enemy name. */
	int damage; /**< Damage units. */
};

/**
 * This function computes the distance between the points A and B.
 * @param ax X coordinate of the point A.
 * @param ay Y coordinate of the point A.
 * @param bx X coordinate of the point B.
 * @param by Y coordinate of the point B.
 * @return The distance between A and B.
 */
float distance(float ax, float ay, float bx, float by)
{
	// Pythagorean theorem
	float dx = ax - bx;
	float dy = ay - by;
	float dist = sqrt(dx*dx + dy*dy);
	return dist;
}

void applyDamage(Enemy* enemy, int damage) {
	
	(*enemy).life -= damage;

	if ((*enemy).life < 0) {
		(*enemy).life = 0;
	}
}

/**
 * This function damages all enemies within the blast wave of a granade.
 * NOTE: Use the "distance" function defined above in order to determine
 * which enemies are affected by the explosion.
 * @param grenade The grenade that is exploding.
 * @param enemies The array with all enemies.
 * @param numEnemies The total number of enemies in the array.
 */
void damageEnemiesWithGrenade(Grenade* grenade, Enemy* enemies, int numEnemies)
{
	// TODO
	for (int i = 0; i < numEnemies; ++i) {
		float dist = distance((*grenade).x, (*grenade).y, (*(enemies + i)).x, (*(enemies + i)).y);
		if (dist <= (*grenade).radius) {
			applyDamage(&(*(enemies + i)), (*grenade).damage);
		}
	}
}

/**
 * This function finds the enemy seeked by a seeker missile.
 * @param missile The missile.
 * @param enemies The array of all enemies.
 * @param numEnemies The number of enemies in the array.
 * @return A pointer to the enemy seeked by the missile.
 */
Enemy *findTargetEnemy(SeekerMissile *missile, Enemy *enemies, int numEnemies)
{
	Enemy *foundEnemy = nullptr;
	
	// TODO
	for (int i = 0; i < numEnemies; ++i) {
		int equal = strcmp((*missile).targetName, (*(enemies + i)).name);
		if (equal == 0) {
			foundEnemy = enemies + i;
		}
	}

	return foundEnemy;
}

/**
 * This function damages an enemy taking into account the missile damage points.
 * @param missile The missile.
 * @param targetEnemy The target enemy to be damaged.
 */
void damageTargetEnemy(SeekerMissile *missile, Enemy *targetEnemy)
{
	// TODO
	applyDamage(targetEnemy, (*missile).damage);
}

#endif
