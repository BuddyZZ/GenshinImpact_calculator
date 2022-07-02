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
		float findMaxGreed(int reactType, int damageType, int maxSubtextNum, float luckValue);
		float findMaxBucket(int reactType, int damageType, int maxSubtextNum, float luckValue);

		void attributeConvert(int sourceType, int aimType, float convertFactor, float startPoint, float max);

	protected:
		tCharacter mCharacter;
		tEnemy mEnemy;
		void subSubtext(int type, float luckValue);
		void addSubtext(int type, float luckValue);
		void staticSubText(int type);
		void readArtSubtext(int type);

		void addAttribute(int type, float value);

		float calHp(void);
		float calAtk(void);
		float calDef(void);
		float calCritRate(void);
		float calCritDmg(void);
		float calRecharge(void);
		float calElementalMastery(void);
		float calDefFactor(void);
		float calLevelFactor(void);
		float calResFactor(int type);

		float getReactFactor(int reactType);
		float getReactCoefficient(int reactType);
		float getRes(int type);
		float getbonus(int type);

	private:
	};

}

#endif
// int getReactElementType(int reactType);
// int calculate::getReactElementType(int reactType)
// {
// 	switch (reactType)
// 	{
// 		// fusion
// 	case REACT_TYPE_SWIRL:
// 		return ELEMENT_ALL;
// 	case REACT_TYPE_SUPERCONDUCT:
// 		return DAMAGE_TYPE_CRYO;
// 	case REACT_TYPE_ELECTRO_CHARGED:
// 		return DAMAGE_TYPE_ELECTRO;
// 	case REACT_TYPE_OVERLOADED:
// 		return DAMAGE_TYPE_PYRO;
// 	case REACT_TYPE_CRUSHINGICE:
// 		return DAMAGE_TYPE_PHYSICS;
// 	case REACT_TYPE_BURNING:
// 		return DAMAGE_TYPE_PYRO;
// 		// increasement
// 	case REACT_TYPE_VAPORIZE_A:
// 		return DAMAGE_TYPE_HYDRO;
// 	case REACT_TYPE_VAPORIZE_B:
// 		return DAMAGE_TYPE_PYRO;
// 	case REACT_TYPE_MELT_A:
// 		return DAMAGE_TYPE_PYRO;
// 	case REACT_TYPE_MELT_B:
// 		return DAMAGE_TYPE_CRYO;
// 		// crystallize
// 	case REACT_TYPE_CRYSTALLIZE:
// 		return ELEMENT_ALL;
// 	default:
// 		DEBUG_LOG("getReactElementType wrong!!!\n");
// 		return 0;
// 	}
// }