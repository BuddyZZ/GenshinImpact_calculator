#include "para.h"
#include "calculate.h"

using namespace std;
using namespace genShinImpact;

#define REACT_COEFFICIENT_BURNING 0.5f
#define REACT_COEFFICIENT_SUPERCONDUCT 1.0f
#define REACT_COEFFICIENT_SWIRL 1.2f
#define REACT_COEFFICIENT_ELECTRO_CHARGED 2.4f
#define REACT_COEFFICIENT_CRUSHINGICE 3.0f
#define REACT_COEFFICIENT_OVERLOADED 4.0f

#define REACT_COEFFICIENT_VAPORIZE_A 2.0f
#define REACT_COEFFICIENT_VAPORIZE_B 1.5f
#define REACT_COEFFICIENT_MELT_A 2.0f
#define REACT_COEFFICIENT_MELT_B 1.5f

#define REACT_COEFFICIENT_CRYSTALLIZE 3.0f
#define REACT_COEFFICIENT_FROZEN 0.0f

#define INCREASEMENT_K (25.0f / 9.0f)
#define INCREASEMENT_A 1400.0f
#define FUSION_K 16.0f	 // 20/3
#define FUSION_A 2000.0f // 1400
#define CRYSTALLIZE_K (40.0f / 9.0f)
#define CRYSTALLIZE_A 1400.0f

#define factor(K, A, EM, F, C) (((K) * (EM) / ((EM) + (A)) + 1 + (F)) * (C))

float fusionLevelFactor[LEVEL_MAX] = {
	/*		1		2		3		4		5		6		7		8		9		10*/
	/*0*/ 7, 10, 13, 17, 20, 24, 28, 33, 37, 42,
	/*10*/ 7, 10, 13, 17, 20, 24, 28, 33, 37, 42,
	/*20*/ 7, 10, 13, 17, 20, 24, 28, 33, 37, 42,
	/*30*/ 7, 10, 13, 17, 20, 24, 28, 33, 37, 42,
	/*40*/ 7, 10, 13, 17, 20, 24, 28, 33, 37, 42,
	/*50*/ 7, 10, 13, 17, 20, 24, 28, 33, 37, 42,
	/*60*/ 7, 10, 13, 17, 20, 24, 28, 33, 37, 42,
	/*70*/ 7, 10, 13, 17, 20, 24, 28, 33, 37, 539,
	/*80*/ 7, 10, 13, 17, 20, 24, 28, 33, 37, 724};

calculate::calculate(tCharacter attacker, tEnemy suffer) : mCharacter(attacker), mEnemy(suffer)
{
}

float calculate::calMaxGreed(int reactType, int damageType, int maxSubtextNum, float luckValue)
{
	float currentDmage = 0, maxDamage = 0;
	int currentAddType = 0xFFFFFFFF;
	tAttribute a;
	int i = 0, j = 0;
	printf("reactType==%X\n",reactType);

	for (i = 0; i < maxSubtextNum; i++)
	{
		for (j = (ART_TEXT_SUB_HP ^ IS_ARTIFACT_TEXT); j <= (ART_TEXT_SUB_ELEMENTAL_MASTERY ^ IS_ARTIFACT_TEXT); j <<= 1)
		{
			addSubtext((j ^ IS_ARTIFACT_TEXT), luckValue);
			currentDmage = calExpectance(reactType, damageType);

			// 	readArtSubtext(j); putchar('\n');
			// 	//printf("hp==%f\n",calHp());
			// 	printf("atk==%f\n", calAtk());
			// 	//printf("def==%f\n", calDef());
			// 	printf("critRate==%f\n",calCritRate());
			// 	printf("critDmg==%f\n",calCritDmg());
			// 	//printf("recharge==%f\n", calRecharge());
			// 	//printf("mastery==%f\n",calElementalMastery());
			// printf("currentDmage=%f\n", currentDmage);
			// printf("\n");

			if (currentDmage > maxDamage)
			{
				currentAddType = (j ^ IS_ARTIFACT_TEXT);
				maxDamage = currentDmage;
			}
			else
			{
			}
			subSubtext((j ^ IS_ARTIFACT_TEXT), luckValue);
			// printf("currentDmage=%f\n", currentDmage);
			// printf("maxDamage=%f\n", maxDamage);
		}
		addSubtext(currentAddType, luckValue);

		printf("time==%d\n", i);
		readArtSubtext(currentAddType);
		printf("maxDamage=%f\n", maxDamage);
		printf("-------------------------------------\n");
	}
	printf("\n");
	// printf("hp==%f\n",calHp());
	printf("atk==%f\n", calAtk());
	// printf("def==%f\n", calDef());
	printf("critRate==%f\n", calCritRate());
	printf("critDmg==%f\n", calCritDmg());
	// printf("recharge==%f\n", calRecharge());
	printf("mastery==%f\n", calElementalMastery());
	printf("Bonus=%f\n", getbonus(damageType));
	printf("defFactor==%f\n", defFactor());
	printf("levelFactor==%f\n", levelFactor());
	printf("resFactor==%f\n", resFactor(damageType));
	printf("maxDamage=%f\n", maxDamage);
}

