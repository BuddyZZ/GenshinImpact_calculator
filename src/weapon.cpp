#include "weapon.h"
#include "origin.h"
#include <cstring>
using namespace genShinImpact;
using namespace std;

tAllAttr weaponArr[2] =
	{
		{
			{
				.name = "test-weapon-",
				.rarity = RARITY_STAR_5,
				.level = 90,
				.element = ELEMENT_UNSURE,
				.weapon = WEAPON_SWORD,
			}, /*info*/
			{
				.atkFix = 608,
				.defFix = 0,
				.hpFix = 0,
			},	/*attrB*/
			{}, /*attrF*/
			{
				.atk = 0,
				.def = 0,
				.hp = 0,
				.critRate = 0,
				.critDmg = 0.668,
				.elementalMastery = 0,
				.recharge = 0,
			},	/*attr*/
			{}, /*res*/
			{
				.pyro = 0.48,
				.hydro = 0.48,
				.electro = 0.48,
				.cryo = 0.48,
				.dendro = 0.48,
				.anemo = 0.48,
				.geo = 0.48,
				.physical = 0,
				.attack = 0,
				.chargeAttack = 0,
				.plunge = 0,
				.skill = 0,
				.burst = 0,
			},	/*bonus*/
			{}, /* reactFactor*/
			{
				.healingBonus = 0,
				.incomingHelthingBonus = 0,
				.sheldStrength = 0,
				.defIgnor = 0,
				.cdReduce = 0,
				.normalAtkSpeed = 0,
				.staminaReduce = 0,
				.moveSpeed = 0,
			},	/* buff*/
			{}, /* attack*/
			{}, /* skill*/
			{}, /* burst*/
			{}, /* indepMult*/
			{}	/* extraRate*/
		},
		{
			{
				.name = "test-weapon-2",
				.rarity = RARITY_STAR_5,
				.level = 90,
				.element = ELEMENT_UNSURE,
				.weapon = WEAPON_BOW,
			}, /*info*/
			{
				.atkFix = 548,
				.defFix = 0,
				.hpFix = 0,
			},	/*attrB*/
			{}, /*attrF*/
			{
				.atk = 0,
				.def = 0,
				.hp = 0.2,
				.critRate = 0,
				.critDmg = 0.886,
				.elementalMastery = 0,
				.recharge = 0,
			},	/*attr*/
			{}, /*res*/
			{
				.pyro = 0.2,
				.hydro = 0.2,
				.electro = 0.2,
				.cryo = 0.2,
				.dendro = 0.2,
				.anemo = 0.2,
				.geo = 0.2,
				.physical = 0.2,
				.attack = 0,
				.chargeAttack = 0,
				.plunge = 0,
				.skill = 0,
				.burst = 0,
			},	/*bonus*/
			{}, /* reactFactor*/
			{
				.healingBonus = 0,
				.incomingHelthingBonus = 0,
				.sheldStrength = 0,
				.defIgnor = 0,
				.cdReduce = 0,
				.normalAtkSpeed = 0,
				.staminaReduce = 0,
				.moveSpeed = 0,
			},	/* buff*/
			{}, /* attack*/
			{}, /* skill*/
			{}, /* burst*/
			{}, /* indepMult*/
			{}	/* extraRate*/
		},
};
weapon::weapon()
{
	base.info.name = "Default Weapon";
	base.attrB.atkFix = 568;
	base.attr.critDmg = 0.886;
	base.attr.hp = 0.2;
	base.bonus.hydro = 0.2;
}
weapon::weapon(eWeaponlist weaponNum, int level, int breakThrough)
{
	LOAD_STRUCT(base.attr, weaponArr[weaponNum].attr, tAttribute, float);
	LOAD_STRUCT(base.attrB, weaponArr[weaponNum].attrB, tAttributeFix, float);
	LOAD_STRUCT(base.bonus, weaponArr[weaponNum].bonus, tBonus, float);
	LOAD_STRUCT(base.buff, weaponArr[weaponNum].buff, tBuff, float);

	base.info.level = level;
	base.info.element = weaponArr[weaponNum].info.element;
	base.info.name = weaponArr[weaponNum].info.name;
	base.info.rarity = weaponArr[weaponNum].info.rarity;
	base.info.weapon = weaponArr[weaponNum].info.weapon;
}
