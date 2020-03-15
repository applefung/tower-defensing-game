/*
 * IceTower.cpp
 *
 *  Created on: Mar 14, 2019
 *      Author: kevinw
 */

#include "TodoIceTower.h"
#include "Object.h"
#include "Tower.h"
#include "Enemy.h"
class Object;
class Tower;

const int TODO_ICE_TOWER_COST = 3;
const int TODO_ICE_TOWER_UPGRADE_COST = 0;
const int TODO_ICE_TOWER_POWER = 0;

bool TodoIceTower::isInRange(int x, int y) const
{
	int a,b;
	getXY(a,b);
	if(a>x)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void TodoIceTower::upgrade()
{
	//power+=1;
}

void TodoIceTower::fire(Enemy& enemy)
{
    int x, y;
    enemy.getXY(x, y);
    bool isDeadYet = (enemy.getState() == ObjectState::FROZEN);  //newly added
    if (isInRange(x, y)) {
	enemy.fired(getPower());
	//if (enemy.getState() == ObjectState::DEAD) //previous code
	if (!isDeadYet && enemy.getState() == ObjectState::FROZEN)
	    money_earned++;
    }
}

TodoIceTower::TodoIceTower(int x, int y): Tower(TODO_ICE_TOWER_COST, TODO_ICE_TOWER_UPGRADE_COST, TODO_ICE_TOWER_POWER)
{
	x_co=x;
	y_co=y;
	money_earned=0;
}

std::string TodoIceTower::getName() const
{
	return "Ice Tower";
}

char TodoIceTower::getSymbol() const
{
	return 'I';
}


