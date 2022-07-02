#ifndef PARA_H
#define PARA_H
#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
using namespace std;

#define _DEBUG_

#ifdef _DEBUG_
#include <stdio.h>
#define DEBUG_LOG printf
#else
#define debug_log //
#endif

#define LOAD_STRUCT(destStruct, srcStruct, structType, ContentType)                \
	for (int i = 0; i < sizeof(structType) / sizeof(ContentType); i++)             \
	{                                                                              \
		*((ContentType *)&(destStruct) + i) += *((ContentType *)&(srcStruct) + i); \
	}
#define INIT_STRUCT(destStruct, structType, ContentType, initValue)    \
	for (int i = 0; i < sizeof(structType) / sizeof(ContentType); i++) \
	{                                                                  \
		*((ContentType *)&(destStruct) + i) = initValue;               \
	}
#define CHECK(in, all, kind) \
	((((in) & (kind)) == (kind)) && (((in) & (all)) ^ (kind)))

#define LEVEL_MAX 90
// Rarity stars u8
#define IS_RARITY 0X10000000
#define STAR_5 (0X00000001 | IS_RARITY)
#define STAR_4 (0X00000002 | IS_RARITY)
#define STAR_3 (0X00000004 | IS_RARITY)
// equipment type
#define IS_EQUIPMENT 0X20000000
#define ARTIFACT_FLOWER_OF_LIFE (0X00000001 | IS_EQUIPMENT)
#define ARTIFACT_PLUME_OF_DEATH (0X00000002 | IS_EQUIPMENT)
#define ARTIFACT_SANDS_OF_EON (0X00000004 | IS_EQUIPMENT)
#define ARTIFACT_GOBLET_OF_EONOTHEM (0X00000008 | IS_EQUIPMENT) // cup
#define ARTIFACT_CIRCLET_OF_LOGOS (0X00000010 | IS_EQUIPMENT)	// head
#define ARTIFACT_ALL (ARTIFACT_FLOWER_OF_LIFE | ARTIFACT_PLUME_OF_DEATH | ARTIFACT_SANDS_OF_EON | ARTIFACT_GOBLET_OF_EONOTHEM | ARTIFACT_CIRCLET_OF_LOGOS)
#define WEAPON_TYPE_SWORD (0X00000100 | IS_EQUIPMENT)
#define WEAPON_TYPE_BOW (0X00000200 | IS_EQUIPMENT)
#define WEAPON_TYPE_POLEARM (0X00000400 | IS_EQUIPMENT)	 // lance
#define WEAPON_TYPE_CATALYST (0X00000800 | IS_EQUIPMENT) // magic
#define WEAPON_TYPE_CLAYMORE (0X00001000 | IS_EQUIPMENT) // heavy sword
#define WEAPON_ALL (WEAPON_TYPE_SWORD | WEAPON_TYPE_BOW | WEAPON_TYPE_POLEARM | WEAPON_TYPE_CATALYST | WEAPON_TYPE_CLAYMORE)
// team effect
#define IS_TEAM_EFFECT 0X40000000
#define TEAM_EFFECT_DOUBLE_PYRO (0x00000001 | IS_TEAM_EFFECT)
#define TEAM_EFFECT_DOUBLE_HYDRO (0x00000002 | IS_TEAM_EFFECT)
#define TEAM_EFFECT_DOUBLE_DENDRO (0x00000004 | IS_TEAM_EFFECT)
#define TEAM_EFFECT_DOUBLE_ELECTRO (0x00000008 | IS_TEAM_EFFECT)
#define TEAM_EFFECT_DOUBLE_ANEMO (0x00000010 | IS_TEAM_EFFECT)
#define TEAM_EFFECT_DOUBLE_CRYO (0x00000020 | IS_TEAM_EFFECT)
#define TEAM_EFFECT_DOUBLE_GEO (0x00000040 | IS_TEAM_EFFECT)
#define TEAM_EFFECT_QUADRUPLE (0x00000080 | IS_TEAM_EFFECT)
// element and damage type
#define IS_ELEMENT 0X80000000
#define IS_DAMAGE IS_ELEMENT
#define ELEMENT_TYPE_PYRO (0X00000001 | IS_ELEMENT)	  // fire
#define ELEMENT_TYPE_HYDRO (0X00000002 | IS_ELEMENT)  // water
#define ELEMENT_TYPE_DENDRO (0X00000004 | IS_ELEMENT) // grass
#define ELEMENT_TYPE_ELECTRO (0X00000008 | IS_ELEMENT)
#define ELEMENT_TYPE_ANEMO (0X00000010 | IS_ELEMENT) // wind
#define ELEMENT_TYPE_CRYO (0X00000020 | IS_ELEMENT)	 // ice
#define ELEMENT_TYPE_GEO (0X00000040 | IS_ELEMENT)
#define ELEMENT_TYPE_PHYSICS (0X00000080 | IS_ELEMENT)
#define ELEMENT_TYPE_STRONG (0X00800000 | IS_ELEMENT) // strong element type, may be useless
#define ELEMENT_ALL (ELEMENT_TYPE_PYRO | ELEMENT_TYPE_HYDRO | ELEMENT_TYPE_DENDRO | ELEMENT_TYPE_ELECTRO | ELEMENT_TYPE_ANEMO | ELEMENT_TYPE_CRYO | ELEMENT_TYPE_GEO | ELEMENT_TYPE_PHYSICS)
#define DAMAGE_TYPE_PYRO ELEMENT_TYPE_PYRO
#define DAMAGE_TYPE_HYDRO ELEMENT_TYPE_HYDRO
#define DAMAGE_TYPE_DENDRO ELEMENT_TYPE_DENDRO
#define DAMAGE_TYPE_ELECTRO ELEMENT_TYPE_ELECTRO
#define DAMAGE_TYPE_ANEMO ELEMENT_TYPE_ANEMO
#define DAMAGE_TYPE_CRYO ELEMENT_TYPE_CRYO
#define DAMAGE_TYPE_GEO ELEMENT_TYPE_GEO
#define DAMAGE_TYPE_PHYSICS ELEMENT_TYPE_PHYSICS
#define DAMAGE_TYPE_HIT (0X00000100 | IS_DAMAGE)
#define DAMAGE_TYPE_CHARGE_HIT (0X00000200 | IS_DAMAGE)
#define DAMAGE_TYPE_PLUNGE (0X00000400 | IS_DAMAGE)
#define DAMAGE_TYPE_SKILL (0X00000800 | IS_DAMAGE)
#define DAMAGE_TYPE_BURST (0X00001000 | IS_DAMAGE)
#define DAMAGE_ALL (ELEMENT_ALL | DAMAGE_TYPE_HIT | DAMAGE_TYPE_CHARGE_HIT | DAMAGE_TYPE_PLUNGE | DAMAGE_TYPE_SKILL | DAMAGE_TYPE_BURST)
// react type
#define IS_REACT 0X01000000
#define REACT_TYPE_SWIRL (0X00000001 | IS_REACT)
#define REACT_TYPE_SUPERCONDUCT (0X00000002 | IS_REACT)
#define REACT_TYPE_ELECTRO_CHARGED (0X00000004 | IS_REACT)
#define REACT_TYPE_OVERLOADED (0X00000008 | IS_REACT)
#define REACT_TYPE_CRUSHINGICE (0X00000010 | IS_REACT)
#define REACT_TYPE_BURNING (0X00000020 | IS_REACT)
#define REACT_TYPE_VAPORIZE_A (0X00000040 | IS_REACT)
#define REACT_TYPE_VAPORIZE_B (0X00000080 | IS_REACT)
#define REACT_TYPE_MELT_A (0X00000100 | IS_REACT)
#define REACT_TYPE_MELT_B (0X00000200 | IS_REACT)
#define REACT_TYPE_CRYSTALLIZE (0X00000400 | IS_REACT)
#define REACT_TYPE_FROZEN (0X00000800 | IS_REACT)
//#define grass						(0X000A000|IS_REACT)
#define REACT_TYPE_FUSION (REACT_TYPE_SWIRL | REACT_TYPE_SUPERCONDUCT | REACT_TYPE_ELECTRO_CHARGED | REACT_TYPE_OVERLOADED | REACT_TYPE_CRUSHINGICE | REACT_TYPE_BURNING)
#define REACT_TYPE_INCREASEMENT (REACT_TYPE_VAPORIZE_A | REACT_TYPE_VAPORIZE_B | REACT_TYPE_MELT_A | REACT_TYPE_MELT_B)
#define REACT_TYPE_ALL (REACT_TYPE_FUSION | REACT_TYPE_INCREASEMENT | REACT_TYPE_CRYSTALLIZE)
// artifact text info & class of attribute
#define IS_ARTIFACT_TEXT 0X02000000
#define ART_TEXT_SUB_FIX_HP (0x00000001 | IS_ARTIFACT_TEXT)
#define ART_TEXT_SUB_FIX_ATK (0x00000002 | IS_ARTIFACT_TEXT)
#define ART_TEXT_SUB_FIX_DEF (0x00000004 | IS_ARTIFACT_TEXT)
#define ART_TEXT_SUB_HP (0x00000008 | IS_ARTIFACT_TEXT)
#define ART_TEXT_SUB_ATK (0x00000010 | IS_ARTIFACT_TEXT)
#define ART_TEXT_SUB_DEF (0x00000020 | IS_ARTIFACT_TEXT)
#define ART_TEXT_SUB_CRIT_RATE (0x00000040 | IS_ARTIFACT_TEXT)
#define ART_TEXT_SUB_CRIT_DMG (0x00000080 | IS_ARTIFACT_TEXT)
#define ART_TEXT_SUB_RECHARGE (0x00000100 | IS_ARTIFACT_TEXT)
#define ART_TEXT_SUB_ELEMENTAL_MASTERY (0x00000200 | IS_ARTIFACT_TEXT)
#define ART_TEXT_MAIN_HP (0x00001000 | IS_ARTIFACT_TEXT)
#define ART_TEXT_MAIN_ATK (0x00002000 | IS_ARTIFACT_TEXT)
#define ART_TEXT_MAIN_DEF (0x00004000 | IS_ARTIFACT_TEXT)
#define ART_TEXT_MAIN_CRIT_RATE (0x00008000 | IS_ARTIFACT_TEXT)
#define ART_TEXT_MAIN_CRIT_DMG (0x00010000 | IS_ARTIFACT_TEXT)
#define ART_TEXT_MAIN_ELEMENTAL_MASTERY (0x00020000 | IS_ARTIFACT_TEXT)
#define ART_TEXT_MAIN_RECHARGE (0x00040000 | IS_ARTIFACT_TEXT)
#define ART_TEXT_MAIN_ELEMENT_BONUS (0x00800000 | IS_ARTIFACT_TEXT)
#define ART_TEXT_MAIN_ELEMENT_BONUS_PYRO (0X00800001 | IS_ARTIFACT_TEXT)   // fire
#define ART_TEXT_MAIN_ELEMENT_BONUS_HYDRO (0X00800002 | IS_ARTIFACT_TEXT)  // water
#define ART_TEXT_MAIN_ELEMENT_BONUS_DENDRO (0X00800004 | IS_ARTIFACT_TEXT) // grass
#define ART_TEXT_MAIN_ELEMENT_BONUS_ELECTRO (0X00800008 | IS_ARTIFACT_TEXT)
#define ART_TEXT_MAIN_ELEMENT_BONUS_ANEMO (0X00800010 | IS_ARTIFACT_TEXT) // wind
#define ART_TEXT_MAIN_ELEMENT_BONUS_CRYO (0X00800020 | IS_ARTIFACT_TEXT)  // ice
#define ART_TEXT_MAIN_ELEMENT_BONUS_GEO (0X00800040 | IS_ARTIFACT_TEXT)
#define ART_TEXT_MAIN_ELEMENT_BONUS_PHYSICS (0X00800080 | IS_ARTIFACT_TEXT)

