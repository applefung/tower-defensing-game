/*
 * IceTower.h
 *
 *  Created on: Mar 14, 2019
 *      Author: kevinw
 */

#ifndef TODOICETOWER_H_
#define TODOICETOWER_H_
#include "Object.h"
#include "definition.h"
#include "Tower.h"

class TodoIceTower: public Tower
{
	public:
		bool isInRange(int x, int y) const;
		void upgrade();
		void fire(Enemy&enemy);
		TodoIceTower(int x, int y);
		string getName() const;
		char getSymbol() const;
		virtual ObjectType getObjectType() const override {return ObjectType::TOWER; };
		//void writeToStream(ostream& os) const;
	private:
		int x_co;
		int y_co;
		int money_earned;
};

#endif /* TODOICETOWER_H_ */
