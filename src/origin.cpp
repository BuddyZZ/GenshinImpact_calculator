#include "origin.h"
using namespace genShinImpact;
using namespace std;
origin::origin()
{
}
origin::~origin()
{
}

float origin::getAttribute(tAllAttr *obj, eTextType type)
{
    switch (type)
    {
    case TEXT_UNSURE:
        return 0;
    case TEXT_HP:
        return obj->attr.hp;
    case TEXT_ATK:
        return obj->attr.atk;
    case TEXT_DEF:
        return obj->attr.def;
    case TEXT_CRIT_RATE:
        return obj->attr.critRate;
    case TEXT_CRIT_DMG:
        return obj->attr.critDmg;
    case TEXT_ELEMENTAL_MASTERY:
        return obj->attr.elementalMastery;
    case TEXT_RECHARGE:
        return obj->attr.rechage;

    case TEXT_FIX_HP:
        return obj->attrF.hpFix;
    case TEXT_FIX_ATK:
        return obj->attrF.atkFix;
    case TEXT_FIX_DEF:
        return obj->attrF.defFix;

    case TEXT_BASE_HP:
        return obj->attrB.hpFix;
    case TEXT_BASE_ATK:
        return obj->attrB.atkFix;
    case TEXT_BASE_DEF:
        return obj->attrB.defFix;

    default:
        return -1;
    }
}
float origin::getInfo(tAllAttr *obj, eInfoType type)
{
    switch (type)
    {
    case INFO_UNSURE:
        return 0;
    // case INFO_NAME :
    // return obj->info.name;
    case INFO_WEAPON:
        return obj->info.weapon;
    case INFO_LEVEL:
        return obj->info.level;
    case INFO_RARITY:
        return obj->info.rarity;
    case INFO_ELEMENT:
        return obj->info.element;
    default:
        return -1;
    }
}

float origin::getBuff(tAllAttr *obj, eBuffType type)
{
    switch (type)
    {
    case BUFF_UNSURE:
        return 0;
    case BUFF_HEALING_BONUS:
        return obj->buff.healingBonus;
    case BUFF_INCOMING_HELTHING_BONUS:
        return obj->buff.incomingHelthingBonus;
    case BUFF_SHELD_STRENGTH:
        return obj->buff.sheldStrength;
    case BUFF_CD_REDUCE:
        return obj->buff.cdReduce;
    case BUFF_MOVE_SPEED:
        return obj->buff.moveSpeed;
    case BUFF_NORMAL_ATK_SPEED:
        return obj->buff.normalAtkSpeed;
    case BUFF_STAMINA_REDUCE:
        return obj->buff.staminaReduce;
    case BUFF_DEF_IGNOR:
        return obj->buff.defIgnor;
    default:
        return -1;
    }
}
float origin::getIndepMult(tAllAttr *obj, eKind kind, int type)
{
    switch (kind)
    {
    case KIND_DAMAGE:
        switch (type)
        {
        case DAMAGE_UNSURE:
            return 0;
        case DAMAGE_HIT:
            return obj->indepMult.hit;
        case DAMAGE_CHARGE_HIT:
            return obj->indepMult.chargeHit;
        case DAMAGE_PLUNGE:
            return obj->indepMult.plunge;
        case DAMAGE_SKILL:
            return obj->indepMult.skill;
        case DAMAGE_TYPE_BURST:
            return obj->indepMult.burst;
        default:
            return -11;
        }
    case KIND_ELEMENT:
        switch (type)
        {
        case ELEMENT_UNSURE:
            return 0;
        case ELEMENT_CRYO:
            return obj->indepMult.cryo;
        case ELEMENT_PYRO:
            return obj->indepMult.pyro;
        case ELEMENT_HYDRO:
            return obj->indepMult.hydro;
        case ELEMENT_DENDRO:
            return obj->indepMult.dendro;
        case ELEMENT_ELECTRO:
            return obj->indepMult.electro;
        case ELEMENT_ANEMO:
            return obj->indepMult.anemo;
        case ELEMENT_GEO:
            return obj->indepMult.geo;
        case ELEMENT_PHYSICS:
            return obj->indepMult.physical;
        default:
            return -22;
        }
    default:
        return -33;
    }
}
float origin::getExtraRate(tAllAttr *obj, eKind kind, int type)
{
    switch (kind)
    {
    case KIND_DAMAGE:
        switch (type)
        {
        case DAMAGE_UNSURE:
            return 0;
        case DAMAGE_HIT:
            return obj->extraRate.hit;
        case DAMAGE_CHARGE_HIT:
            return obj->extraRate.chargeHit;
        case DAMAGE_PLUNGE:
            return obj->extraRate.plunge;
        case DAMAGE_SKILL:
            return obj->extraRate.skill;
        case DAMAGE_TYPE_BURST:
            return obj->extraRate.burst;
        default:
            return -11;
        }
    case KIND_ELEMENT:
        switch (type)
        {
        case ELEMENT_UNSURE:
            return 0;
        case ELEMENT_CRYO:
            return obj->extraRate.cryo;
        case ELEMENT_PYRO:
            return obj->extraRate.pyro;
        case ELEMENT_HYDRO:
            return obj->extraRate.hydro;
        case ELEMENT_DENDRO:
            return obj->extraRate.dendro;
        case ELEMENT_ELECTRO:
            return obj->extraRate.electro;
        case ELEMENT_ANEMO:
            return obj->extraRate.anemo;
        case ELEMENT_GEO:
            return obj->extraRate.geo;
        case ELEMENT_PHYSICS:
            return obj->extraRate.physical;
        default:
            return -22;
        }
    default:
        return -33;
    }
}
float origin::getReactFactor(tAllAttr *obj, eReactType type)
{
    switch (type)
    {
    case REACT_UNSURE:
        return 0;
    case REACT_VAPORIZE_A:
        return obj->reactFactor.vaporize_a;
    case REACT_VAPORIZE_B:
        return obj->reactFactor.vaporize_b;
    case REACT_MELT_A:
        return obj->reactFactor.melt_a;
    case REACT_MELT_B:
        return obj->reactFactor.melt_b;
    case REACT_SWIRL:
        return obj->reactFactor.swirl;
    case REACT_SUPERCONDUCT:
        return obj->reactFactor.superconduct;
    case REACT_BURNING:
        return obj->reactFactor.burning;
    case REACT_OVERGROWN:
        return obj->reactFactor.overgrown;
    case REACT_RADICALIZE:
        return obj->reactFactor.redicalize;
    case REACT_ELECTRO_CHARGED:
        return obj->reactFactor.electroCharged;
    case REACT_OVERLOADED:
        return obj->reactFactor.overloaded;
    case REACT_CRYSTALLIZE:
        return obj->reactFactor.crystallize;
        // case REACT_FROZEN:
        //     return obj->reactFactor.frozen;

    default:
        return -1;
    }
}