#define ATTRIBUTE_HP ART_TEXT_MAIN_HP
#define ATTRIBUTE_ATK ART_TEXT_MAIN_ATK
#define ATTRIBUTE_DEF ART_TEXT_MAIN_DEF
#define ATTRIBUTE_CRIT_RATE ART_TEXT_MAIN_CRIT_RATE
#define ATTRIBUTE_CRIT_DMG ART_TEXT_MAIN_CRIT_DMG
#define ATTRIBUTE_ELEMENTAL_MASTERY ART_TEXT_MAIN_ELEMENTAL_MASTERY
#define ATTRIBUTE_RECHARGE ART_TEXT_MAIN_RECHARGE
#define ATTRIBUTE_ELEMENT_BONUS ART_TEXT_MAIN_ELEMENT_BONUS
#define ATTRIBUTE_ELEMENT_BONUS_PYRO ART_TEXT_MAIN_ELEMENT_BONUS_PYRO
#define ATTRIBUTE_ELEMENT_BONUS_HYDRO ART_TEXT_MAIN_ELEMENT_BONUS_HYDRO
#define ATTRIBUTE_ELEMENT_BONUS_DENDRO ART_TEXT_MAIN_ELEMENT_BONUS_DENDRO
#define ATTRIBUTE_ELEMENT_BONUS_ELECTRO ART_TEXT_MAIN_ELEMENT_BONUS_ELECTRO
#define ATTRIBUTE_ELEMENT_BONUS_ANEMO ART_TEXT_MAIN_ELEMENT_BONUS_ANEMO
#define ATTRIBUTE_ELEMENT_BONUS_CRYO ART_TEXT_MAIN_ELEMENT_BONUS_CRYO
#define ATTRIBUTE_ELEMENT_BONUS_GEO ART_TEXT_MAIN_ELEMENT_BONUS_GEO
#define ATTRIBUTE_ELEMENT_BONUS_PHYSICS ART_TEXT_MAIN_ELEMENT_BONUS_PHYSICS

