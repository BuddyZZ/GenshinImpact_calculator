#include "calculate.h"

using namespace genShinImpact;
using namespace std;

float fusioncalLevelFactor[LEVEL_MAX] = {
    /*		1		2		3		4 5 6 7 8 9 10*/
    /* 0*/ 7, 10, 13, 17, 20, 24, 28, 33, 37, 42,
    /*10*/ 7, 10, 13, 17, 20, 24, 28, 33, 37, 42,
    /*20*/ 7, 10, 13, 17, 20, 24, 28, 33, 37, 42,
    /*30*/ 7, 10, 13, 17, 20, 24, 28, 33, 37, 42,
    /*40*/ 7, 10, 13, 17, 20, 24, 28, 33, 37, 42,
    /*50*/ 7, 10, 13, 17, 20, 24, 28, 33, 37, 42,
    /*60*/ 7, 10, 13, 17, 20, 24, 28, 33, 37, 42,
    /*70*/ 7, 10, 13, 17, 20, 24, 28, 33, 37, 539,
    /*80*/ 7, 10, 13, 17, 20, 24, 28, 33, 37, 723.9};

calculate::calculate() { memset(&(character::base), '0', sizeof(tAllAttr)); }
calculate::~calculate() { memset(&(character::base), '0', sizeof(tAllAttr)); }
void calculate::resetAll()
{
  memset(&mAttacker, '\0', sizeof(tAttribute));
  memset(&mSuffer, '\0', sizeof(tAttribute));
  memset(&mWeapon, '\0', sizeof(tAttribute));
  memset(&mArtifact, '\0', sizeof(tAttribute));
  memset(&mEnvironment, '\0', sizeof(tAttribute));
}
void calculate::loadALL()
{
  loadAttacker();
  loadSuffer();
  loadWeapon();
  loadArtifact();
  loadEnvironment();
}

float calculate::calDamage(float rate, eReactType reactType, TextType mainAttr,
                           eCalType calType, eDamageType damageType,
                           eElementType elementType)
{
  float critFactor;
  float basicDamageValue;
  float critRate = calCritRate();
  float critDmg = calCritDmg();
  float defFactor = calDefFactor();
  float levelFactor = calLevelFactor();
  float resFactor = calResFactor(damageType, elementType);
  float bonus = calBonus(damageType, elementType);
  float elementalMastery = calElementalMastery();
  float reactFactor = calReactFactor(reactType, elementalMastery);
  float indepMult = calIndepMult(damageType, elementType);
  float extraRate = calExtraRate(damageType, elementType);

  switch (mainAttr)
  {
  case TEXT_HP:
    basicDamageValue = calHp();
    break;
  case TEXT_ATK:
    basicDamageValue = calAtk();
    break;
  case TEXT_DEF:
    basicDamageValue = calDef();
    break;
  default:
    critFactor = 1;
  }

  switch (calType)
  {
  case CAL_MAX:
    critFactor = 1 + critDmg;
    break;
  case CAL_EXPECTANCE:
    critFactor = (1 - critRate) + critRate * (1 + critDmg);
    break;
  case CAL_MIN:
    critFactor = 1;
    break;
  default:
    critFactor = -0;
  }

  if (REACT_TYPE_INCREASEMENT_START < reactType &&
      reactType < REACT_TYPE_INCREASEMENT_END)
  {
    return defFactor * resFactor * levelFactor * bonus *
           (basicDamageValue * rate + extraRate) * indepMult * critFactor *
           reactFactor;
  }
  else if (REACT_TYPE_FUSION_START < reactType &&
           reactType < REACT_TYPE_FUSION_END)
  {
    return resFactor * levelFactor * reactFactor *
           fusioncalLevelFactor[mAttacker.info.level];
  }
  else // no react
  {
    return defFactor * resFactor * levelFactor * bonus *
           (basicDamageValue * rate + extraRate) * indepMult * critFactor;
  }
}