// #define ART_TEXT_SUB_FIX_HP 				0x0001//not in consideration
// #define ART_TEXT_SUB_FIX_ATK 			0x0002//not in consideration
// #define ART_TEXT_SUB_FIX_DEF 			0x0004//not in consideration
void calculate::addSubtext(int type, float luckValue)
{
	switch (type)
	{
	case ART_TEXT_SUB_HP:
		mCharacter.attribute.hp += luckValue * ART_VALUE_SUB_HP;
		break;
	case ART_TEXT_SUB_ATK:
		mCharacter.attribute.atk += luckValue * ART_VALUE_SUB_ATK;
		break;
	case ART_TEXT_SUB_DEF:
		mCharacter.attribute.def += luckValue * ART_VALUE_SUB_DEF;
		break;
	case ART_TEXT_SUB_CRIT_RATE:
		mCharacter.attribute.critRate += luckValue * ART_VALUE_SUB_CRIT_RATE;
		break;
	case ART_TEXT_SUB_CRIT_DMG:
		mCharacter.attribute.critDmg += luckValue * ART_VALUE_SUB_CRIT_DMG;
		break;
	case ART_TEXT_SUB_RECHARGE:
		mCharacter.attribute.rechage += luckValue * ART_VALUE_SUB_RECHARGE;
		break;
	case ART_TEXT_SUB_ELEMENTAL_MASTERY:
		mCharacter.attribute.elementalMastery += luckValue * ART_VALUE_SUB_ELEMENTAL_MASTERY;
		break;
	default:
		DEBUG_LOG("subSubtext wrong!!!\n");
		break;
	}
}
void calculate::subSubtext(int type, float luckValue)
{
	switch (type)
	{
	case ART_TEXT_SUB_HP:
		mCharacter.attribute.hp -= luckValue * ART_VALUE_SUB_HP;
		break;
	case ART_TEXT_SUB_ATK:
		mCharacter.attribute.atk -= luckValue * ART_VALUE_SUB_ATK;
		break;
	case ART_TEXT_SUB_DEF:
		mCharacter.attribute.def -= luckValue * ART_VALUE_SUB_DEF;
		break;
	case ART_TEXT_SUB_CRIT_RATE:
		mCharacter.attribute.critRate -= luckValue * ART_VALUE_SUB_CRIT_RATE;
		break;
	case ART_TEXT_SUB_CRIT_DMG:
		mCharacter.attribute.critDmg -= luckValue * ART_VALUE_SUB_CRIT_DMG;
		break;
	case ART_TEXT_SUB_RECHARGE:
		mCharacter.attribute.rechage -= luckValue * ART_VALUE_SUB_RECHARGE;
		break;
	case ART_TEXT_SUB_ELEMENTAL_MASTERY:
		mCharacter.attribute.elementalMastery -= luckValue * ART_VALUE_SUB_ELEMENTAL_MASTERY;
		break;
	default:
		DEBUG_LOG("subSubtext wrong!!!\n");
		break;
	}
}
void calculate::readArtSubtext(int type)
{
	switch (type)
	{
	case ART_TEXT_SUB_HP:
		printf("ART_TEXT_SUB_HP");
		break;
	case ART_TEXT_SUB_ATK:
		printf("ART_TEXT_SUB_ATK");
		break;
	case ART_TEXT_SUB_DEF:
		printf("ART_TEXT_SUB_DEF");
		break;
	case ART_TEXT_SUB_CRIT_RATE:
		printf("ART_TEXT_SUB_CRIT_RATE");
		break;
	case ART_TEXT_SUB_CRIT_DMG:
		printf("ART_TEXT_SUB_CRIT_DMG");
		break;
	case ART_TEXT_SUB_RECHARGE:
		printf("ART_TEXT_SUB_RECHARGE");
		break;
	case ART_TEXT_SUB_ELEMENTAL_MASTERY:
		printf("ART_TEXT_SUB_ELEMENTAL_MASTERY");
		break;
	default:
		DEBUG_LOG("subSubtext wrong!!!\n");
		break;
	}
}

