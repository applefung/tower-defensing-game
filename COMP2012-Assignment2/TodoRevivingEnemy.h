/*
 * RevivingEnemy.h
 *
 *  Created on: Mar 15, 2019
 *      Author: kevinw
 */

#ifndef TODOREVIVINGENEMY_H_
#define TODOREVIVINGENEMY_H_
#include "Object.h"
#include "definition.h"
#include "Enemy.h"

class TodoRevivingEnemy: public Enemy
{
	public:
		char getSymbol() const;
		string getName() const;
		void move();
		int getHP() const;
		void fire(int power);
		TodoRevivingEnemy(int a, int b, int c);
		virtual ObjectType getObjectType() const override {return ObjectType::ENEMY; }
		//void writeToStream(ostream& os) const;
	private:
		int hp;
		int previous_y;
		int x_co;
		int y_co;
};
#endif /* TODOREVIVINGENEMY_H_ */
