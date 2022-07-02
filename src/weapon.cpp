#include "para.h"
#include "weapon.h"

using namespace genShinImpact;

// typedef struct weaponAttribute
// {
// 	s8 level;
// 	s8 rare;
// 	string name;
// 	u8 type;
// 	float basicAtk;
// 	tAttribute attribute;
// 	tBonus bonus;
// 	tBuff buff;
// } tWeapon, *pWeapon;

tWeapon weaponList[2]={
//level;    rare;    name;     type;    basicAtk;    fba fa fh fd    
{90, STAR_5, "weaponTample", IS_EQUIPMENT,    608.0f,{0, 0, 0, 0},
//hp;     atk;    def;    elementalMastery;   critRate;   critDmg;    rechage;
{0.0f,   0.0f,   0.0f,   0.0f,               0.0f,       0.0f,       0.0f},       
//pyro;     hydro;     dendro;    electro;  anemo;  cryo;   geo;     physical;  hit;    chargeHit;    plunge;   burst;   skill;
{0.0f,      0.0f,       0.0f,   0.0f,       0.0f,   0.0f,   0.0f,   0.0f,       0.0f,   0.0f,       0.0f,       0.0f,   0.0f,},       
//healingBonus;   incomingHelthingBonus;   sheldStrength;   cdReduction;     moveSpeed;     normalAtkSpeed;    defBonus;     defIgnor;
{0.0f,          0.0f,                       0.0f,           0.0f,           0.0f,           0.0f,               0.0f,       0.0f}},

};
weapon::weapon(int rarity, int level, int atkGrade)
{
    switch(rarity)
    {
        case STAR_5:
        case STAR_4:
        break;
    }
    mWeapon.type=WEAPON_ALL;
}
weapon::weapon(tWeapon oWeapon,int level)
{

}
weapon::weapon()
{
mWeapon.basicAtk=608;
mWeapon.type=WEAPON_ALL;
mWeapon.name="test_weapon";
mWeapon.rare=STAR_5;
mWeapon.level=90;
	memset(&mWeapon.buff, '\0', sizeof(tBuff));
	memset(&mWeapon.bonus, '\0', sizeof(tBonus));
	memset(&mWeapon.attribute, '\0', sizeof(tAttribute));
	memset(&mWeapon.attributeFix, '\0', sizeof(tAttributeFix));
}

// bool weapon::checkWeaponAttribute()
// {
// }
void weapon::calWeaponTable(int star, int level, int initialAtk, int subText,tWeapon weap)
{
}