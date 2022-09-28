#include "character.h"
using namespace genShinImpact;
using namespace std;
character::character()
{
    base.info.level = 90;
    base.info.name = "Default Character";
    base.attrB.hpFix = 15000;
    base.attrB.atkFix = 350;
    base.attrB.defFix = 650;
    
    base.attr.critRate=0.05+0.184;

    base.attr.hp=0.4;
}
character::character(eCharacterList characterNum, int level, int breakthrough)
{
    LOAD_STRUCT(base.attr, characterArr[characterNum].attr, tAttribute, float);
    LOAD_STRUCT(base.attrF, characterArr[characterNum].attrF, tAttributeFix, float);
    LOAD_STRUCT(base.attrB, characterArr[characterNum].attrB, tAttributeFix, float);
    LOAD_STRUCT(base.res, characterArr[characterNum].res, tRes, float);
    LOAD_STRUCT(base.bonus, characterArr[characterNum].bonus, tBonus, float);
    LOAD_STRUCT(base.indepMult, characterArr[characterNum].indepMult, tIndepMult, float);
    LOAD_STRUCT(base.extraRate, characterArr[characterNum].extraRate, tExtraRate, float);
    LOAD_STRUCT(base.reactFactor, characterArr[characterNum].reactFactor, tReactFactor, float);
    LOAD_STRUCT(base.buff, characterArr[characterNum].buff, tBuff, float);
    base.info.level = level;
    base.info.element = characterArr[characterNum].info.element;
    base.info.name = characterArr[characterNum].info.name;
    base.info.rarity = characterArr[characterNum].info.rarity;
    base.info.weapon = characterArr[characterNum].info.weapon;

    base.attack.name = characterArr[characterNum].attack.name;
    base.attack.element = characterArr[characterNum].attack.element;
    LOAD_STRUCT(base.attack, characterArr[characterNum].attack, tAttack, float);

    base.skill.name = characterArr[characterNum].skill.name;
    base.skill.element = characterArr[characterNum].skill.element;
    LOAD_STRUCT(base.skill, characterArr[characterNum].skill, tSkill, float);

    base.burst.name = characterArr[characterNum].burst.name;
    base.burst.element = characterArr[characterNum].burst.element;
    LOAD_STRUCT(base.burst, characterArr[characterNum].burst, tBurst, float);
}

void character::breakthrough(eCharacterList characterNum, int time)
{
//     switch (characterNum)
//     {
//     case TEST_A:
//         switch (time)
//         {
//         case 4:
//         case 3:
//         case 2:
//         case 1:
//         case 0:
//         }
//     case TEST_B:
//         switch (time)
//         {
//         case 4:
//         case 3:
//         case 2:
//         case 1:
//         case 0:
//         }
//         break;
//     }
}
