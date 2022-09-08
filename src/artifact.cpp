#include "artifact.h"
using namespace genShinImpact;
using namespace std;
artifact::artifact()
{
    memset(&base, '0', sizeof(tAllAttr));
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
}
artifact::~artifact()
{
    memset(&base, '0', sizeof(tAllAttr));
}
float artifact::changeOneText(eAddOrSub add, eTextType text, float fortune)
{
    float value;

    if (add == ADD)
        value = 1;
    else if (add == SUB)
        value = -1;
    else
        return 0;

    switch (text)
    {
    case TEXT_UNSURE:
        return 0;
    case TEXT_HP:
        value *= ART_VALUE_SUB_HP * fortune;
        return changeAttribute(&base, TEXT_HP, value);
    case TEXT_ATK:
        value *= ART_VALUE_SUB_ATK * fortune;
        return changeAttribute(&base, TEXT_ATK, value);
    case TEXT_DEF:
        value *= ART_VALUE_SUB_DEF * fortune;
        return changeAttribute(&base, TEXT_DEF, value);
    case TEXT_CRIT_RATE:
        value *= ART_VALUE_SUB_CRIT_RATE * fortune;
        return changeAttribute(&base, TEXT_CRIT_RATE, value);
    case TEXT_CRIT_DMG:
        value *= ART_VALUE_SUB_CRIT_DMG * fortune;
        return changeAttribute(&base, TEXT_CRIT_DMG, value);
    case TEXT_ELEMENTAL_MASTERY:
        value *= ART_VALUE_SUB_ELEMENTAL_MASTERY * fortune;
        return changeAttribute(&base, TEXT_ELEMENTAL_MASTERY, value);
    case TEXT_RECHARGE:
        value *= ART_VALUE_SUB_RECHARGE * fortune;
        return changeAttribute(&base, TEXT_RECHARGE, value);
    }
}
