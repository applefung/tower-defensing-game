/*
 * LazyTower.h
 *
 *  Created on: Mar 11, 2019
 *      Author: kevinw
 */

#ifndef TODOSIMPLETOWER_H_
#define TODOSIMPLETOWER_H_
#include "enemy.h"
#include "tower.h"

class TodoSimpleTower: public Tower
{
	public:
		bool isInRange(int x, int y) const;
		void upgrade();
		void fire(Enemy&enemy);
		TodoSimpleTower(int x, int y);
		string getName() const;
		char getSymbol() const;
		TodoSimpleTower();
		virtual ObjectType getObjectType() const override {return ObjectType::TOWER; };
		//void writeToStream(ostream& os) const;
	private:
		int x_co;
		int y_co;
};
#endif /* TODOSIMPLETOWER_H_ */
