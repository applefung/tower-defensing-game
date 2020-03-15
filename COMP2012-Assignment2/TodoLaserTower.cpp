/*
 * Laser.cpp
 *
 *  Created on: Mar 14, 2019
 *      Author: kevinw
 */

#include "TodoLaserTower.h"
#include "Object.h"
#include "Tower.h"
#include "Enemy.h"
class Object;
class Tower;

const int LASER_COST = 3;
const int LASER_UPGRADE_COST = 2;
const int LASER_POWER = 10;

bool TodoLaserTower::isInRange(int x, int y) const
{
	int a,b;
	getXY(a,b);
	if(x==a || y==b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void TodoLaserTower::upgrade()
{
	//power+=1;
}

void TodoLaserTower::fire(Enemy& enemy)
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

TodoLaserTower::TodoLaserTower(int x, int y):Tower(LASER_COST,  LASER_UPGRADE_COST, LASER_POWER)
{
	x_co=x;
	y_co=y;
	money_earned=0;
}

std::string TodoLaserTower::getName() const
{
	return "Laser";
}

char TodoLaserTower::getSymbol() const
{
	return 'L';
}

