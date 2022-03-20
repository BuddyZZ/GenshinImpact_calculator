#include "para.h"
#include "character.h"

// int a[10];
// fill(a,a+10,0);
using namespace genShinImpact;
using namespace std;
character::character()
{
	memset(&mCharacter, '\0', sizeof(tCharacter));
	mCharacter.level = 90;
	mCharacter.basic.atk = 300;
	mCharacter.basic.critDmg = 0.5;
	mCharacter.basic.critRate = 0.05;
	mCharacter.basic.def = 600;
	mCharacter.basic.elementalMastery = 0;
	mCharacter.basic.rechage = 1;
	mCharacter.basic.hp = 10000;
	// INIT_STRUCT(mCharacter.basic, tAttribute, float, 0);
	mCharacter.attributeFix.atkBasic = 608;
}

character::character(const tCharacter temp) : mCharacter(temp)
{
	weaponLoaded = false;
	artifactMainTextLoaded = false;
	artifactSubTextLoaded = false;
	artifactEffectLoaded = false;
	teamEffectLoaded = false;
}
void character::printAllAttribute(void)
{
	printf("mCharacter.attributeFix.atkBasic==%6.3f\n", mCharacter.attributeFix.atkBasic);
	printf("mCharacter.attributeFix.atkFix  ==%6.3f\n", mCharacter.attributeFix.atkFix);
	printf("mCharacter.attributeFix.defFix  ==%6.3f\n", mCharacter.attributeFix.defFix);
	printf("mCharacter.attributeFix.hpFix   ==%6.3f\n", mCharacter.attributeFix.hpFix);
	printf("mCharacter.basic.atk               ==%6.3f\n", mCharacter.basic.atk);
	printf("mCharacter.basic.def               ==%6.3f\n", mCharacter.basic.def);
	printf("mCharacter.basic.hp                ==%6.3f\n", mCharacter.basic.hp);
	printf("mCharacter.basic.critRate          ==%6.3f\n", mCharacter.basic.critRate);
	printf("mCharacter.basic.critDmg           ==%6.3f\n", mCharacter.basic.critDmg);
	printf("mCharacter.basic.elementalMastery  ==%6.3f\n", mCharacter.basic.elementalMastery);
	printf("mCharacter.basic.rechage           ==%6.3f\n", mCharacter.basic.rechage);
	printf("mCharacter.attribute.atk              ==%6.3f\n", mCharacter.attribute.atk);
	printf("mCharacter.attribute.def              ==%6.3f\n", mCharacter.attribute.def);
	printf("mCharacter.attribute.hp               ==%6.3f\n", mCharacter.attribute.hp);
	printf("mCharacter.attribute.critRate         ==%6.3f\n", mCharacter.attribute.critRate);
	printf("mCharacter.attribute.critDmg          ==%6.3f\n", mCharacter.attribute.critDmg);
	printf("mCharacter.attribute.elementalMastery ==%6.3f\n", mCharacter.attribute.elementalMastery);
	printf("mCharacter.attribute.rechage          ==%6.3f\n", mCharacter.attribute.rechage);
	printf("mCharacter.bonus.anemo       ==%6.3f\n", mCharacter.bonus.anemo);
	printf("mCharacter.bonus.cryo        ==%6.3f\n", mCharacter.bonus.cryo);
	printf("mCharacter.bonus.dendro      ==%6.3f\n", mCharacter.bonus.dendro);
	printf("mCharacter.bonus.electro     ==%6.3f\n", mCharacter.bonus.electro);
	printf("mCharacter.bonus.geo         ==%6.3f\n", mCharacter.bonus.geo);
	printf("mCharacter.bonus.hydro       ==%6.3f\n", mCharacter.bonus.hydro);
	printf("mCharacter.bonus.pyro        ==%6.3f\n", mCharacter.bonus.pyro);
	printf("mCharacter.bonus.physical    ==%6.3f\n", mCharacter.bonus.physical);
	printf("mCharacter.bonus.skill       ==%6.3f\n", mCharacter.bonus.skill);
	printf("mCharacter.bonus.burst       ==%6.3f\n", mCharacter.bonus.burst);
	printf("mCharacter.bonus.plunge      ==%6.3f\n", mCharacter.bonus.plunge);
	printf("mCharacter.bonus.chargeHit   ==%6.3f\n", mCharacter.bonus.chargeHit);
	printf("mCharacter.bonus.hit         ==%6.3f\n", mCharacter.bonus.hit);

	mCharacter.bonus;
}

