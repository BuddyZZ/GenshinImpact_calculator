#ifndef ORIGIN_H
#define ORIGIN_H
#include <cstring>
#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

#define _DEBUG_

#ifdef _DEBUG_
#include <stdio.h>
#define DEBUG_LOG printf
#else
#define debug_log //
#endif

#define LOAD_STRUCT(destStruct, srcStruct, structType, ContentType)            \
  for (int i = 0; i < sizeof(structType) / sizeof(ContentType); i++)           \
  {                                                                            \
    *((ContentType *)&(destStruct) + i) += *((ContentType *)&(srcStruct) + i); \
  }
#define INIT_STRUCT(destStruct, structType, ContentType, initValue)  \
  for (int i = 0; i < sizeof(structType) / sizeof(ContentType); i++) \
  {                                                                  \
    *((ContentType *)&(destStruct) + i) = initValue;                 \
  }

namespace genShinImpact
{
  typedef enum calculateType
  {
    CAL_MAX = 0,
    CAL_EXPECTANCE,
    CAL_MIN
  } eCalType;
  typedef enum findExtreme
  {
    EXTREME_GREED = 0,
    EXTREME_BARREL
  } eFindExtreme;

  const int LEVEL_MAX = 90;
  const int LEVEL_MAX_TALENT = 15;
  const int LEVEL_MAX_ARTIFACT = 20;

#define REACT_COEFFICIENT_BURNING 0.5f
#define REACT_COEFFICIENT_SUPERCONDUCT 1.0f
#define REACT_COEFFICIENT_SWIRL 1.2f
#define REACT_COEFFICIENT_ELECTRO_CHARGED 2.4f
#define REACT_COEFFICIENT_CRUSHINGICE 3.0f
#define REACT_COEFFICIENT_OVERLOADED 4.0f
#define REACT_COEFFICIENT_BLOOM 4.0f
#define REACT_COEFFICIENT_BURGEON 6.0f
#define REACT_COEFFICIENT_HYPERBLOOM 6.0f
#define REACT_COEFFICIENT_SPREAD 2.5f    // 2*1.25f
#define REACT_COEFFICIENT_AGGRAVATE 2.3f // 2*1.15f
#define REACT_COEFFICIENT_VAPORIZE_A 2.0f
#define REACT_COEFFICIENT_VAPORIZE_B 1.5f
#define REACT_COEFFICIENT_MELT_A 2.0f
#define REACT_COEFFICIENT_MELT_B 1.5f
#define REACT_COEFFICIENT_CRYSTALLIZE 3.0f

#define INCREASEMENT_K (25.0f / 9.0f)
#define INCREASEMENT_A 1400.0f
#define FUSION_K 16.0f   // 20/3
#define FUSION_A 2000.0f // 1400
#define CATALYZE_K 5.0f
#define CATALYZE_A 1200.0f
#define CRYSTALLIZE_K (40.0f / 9.0f)
#define CRYSTALLIZE_A 1400.0f

#define factor(K, A, EM, F, C) (((K) * (EM) / ((EM) + (A)) + 1 + (F)) * (C))

#define ART_VALUE_MAIN_HP 0.466f            // all			36
#define ART_VALUE_MAIN_DEF 0.583f           // all			45
#define ART_VALUE_MAIN_ATK 0.466f           // all
#define ART_VALUE_MAIN_CRIT_RATE 0.311f     // head			24
#define ART_VALUE_MAIN_CRIT_DMG 0.622f      // head			48
#define ART_VALUE_MAIN_ELEMENT_BONUS 0.466f // cup 583*0.8
#define ART_VALUE_MAIN_PHYSIC_BONUS 0.583f  // cup
#define ART_VALUE_MAIN_FIX_HP 4780.0f
#define ART_VALUE_MAIN_FIX_ATK 311.0f
#define ART_VALUE_MAIN_ELEMENTAL_MASTERY 187.0f
#define ART_VALUE_MAIN_RECHARGE 0.518 // 40
#define ART_VALUE_SUB_HP 0.058f
#define ART_VALUE_SUB_ATK 0.058f
#define ART_VALUE_SUB_DEF 0.073f
#define ART_VALUE_SUB_CRIT_RATE 0.039f
#define ART_VALUE_SUB_CRIT_DMG 0.078f
#define ART_VALUE_SUB_RECHARGE 0.065
#define ART_VALUE_SUB_FIX_HP 299.0f
#define ART_VALUE_SUB_FIX_ATK 19.0f
#define ART_VALUE_SUB_FIX_DEF 23.0f
#define ART_VALUE_SUB_ELEMENTAL_MASTERY 23.0f

#define STARTS_5_RATIO 1.0f
#define STARTS_5_MAX_SUBTEXT_NUM 9     //(4+5)
#define STARTS_5_MAX_ONE_SUBTEXT_NUM 6 //(1+5)

#define STARTS_4_RATIO 0.8f
#define STARTS_4_MAX_SUBTEXT_NUM 7     //(3+4)
#define STARTS_4_MAX_ONE_SUBTEXT_NUM 4 //(1+3)

#define MAX_LUCK_VALUE 1.0f
#define MIN_LUCK_VALUE 0.7f
  typedef enum kind
  {
    KIND_RARITY = 0,
    KIND_WEAPON,
    KIND_ARTIFACT,
    KIND_BUFF,
    KIND_ELEMENT,
    KIND_DAMAGE,
    KIND_REACT,
    KIND_TEXT,
    KIND_SKILL,
    KIND_BURST,
    KIND_ATTACK
  } eKind;

