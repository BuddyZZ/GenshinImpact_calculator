#include "calculate.h"

using namespace genShinImpact;
using namespace std;

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

float fusioncalLevelFactor[LEVEL_MAX] = {
	/*		1		2		3		4		5		6		7		8		9		10*/
	/* 0*/ 7, 10, 13, 17, 20, 24, 28, 33, 37, 42,
	/*10*/ 7, 10, 13, 17, 20, 24, 28, 33, 37, 42,
	/*20*/ 7, 10, 13, 17, 20, 24, 28, 33, 37, 42,
	/*30*/ 7, 10, 13, 17, 20, 24, 28, 33, 37, 42,
	/*40*/ 7, 10, 13, 17, 20, 24, 28, 33, 37, 42,
	/*50*/ 7, 10, 13, 17, 20, 24, 28, 33, 37, 42,
	/*60*/ 7, 10, 13, 17, 20, 24, 28, 33, 37, 42,
	/*70*/ 7, 10, 13, 17, 20, 24, 28, 33, 37, 539,
	/*80*/ 7, 10, 13, 17, 20, 24, 28, 33, 37, 723.9};

calculate::calculate()
{
	memset(&(character::base), '0', sizeof(tAllAttr));
}
calculate::~calculate()
{
	memset(&(character::base), '0', sizeof(tAllAttr));
}
void calculate::resetAll()
{
	memset(&mAttacker, '\0', sizeof(tAttribute));
	memset(&mSuffer, '\0', sizeof(tAttribute));
	memset(&mWeapon, '\0', sizeof(tAttribute));
	memset(&mArtifact, '\0', sizeof(tAttribute));
	memset(&mEnvironment, '\0', sizeof(tAttribute));
}
void calculate::loadALL()
{
	loadAttacker();
	loadSuffer();
	loadWeapon();
	loadArtifact();
	loadEnvironment();
}

float calculate::calDamage(float rate, eReactType reactType, TextType mainAttr, eCalType calType, eDamageType damageType, eElementType elementType)
{
	float critFactor;
	float basicDamageValue;
	float critRate = calCritRate();
	float critDmg = calCritDmg();
	float defFactor = calDefFactor();
	float levelFactor = calLevelFactor();
	float resFactor = calResFactor(damageType, elementType);
	float bonus = calBonus(damageType, elementType);
	float elementalMastery = calElmentalMastery();
	float reactFactor = calReactFactor(reactType, elementalMastery);
	float indepMult = calIndepMult(damageType, elementType);
	float extraRate = calExtraRate(damageType, elementType);

	switch (mainAttr)
	{
	case TEXT_HP:
		basicDamageValue = calHp();
		break;
	case TEXT_ATK:
		basicDamageValue = calAtk();
		break;
	case TEXT_DEF:
		basicDamageValue = calDef();
		break;
	default:
		critFactor = 1;
	}

	switch (calType)
	{
	case CAL_MAX:
		critFactor = 1 + critDmg;
		break;
	case CAL_EXPECTANCE:
		critFactor = (1 - critRate) + critRate * (1 + critDmg);
		break;
	case CAL_MIN:
		critFactor = 1;
		break;
	default:
		critFactor = -0;
	}

	if (REACT_UNSURE < reactType && reactType < REACT_TYPE_INCREASEMENT)
	{
		return defFactor * resFactor * levelFactor * bonus * (basicDamageValue * rate + extraRate) * indepMult * critFactor * reactFactor;
	}
	else if (REACT_TYPE_INCREASEMENT < reactType && reactType < REACT_TYPE_FUSION)
	{
		return resFactor * levelFactor * reactFactor * fusioncalLevelFactor[mAttacker.info.level];
	}
	else // no react
	{
		return defFactor * resFactor * levelFactor * bonus * (basicDamageValue * rate + extraRate) * indepMult * critFactor;
	}
}

float calculate::calHp()
{
	float basic=origin::getAttribute(&mAttacker, TEXT_BASE_HP);
	float percent;
	float fix;
}
float calculate::calAtk()
{
}
float calculate::calDef()
{
}
float calculate::calCritRate()
{
}
float calculate::calCritDmg()
{
}
float calculate::calDefFactor()
{
}
float calculate::calLevelFactor()
{
}
float calculate::calElmentalMastery()
{
}
float calculate::calReactFactor(eReactType reactType, float elementalMastery)
{
}
float calculate::calResFactor(eDamageType damageType, eElementType elementType)
{
}
float calculate::calBonus(eDamageType damageType, eElementType elementType)
{
}
float calculate::calIndepMult(eDamageType damageType, eElementType elementType)
{
}
float calculate::calExtraRate(eDamageType damageType, eElementType elementType)
{
}

void calculate::loadAttacker()
{
	memcpy(&mAttacker, &(character::base), sizeof(tAttribute));
}
void calculate::loadSuffer()
{
	memcpy(&mSuffer, &(enemy::base), sizeof(tAttribute));
}
void calculate::loadWeapon()
{
	memcpy(&mWeapon, &(weapon::base), sizeof(tAttribute));
}
void calculate::loadArtifact()
{
	memcpy(&mArtifact, &(artifact::base), sizeof(tAttribute));
}
void calculate::loadEnvironment()
{
	memcpy(&mEnvironment, &(environment::base), sizeof(tAttribute));
}