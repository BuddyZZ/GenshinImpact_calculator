#include "artifact.h"
#include "character.h"
#include "enemy.h"
#include "environment.h"
#include "origin.h"
#include "weapon.h"
#ifndef CALCULATE_H
#define CALCULATE_H

namespace genShinImpact
{

  class calculate : public character, enemy, environment, weapon, artifact
  {
  public:
    calculate();
    calculate(eCharacterList characterNum, int characterLevel, int constellation,
              eWeaponlist weaponNum, int weaponLevel, int refine,
              eArtifactList artifactNumOne, eArtifactList artifactNumTwo, eRarityType ArtifactRarity,
              eEnemyList enemyNum, int enemyLevel);

    tAllAttr mAttacker;
    tAllAttr mSuffer;
    tAllAttr mWeapon;
    tAllAttr mArtifact;
    tAllAttr mEnvironment;

    void loadAll();

    float calDamage(eCalType calType, float rate, TextType mainAttr, eDamageType damageType, eElementType elementType, eReactType reactType);

    float findMaxGreed(int TextAmount, float fortune, float rate, TextType mainAttr, eDamageType damageType, eElementType elementType, eReactType reactType, float reactRatio);

    float attrConvert(float minSrc, float src, float maxSrc, float rate, float aim, float maxAim);

    float chargeEffect(float energyCost, float rechargeFactor, eTeamMember teamMemberNum, float frontSameColor, float frontNonColor, float frontDiffColor,
                       float backSameColor, float backNonColor, float backDiffColor);

  protected:
    float calHp();
    float calAtk();
    float calDef();
    float calCritRate();
    float calCritDmg();
    float calElementalMastery();

    float calDefFactor();
    float calLevelFactor();
    float calMainFactor(TextType mainAttr);
    float calCritFactor(eCalType calType);
    float calReactFactor(eReactType reactType, float elementalMastery);
    float calResFactor(eDamageType damageType, eElementType elementType);
    float calBonus(eDamageType damageType, eElementType elementType);
    float calIndepMult(eDamageType damageType, eElementType elementType);
    float calExtraRate(eDamageType damageType, eElementType elementType);

  private:
    static const float INCREASEMENT_K = (25.0f / 9.0f);
    static const float INCREASEMENT_A = 1400.0f;
    static const float FUSION_K = 16.0f;
    static const float FUSION_A = 2000.0f;
    static const float CATALYZE_K = 5.0f;
    static const float CATALYZE_A = 1200.0f;
    static const float CRYSTALLIZE_K = (40.0f / 9.0f);
    static const float CRYSTALLIZE_A = 1400.0f;
  };
} // namespace genShinImpact

#endif
