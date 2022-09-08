#include "logger.h"
using namespace genShinImpact;
using namespace std;

logger::logger() {}
logger::~logger() {}

void logger::logAttribute(tAllAttr *obj, int type) {}

void logger::logAttributeFix(tAllAttr *obj, int type) {
  // cout << attributeFixLog[type] << (*((float *)&(obj->attrF) + type)) <<
  // endl;
}

void logger::logRes(tAllAttr *obj, int damageType, int elementType) {
  float resValue = 0;
  switch (damageType) {
  case DAMAGE_UNSURE:
    resValue += 0;
    break;
  case DAMAGE_HIT:
    resValue += obj->res.hit;
    break;
  case DAMAGE_CHARGE_HIT:
    resValue += obj->res.chargeHit;
    break;
  case DAMAGE_PLUNGE:
    resValue += obj->res.plunge;
    break;
  case DAMAGE_SKILL:
    resValue += obj->res.skill;
    break;
  case DAMAGE_BURST:
    resValue += obj->res.burst;
    break;
  default:
    resValue += 0;
  }
  switch (elementType) {
  case ELEMENT_UNSURE:
    resValue += 0;
    break;
  case ELEMENT_CRYO:
    resValue += obj->res.cryo;
    break;
  case ELEMENT_PYRO:
    resValue += obj->res.pyro;
    break;
  case ELEMENT_HYDRO:
    resValue += obj->res.hydro;
    break;
  case ELEMENT_DENDRO:
    resValue += obj->res.dendro;
    break;
  case ELEMENT_ELECTRO:
    resValue += obj->res.electro;
    break;
  case ELEMENT_ANEMO:
    resValue += obj->res.anemo;
    break;
  case ELEMENT_GEO:
    resValue += obj->res.geo;
    break;
  case ELEMENT_PHYSICS:
    resValue += obj->res.physical;
    break;
  case ELEMENT_STRONG:
    resValue += obj->res.anemo;
    break;
  default:
    resValue += 0;
  }
}

void logger::logBonus(tAllAttr *obj, int type) {}

void logger::logIndepMult(tAllAttr *obj, int type) {}

void logger::logExtraRate(tAllAttr *obj, int type) {}

void logger::logReactFactor(tAllAttr *obj, int type) {}

void logger::logBuff(tAllAttr *obj, int type) {}
// char infoLog[sizeof(tInfo)][64]{
//     "Level is",
//     "Name is",
//     "Rarity is",
//     "Element is",
//     "Weapon is",
//     "Artifact is"

// };
void logger::logInfo(tAllAttr *obj, int type) {
  if (obj == NULL) {
  }
  switch (type) {
  case 1:
    // cout << infoLog[type] << obj->info.level << endl;
    break;
  }
}

void logger::logAttack(tAllAttr *obj, int type) {}

void logger::logBurst(tAllAttr *obj, int type) {}

void logger::logSkill(tAllAttr *obj, int type) {}

// void character::printAllAttribute(void)
// {

