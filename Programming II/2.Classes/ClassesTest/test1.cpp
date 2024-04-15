#include "SimpleUnitTest.h"
#include "Classes.h"
#include <iostream>
using namespace std;

void testExercises();

int main() 
{
	/* -- Auto evaluation -- */
	/* Uncomment the line below if you want to evaluate your code */
	testExercises();

	system("pause");
	return 0;
}


/* ----------------------------------------------------------------------- */
/*                     DO NOT TOUCH THE CODE BELOW                         */
/* ----------------------------------------------------------------------- */

void testExercises()
{
	Battalion* infBat1 = new Infantry("5th Line Battalion", 300, 200);
	Battalion* infBat2 = new Infantry("28e Régiment de Ligne", 250, 250);
	Battalion* infBat3 = new Infantry("54e Régiment de Ligne", 200, 400);
	Battalion* infBat4 = new Infantry("79th Regiment of Foot (Cameron Highlanders)", 0, 0);

	Battalion* chivBat1 = new Chivalry("1st King's Dragoon Guards", 75, 75);
	Battalion* chivBat2 = new Chivalry("1er Régiment de Hussards", 100, 50);
	Battalion* chivBat3 = new Chivalry("11e Régiment de Chasseurs-à-Cheval", 100, 0);
	Battalion* chivBat4 = new Chivalry("Royal Regiment of Horse Guards", 0, 200);

	Battalion* artBat1 = new Artillery("Sandham's Battery Royal Artillery", 50, 25);
	Battalion* artBat2 = new Artillery("20e Companie 6e d'Artillerie à Pied", 70, 30);
	Battalion* artBat3 = new Artillery("11e Companie 6e d'Artillerie à Pied", 1, 1);
	Battalion* artBat4 = new Artillery("Roger's Battery RA", 20, 10);

	TEST(": getName() inherited by the derived classes", 
		strcmp(infBat4->getName(), "79th Regiment of Foot (Cameron Highlanders)") == 0 &&
		strcmp(chivBat2->getName(), "1er Régiment de Hussards") == 0 &&
		strcmp(artBat3->getName(), "11e Companie 6e d'Artillerie à Pied") == 0);

	TEST(": Computation Infantry's combatValue()", 
		infBat1->combatValue() == 700 &&
		infBat2->combatValue() == 750 &&
		infBat3->combatValue() == 1000 &&
		infBat4->combatValue() == 0);

	TEST(": Computation Chivalry's combatValue()", 
		chivBat1->combatValue() == 525 &&
		chivBat2->combatValue() == 500 &&
		chivBat3->combatValue() == 300 &&
		chivBat4->combatValue() == 800);

	TEST(": Computation Artillery's combatValue()", 
		artBat1->combatValue() == 400 &&
		artBat2->combatValue() == 530 &&
		artBat3->combatValue() == 11 &&
		artBat4->combatValue() == 160);

	TEST(": victoryInBattlefield(...) function", 
		victoryInBattlefield(infBat1, infBat1) == "Same combat value" &&
		victoryInBattlefield(infBat1, infBat2) == "28e Régiment de Ligne" &&
		victoryInBattlefield(infBat1, infBat3) == "54e Régiment de Ligne" &&
		victoryInBattlefield(chivBat1, chivBat2) == "1st King's Dragoon Guards" &&
		victoryInBattlefield(artBat1, artBat2) == "20e Companie 6e d'Artillerie à Pied" &&
		victoryInBattlefield(infBat4, artBat3) == "11e Companie 6e d'Artillerie à Pied");

	delete infBat1;
	delete infBat2;
	delete infBat3;
	delete infBat4;

	delete chivBat1;
	delete chivBat2;
	delete chivBat3;
	delete chivBat4;

	delete artBat1;
	delete artBat2;
	delete artBat3;
	delete artBat4;
	
	PRINT_TEST_REPORT();
}