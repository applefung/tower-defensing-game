/*
 * Catapult.cpp
 *
 *  Created on: Mar 12, 2019
 *      Author: kevinw
 */

#include "TodoCatapult.h"
#include "Object.h"
#include "Tower.h"
#include "Enemy.h"
class Tower;
class Enemy;
const int TODO_CATAPULT_COST = 2;
const int TODO_CATAPULT_UPGRADE_COST = 2;
const int TODO_CATAPULT_POWER = 5;
const int TODO_CATAPULT_RANGE = 5;

bool TodoCatapultTower::isInRange(int x, int y) const
{
	int a,b;
	getXY(a,b);
	int x_diff=a-x, y_diff=b-y;
	if(x_diff>5 || y_diff>5 || x_diff<-5 || y_diff<-5)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void TodoCatapultTower::upgrade()
{
	//power+=1;
}

void TodoCatapultTower::fire(Enemy& enemy)
{
    int x, y;
    enemy.getXY(x, y);
    bool isDeadYet = (enemy.getState() == ObjectState::DEAD);  //newly added
    if (isInRange(x, y)) {
	enemy.fired(getPower());
	//if (enemy.getState() == ObjectState::DEAD) //previous code
	if (!isDeadYet && enemy.getState() == ObjectState::DEAD)
	    money_earned++;
    }
}

TodoCatapultTower::TodoCatapultTower(int x, int y): Tower(TODO_CATAPULT_COST, TODO_CATAPULT_UPGRADE_COST, TODO_CATAPULT_POWER)
{
	x_co=x;
	y_co=y;
	money_earned=0;
}

string TodoCatapultTower::getName() const
{
	return "Catapult";
}

char TodoCatapultTower::getSymbol() const
{
	return 'C';
}