  typedef enum rarity
  {
    RARITY_UNSURE = 0,
    RARITY_STAR_3,
    RARITY_STAR_4,
    RARITY_STAR_5
  } eRarityType;

  typedef enum weaponType
  {
    WEAPON_UNSURE = 0,
    WEAPON_SWORD,
    WEAPON_BOW,
    WEAPON_POLEARM,  // lance
    WEAPON_CATALYST, // magic
    WEAPON_CLAYMORE  // heavy sword
  } eWeaponType;

  typedef enum artifactType
  {
    ARTIFACT_UNSURE = 0,
    ARTIFACT_FLOWER_OF_LIFE,
    ARTIFACT_PLUME_OF_DEATH,
    ARTIFACT_SANDS_OF_EON,
    ARTIFACT_GOBLET_OF_EONOTHEM,
    ARTIFACT_CIRCLET_OF_LOGOS
  } eArtifactType;

  typedef enum buff
  {
    BUFF_UNSURE = 0,
    BUFF_HEALING_BONUS,
    BUFF_INCOMING_HELTHING_BONUS,
    BUFF_SHELD_STRENGTH,
    BUFF_CD_REDUCE,
    BUFF_MOVE_SPEED,
    BUFF_NORMAL_ATK_SPEED,
    BUFF_STAMINA_REDUCE,
    BUFF_DEF_IGNOR,
  } eBuffType;
  typedef enum info
  {
    INFO_UNSURE = 0,
    INFO_NAME,
    INFO_WEAPON,
    INFO_LEVEL,
    INFO_RARITY,
    INFO_ELEMENT,
  } eInfoType;

  typedef enum elementType
  {
    ELEMENT_UNSURE = 0,
    ELEMENT_CRYO,
    ELEMENT_PYRO,
    ELEMENT_HYDRO,
    ELEMENT_DENDRO,
    ELEMENT_ELECTRO,
    ELEMENT_ANEMO,
    ELEMENT_GEO,
    ELEMENT_PHYSICS,
    ELEMENT_STRONG
  } eElementType;

  typedef enum damageType
  {
    DAMAGE_UNSURE = 0,
    DAMAGE_HIT,
    DAMAGE_CHARGE_HIT,
    DAMAGE_PLUNGE,
    DAMAGE_SKILL,
    DAMAGE_BURST,
  } eDamageType;

  typedef enum reactType
  {
    REACT_UNSURE = 0,

    REACT_TYPE_INCREASEMENT_START,
    REACT_VAPORIZE_A,
    REACT_VAPORIZE_B,
    REACT_MELT_A,
    REACT_MELT_B,
    REACT_TYPE_INCREASEMENT_END,

    REACT_TYPE_FUSION_START,
    REACT_SWIRL,
    REACT_SUPERCONDUCT,
    REACT_CRUSHINGICE,
    REACT_BURNING,
    REACT_BLOOM,
    REACT_BURGEON,
    REACT_HYPERBLOOM,
    REACT_ELECTRO_CHARGED,
    REACT_OVERLOADED,
    REACT_CRYSTALLIZE,
    REACT_TYPE_FUSION_END,

    REACT_CATALYZE_START,
    REACT_SPREAD,
    REACT_AGGRAVATE,
    REACT_CATALYZE_END,

  } eReactType;

  typedef enum TextType
  {
    TEXT_UNSURE = 0,
    TEXT_HP,
    TEXT_ATK,
    TEXT_DEF,
    TEXT_CRIT_RATE,
    TEXT_CRIT_DMG,
    TEXT_ELEMENTAL_MASTERY,
    TEXT_RECHARGE,
    TEXT_ELEMENT_BONUS,
    TEXT_ELEMENT_BONUS_PYRO,
    TEXT_ELEMENT_BONUS_HYDRO,
    TEXT_ELEMENT_BONUS_DENDRO,
    TEXT_ELEMENT_BONUS_ELECTRO,
    TEXT_ELEMENT_BONUS_ANEMO,
    TEXT_ELEMENT_BONUS_CRYO,
    TEXT_ELEMENT_BONUS_GEO,
    TEXT_ELEMENT_BONUS_PHYSICS,
    TEXT_FIX_HP,
    TEXT_FIX_ATK,
    TEXT_FIX_DEF,
    TEXT_BASE_HP,
    TEXT_BASE_ATK,
    TEXT_BASE_DEF,
  } eTextType;