float calculate::calHp()
{
  float base = getAttribute(&mAttacker, TEXT_BASE_HP) +
               getAttribute(&mWeapon, TEXT_BASE_HP) +
               getAttribute(&mArtifact, TEXT_BASE_HP) +
               getAttribute(&mEnvironment, TEXT_BASE_HP);
  float fix = getAttribute(&mAttacker, TEXT_FIX_HP) +
              getAttribute(&mWeapon, TEXT_FIX_HP) +
              getAttribute(&mArtifact, TEXT_FIX_HP) +
              getAttribute(&mEnvironment, TEXT_FIX_HP);
  float percent = getAttribute(&mAttacker, TEXT_HP) +
                  getAttribute(&mWeapon, TEXT_HP) +
                  getAttribute(&mArtifact, TEXT_HP) +
                  getAttribute(&mEnvironment, TEXT_HP);
  cout << "base==" << base << endl;
  cout << "fix==" << fix << endl;
  cout << "percent==" << percent << endl;

  return base * (1 + percent) + fix;
}
float calculate::calAtk()
{
  float base = getAttribute(&mAttacker, TEXT_BASE_ATK) +
               getAttribute(&mWeapon, TEXT_BASE_ATK) +
               getAttribute(&mArtifact, TEXT_BASE_ATK) +
               getAttribute(&mEnvironment, TEXT_BASE_ATK);
  float fix = getAttribute(&mAttacker, TEXT_FIX_ATK) +
              getAttribute(&mWeapon, TEXT_FIX_ATK) +
              getAttribute(&mArtifact, TEXT_FIX_ATK) +
              getAttribute(&mEnvironment, TEXT_FIX_ATK);
  float percent = getAttribute(&mAttacker, TEXT_ATK) +
                  getAttribute(&mWeapon, TEXT_ATK) +
                  getAttribute(&mArtifact, TEXT_ATK) +
                  getAttribute(&mEnvironment, TEXT_ATK);
  return base * (1 + percent) + fix;
}
float calculate::calDef()
{
  float base = getAttribute(&mAttacker, TEXT_BASE_DEF) +
               getAttribute(&mWeapon, TEXT_BASE_DEF) +
               getAttribute(&mArtifact, TEXT_BASE_DEF) +
               getAttribute(&mEnvironment, TEXT_BASE_DEF);
  float fix = getAttribute(&mAttacker, TEXT_FIX_DEF) +
              getAttribute(&mWeapon, TEXT_FIX_DEF) +
              getAttribute(&mArtifact, TEXT_FIX_DEF) +
              getAttribute(&mEnvironment, TEXT_FIX_DEF);
  float percent = getAttribute(&mAttacker, TEXT_DEF) +
                  getAttribute(&mWeapon, TEXT_DEF) +
                  getAttribute(&mArtifact, TEXT_DEF) +
                  getAttribute(&mEnvironment, TEXT_DEF);
  return base * (1 + percent) + fix;
}
float calculate::calCritRate()
{
  float base = getAttribute(&mAttacker, TEXT_CRIT_RATE) +
               getAttribute(&mWeapon, TEXT_CRIT_RATE) +
               getAttribute(&mArtifact, TEXT_CRIT_RATE) +
               getAttribute(&mEnvironment, TEXT_CRIT_RATE);
  if (base > 1)
    return 1;
  else if (base > 0)
    return base;
  else
    return 0;
}
float calculate::calCritDmg()
{
  float base = getAttribute(&mAttacker, TEXT_CRIT_DMG) +
               getAttribute(&mWeapon, TEXT_CRIT_DMG) +
               getAttribute(&mArtifact, TEXT_CRIT_DMG) +
               getAttribute(&mEnvironment, TEXT_CRIT_DMG);

  if (base > 0)
    return base;
  else
    return 0;
}
float calculate::calDefFactor()
{
  return (1 - (mSuffer.info.level + 100.0f) /
                  (mAttacker.info.level + mSuffer.info.level + 200.0f));
}
float calculate::calLevelFactor()
{
  if (mAttacker.info.level < 10 || mSuffer.info.level < 10)
  {
    if ((mAttacker.info.level - mSuffer.info.level) >= 70)
    {
      return 1.5;
    }
    if ((mAttacker.info.level - mSuffer.info.level) <= -70)
    {
      return 0.5;
    }
    return 0;
  }
  else
  {
    return 1;
  }
}
float calculate::calElementalMastery()
{
  float base = getAttribute(&mAttacker, TEXT_ELEMENTAL_MASTERY) +
               getAttribute(&mWeapon, TEXT_ELEMENTAL_MASTERY) +
               getAttribute(&mArtifact, TEXT_ELEMENTAL_MASTERY) +
               getAttribute(&mEnvironment, TEXT_ELEMENTAL_MASTERY);

  if (base > 0)
    return base;
  else
    return 0;
}
float calculate::calReactFactor(eReactType reactType, float elementalMastery)
{
  float mastery = calElementalMastery();

  if (REACT_TYPE_FUSION_START < reactType &&
      reactType <
          REACT_TYPE_FUSION_END) // CHECK(reactType,REACT_TYPE_FUSION,IS_REACT)
  {
    // cout<< "REACT_TYPE_FUSION"<<endl;
    return (FUSION_K * mastery / (mastery + FUSION_A) + 1 +
            getReactFactor(&mAttacker, reactType)) *
           getReactCoefficient(reactType);
  }
  else if (
      REACT_TYPE_INCREASEMENT_START < reactType &&
      reactType <
          REACT_TYPE_INCREASEMENT_END) // CHECK(reactType,REACT_TYPE_FUSION,IS_REACT)
  {
    // cout<< "REACT_TYPE_INCREASEMENT"<<endl;
    // return (INCREASEMENT_K * mastery / (mastery + INCREASEMENT_A) + 1 +
    // getReactFactor(reactType)) * getReactCoefficient(reactType);

    return (CRYSTALLIZE_K * mastery / (mastery + CRYSTALLIZE_A) + 1 +
            getReactFactor(&mAttacker, reactType)) *
           getReactCoefficient(reactType);
  }
  else
  {
    // cout<< "qwe"<<endl;
    // return (CRYSTALLIZE_K * mastery / (mastery + CRYSTALLIZE_A) + 1 +
    // getReactFactor(reactType)) * getReactCoefficient(reactType);
    return (INCREASEMENT_K * mastery / (mastery + INCREASEMENT_A) + 1 +
            getReactFactor(&mAttacker, reactType)) *
           getReactCoefficient(reactType);
  }
}
float calculate::calResFactor(eDamageType damageType,
                              eElementType elementType)
{
  float base = getRes(&mAttacker, damageType, elementType) +
               getRes(&mWeapon, damageType, elementType) +
               getRes(&mArtifact, damageType, elementType) +
               getRes(&mEnvironment, damageType, elementType);
  if (base > 0.75) // Res>0.75
  {
    return 1 / (1 + 4 * base);
  }
  else if (base > 0) // 0.75>=Res>0
  {
    return 1 - base;
  }
  else // 0>=Res
  {
    return 1 - (base / 2);
  }
}
float calculate::calBonus(eDamageType damageType, eElementType elementType)
{
  float base = getBonus(&mAttacker, damageType, elementType) +
               getBonus(&mWeapon, damageType, elementType) +
               getBonus(&mArtifact, damageType, elementType) +
               getBonus(&mEnvironment, damageType, elementType);
  return base;
}
float calculate::calIndepMult(eDamageType damageType,
                              eElementType elementType)
{
  float base = getIndepMult(&mAttacker, damageType, elementType) +
               getIndepMult(&mWeapon, damageType, elementType) +
               getIndepMult(&mArtifact, damageType, elementType) +
               getIndepMult(&mEnvironment, damageType, elementType);
  return base;
}
float calculate::calExtraRate(eDamageType damageType,
                              eElementType elementType)
{
  float base = getExtraRate(&mAttacker, damageType, elementType) +
               getExtraRate(&mWeapon, damageType, elementType) +
               getExtraRate(&mArtifact, damageType, elementType) +
               getExtraRate(&mEnvironment, damageType, elementType);
  return base;
}

void calculate::loadAttacker()
{
    character *testCharacter = new character();

  cout<<"character::base.attrB.hpFix=="<<testCharacter->base.attrB.hpFix<<endl;
  memcpy(&mAttacker, &(testCharacter->base), sizeof(tAttribute));
}
void calculate::loadSuffer()
{
  memcpy(&mSuffer, &(enemy::base), sizeof(tAttribute));
}
void calculate::loadWeapon()
{
  memcpy(&mWeapon, &(weapon::base), sizeof(tAttribute));
}
void calculate::loadArtifact()
{
  memcpy(&mArtifact, &(artifact::base), sizeof(tAttribute));
}
void calculate::loadEnvironment()
{
  memcpy(&mEnvironment, &(environment::base), sizeof(tAttribute));
}