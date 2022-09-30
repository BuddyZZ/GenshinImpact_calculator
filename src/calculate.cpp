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

calculate::calculate()
{
  character();
  enemy();
  weapon();
  artifact();
  environment();
  loadAll();
}
calculate::calculate(eCharacterList characterNum, int characterLevel, int constellation,
                     eWeaponlist weaponNum, int weaponLevel, int refine,
                     eArtifactList artifactNumOne, eArtifactList artifactNumTwo, eRarityType ArtifactRarity,
                     eEnemyList enemyNum, int enemyLevel)
{
  character(characterNum, characterLevel, constellation);
  enemy(enemyNum, enemyLevel);
  weapon(weaponNum, weaponLevel, refine);
  artifact(artifactNumOne, artifactNumTwo, ArtifactRarity);
  environment();
  loadAll();
}

void calculate::loadAll()
{
  memcpy(&mAttacker, &(character::base), sizeof(tAllAttr));
  memcpy(&mSuffer, &(enemy::base), sizeof(tAllAttr));
  memcpy(&mWeapon, &(weapon::base), sizeof(tAllAttr));
  memcpy(&mArtifact, &(artifact::base), sizeof(tAllAttr));
  memcpy(&mEnvironment, &(environment::base), sizeof(tAllAttr));
}

float attrConvert(float minSrc, float src, float maxSrc, float rate, float aim, float maxAim)
{
  float value, rtval;
  value = src;

  if (minSrc > 0 && value > minSrc)
    value -= minSrc;
  else
    return 0;

  if (maxSrc > 0 && value > maxSrc)
    value = maxSrc;

  rtval = value * rate;

  if (maxAim > 0 && rtval > maxAim)
    rtval = maxAim;

  return rtval;
}

float calculate::calDamage(eCalType calType, float rate, TextType mainAttr, eDamageType damageType, eElementType elementType, eReactType reactType)
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

  if (REACT_TYPE_INCREASEMENT_START < reactType && reactType < REACT_TYPE_INCREASEMENT_END) // INCREASEMENT
  {
    return defFactor * resFactor * levelFactor * (1 + bonus) * (basicDamageFactor * rate + extraRate) * (1 + indepMult) * critFactor * reactFactor;
  }
  else if (REACT_TYPE_FUSION_START < reactType && reactType < REACT_TYPE_FUSION_END) // FUSION & BLOOM
  {
    return resFactor * levelFactor * reactFactor * fusioncalLevelFactor[mAttacker.info.level - 1];
  }
  else if (REACT_CATALYZE_START < reactType && reactType < REACT_CATALYZE_END) // CATALYZE
  {
    return defFactor * resFactor * levelFactor * (1 + bonus) * (basicDamageFactor * rate + extraRate + reactFactor * fusioncalLevelFactor[mAttacker.info.level - 1]) * (1 + indepMult) * critFactor;
  }
}