float calculate::calHp(void)
{
	float hpbasic = mCharacter.basic.hp;
	float hpPercent = mCharacter.attribute.hp;
	float hpFix = mCharacter.attributeFix.hpFix;
	return hpbasic * (1 + hpPercent) + hpFix;
}
float calculate::calAtk(void)
{
	float Atkbasic = mCharacter.attributeFix.atkBasic + mCharacter.basic.atk;
	float AtkPercent = mCharacter.attribute.atk;
	float AtkFix = mCharacter.attributeFix.atkFix;

	return Atkbasic * (1 + AtkPercent) + AtkFix;
}
float calculate::calDef(void)
{
	float defbasic = mCharacter.basic.def;
	float defPercent = mCharacter.attribute.def;
	float defFix = mCharacter.attributeFix.defFix;
	return defbasic * (1 + defPercent) + defFix;
}
float calculate::calCritRate(void)
{
	float critRatebasic = mCharacter.basic.critRate;
	float critRatePercent = mCharacter.attribute.critRate;
	float critRate = critRatebasic + critRatePercent;
	if (critRate > 1)
	{
		critRate = 1;
	}
	else if (critRate < 0)
	{
		critRate = 0;
	}
	return critRate;
}
float calculate::calCritDmg(void)
{
	float critDmgbasic = mCharacter.basic.critDmg;
	float critDmgPercent = mCharacter.attribute.critDmg;
	return critDmgbasic + critDmgPercent;
}
float calculate::calRecharge(void)
{
	float rechagebasic = mCharacter.basic.rechage;
	float rechagePercent = mCharacter.attribute.rechage;
	return rechagebasic + rechagePercent;
}
float calculate::calElementalMastery(void)
{
	float elementalMasterybasic = mCharacter.basic.elementalMastery;
	float elementalMasteryPercent = mCharacter.attribute.elementalMastery;
	return elementalMasterybasic + elementalMasteryPercent;
}

float calculate::levelFactor(void)
{
	if (mCharacter.level < 10 || mEnemy.level < 10)
	{
		if ((mCharacter.level - mEnemy.level) >= 70)
		{
			return 1.5;
		}
		if ((mCharacter.level - mEnemy.level) <= -70)
		{
			return 0.5;
		}
	}
	else
	{
		return 1;
	}
}

float calculate::resFactor(int Type)
{
	float res = getRes(Type);
	if (res > 0.75) // Res>0.75
	{
		return 1 / (1 + 4 * res);
	}
	else if (res > 0) // 0.75>=Res>0
	{
		return 1 - res;
	}
	else // 0>=Res
	{
		return 1 - (res / 2);
	}
}
float calculate::defFactor(void)
{
	return (mCharacter.level + 100.0f) / (mCharacter.level + mEnemy.level + 200.0f);
	// return chracterDef / (chracterDef + 5 * enemyLevel + 500);
}
float calculate::calReactFactor(int reactType)
{
	float mastery = calElementalMastery();

	if ((reactType & REACT_TYPE_FUSION)^IS_REACT)
	{
		return (FUSION_K * mastery / (mastery + FUSION_A) + 1 + getReactFactor(reactType)) * getReactCoefficient(reactType);
	}
	else if ((reactType & REACT_TYPE_INCREASEMENT)^IS_REACT)
	{
		return (CRYSTALLIZE_K * mastery / (mastery + CRYSTALLIZE_A) + 1 + getReactFactor(reactType)) * getReactCoefficient(reactType);
	}
	else
	{
		return (INCREASEMENT_K * mastery / (mastery + INCREASEMENT_A) + 1 + getReactFactor(reactType)) * getReactCoefficient(reactType);
	}
}