/**
 * A struct use to define all kinds of normal attack type
 * @param NormalAttackDmg[level][segment]
 */
typedef struct normalAttackDmg
{
	float NormalAttackDmg[15][16];
	float chargeAttackDmg[15];
	float chargeAttackStaminaCost[15];
	float plungeDmg[15];
	float lowPlungeDmg[15];
	float highPlungeDmg[15];
} tAttack, *pAttack;
/**
 * A struct use to define character skill info
 * @param rate[level][segmentRate]
 */
typedef struct skill
{
	string name;
	int element;
	float rate[15][16];
	float cooldown[15];
} tSkill, *pSkill;
/**
 * A struct use to define character elemental burst info
 * @param rate[level][segmentRate]
 */
typedef struct burst
{
	string name;
	int element;
	float energy;
	float rate[15][16];
	float cooldown[15];
} tBurst, *pBurst;
/**
 * A struct use to define basic attribute that used commonly
 */
typedef struct basicAttribute
{
	float hp;
	float atk;
	float def;
	float elementalMastery;
	float critRate;
	float critDmg;
	float rechage;
	// float stamina;
} tAttribute, *pAttribute;
/**
 * A struct use to define some character attribute seldom use or can not be seen in attribute page
 */
typedef struct buffOrDebuff
{
	float healingBonus;
	float incomingHelthingBonus;
	float sheldStrength;
	float cdReduction;
	float moveSpeed;
	float staminaReduce;
	float normalAtkSpeed;
	float defBonus;
	float defIgnor;
} tBuff, *pBuff;
/**
 * A struct use to define extra Fixed value bonus, which come from artifact all skill/burst
 * now there are only atk hp def have fix value
 */
