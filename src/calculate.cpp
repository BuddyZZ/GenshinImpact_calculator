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
void calculate::loadAll()
{
  loadAttacker();
  loadSuffer();
  loadWeapon();
  loadArtifact();
  loadEnvironment();
}

float calculate::attrChange(TextType aim, float maxAim, float rate, float minSrc, TextType src, float maxSrc)
{
  float value, rtval;
  value = *getAttributeAddr(&mAttacker, src);
  if (value > maxSrc)
    value = maxSrc;
  else if (value > minSrc)
    value -= minSrc;
  else
    value = 0;

  rtval = value * rate;

  if (rtval > maxAim)
    rtval = maxAim;

  return rtval;
}

float calculate::calDamage(float rate, eReactType reactType, TextType mainAttr, eCalType calType, eDamageType damageType, eElementType elementType)
{
  float elementalMastery = calElementalMastery();
  float critFactor = calCritFactor(calType);
  float basicDamageFactor = calMainFactor(mainAttr);
  float defFactor = calDefFactor();
  float levelFactor = calLevelFactor();
  float resFactor = calResFactor(damageType, elementType);
  float reactFactor = calReactFactor(reactType, elementalMastery);
  float bonus = calBonus(damageType, elementType);
  float indepMult = calIndepMult(damageType, elementType);
  float extraRate = calExtraRate(damageType, elementType);

  cout << "calHp()                ==" << calHp() << endl;
  cout << "calAtk()               ==" << calAtk() << endl;
  cout << "calDef()               ==" << calDef() << endl;
  cout << "calCritRate()          ==" << calCritRate() << endl;
  cout << "calCritDmg()           ==" << calCritDmg() << endl;
  cout << "calDefFactor()         ==" << defFactor << endl;
  cout << "calLevelFactor()       ==" << levelFactor << endl;
  cout << "calElementalMastery()  ==" << elementalMastery << endl;
  cout << "calReactFactor()       ==" << reactFactor << endl;
  cout << "calResFactor()         ==" << resFactor << endl;
  cout << "calBonus()             ==" << bonus << endl;
  cout << "calIndepMult()         ==" << indepMult << endl;
  cout << "calExtraRate()         ==" << extraRate << endl;

  if (REACT_TYPE_INCREASEMENT_START < reactType && reactType < REACT_TYPE_INCREASEMENT_END)
  {
    return defFactor * resFactor * levelFactor * (1 + bonus) * (basicDamageFactor * rate + extraRate) * (1 + indepMult) * critFactor * reactFactor;
  }
  else if (REACT_TYPE_FUSION_START < reactType && reactType < REACT_TYPE_FUSION_END)
  {
    return resFactor * levelFactor * reactFactor * fusioncalLevelFactor[mAttacker.info.level];
  }
  else // no react
  {
    return defFactor * resFactor * levelFactor * (1 + bonus) * (basicDamageFactor * rate + extraRate) * (1 + indepMult) * critFactor;
  }
}
float calculate::findMaxGreedSimple(int times, float fortune, eCalType calType, TextType mainAttr, eReactType reactType)
{
  int i = 0;
  float befor, after;
  for (i = 0; i < times; i++)
  {
    calMainFactor(mainAttr);
    calReactFactor(reactType, calElementalMastery());
    calCritFactor(calType);
  }
}
float calculate::findMaxGreed(int times, float fortune, float rate, eCalType calType, TextType mainAttr, eReactType reactType)
{
}