// 	printf("mCharacter.name  ==%s\n", mCharacter.name);
// 	printf("mCharacter.rare  ==%d\n", mCharacter.rare);
// 	printf("mCharacter.level ==%d\n", mCharacter.level);
// 	printf("mCharacter.attributeFix.atkBasic    ==%6.3f\n",
// mCharacter.attributeFix.atkBasic); 	printf("mCharacter.attributeFix.atkFix
// ==%6.3f\n", mCharacter.attributeFix.atkFix);
// 	printf("mCharacter.attributeFix.defFix      ==%6.3f\n",
// mCharacter.attributeFix.defFix); 	printf("mCharacter.attributeFix.hpFix
// ==%6.3f\n", mCharacter.attributeFix.hpFix); 	printf("mCharacter.basic.atk
// ==%6.3f\n", mCharacter.basic.atk); 	printf("mCharacter.basic.def ==%6.3f\n",
// mCharacter.basic.def); 	printf("mCharacter.basic.hp ==%6.3f\n",
// mCharacter.basic.hp); 	printf("mCharacter.basic.critRate ==%6.3f\n",
// mCharacter.basic.critRate); 	printf("mCharacter.basic.critDmg ==%6.3f\n",
// mCharacter.basic.critDmg); 	printf("mCharacter.basic.elementalMastery
// ==%6.3f\n", mCharacter.basic.elementalMastery);
// 	printf("mCharacter.basic.recharge             ==%6.3f\n",
// mCharacter.basic.recharge); 	printf("mCharacter.attribute.atk ==%6.3f\n",
// mCharacter.attribute.atk); 	printf("mCharacter.attribute.def ==%6.3f\n",
// mCharacter.attribute.def); 	printf("mCharacter.attribute.hp ==%6.3f\n",
// mCharacter.attribute.hp); 	printf("mCharacter.attribute.critRate
// ==%6.3f\n", mCharacter.attribute.critRate);
// printf("mCharacter.attribute.critDmg
// ==%6.3f\n", mCharacter.attribute.critDmg);
// 	printf("mCharacter.attribute.elementalMastery ==%6.3f\n",
// mCharacter.attribute.elementalMastery);
// printf("mCharacter.attribute.recharge
// ==%6.3f\n", mCharacter.attribute.recharge); 	printf("mCharacter.bonus.anemo
// ==%6.3f\n", mCharacter.bonus.anemo); 	printf("mCharacter.bonus.cryo
// ==%6.3f\n", mCharacter.bonus.cryo); 	printf("mCharacter.bonus.dendro
// ==%6.3f\n", mCharacter.bonus.dendro); 	printf("mCharacter.bonus.electro
// ==%6.3f\n", mCharacter.bonus.electro); 	printf("mCharacter.bonus.geo
// ==%6.3f\n", mCharacter.bonus.geo); 	printf("mCharacter.bonus.hydro
// ==%6.3f\n", mCharacter.bonus.hydro); 	printf("mCharacter.bonus.pyro
// ==%6.3f\n", mCharacter.bonus.pyro); 	printf("mCharacter.bonus.physical
// ==%6.3f\n", mCharacter.bonus.physical); 	printf("mCharacter.bonus.skill
// ==%6.3f\n", mCharacter.bonus.skill); 	printf("mCharacter.bonus.burst
// ==%6.3f\n", mCharacter.bonus.burst); 	printf("mCharacter.bonus.plunge
// ==%6.3f\n", mCharacter.bonus.plunge);
// printf("mCharacter.bonus.chargeHit
// ==%6.3f\n", mCharacter.bonus.chargeHit); 	printf("mCharacter.bonus.hit
// ==%6.3f\n", mCharacter.bonus.hit); 	printf("mCharacter.buff.cdReduction
// ==%6.3f\n", mCharacter.buff.cdReduction); 	printf("mCharacter.buff.defBonus
// ==%6.3f\n", mCharacter.buff.defBonus); 	printf("mCharacter.buff.defIgnor
// ==%6.3f\n", mCharacter.buff.defIgnor);
// printf("mCharacter.buff.healingBonus
// ==%6.3f\n", mCharacter.buff.healingBonus);
// 	printf("mCharacter.buff.incomingHelthingBonus   ==%6.3f\n",
// mCharacter.buff.incomingHelthingBonus);
// printf("mCharacter.buff.staminaReduce
// ==%6.3f\n", mCharacter.buff.staminaReduce); printf("mCharacter.buff.moveSpeed
// ==%6.3f\n", mCharacter.buff.moveSpeed);
// 	printf("mCharacter.buff.normalAtkSpeed          ==%6.3f\n",
// mCharacter.buff.normalAtkSpeed); 	printf("mCharacter.buff.sheldStrength
// ==%6.3f\n", mCharacter.buff.sheldStrength); 	printf("mCharacter.res.anemo
// ==%6.3f\n", mCharacter.res.anemo); 	printf("mCharacter.res.cryo
// ==%6.3f\n", mCharacter.res.cryo); 	printf("mCharacter.res.dendro
// ==%6.3f\n", mCharacter.res.dendro); 	printf("mCharacter.res.electro
// ==%6.3f\n", mCharacter.res.electro); 	printf("mCharacter.res.geo
// ==%6.3f\n", mCharacter.res.geo); 	printf("mCharacter.res.hydro
// ==%6.3f\n", mCharacter.res.hydro); 	printf("mCharacter.res.pyro
// ==%6.3f\n", mCharacter.res.pyro); 	printf("mCharacter.res.physical
// ==%6.3f\n", mCharacter.res.physical); 	printf("mCharacter.res.skill
// ==%6.3f\n", mCharacter.res.skill); 	printf("mCharacter.res.burst
// ==%6.3f\n", mCharacter.res.burst); 	printf("mCharacter.res.plunge
// ==%6.3f\n", mCharacter.res.plunge); 	printf("mCharacter.res.chargeHit
// ==%6.3f\n", mCharacter.res.chargeHit); 	printf("mCharacter.res.hit
// ==%6.3f\n", mCharacter.res.hit);
// }