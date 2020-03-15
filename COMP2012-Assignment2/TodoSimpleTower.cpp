/*
 * LazyTower.cpp
 *
 *  Created on: Mar 11, 2019
 *      Author: kevinw
 */

#include "TodoSimpleTower.h"
const int SIMPLE_TOWER_COST = 1;
const int SIMPLE_TOWER_UPGRADE_COST = 1;
const int SIMPLE_TOWER_POWER = 3;

bool TodoSimpleTower::isInRange(int x, int y) const
{
	int a,b;
	getXY(a,b);
	int x_diff=a-x, y_diff=b-y;
	if(x_diff>2 || y_diff>2 || x_diff<-2 || y_diff<-2)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void TodoSimpleTower::upgrade()
{
	//power+=1;
}

void TodoSimpleTower::fire(Enemy& enemy)
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
string TodoSimpleTower::getName() const
{
	return "Simple Tower";
}

TodoSimpleTower::TodoSimpleTower(int x, int y): Tower(SIMPLE_TOWER_COST, SIMPLE_TOWER_UPGRADE_COST,SIMPLE_TOWER_POWER)
{
	x_co=x;
	y_co=y;
}

char TodoSimpleTower::getSymbol() const
{
	return 'S';
}
