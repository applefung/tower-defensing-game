/*
 * Catapult.h
 *
 *  Created on: Mar 12, 2019
 *      Author: kevinw
 */

#ifndef TODOCATAPULT_H_
#define TODOCATAPULT_H_

#include "Object.h"
#include "definition.h"
#include "Tower.h"

class TodoCatapultTower: public Tower
{
	public:
		bool isInRange(int x, int y) const;
		void upgrade();
		void fire(Enemy&enemy);
		TodoCatapultTower(int x, int y);
		string getName() const;
		char getSymbol() const;
		virtual ObjectType getObjectType() const override {return ObjectType::TOWER; };
		//void writeToStream(ostream& os) const;
	private:
		int x_co;
		int y_co;
		int money_earned;
};

#endif /* TODOCATAPULT_H_ */
