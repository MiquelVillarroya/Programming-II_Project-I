#pragma once
#include <iostream>
using namespace std;

void DealDoubleDamage(float &hp, float damage) 
{
	damage *= 2;
	hp -= damage;
	
}

//DO NOT MODIFY THIS FUNCTION
void Ex1() {
	float currentHP = 99;
	float damage = 10;
	DealDoubleDamage(currentHP, damage);
	cout << currentHP << endl;
	cout << damage << endl;
}