  /**
   * A struct use to define all kinds of normal attack type
   * @param NormalAttackDmg[level][segment]
   */
  typedef struct normalAttackDmg
  {
    float NormalAttackDmg[15][16];
    float chargeAttackDmg[15][16];
    float chargeAttackStaminaCost[15];
    float plungeDmg[15];
    float lowPlungeDmg[15];
    float highPlungeDmg[15];
  } tAttack;
  /**
   * A struct use to define character skill info
   * @param rate[level][segmentRate]
   */
  typedef struct skill
  {
    string name;
    int element;
    float rate[15][16];
    float cooldown[15];
  } tSkill;
  /**
   * A struct use to define character elemental burst info
   * @param rate[level][segmentRate]
   */
  typedef struct burst
  {
    string name;
    int element;
    float energy;
    float rate[15][16];
    float cooldown[15];
  } tBurst;
  /**
   * A struct use to define basic attribute that used commonly
   */
  typedef struct basicAttribute
  {
    float hp;
    float atk;
    float def;
    float elementalMastery;
    float critRate;
    float critDmg;
    float rechage;
    // float stamina;
  } tAttribute;
  /**
   * A struct use to define extra Fixed value bonus, which come from artifact all
   * skill/burst now there are only atk hp def have fix value
   */
  typedef struct attributeFixAdd
  {
    float hpFix;
    float atkFix;
    float defFix;
  } tAttributeFix;
  /**
   * A struct use to define some character attribute seldom use or can not be seen
   * in attribute page
   */
  typedef struct buffOrDebuff
  {
    float healingBonus;
    float incomingHelthingBonus;
    float sheldStrength;
    float cdReduce;
    float moveSpeed;
    float normalAtkSpeed;
    float staminaReduce;
    float defIgnor;
  } tBuff;

  /**
   * A struct use to define all kinds of bonus/resistance E.g.
   * element/physics/skill/burst/Attack All the value should Addition and
   * subtraction operations
   */
  typedef struct BonusAndResistance
  {
    float pyro;
    float hydro;
    float dendro;
    float electro;
    float anemo;
    float cryo;
    float geo;
    float physical;
    float hit;
    float chargeHit;
    float plunge;
    float burst;
    float skill;
  } tBonus, tRes;
  /**
   * A struct use to define all kinds of elemental react bonus factor
   * Now it can be get from artifact 4-set only
   * @param vaporize_a a react end with _a/_b is stands for high/low react factor
   */
  typedef struct reactFactorBonus
  {
    float vaporize_a;
    float vaporize_b;
    float melt_a;
    float melt_b;
    float swirl;
    float superconduct;
    float electroCharged;
    float overloaded;
    float crushingice;
    float burning;
    float bloom;
    float burgeon;
    float hyperbloom;
    float spread;
    float aggravate;

    float crystallize;
    // float frozen;
  } tReactFactor;

  typedef struct independentRate
  {
    float burst;
    float skill;
    float hit;
    float chargeHit;
    float plunge;
    float cryo;
    float pyro;
    float hydro;
    float dendro;
    float electro;
    float anemo;
    float geo;
    float physical;
  } tIndepMult, tExtraRate;

  typedef struct infomation
  {
    int level;
    string name;
    eRarityType rarity;
    eElementType element;
    eWeaponType weapon;
    // eArtifactKind artifact;
  } tInfo;
  typedef struct allAttribute
  {
    tAttribute attr;
    tAttributeFix attrF;
    tAttributeFix attrB;
    tRes res;
    tBonus bonus;
    tIndepMult indepMult;
    tExtraRate extraRate;
    tReactFactor reactFactor;
    tBuff buff;
    tInfo info;
    tAttack attack;
    tSkill skill;
    tBurst burst;
  } tAllAttr;
  class origin
  {
  public:
    origin();
    ~origin();
    tAllAttr base;

    static float *getAttributeAddr(tAllAttr *obj, eTextType type);
    static float *getBuffAddr(tAllAttr *obj, eBuffType type);
    static void *getInfoAddr(tAllAttr *obj, eInfoType type);
    static float *getReactFactorAddr(tAllAttr *obj, eReactType type);

    static float *getIndepMultAddr(tAllAttr *obj, eKind kind, int type);
    static float *getExtraRateAddr(tAllAttr *obj, eKind kind, int type);
    static float *getResAddr(tAllAttr *obj, eKind kind, int type);
    static float *getBonusAddr(tAllAttr *obj, eKind kind, int type);

    static float *getRateAddr(tAllAttr *obj, eKind kind, int level, int segment);

    static float getReactCoefficient(eReactType type);

  protected:
  private:
  };

} // namespace genShinImpact
#endif
