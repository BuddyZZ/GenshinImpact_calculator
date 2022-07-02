#ifndef WEAPON_H
#define WEAPON_H

#include "para.h"

namespace genShinImpact
{
	extern tWeapon weaponList[10];
	class weapon
	{
	public:
		weapon(int rarity, int level, int atkGrade);
		weapon(tWeapon oWeapon,int level);
		weapon();
		tWeapon mWeapon;
		// bool checkWeaponAttribute();
		void calWeaponTable(int star, int level, int initialAtk, int subText,tWeapon weap);
	protected:
	private:
	};
}
#endif