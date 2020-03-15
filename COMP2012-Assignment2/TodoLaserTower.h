/*
 * Laser.h
 *
 *  Created on: Mar 14, 2019
 *      Author: kevinw
 */

#ifndef TODOLASERTOWER_H_
#define TODOLASERTOWER_H_
#include "Object.h"
#include "definition.h"
#include "Tower.h"
class TodoLaserTower: public Tower
{
	public:
		bool isInRange(int x, int y) const;
		void upgrade();
		void fire(Enemy&enemy);
		TodoLaserTower(int x, int y);
		std::string getName() const;
		char getSymbol() const;
		virtual ObjectType getObjectType() const override {return ObjectType::TOWER; };
		//void writeToStream(ostream& os) const;
	private:
		int x_co;
		int y_co;
		int money_earned;
};

#endif /* TODOLASERTOWER_H_ */
