/*
 * DiagonalEnemy.cpp
 *
 *  Created on: Mar 13, 2019
 *      Author: kevinw
 */

#include "TodoDiagonalEnemy.h"
#include "Object.h"
#include "Tower.h"
#include "Enemy.h"
class Object;
class Enemy;

using namespace std;

char TodoDiagonalEnemy::getSymbol() const
{
	return 'D';
}

std::string TodoDiagonalEnemy::getName() const
{
	return "Diagonal Enemy";
}

void TodoDiagonalEnemy::move()
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

	previous_y=y;
	getXY(x,y);
	if(y>0 && y<previous_y) //move right upward
	{
		setXY(x+1, y-1);
	}
	else if(y==4 && y>previous_y) //move right upward when y=ARENA_H
	{
		setXY(x+1, y-1);
	}
	else if(y>0 && y>previous_y && y!=4) //move right downward
	{
		setXY(x+1, y+1);
	}
	else if(y==0 && y<previous_y) //move right downward when y=0
	{
		setXY(x+1, y+1);
	}
}

int TodoDiagonalEnemy::getHP() const
{
	return hp;
}

void TodoDiagonalEnemy::fire(int power)
{
	hp -= power;
	if (hp <= 0)
	{
		setState(ObjectState::DEAD);
	}
}

TodoDiagonalEnemy::TodoDiagonalEnemy(int Hp, int ax, int ay): Enemy(Hp,ax,ay)
{
	hp=Hp;
	x=ax;
	y=10;
	previous_y=10;
}

