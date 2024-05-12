#include "Ranking.h"
#include "UnitTest.h"
#include "BST.h"
#include <iostream>
#include <cstdlib>

void TestBST() {
#if defined(TEST_3_BST)
	BSTNode* root = nullptr;
	bool res1 = maxValue(root) == -1;

	root = Insert(root, 42);
	root = Insert(root, 21);
	root = Insert(root, 11);
	root = Insert(root, 5);
	root = Insert(root, 7);
	root = Insert(root, 2);

	//bool isIn = Search(root, 3);

	bool res2 = maxValue(root) == 42;

	TEST(": Exercise 3: BST max value ", res1 && res2);
#endif
}

void TestMario()// find_player_position() test
{
#if defined(TEST_3_RANKING)
	{
	Ranking ranking;
	ranking.push_front("Wario");
	bool ok1 = ranking.find_player_position("Wario") == 0;
	bool ok2 = ranking.find_player_position("asdasd") == -1;
	TEST("find_player_position() with one element", ok1 && ok2);

	ranking.push_front("Peach");
	bool ok3 = ranking.find_player_position("Wario") == 1;
	bool ok4 = ranking.find_player_position("Peach") == 0;
	bool ok5 = ranking.find_player_position("asdadfs") == -1;
	TEST("find_player_position() with two element", ok3 && ok4 && ok5);

	ranking.push_front("Yoshi");
	ranking.push_front("Mario");
	ranking.push_front("Luigi");
	bool ok6 = ranking.find_player_position("Wario") == 4;
	bool ok7 = ranking.find_player_position("Peach") == 3;
	bool ok8 = ranking.find_player_position("Mario") == 1;
	bool ok9 = ranking.find_player_position("Mario2") == -1;
	TEST("find_player_position() with several elements", ok6 && ok7 && ok8 && ok9);
}

// advance() test
{
	Ranking ranking;
	ranking.push_front("Wario");
	ranking.advance(ranking.find_player_position("Wario"));
	bool ok1 = ranking.find_player_position("Wario") == 0;
	TEST("advance() with one element", ok1);

	ranking.push_front("Peach");
	ranking.advance(ranking.find_player_position("Wario"));
	ranking.advance(ranking.find_player_position("Peach"));
	bool ok3 = ranking.find_player_position("Wario") == 1;
	bool ok4 = ranking.find_player_position("Peach") == 0;
	TEST("advance() with two element", ok3 && ok4);

	ranking.push_front("Yoshi");
	ranking.push_front("Mario");
	ranking.push_front("Luigi");
	// Luigi - Mario - Yoshi - Peach - Wario
	ranking.advance(ranking.find_player_position("Wario"));
	// Luigi - Mario - Yoshi - Wario - Peach
	ranking.advance(ranking.find_player_position("Luigi"));
	// Luigi - Mario - Yoshi - Wario - Peach
	ranking.advance(ranking.find_player_position("Mario"));
	// Mario - Luigi - Yoshi - Wario - Peach
	ranking.advance(ranking.find_player_position("Yoshi"));
	// Mario - Yoshi - Luigi - Wario - Peach
	bool ok5 = ranking.find_player_position("Mario") == 0;
	bool ok6 = ranking.find_player_position("Yoshi") == 1;
	bool ok7 = ranking.find_player_position("Luigi") == 2;
	bool ok8 = ranking.find_player_position("Wario") == 3;
	bool ok9 = ranking.find_player_position("Peach") == 4;
	TEST("advance() with several elements", ok5 && ok6 && ok7 && ok8 && ok9);
}

#endif
}
int main()
{
	TestMario();
	TestBST();
	PRINT_TEST_REPORT();

	system("pause");
	return 0;
}