typedef struct attributeFixAdd
{
	float atkBasic;
	float hpFix;
	float atkFix;
	float defFix;
} tAttributeFix, *pAttributeFix;
/**
 * A struct use to define all kinds of bonus/resistance E.g. element/physics/skill/burst/Attack
 * All the value should Addition and subtraction operations
 */
typedef struct BonusAndResistance
{
	float pyro;
	float hydro;
	float dendro;
	float electro;
	float anemo;
	float cryo;
	float geo;
	float physical;
	float hit;
	float chargeHit;
	float plunge;
	float burst;
	float skill;
} tBonus, *pBonus, tRes, *pRes;
/**
 * A struct use to define all kinds of elemental react bonus factor
 * Now it can be get from artifact 4-set only
 * @param vaporize_a a react end with _a/_b is stands for high/low react factor
 */
typedef struct reactFactorBonus
{
	float swirl;
	float superconduct;
	float electroCharged;
	float overloaded;
	float crushingice;
	float burning;
	float vaporize_a;
	float vaporize_b;
	float melt_a;
	float melt_b;
	float crystallize;
	// float frozen;
} tReactFactor;
/**
 * A struct use to define enemy info
 * Now the important part is enemy resistace/level
 */
typedef struct enemyAttribute
{
	int level;
	string name;
	tRes res;
} tEnemy, *pEnemy;

