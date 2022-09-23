#include "artifact.h"
using namespace genShinImpact;
using namespace std;
artifact::artifact()
{
    base.attrF.atkFix = 311;
    base.attrF.defFix = 0;
    base.attrF.hpFix = 4786;
    base.attr.atk = 0.45;
    base.attr.critDmg = 0.70;
    base.attr.critRate = 0.35;
    base.attr.def = 0.2;
    base.attr.elementalMastery = 120;
    base.attr.hp = 0.2;
    base.attr.recharge = 0.5;
    base.info.name="Default Artifact";
}

void artifact::resetArtifact()
{
    // memset(&base, '0', sizeof(tAllAttr)); segment fault
}

float artifact::changeOneSubText(eAddOrSub add, eTextType text, float fortune)
{
    switch (text)
    {
    case TEXT_UNSURE:
        return 0;
    case TEXT_HP:
        return changeAttribute(&base, TEXT_HP, ART_VALUE_SUB_HP * fortune * posOrNeg(add));
    case TEXT_ATK:
        return changeAttribute(&base, TEXT_ATK, ART_VALUE_SUB_ATK * fortune * posOrNeg(add));
    case TEXT_DEF:
        return changeAttribute(&base, TEXT_DEF, ART_VALUE_SUB_DEF * fortune * posOrNeg(add));
    case TEXT_CRIT_RATE:
        return changeAttribute(&base, TEXT_CRIT_RATE, ART_VALUE_SUB_CRIT_RATE * fortune * posOrNeg(add));
    case TEXT_CRIT_DMG:
        return changeAttribute(&base, TEXT_CRIT_DMG, ART_VALUE_SUB_CRIT_DMG * fortune * posOrNeg(add));
    case TEXT_ELEMENTAL_MASTERY:
        return changeAttribute(&base, TEXT_ELEMENTAL_MASTERY, ART_VALUE_SUB_ELEMENTAL_MASTERY * fortune * posOrNeg(add));
    case TEXT_RECHARGE:
        return changeAttribute(&base, TEXT_RECHARGE, ART_VALUE_SUB_RECHARGE * fortune * posOrNeg(add));
    }
}

float artifact::changeFlowerOfLife(eAddOrSub add, eRarityType rarity)
{
    return *getAttributeAddr(&base, TEXT_FIX_HP) = ART_VALUE_MAIN_HP_FIX * calRarityFactor(rarity) * posOrNeg(add);
}

float artifact::changePlumeOfDeath(eAddOrSub add, eRarityType rarity)
{
    return *getAttributeAddr(&base, TEXT_FIX_ATK) = ART_VALUE_MAIN_ATK_FIX * calRarityFactor(rarity) * posOrNeg(add);
}

float artifact::changeSandOfEon(eAddOrSub add, eRarityType rarity, eTextType mainText)
{
    float value;

    switch (mainText)
    {
    case TEXT_RECHARGE:
        value = ART_VALUE_MAIN_RECHARGE;
        break;
    case TEXT_HP:
        value = ART_VALUE_MAIN_HP;
        break;
    case TEXT_ATK:
        value = ART_VALUE_MAIN_ATK;
        break;
    case TEXT_DEF:
        value = ART_VALUE_MAIN_DEF;
        break;
    case TEXT_ELEMENTAL_MASTERY:
        value = ART_VALUE_MAIN_ELEMENTAL_MASTERY;
        break;
    default:
        return 0;
    }
    return *getAttributeAddr(&base, mainText) = value * calRarityFactor(rarity) * posOrNeg(add);
}

float artifact::changeGobletOfEonothem(eAddOrSub add, eRarityType rarity, eTextType mainText)
{
    float value;

    switch (mainText)
    {
    case TEXT_ELEMENT_BONUS_PYRO:
    case TEXT_ELEMENT_BONUS_HYDRO:
    case TEXT_ELEMENT_BONUS_DENDRO:
    case TEXT_ELEMENT_BONUS_ELECTRO:
    case TEXT_ELEMENT_BONUS_ANEMO:
    case TEXT_ELEMENT_BONUS_CRYO:
    case TEXT_ELEMENT_BONUS_GEO:
        value = ART_VALUE_MAIN_ELEMENT_BONUS;
        break;
    case TEXT_ELEMENT_BONUS_PHYSICS:
        value = ART_VALUE_MAIN_PHYSIC_BONUS;
        break;
    case TEXT_HP:
        value = ART_VALUE_MAIN_HP;
        break;
    case TEXT_ATK:
        value = ART_VALUE_MAIN_ATK;
        break;
    case TEXT_DEF:
        value = ART_VALUE_MAIN_DEF;
        break;
    case TEXT_ELEMENTAL_MASTERY:
        value = ART_VALUE_MAIN_ELEMENTAL_MASTERY;
        break;
    default:
        return 0;
    }
    return *getAttributeAddr(&base, mainText) = value * calRarityFactor(rarity) * posOrNeg(add);
}

float artifact::changeCircletOfLogos(eAddOrSub add, eRarityType rarity, eTextType mainText)
{
    float value;

    switch (mainText)
    {
    case TEXT_CRIT_RATE:
        value = ART_VALUE_MAIN_CRIT_RATE;
        break;
    case TEXT_CRIT_DMG:
        value = ART_VALUE_MAIN_CRIT_DMG;
        break;
    case TEXT_HP:
        value = ART_VALUE_MAIN_HP;
        break;
    case TEXT_ATK:
        value = ART_VALUE_MAIN_ATK;
        break;
    case TEXT_DEF:
        value = ART_VALUE_MAIN_DEF;
        break;
    case TEXT_ELEMENTAL_MASTERY:
        value = ART_VALUE_MAIN_ELEMENTAL_MASTERY;
        break;
    default:
        return 0;
    }
    return *getAttributeAddr(&base, mainText) = value * calRarityFactor(rarity) * posOrNeg(add);
}

float artifact::calRarityFactor(eRarityType rarity)
{
    float rarityFactor;
    if (rarity == RARITY_STAR_5)
        rarityFactor = 1;
    else if (rarity == RARITY_STAR_4)
        rarityFactor = 0.8;
    else
        return 0;
}
float artifact::posOrNeg(eAddOrSub add)
{
    if (add == ADD)
        return 1;
    else if (add == SUB)
        return -1;
    else
        return 0;
}