float origin::getRes(tAllAttr *obj, eKind kind, int type)
{
    switch (kind)
    {
    case KIND_DAMAGE:
        switch (type)
        {
        case DAMAGE_UNSURE:
            return 0;
        case DAMAGE_HIT:
            return obj->res.hit;
        case DAMAGE_CHARGE_HIT:
            return obj->res.chargeHit;
        case DAMAGE_PLUNGE:
            return obj->res.plunge;
        case DAMAGE_SKILL:
            return obj->res.skill;
        case DAMAGE_TYPE_BURST:
            return obj->res.burst;
        default:
            return -11;
        }
    case KIND_ELEMENT:
        switch (type)
        {
        case ELEMENT_UNSURE:
            return 0;
        case ELEMENT_CRYO:
            return obj->res.cryo;
        case ELEMENT_PYRO:
            return obj->res.pyro;
        case ELEMENT_HYDRO:
            return obj->res.hydro;
        case ELEMENT_DENDRO:
            return obj->res.dendro;
        case ELEMENT_ELECTRO:
            return obj->res.electro;
        case ELEMENT_ANEMO:
            return obj->res.anemo;
        case ELEMENT_GEO:
            return obj->res.geo;
        case ELEMENT_PHYSICS:
            return obj->res.physical;
        default:
            return -22;
        }
    default:
        return -33;
    }
}
float origin::getBonus(tAllAttr *obj, eKind kind, int type)
{
    float bonusValue = 0;
    switch (kind)
    {
    case KIND_DAMAGE:
        switch (type)
        {
        case DAMAGE_UNSURE:
            return 0;
        case DAMAGE_HIT:
            return obj->bonus.hit;
        case DAMAGE_CHARGE_HIT:
            return obj->bonus.chargeHit;
        case DAMAGE_PLUNGE:
            return obj->bonus.plunge;
        case DAMAGE_SKILL:
            return obj->bonus.skill;
        case DAMAGE_TYPE_BURST:
            return obj->bonus.burst;
        default:
            return -11;
        }
    case KIND_ELEMENT:
        switch (type)
        {
        case ELEMENT_UNSURE:
            return 0;
        case ELEMENT_CRYO:
            return obj->bonus.cryo;
        case ELEMENT_PYRO:
            return obj->bonus.pyro;
        case ELEMENT_HYDRO:
            return obj->bonus.hydro;
        case ELEMENT_DENDRO:
            return obj->bonus.dendro;
        case ELEMENT_ELECTRO:
            return obj->bonus.electro;
        case ELEMENT_ANEMO:
            return obj->bonus.anemo;
        case ELEMENT_GEO:
            return obj->bonus.geo;
        case ELEMENT_PHYSICS:
            return obj->bonus.physical;
        default:
            return -22;
        }
    default:
        return -33;
    }
}

float getRate(tAllAttr *obj, eKind kind, int level, int segment)
{
    void *temp;
    switch (kind)
    {
    case KIND_SKILL:
        return obj->skill.rate[level][segment];
        break;
    case KIND_BURST:
        return obj->burst.rate[level][segment];
    case KIND_ATTACK:
        return obj->attack.NormalAttackDmg[level][segment];
        break;
    default:
        return 1;
    }
}
