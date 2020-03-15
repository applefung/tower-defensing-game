/*
 * RevivingEnemy.cpp
 *
 *  Created on: Mar 15, 2019
 *      Author: kevinw
 */
#include "TodoRevivingEnemy.h"
#include "Object.h"
#include "Tower.h"
#include "Enemy.h"
class Object;
class Enemy;

using namespace std;

char TodoRevivingEnemy::getSymbol() const
{
	return 'R';
}

string TodoRevivingEnemy::getName() const
{
	return "Reviving Enemy";
}

void TodoRevivingEnemy::move()
{
	if (getState() == ObjectState::DEAD)
	{
		return;
	}
	if (getState() == ObjectState::FROZEN)
	{
		setState(ObjectState::NORMAL);
		return;
	}

	int x, y;
	getXY(x,y);
	setXY(x + 1, y);
}

int TodoRevivingEnemy::getHP() const
{
	return hp;
}

void TodoRevivingEnemy::fire(int power)
{
	int remember=1;
	if (hp==1 &&remember==1)
	{
		remember=0;
	}
	else if (hp==1 &&remember==0)
	{
		setState(ObjectState::DEAD);
	}
}

TodoRevivingEnemy::TodoRevivingEnemy(int Hp, int x, int y): Enemy(Hp,x,y)
{
	hp=Hp;
	previous_y=0;
	x_co=x;
	y_co=y;
}
