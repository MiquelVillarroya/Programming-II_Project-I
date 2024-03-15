#pragma once
#include <iostream>
using namespace std;

//You can modify this function
void DealDoubleDamage(float& hp, float damage) 
{
	hp -= 2.f * damage;
}

//DO NOT MODIFY THIS FUNCTION
void Ex1() {
	float currentHP = 99;
	float damage = 10;
	DealDoubleDamage(currentHP, damage);
	cout << currentHP << endl;
	cout << damage << endl;
}