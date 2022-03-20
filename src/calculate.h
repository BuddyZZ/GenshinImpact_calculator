#ifndef CALCULATE_H
#define CALCULATE_H
#include "para.h"
#include "artifact.h"
#include "weapon.h"
#include "character.h"
#include "enemy.h"

namespace genShinImpact
{
	class calculate
	{
	public:
		calculate(tCharacter attacker, tEnemy suffer);

		float calReactFactor(int reactType);
		float calExpectance(int reactType, int damageType);
		float calMaxGreed(int reactType, int damageType, int maxSubtextNum, float luckValue);

	protected:
		tCharacter mCharacter;
		tEnemy mEnemy;
		void subSubtext(int type, float luckValue);
		void addSubtext(int type, float luckValue);
		void readArtSubtext(int type);

		float calHp(void);
		float calAtk(void);
		float calDef(void);
		float calCritRate(void);
		float calCritDmg(void);
		float calRecharge(void);
		float calElementalMastery(void);

		float defFactor(void);
		float levelFactor(void);
		float resFactor(int type);

		float getReactFactor(int reactType);
		float getReactCoefficient(int reactType);
		int getReactElementType(int reactType);
		float getRes(int type);
		float getbonus(int type);

	private:
	};

}

#endif