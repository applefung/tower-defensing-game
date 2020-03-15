/*
 * DiagonalEnemy.h
 *
 *  Created on: Mar 13, 2019
 *      Author: kevinw
 */

#ifndef TODODIAGONALENEMY_H_
#define TODODIAGONALENEMY_H_
#include "Object.h"
#include "definition.h"
#include "Enemy.h"

class TodoDiagonalEnemy: public Enemy
{
	public:
		char getSymbol() const;
		std::string getName() const;
		void move();
		int getHP() const;
		void fire(int power);
		TodoDiagonalEnemy(int a, int b, int c);
		virtual ObjectType getObjectType() const override {return ObjectType::ENEMY; }
		//void writeToStream(ostream& os) const;
	private:
		int hp;
		int previous_y;
		int x;
		int y;
};
#endif /* TODODIAGONALENEMY_H_ */