float calculate::getReactFactor(int reactType)
{
	switch (reactType)
	{
		// fusion
	case REACT_TYPE_SWIRL:
		return mCharacter.reactFactor.swirl;
	case REACT_TYPE_SUPERCONDUCT:
		return mCharacter.reactFactor.superconduct;
	case REACT_TYPE_ELECTRO_CHARGED:
		return mCharacter.reactFactor.electroCharged;
	case REACT_TYPE_OVERLOADED:
		return mCharacter.reactFactor.overloaded;
	case REACT_TYPE_CRUSHINGICE:
		return mCharacter.reactFactor.crushingice;
	case REACT_TYPE_BURNING:
		return mCharacter.reactFactor.burning;
		// increasement
	case REACT_TYPE_VAPORIZE_A:
		return mCharacter.reactFactor.vaporize_a;
	case REACT_TYPE_VAPORIZE_B:
		return mCharacter.reactFactor.vaporize_b;
	case REACT_TYPE_MELT_A:
		return mCharacter.reactFactor.melt_a;
	case REACT_TYPE_MELT_B:
		return mCharacter.reactFactor.melt_b;
		// crystallize
	case REACT_TYPE_CRYSTALLIZE:
		return mCharacter.reactFactor.crystallize;
	default:
		DEBUG_LOG("getReactFactor wrong!!!\n");
		return 0;
	}
}
int calculate::getReactElementType(int reactType)
{
	switch (reactType)
	{
		// fusion
	case REACT_TYPE_SWIRL:
		return ELEMENT_ALL;
	case REACT_TYPE_SUPERCONDUCT:
		return DAMAGE_TYPE_CRYO;
	case REACT_TYPE_ELECTRO_CHARGED:
		return DAMAGE_TYPE_ELECTRO;
	case REACT_TYPE_OVERLOADED:
		return DAMAGE_TYPE_PYRO;
	case REACT_TYPE_CRUSHINGICE:
		return DAMAGE_TYPE_PHYSICS;
	case REACT_TYPE_BURNING:
		return DAMAGE_TYPE_PYRO;
		// increasement
	case REACT_TYPE_VAPORIZE_A:
		return DAMAGE_TYPE_HYDRO;
	case REACT_TYPE_VAPORIZE_B:
		return DAMAGE_TYPE_PYRO;
	case REACT_TYPE_MELT_A:
		return DAMAGE_TYPE_PYRO;
	case REACT_TYPE_MELT_B:
		return DAMAGE_TYPE_CRYO;
		// crystallize
	case REACT_TYPE_CRYSTALLIZE:
		return ELEMENT_ALL;
	default:
		DEBUG_LOG("getReactElementType wrong!!!\n");
		return 0;
	}
}
float calculate::getReactCoefficient(int reactType)
{
	switch (reactType)
	{
		// fusion
	case REACT_TYPE_SWIRL:
		return REACT_COEFFICIENT_SWIRL;
	case REACT_TYPE_SUPERCONDUCT:
		return REACT_COEFFICIENT_SUPERCONDUCT;
	case REACT_TYPE_ELECTRO_CHARGED:
		return REACT_COEFFICIENT_ELECTRO_CHARGED;
	case REACT_TYPE_OVERLOADED:
		return REACT_COEFFICIENT_OVERLOADED;
	case REACT_TYPE_CRUSHINGICE:
		return REACT_COEFFICIENT_CRUSHINGICE;
	case REACT_TYPE_BURNING:
		return REACT_COEFFICIENT_BURNING;
		// increasement
	case REACT_TYPE_VAPORIZE_A:
		return REACT_COEFFICIENT_VAPORIZE_A;
	case REACT_TYPE_VAPORIZE_B:
		return REACT_COEFFICIENT_VAPORIZE_B;
	case REACT_TYPE_MELT_A:
		return REACT_COEFFICIENT_MELT_A;
	case REACT_TYPE_MELT_B:
		return REACT_COEFFICIENT_MELT_B;
		// crystallize
	case REACT_TYPE_CRYSTALLIZE:
		return REACT_COEFFICIENT_CRYSTALLIZE;
	default:
		DEBUG_LOG("getReactCoefficient wrong!!!\n");
		return 0;
	}
}
float calculate::getRes(int type)
{
	switch (type)
	{
	case DAMAGE_TYPE_PHYSICS:
		return mEnemy.res.physical;
	case DAMAGE_TYPE_PYRO:
		return mEnemy.res.pyro;
	case DAMAGE_TYPE_HYDRO:
		return mEnemy.res.hydro;
	case DAMAGE_TYPE_DENDRO:
		return mEnemy.res.dendro;
	case DAMAGE_TYPE_ELECTRO:
		return mEnemy.res.electro;
	case DAMAGE_TYPE_ANEMO:
		return mEnemy.res.anemo;
	case DAMAGE_TYPE_CRYO:
		return mEnemy.res.cryo;
	case DAMAGE_TYPE_GEO:
		return mEnemy.res.geo;
	case DAMAGE_TYPE_HIT:
		return mEnemy.res.hit;
	case DAMAGE_TYPE_CHARGE_HIT:
		return mEnemy.res.chargeHit;
	case DAMAGE_TYPE_PLUNGE:
		return mEnemy.res.plunge;
	case DAMAGE_TYPE_SKILL:
		return mEnemy.res.skill;
	case DAMAGE_TYPE_BURST:
		return mEnemy.res.burst;
	default:
		DEBUG_LOG("getRes not sure, return default value == 0\n");
		return 0;
	}
}
float calculate::getbonus(int type)
{
	float bonus = 1;
	if ((type & DAMAGE_TYPE_PHYSICS) ^ IS_DAMAGE)
	{
		bonus += mCharacter.bonus.physical;
	}
	if ((type & DAMAGE_TYPE_PYRO) ^ IS_DAMAGE)
	{
		bonus += mCharacter.bonus.pyro;
	}
	if ((type & DAMAGE_TYPE_HYDRO) ^ IS_DAMAGE)
	{
		bonus += mCharacter.bonus.hydro;
	}
	if ((type & DAMAGE_TYPE_DENDRO) ^ IS_DAMAGE)
	{
		bonus += mCharacter.bonus.dendro;
	}
	if ((type & DAMAGE_TYPE_ELECTRO) ^ IS_DAMAGE)
	{
		bonus += mCharacter.bonus.electro;
	}
	if ((type & DAMAGE_TYPE_ANEMO) ^ IS_DAMAGE)
	{
		bonus += mCharacter.bonus.anemo;
	}
	if ((type & DAMAGE_TYPE_CRYO) ^ IS_DAMAGE)
	{
		bonus += mCharacter.bonus.cryo;
	}
	if ((type & DAMAGE_TYPE_GEO) ^ IS_DAMAGE)
	{
		bonus += mCharacter.bonus.geo;
	}
	if ((type & DAMAGE_TYPE_HIT) ^ IS_DAMAGE)
	{
		bonus += mCharacter.bonus.hit;
	}
	if ((type & DAMAGE_TYPE_CHARGE_HIT) ^ IS_DAMAGE)
	{
		bonus += mCharacter.bonus.chargeHit;
	}
	if ((type & DAMAGE_TYPE_PLUNGE) ^ IS_DAMAGE)
	{
		bonus += mCharacter.bonus.plunge;
	}
	if ((type & DAMAGE_TYPE_SKILL) ^ IS_DAMAGE)
	{
		bonus += mCharacter.bonus.skill;
	}
	if ((type & DAMAGE_TYPE_BURST) ^ IS_DAMAGE)
	{
		bonus += mCharacter.bonus.burst;
	}
}
float calculate::calExpectance(int reactType, int damageType)
{
	float atk = calAtk();
	float critRate = calCritRate();
	float critDmg = calCritDmg();

	if (((REACT_TYPE_INCREASEMENT & reactType))^IS_REACT)
	{
		return defFactor() * resFactor(damageType) * levelFactor() * getbonus(damageType) * atk * ((1 - critRate) + critRate * (1 + critDmg)) * calReactFactor(reactType);
	}
	else if ((REACT_TYPE_FUSION & reactType)^IS_REACT)
	{
		return defFactor() * resFactor(damageType) * levelFactor() * calReactFactor(reactType) * fusionLevelFactor[mCharacter.level - 1];
	}
	else // no react
	{
		return defFactor() * resFactor(damageType) * levelFactor() * getbonus(damageType) * atk * ((1 - critRate) + critRate * (1 + critDmg));
		// return atk * ((1 - critRate) + critRate * (1 + critDmg));
	}
}