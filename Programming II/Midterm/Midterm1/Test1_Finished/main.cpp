

#include <iostream>
#include "Ex1.h"
#include "Ex2.h"
#include "Ex3.h"
#include "Ex4and5.h"
#include "SimpleUnitTest.h"

using namespace std;

/*INSERT YOUR NAME HERE*/

#define TEST_EX_1
#define TEST_EX_2
#define TEST_EX_3
#define TEST_EX_4
#define TEST_EX_5

void testExercise1();
void testExercise2();
void testExercise3();
void testExercise4();
void testExercise5();

int main()
{
    testExercise1();
    Ex2();
    testExercise2();
    testExercise3();
    testExercise4();
    testExercise5();

    return 0;
}
void testExercise1() {
#ifdef TEST_EX_1

    float currentHP = 50;
    float damage = 5;
    DealDoubleDamage(currentHP, damage);
    bool res1 = currentHP == 40;
    bool res2 = damage == 5;
    DealDoubleDamage(currentHP, damage);
    bool res3 = currentHP == 30;
    TEST(": Deal Double Damage(...)", res1 && res2 && res3);
#endif 
}
void testExercise2() {
#ifdef TEST_EX_2
    int* a = new int[10]();
    SetArray(a, 10);
    int sum1 = GetSum(a, 10, 1, 3);
    int sum2 = GetSum(a, 10, 1, 10);
    int sum3 = GetSum(a, 10, -1, 5);
    int sum4 = GetSum(a, 10, 6, 2);
    int sum5 = GetSum(a, 10, 0, 7);

    bool res4 = sum1 == 24;
    bool res5 = sum2 == -1;
    bool res6 = sum3 == -1;
    bool res7 = sum4 == -1;
    bool res8 = sum5 == 52;

    TEST(": Sum array(...)", res4 && res5 && res6 && res7 && res8);

    delete[]a;
#endif
}
void testExercise3() {
#ifdef TEST_EX_3
    Ex3();
    bool res9 = num == 42;
    bool res10;
    if (ptr == nullptr) res10 = false;
    else res10 = (*ptr == 42);
    TEST(": Sum pointer(...)", res9, res10);
#endif
}

void testExercise4() {
#ifdef TEST_EX_4
    Book* book1 = new Book();
    bool res1 = strcmp(book1->GetAuthor(), "unknown") == 0;
    bool res2 = strcmp(book1->GetTitle(), "newTitle") == 0;
    bool res3 = book1->GetPages() == 0;

    Book* book2 = new Book("Pepe", "Mi vida", 42);
    bool res4 = strcmp(book2->GetAuthor(), "Pepe") == 0;
    bool res5 = strcmp(book2->GetTitle(), "Mi vida") == 0;
    bool res6 = book2->GetPages() == 42;

    Book* book3 = new Book("Pepe", "Mi vida", 42);
    bool res7 = (*book2 == *book3);
    bool res8 = book1 != book2;

    bool res9 = strcmp(book3->ReadPage(33), "Reading a random page") == 0;

    TEST(": Books(...)", res1 && res2 && res3 && res4 && res5 && res6 && res7 && res8 && res9);

#endif
}

void testExercise5() {
#ifdef TEST_EX_5
    Book* book1 = new Dictionary();
    bool res1 = strcmp(book1->GetAuthor(), "unknown") == 0;
    bool res2 = strcmp(book1->GetTitle(), "newTitle") == 0;
    bool res3 = book1->GetPages() == 0;

    Dictionary* book2 = new Dictionary("Oxford", "English", 33);
    bool res4 = strcmp(book2->GetAuthor(), "Oxford") == 0;
    bool res5 = strcmp(book2->GetTitle(), "English") == 0;
    bool res6 = book2->GetPages() == 33;

    book2->AddEntry(2, "pass", "get a mark higher that 5");
    book2->AddEntry(3, "mudo", "una persona que no puede hablar");

    bool res7 = strcmp(book2->ReadPage(3), "una persona que no puede hablar") == 0;
    book2->ChangeDefinition(3, "una paded");
    bool res8 = strcmp(book2->ReadPage(3), "una paded") == 0;

    bool res9 = strcmp(book2->ReadPage(333), "404") == 0;

    TEST(": Dictionary(...)", res1 && res2 && res3 && res4 && res5 && res6 && res7 && res8 && res9);

#endif

}