bool character::loadWeapon(const tWeapon *weapon)
{
	if ((mCharacter.weaponType & weapon->type) ^ IS_EQUIPMENT)
	{
		mCharacter.attributeFix.atkBasic = weapon->basicAtk;
		LOAD_STRUCT(mCharacter.attribute, weapon->attribute, tAttribute, float);
		LOAD_STRUCT(mCharacter.bonus, weapon->bonus, tBonus, float);
		LOAD_STRUCT(mCharacter.buff, weapon->buff, tBuff, float);
		weaponLoaded = true;
	}
	else
	{
		weaponLoaded = false;
		DEBUG_LOG("mCharacter.weaponType==%8X, weapon->type==%8X", mCharacter.weaponType, weapon->type);
		return weaponLoaded;
	}
	return weaponLoaded;
}
bool character::loadArtifactMainText(const tArtifact *tempArtifact)
{
	LOAD_STRUCT(mCharacter.attribute, tempArtifact->mainText, tAttribute, float);
	LOAD_STRUCT(mCharacter.attributeFix, tempArtifact->mainTextFix, tAttributeFix, float);
	LOAD_STRUCT(mCharacter.bonus, tempArtifact->mainBonus, tBonus, float);

	artifactMainTextLoaded = true;
}
bool character::loadArtifactSubText(const tArtifact *tempArtifact)
{
	LOAD_STRUCT(mCharacter.attribute, tempArtifact->subText, tAttribute, float);
	LOAD_STRUCT(mCharacter.attributeFix, tempArtifact->subTextFix, tAttributeFix, float);
	artifactSubTextLoaded = true;
}
bool character::loadArtifactEffect(const tArtifact *tempArtifact, int set)
{
}
bool character::loadTeamEffect(int type)
{
	if (type & TEAM_EFFECT_DOUBLE_PYRO)
	{
		mCharacter.attribute.atk += 0.25;
	}
	else if (type & TEAM_EFFECT_DOUBLE_HYDRO)
	{
		mCharacter.buff.incomingHelthingBonus += 0.25;
	}
	else if (type & TEAM_EFFECT_DOUBLE_DENDRO)
	{
		// unkown
	}
	else if (type & TEAM_EFFECT_DOUBLE_ELECTRO)
	{
		mCharacter.burst.energy *= 0.9;
	}
	else if (type & TEAM_EFFECT_DOUBLE_ANEMO)
	{
	}
	else if (type & TEAM_EFFECT_DOUBLE_CRYO)
	{
		mCharacter.attribute.critRate += 0.15;
	}
	else if (type & TEAM_EFFECT_DOUBLE_GEO)
	{
		mCharacter.buff.sheldStrength += 0.25;
		mCharacter.bonus.geo += 0.15;
	}
	else if (type & TEAM_EFFECT_QUADRUPLE)
	{
		tRes temp;
		INIT_STRUCT(temp, tRes, float, 0.15);
		LOAD_STRUCT(mCharacter.res, temp, tRes, float);
	}
}

void character::resetCharacter(void)
{
	memset(&mCharacter.attribute, '\0', sizeof(tAttribute));
	memset(&mCharacter.attributeFix, '\0', sizeof(tAttributeFix));
	memset(&mCharacter.bonus, '\0', sizeof(tBonus));
	memset(&mCharacter.buff, '\0', sizeof(tBuff));
	memset(&mCharacter.reactFactor, '\0', sizeof(tReactFactor));
	memset(&mCharacter.res, '\0', sizeof(tRes));

	weaponLoaded = false;
	artifactMainTextLoaded = false;
	artifactSubTextLoaded = false;
	artifactEffectLoaded = false;
	teamEffectLoaded = false;
}