float calculate::calHp()
{
  float base = *getAttributeAddr(&mAttacker, TEXT_BASE_HP) +
               *getAttributeAddr(&mWeapon, TEXT_BASE_HP) +
               *getAttributeAddr(&mArtifact, TEXT_BASE_HP) +
               *getAttributeAddr(&mEnvironment, TEXT_BASE_HP);
  float fix = *getAttributeAddr(&mAttacker, TEXT_FIX_HP) +
              *getAttributeAddr(&mWeapon, TEXT_FIX_HP) +
              *getAttributeAddr(&mArtifact, TEXT_FIX_HP) +
              *getAttributeAddr(&mEnvironment, TEXT_FIX_HP);
  float percent = *getAttributeAddr(&mAttacker, TEXT_HP) +
                  *getAttributeAddr(&mWeapon, TEXT_HP) +
                  *getAttributeAddr(&mArtifact, TEXT_HP) +
                  *getAttributeAddr(&mEnvironment, TEXT_HP);
  return base * (1 + percent) + fix;
}
float calculate::calAtk()
{
  float base = *getAttributeAddr(&mAttacker, TEXT_BASE_ATK) +
               *getAttributeAddr(&mWeapon, TEXT_BASE_ATK) +
               *getAttributeAddr(&mArtifact, TEXT_BASE_ATK) +
               *getAttributeAddr(&mEnvironment, TEXT_BASE_ATK);
  float fix = *getAttributeAddr(&mAttacker, TEXT_FIX_ATK) +
              *getAttributeAddr(&mWeapon, TEXT_FIX_ATK) +
              *getAttributeAddr(&mArtifact, TEXT_FIX_ATK) +
              *getAttributeAddr(&mEnvironment, TEXT_FIX_ATK);
  float percent = *getAttributeAddr(&mAttacker, TEXT_ATK) +
                  *getAttributeAddr(&mWeapon, TEXT_ATK) +
                  *getAttributeAddr(&mArtifact, TEXT_ATK) +
                  *getAttributeAddr(&mEnvironment, TEXT_ATK);
  return base * (1 + percent) + fix;
}
float calculate::calDef()
{
  float base = *getAttributeAddr(&mAttacker, TEXT_BASE_DEF) +
               *getAttributeAddr(&mWeapon, TEXT_BASE_DEF) +
               *getAttributeAddr(&mArtifact, TEXT_BASE_DEF) +
               *getAttributeAddr(&mEnvironment, TEXT_BASE_DEF);
  float fix = *getAttributeAddr(&mAttacker, TEXT_FIX_DEF) +
              *getAttributeAddr(&mWeapon, TEXT_FIX_DEF) +
              *getAttributeAddr(&mArtifact, TEXT_FIX_DEF) +
              *getAttributeAddr(&mEnvironment, TEXT_FIX_DEF);
  float percent = *getAttributeAddr(&mAttacker, TEXT_DEF) +
                  *getAttributeAddr(&mWeapon, TEXT_DEF) +
                  *getAttributeAddr(&mArtifact, TEXT_DEF) +
                  *getAttributeAddr(&mEnvironment, TEXT_DEF);
  return base * (1 + percent) + fix;
}
float calculate::calCritRate()
{
  float base = *getAttributeAddr(&mAttacker, TEXT_CRIT_RATE) +
               *getAttributeAddr(&mWeapon, TEXT_CRIT_RATE) +
               *getAttributeAddr(&mArtifact, TEXT_CRIT_RATE) +
               *getAttributeAddr(&mEnvironment, TEXT_CRIT_RATE);
  if (base > 1)
    return 1;
  else if (base > 0)
    return base;
  else
    return 0;
}
float calculate::calCritDmg()
{
  float base = *getAttributeAddr(&mAttacker, TEXT_CRIT_DMG) +
               *getAttributeAddr(&mWeapon, TEXT_CRIT_DMG) +
               *getAttributeAddr(&mArtifact, TEXT_CRIT_DMG) +
               *getAttributeAddr(&mEnvironment, TEXT_CRIT_DMG);

  if (base > 0)
    return base;
  else
    return 0;
}

float calculate::calDefFactor()
{
  int attackerLevel = *static_cast<int *>(getInfoAddr(&mAttacker, INFO_LEVEL));
  int sufferLevel = *static_cast<int *>(getInfoAddr(&mSuffer, INFO_LEVEL));
  return (1 - (sufferLevel + 100.0f) / (attackerLevel + sufferLevel + 200.0f));
}

