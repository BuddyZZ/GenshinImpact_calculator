#include "origin.h"
using namespace genShinImpact;
using namespace std;
origin::origin() {}
origin::~origin() {}

float * origin::getAttribute(tAllAttr *obj, eTextType type)
{
  switch (type)
  {
  case TEXT_UNSURE:
    return NULL;
  case TEXT_HP:
    return &(obj->attr.hp);
  case TEXT_ATK:
    return &(obj->attr.atk);
  case TEXT_DEF:
    return &(obj->attr.def);
  case TEXT_CRIT_RATE:
    return &(obj->attr.critRate);
  case TEXT_CRIT_DMG:
    return &(obj->attr.critDmg);
  case TEXT_ELEMENTAL_MASTERY:
    return &(obj->attr.elementalMastery);
  case TEXT_RECHARGE:
    return &(obj->attr.rechage);

  case TEXT_FIX_HP:
    return &(obj->attrF.hpFix);
  case TEXT_FIX_ATK:
    return &(obj->attrF.atkFix);
  case TEXT_FIX_DEF:
    return &(obj->attrF.defFix);

  case TEXT_BASE_HP:
    return &(obj->attrB.hpFix);
  case TEXT_BASE_ATK:
    return &(obj->attrB.atkFix);
  case TEXT_BASE_DEF:
    return &(obj->attrB.defFix);

  default:
    return NULL;
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
float origin::getIndepMult(tAllAttr *obj, eDamageType damageType, eElementType elementType)
{
  float retVal = 0;
  switch (damageType)
  {
  case DAMAGE_UNSURE:
    retVal += 0;
    break;
  case DAMAGE_HIT:
    retVal += obj->indepMult.hit;
    break;
  case DAMAGE_CHARGE_HIT:
    retVal += obj->indepMult.chargeHit;
    break;
  case DAMAGE_PLUNGE:
    retVal += obj->indepMult.plunge;
    break;
  case DAMAGE_SKILL:
    retVal += obj->indepMult.skill;
    break;
  case DAMAGE_BURST:
    retVal += obj->indepMult.burst;
    break;
  default:
    return -1;
  }

  switch (elementType)
  {
  case ELEMENT_UNSURE:
    retVal += 0;
  case ELEMENT_CRYO:
    retVal += obj->indepMult.cryo;
    break;
  case ELEMENT_PYRO:
    retVal += obj->indepMult.pyro;
    break;
  case ELEMENT_HYDRO:
    retVal += obj->indepMult.hydro;
    break;
  case ELEMENT_DENDRO:
    retVal += obj->indepMult.dendro;
    break;
  case ELEMENT_ELECTRO:
    retVal += obj->indepMult.electro;
    break;
  case ELEMENT_ANEMO:
    retVal += obj->indepMult.anemo;
    break;
  case ELEMENT_GEO:
    retVal += obj->indepMult.geo;
    break;
  case ELEMENT_PHYSICS:
    retVal += obj->indepMult.physical;
    break;
  default:
    return -2;
  }
  return retVal;
}
float origin::getExtraRate(tAllAttr *obj, eDamageType damageType, eElementType elementType)
{
  float retVal = 0;

  switch (damageType)
  {
  case DAMAGE_UNSURE:
    retVal += 0;
    break;
  case DAMAGE_HIT:
    retVal += obj->extraRate.hit;
    break;
  case DAMAGE_CHARGE_HIT:
    retVal += obj->extraRate.chargeHit;
    break;
  case DAMAGE_PLUNGE:
    retVal += obj->extraRate.plunge;
    break;
  case DAMAGE_SKILL:
    retVal += obj->extraRate.skill;
    break;
  case DAMAGE_BURST:
    retVal += obj->extraRate.burst;
    break;
  default:
    retVal += -11;
  }

  switch (elementType)
  {
  case ELEMENT_UNSURE:
    retVal += 0;
    break;
  case ELEMENT_CRYO:
    retVal += obj->extraRate.cryo;
    break;
  case ELEMENT_PYRO:
    retVal += obj->extraRate.pyro;
    break;
  case ELEMENT_HYDRO:
    retVal += obj->extraRate.hydro;
    break;
  case ELEMENT_DENDRO:
    retVal += obj->extraRate.dendro;
    break;
  case ELEMENT_ELECTRO:
    retVal += obj->extraRate.electro;
    break;
  case ELEMENT_ANEMO:
    retVal += obj->extraRate.anemo;
    break;
  case ELEMENT_GEO:
    retVal += obj->extraRate.geo;
    break;
  case ELEMENT_PHYSICS:
    retVal += obj->extraRate.physical;
    break;
  default:
    return -22;
  }
  return retVal;
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

float origin::getRes(tAllAttr *obj, eDamageType damageType, eElementType elementType)
{
  float retVal = 0;
  switch (damageType)
  {
  case DAMAGE_UNSURE:
    retVal += 0;
    break;
  case DAMAGE_HIT:
    retVal += obj->res.hit;
    break;
  case DAMAGE_CHARGE_HIT:
    retVal += obj->res.chargeHit;
    break;
  case DAMAGE_PLUNGE:
    retVal += obj->res.plunge;
    break;
  case DAMAGE_SKILL:
    retVal += obj->res.skill;
    break;
  case DAMAGE_BURST:
    retVal += obj->res.burst;
    break;
  default:
    return -11;
  }
  switch (elementType)
  {
  case ELEMENT_UNSURE:
    retVal += 0;
    break;
  case ELEMENT_CRYO:
    retVal += obj->res.cryo;
    break;
  case ELEMENT_PYRO:
    retVal += obj->res.pyro;
    break;
  case ELEMENT_HYDRO:
    retVal += obj->res.hydro;
    break;
  case ELEMENT_DENDRO:
    retVal += obj->res.dendro;
    break;
  case ELEMENT_ELECTRO:
    retVal += obj->res.electro;
    break;
  case ELEMENT_ANEMO:
    retVal += obj->res.anemo;
    break;
  case ELEMENT_GEO:
    retVal += obj->res.geo;
    break;
  case ELEMENT_PHYSICS:
    retVal += obj->res.physical;
    break;
  default:
    return -22;
  }
  return retVal;
}
float origin::getBonus(tAllAttr *obj, eDamageType damageType, eElementType elementType)
{
  float retVal = 0;

  switch (damageType)
  {
  case DAMAGE_UNSURE:
    retVal += 0;
    break;
  case DAMAGE_HIT:
    retVal += obj->bonus.hit;
    break;
  case DAMAGE_CHARGE_HIT:
    retVal += obj->bonus.chargeHit;
    break;
  case DAMAGE_PLUNGE:
    retVal += obj->bonus.plunge;
    break;
  case DAMAGE_SKILL:
    retVal += obj->bonus.skill;
    break;
  case DAMAGE_BURST:
    retVal += obj->bonus.burst;
    break;
  default:
    return -11;
  }

  switch (elementType)
  {
  case ELEMENT_UNSURE:
    retVal += 0;
    break;
  case ELEMENT_CRYO:
    retVal += obj->bonus.cryo;
    break;
  case ELEMENT_PYRO:
    retVal += obj->bonus.pyro;
    break;
  case ELEMENT_HYDRO:
    retVal += obj->bonus.hydro;
    break;
  case ELEMENT_DENDRO:
    retVal += obj->bonus.dendro;
    break;
  case ELEMENT_ELECTRO:
    retVal += obj->bonus.electro;
    break;
  case ELEMENT_ANEMO:
    retVal += obj->bonus.anemo;
    break;
  case ELEMENT_GEO:
    retVal += obj->bonus.geo;
    break;
  case ELEMENT_PHYSICS:
    retVal += obj->bonus.physical;
    break;
  default:
    return -22;
  }
  return retVal;
}

float origin::getRate(tAllAttr *obj, eKind kind, int level, int segment)
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
float origin::getReactCoefficient(eReactType type)
{

  switch (type)
  {
  // no react
  case REACT_UNSURE:
    return 0;
    // fusion
  case REACT_SWIRL:
    return REACT_COEFFICIENT_SWIRL;
  case REACT_SUPERCONDUCT:
    return REACT_COEFFICIENT_SUPERCONDUCT;
  case REACT_ELECTRO_CHARGED:
    return REACT_COEFFICIENT_ELECTRO_CHARGED;
  case REACT_OVERLOADED:
    return REACT_COEFFICIENT_OVERLOADED;
  case REACT_CRUSHINGICE:
    return REACT_COEFFICIENT_CRUSHINGICE;
  case REACT_BURNING:
    return REACT_COEFFICIENT_BURNING;
    // froze
  case REACT_FROZEN:
    return REACT_COEFFICIENT_FROZEN;
    // crystallize
  case REACT_CRYSTALLIZE:
    return REACT_COEFFICIENT_CRYSTALLIZE;
    // increasement
  case REACT_VAPORIZE_A:
    return REACT_COEFFICIENT_VAPORIZE_A;
  case REACT_VAPORIZE_B:
    return REACT_COEFFICIENT_VAPORIZE_B;
  case REACT_MELT_A:
    return REACT_COEFFICIENT_MELT_A;
  case REACT_MELT_B:
    return REACT_COEFFICIENT_MELT_B;
  default:
    return 0;
  }
}