/**
 * A struct use to define a whole character, and it is consist of some other struct defined before
 * This struct can be use to transfer data between object to simplize operate steps
 * @param basic character basic attribute that should not change after initiate
 * @param attribute addition attribute form weapon/artifact/
 *
 */
typedef struct characterAttribute
{
	int level;
	int rare;
	string name;
	int weaponType;
	int element;
	tAttribute basic;			// character basic value
	tAttribute attribute;		// add percent and such as element master
	tAttributeFix attributeFix; // add fix Atk Hp Def basicAtk
	tBonus bonus;
	tRes res;
	tBuff buff;
	tReactFactor reactFactor;
	tSkill skill;
	tBurst burst;
	tAttack attack;
} tCharacter, *pCharacter;
/**
 * A struct use to define a whole weapon attribute
 * This struct can be use to transfer data between object to simplize operate steps
 */
typedef struct weaponAttribute
{
	int level;
	int rare;
	string name;
	int type;
	float basicAtk;
	tAttributeFix attributeFix;
	tAttribute attribute;
	tBonus bonus;
	tBuff buff;
} tWeapon, *pWeapon;
/**
 * A struct use to define one piece of artifact
 * This should only use in class artifact and it only a number of /artifactAttribute/
 * @param subtext type of Corresponding subtext
 * @param totalFortune value of Corresponding subtext should be a float like 3.4=1.0+0.9+0.8+0.7
 */
typedef struct onePieceArtifact
{
	int level;
	int rare;
	string name;
	int position;
	int maintext;
	int subtext[4];
	float totalFortune[4]; // 10 9 8 7
} tOneArtifact;
/**
 * A struct use to define whole artifact set such as set_2/set_4
 * This struct can be use to transfer data between object to simplize operate steps
 * @param setRes  	[0]is set_2 effect [1]is set_4 effect.
 * 					If there is a Probabilistic trigger event, the content will be the expectation
 * 					If there are 2 set_2 the [0]and[1] stand for 2 different set_2 effect
 * following are same with /setRes/
 */
typedef struct artifactAttribute
{
	int level;
	int rare;
	string name;
	tOneArtifact pieces[5];
	// u8 artifactType;
	tAttribute mainText;
	tAttributeFix mainTextFix;
	tBonus mainBonus;
	tAttribute subText;
	tAttributeFix subTextFix;

	tRes setRes[2];
	tBuff setBuff[2];
	tBonus setBonus[2];
	tReactFactor setReactFactor[2];
	tAttribute setAttribute[2];
	tAttributeFix setAttributeFix[2];
} tArtifact, *pArtifact;

#endif
