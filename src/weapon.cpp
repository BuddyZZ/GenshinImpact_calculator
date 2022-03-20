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

tWeapon weaponList[10]={
//level;    rare;    name;     type;    basicAtk;       hp;     atk;    def;    elementalMastery;   critRate;   critDmg;    rechage;
{90, STAR_5, "weaponTample", IS_EQUIPMENT,    608.0f,{0.0f,   0.0f,   0.0f,   0.0f,               0.0f,       0.0f,       0.0f},       
//pyro;     hydro;     dendro;    electro;  anemo;  cryo;   geo;     physical;  hit;    chargeHit;    plunge;   burst;   skill;
{0.0f,      0.0f,       0.0f,   0.0f,       0.0f,   0.0f,   0.0f,   0.0f,       0.0f,   0.0f,       0.0f,       0.0f,   0.0f,},       
//healingBonus;   incomingHelthingBonus;   sheldStrength;   cdReduction;     moveSpeed;     normalAtkSpeed;    defBonus;     defIgnor;
{0.0f,          0.0f,                       0.0f,           0.0f,           0.0f,           0.0f,               0.0f,       0.0f}
},
//level;    rare;    name;     type;    basicAtk;       hp;     atk;    def;    elementalMastery;   critRate;   critDmg;    rechage;
{90, STAR_5, "weaponTample", WEAPON_TYPE_SWORD,    608.0f,{0.0f,   0.0f,   0.0f,   0.0f,               0.0f,       0.0f,       0.0f},       
//pyro;     hydro;     dendro;    electro;  anemo;  cryo;   geo;     physical;  hit;    chargeHit;    plunge;   burst;   skill;
{0.0f,      0.0f,       0.0f,   0.0f,       0.0f,   0.0f,   0.0f,   0.0f,       0.0f,   0.0f,       0.0f,       0.0f,   0.0f,},       
//healingBonus;   incomingHelthingBonus;   sheldStrength;   cdReduction;     moveSpeed;     normalAtkSpeed;    defBonus;     defIgnor;
{0.0f,          0.0f,                       0.0f,           0.0f,           0.0f,           0.0f,               0.0f,       0.0f}
},

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

bool weapon::checkWeaponAttribute()
{
}
void weapon::calWeaponTable(int star, int level, int initialAtk, int subText,tWeapon weap)
{
}