float calculate::findMaxGreed(int TextAmount, float fortune, float rate, TextType mainAttr, eDamageType damageType, eElementType elementType, eReactType reactType, float reactRatio)
{
  int time = 0;
  int textType;
  float befor = 0, after = 0;
  eTextType resultTextType = TEXT_UNSURE;
  for (time = 0; time < TextAmount; time++)
  {
    for (textType = TEXT_HP; textType <= TEXT_RECHARGE; textType++)
    {
      changeOneSubText(ADD, static_cast<eTextType>(textType), fortune);
      *getAttributeAddr(&mArtifact, static_cast<eTextType>(textType)) = *getAttributeAddr(&(artifact::base), static_cast<eTextType>(textType));
      if (reactType == REACT_UNSURE)
        after = calDamage(CAL_EXPECTANCE, rate, mainAttr, damageType, elementType, reactType);
      else
        after = reactRatio * calDamage(CAL_EXPECTANCE, rate, mainAttr, damageType, elementType, reactType) + (1 - reactRatio) * calDamage(CAL_EXPECTANCE, rate, mainAttr, damageType, elementType, REACT_UNSURE);
      changeOneSubText(SUB, static_cast<eTextType>(textType), fortune);
      *getAttributeAddr(&mArtifact, static_cast<eTextType>(textType)) = *getAttributeAddr(&(artifact::base), static_cast<eTextType>(textType));
      if (befor < after)
      {
        befor = after;
        resultTextType = static_cast<eTextType>(textType);
      }
    }
    changeOneSubText(ADD, resultTextType, fortune);
    *getAttributeAddr(&mArtifact, resultTextType) = *getAttributeAddr(&(artifact::base), resultTextType);
    // logText(&mArtifact, resultTextType);
  }

  // printf("HP==%.3f\n", calHp());
  // printf("ATK==%.3f\n", calAtk());
  // printf("DEF==%.3f\n", calDef());
  // printf("CRIT_RATE==%.3f\n", calCritRate());
  // printf("CRIT_DMG==%.3f\n", calCritDmg());
  // printf("EM==%.3f\n", calElementalMastery());
  // printf("BONUS==%.3f\n", calBonus(DAMAGE_SKILL, ELEMENT_HYDRO));

  if (reactType == REACT_UNSURE)
  {
    cout << "CAL_MAX==" << calDamage(CAL_MAX, rate, mainAttr, damageType, elementType, reactType) << endl;
    cout << "CAL_EXPECTANCE==" << calDamage(CAL_EXPECTANCE, rate, mainAttr, damageType, elementType, reactType) << endl;
    cout << "CAL_MIN==" << calDamage(CAL_MIN, rate, mainAttr, damageType, elementType, reactType) << endl;
  }
  else
  {
    cout << "CAL_MAX==" << reactRatio * calDamage(CAL_MAX, rate, mainAttr, damageType, elementType, reactType) + (1 - reactRatio) * calDamage(CAL_MAX, rate, mainAttr, damageType, elementType, REACT_UNSURE) << endl;
    cout << "CAL_EXPECTANCE==" << reactRatio * calDamage(CAL_EXPECTANCE, rate, mainAttr, damageType, elementType, reactType) + (1 - reactRatio) * calDamage(CAL_EXPECTANCE, rate, mainAttr, damageType, elementType, REACT_UNSURE) << endl;
    cout << "CAL_MIN==" << reactRatio * calDamage(CAL_MIN, rate, mainAttr, damageType, elementType, reactType) + (1 - reactRatio) * calDamage(CAL_MIN, rate, mainAttr, damageType, elementType, REACT_UNSURE) << endl;
  }
}
float calculate::chargeEffect(float energyCost, float rechargeFactor, eTeamMember teamMemberNum, float frontSameColor, float frontNonColor, float frontDiffColor,
                              float backSameColor, float backNonColor, float backDiffColor)

{
  // big == 3 small

  float base, backgroundFactor;

  switch (teamMemberNum)
  {
  case TEAM_MEMBER_1:
    backgroundFactor = 1;
    break;
  case TEAM_MEMBER_2:
    backgroundFactor = 0.8;
    break;
  case TEAM_MEMBER_3:
    backgroundFactor = 0.7;
    break;
  case TEAM_MEMBER_4:
    backgroundFactor = 0.6;
    break;
  }
  base = 3 * backSameColor + 2 * backNonColor + 1 * backDiffColor;
  base *= backgroundFactor;
  base += 3 * frontSameColor + 2 * frontNonColor + 1 * frontDiffColor;
  return base * rechargeFactor;
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

  if (REACT_TYPE_FUSION_START < reactType && reactType < REACT_TYPE_FUSION_END) // FUSION
  {
    return (FUSION_K * mastery / (mastery + FUSION_A) + 1 + *getReactFactorAddr(&mAttacker, reactType)) * getReactCoefficient(reactType);
  }
  else if (REACT_TYPE_INCREASEMENT_START < reactType && reactType < REACT_TYPE_INCREASEMENT_END) // INCREASEMENT
  {
    return (INCREASEMENT_K * mastery / (mastery + INCREASEMENT_A) + 1 + *getReactFactorAddr(&mAttacker, reactType)) * getReactCoefficient(reactType);
  }
  else if (REACT_CATALYZE_START < reactType && reactType < REACT_CATALYZE_END) // CATALYZE
  {
    return (CATALYZE_K * mastery / (mastery + CATALYZE_A) + 1 + *getReactFactorAddr(&mAttacker, reactType)) * getReactCoefficient(reactType);
  }
  else // CRYSTALLIZE
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