float calculate::calLevelFactor()
{
  int attackerLevel = *static_cast<int *>(getInfoAddr(&mAttacker, INFO_LEVEL));
  int sufferLevel = *static_cast<int *>(getInfoAddr(&mSuffer, INFO_LEVEL));

  if (attackerLevel < 10 || sufferLevel < 10)
  {
    if ((attackerLevel - sufferLevel) >= 70)
    {
      return 1.5;
    }
    if ((attackerLevel - sufferLevel) <= -70)
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
  float base = *getAttributeAddr(&mAttacker, TEXT_ELEMENTAL_MASTERY) +
               *getAttributeAddr(&mWeapon, TEXT_ELEMENTAL_MASTERY) +
               *getAttributeAddr(&mArtifact, TEXT_ELEMENTAL_MASTERY) +
               *getAttributeAddr(&mEnvironment, TEXT_ELEMENTAL_MASTERY);

  if (base > 0)
    return base;
  else
    return 0;
}

float calculate::calReactFactor(eReactType reactType, float elementalMastery)
{
  float mastery = calElementalMastery();

  if (REACT_TYPE_FUSION_START < reactType && reactType < REACT_TYPE_FUSION_END) // CHECK(reactType,REACT_TYPE_FUSION,IS_REACT)
  {
    // cout<< "REACT_TYPE_FUSION"<<endl;
    return (FUSION_K * mastery / (mastery + FUSION_A) + 1 + *getReactFactorAddr(&mAttacker, reactType)) * getReactCoefficient(reactType);
  }
  else if (REACT_TYPE_INCREASEMENT_START < reactType && reactType < REACT_TYPE_INCREASEMENT_END) // CHECK(reactType,REACT_TYPE_FUSION,IS_REACT)
  {
    return (INCREASEMENT_K * mastery / (mastery + INCREASEMENT_A) + 1 + *getReactFactorAddr(&mAttacker, reactType)) * getReactCoefficient(reactType);
  }
  else
  {
    return (CRYSTALLIZE_K * mastery / (mastery + CRYSTALLIZE_A) + 1 + *getReactFactorAddr(&mAttacker, reactType)) * getReactCoefficient(reactType);
  }
}
float calculate::calResFactor(eDamageType damageType, eElementType elementType)
{
  float base = *getResAddr(&mSuffer, KIND_DAMAGE, damageType) + *getResAddr(&mSuffer, KIND_ELEMENT, elementType);
  if (base > 0.75) // Res>0.75
  {
    return 1 - 1 / (1 + 4 * base);
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
  float base = *getBonusAddr(&mAttacker, KIND_DAMAGE, damageType) + *getBonusAddr(&mAttacker, KIND_ELEMENT, elementType) +
               *getBonusAddr(&mWeapon, KIND_DAMAGE, damageType) + *getBonusAddr(&mWeapon, KIND_ELEMENT, elementType) +
               *getBonusAddr(&mArtifact, KIND_DAMAGE, damageType) + *getBonusAddr(&mArtifact, KIND_ELEMENT, elementType) +
               *getBonusAddr(&mEnvironment, KIND_DAMAGE, damageType) + *getBonusAddr(&mEnvironment, KIND_ELEMENT, elementType);
  cout<<"bonus=="<<*getBonusAddr(&mAttacker, KIND_ELEMENT, elementType)<<endl;
    cout<<"bonus=="<<*getBonusAddr(&mWeapon, KIND_ELEMENT, elementType)<<endl;

  cout<<"bonus=="<<*getBonusAddr(&mArtifact, KIND_ELEMENT, elementType)<<endl;

  cout<<"bonus=="<<*getBonusAddr(&mEnvironment, KIND_ELEMENT, elementType)<<endl;

  return base;
}
float calculate::calIndepMult(eDamageType damageType, eElementType elementType)
{
  float base = *getIndepMultAddr(&mAttacker, KIND_DAMAGE, damageType) + *getIndepMultAddr(&mAttacker, KIND_ELEMENT, elementType) +
               *getIndepMultAddr(&mWeapon, KIND_DAMAGE, damageType) + *getIndepMultAddr(&mWeapon, KIND_ELEMENT, elementType) +
               *getIndepMultAddr(&mArtifact, KIND_DAMAGE, damageType) + *getIndepMultAddr(&mArtifact, KIND_ELEMENT, elementType) +
               *getIndepMultAddr(&mEnvironment, KIND_DAMAGE, damageType) + *getIndepMultAddr(&mEnvironment, KIND_ELEMENT, elementType);
  return base;
}
float calculate::calExtraRate(eDamageType damageType, eElementType elementType)
{
  float base = *getExtraRateAddr(&mAttacker, KIND_DAMAGE, damageType) + *getExtraRateAddr(&mAttacker, KIND_ELEMENT, elementType) +
               *getExtraRateAddr(&mWeapon, KIND_DAMAGE, damageType) + *getExtraRateAddr(&mWeapon, KIND_ELEMENT, elementType) +
               *getExtraRateAddr(&mArtifact, KIND_DAMAGE, damageType) + *getExtraRateAddr(&mArtifact, KIND_ELEMENT, elementType) +
               *getExtraRateAddr(&mEnvironment, KIND_DAMAGE, damageType) + *getExtraRateAddr(&mEnvironment, KIND_ELEMENT, elementType);
  return base;
}

float calculate::calMainFactor(TextType mainAttr)
{
  switch (mainAttr)
  {
  case TEXT_HP:
    return calHp();
  case TEXT_ATK:
    return calAtk();
  case TEXT_DEF:
    return calDef();
  default:
    return 0;
  }
}

float calculate::calCritFactor(eCalType calType)
{
  float critRate = calCritRate();
  float critDmg = calCritDmg();

  switch (calType)
  {
  case CAL_MAX:
    return 1 + critDmg;
  case CAL_EXPECTANCE:
    return (1 - critRate) + critRate * (1 + critDmg);
  case CAL_MIN:
    return 1;
  default:
    return 0;
  }
}

void calculate::loadAttacker()
{
  character *testCharacter = new character();
  memcpy(&mAttacker, &testCharacter->base, sizeof(tAllAttr));
  // delete testCharacter;
}
void calculate::loadSuffer()
{
  enemy *testEnemy = new enemy();
  memcpy(&mSuffer, &(testEnemy->base), sizeof(tAllAttr));
  // delete testEnemy; auto delete?
}
void calculate::loadWeapon()
{
  weapon *testWeapon = new weapon();
  memcpy(&mWeapon, &(testWeapon->base), sizeof(tAllAttr));
  // delete testWeapon;
}
void calculate::loadArtifact()
{
  artifact *testArtifact = new artifact();
  memcpy(&mArtifact, &(testArtifact->base), sizeof(tAllAttr));
  // delete testArtifact;
}
void calculate::loadEnvironment()
{
  environment *testEnvironment = new environment();
  memcpy(&mEnvironment, &(testEnvironment->base), sizeof(tAllAttr));
  // delete testEnvironment;
}