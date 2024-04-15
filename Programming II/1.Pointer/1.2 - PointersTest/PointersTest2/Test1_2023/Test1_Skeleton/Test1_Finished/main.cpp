

#include <iostream>
#include "Ex1.h"
#include "Ex2.h"
#include "Ex3.h"
#include "SimpleUnitTest.h"

using namespace std;

/*MIQUEL VILLARROYA MARTÍ*/

void testExercises();

int main()
{
    //Ex1();
    //Ex2();
     testExercises();
    return 0;
}

void testExercises() {
    float currentHP = 50;
    float damage = 5;
    DealDoubleDamage(currentHP, damage);
    bool res1 = currentHP == 40;
    bool res2 = damage == 5;
    DealDoubleDamage(currentHP, damage);
    bool res3 = currentHP == 30;
    TEST(": Deal Double Damage(...)", res1 && res2  && res3 );

    int* a = new int[10]();
    SetArray(a, 10);
    int sum1= GetSum(a, 10, 1, 3);
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

    Ex3();
    bool res9 = num == 42;
    //bool res10 = *ptr == 42;
    TEST(": Sum pointer(...)", res9);
}


