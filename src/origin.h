#ifndef ORIGIN_H
#define ORIGIN_H
#include <cstring>
#include <iostream>
#include <unistd.h>
using namespace std;

#define _DEBUG_

#ifdef _DEBUG_
#include <stdio.h>
#define DEBUG_LOG printf
#else
#define debug_log //
#endif

#define LOAD_STRUCT(destStruct, srcStruct, structType, ContentType)           \
  for (int i = 0; i < sizeof(structType) / sizeof(ContentType); i++)          \
  {                                                                           \
    *((ContentType *)&(destStruct) + i) = *((ContentType *)&(srcStruct) + i); \
  }

#define ADD_STRUCT(destStruct, srcStruct, structType, ContentType)             \
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
  typedef enum teamMember
  {
    TEAM_MEMBER_1 = 0,
    TEAM_MEMBER_2,
    TEAM_MEMBER_3,
    TEAM_MEMBER_4
  } eTeamMember;

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
    RARITY_STAR_1,
    RARITY_STAR_2,
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
    ELEMENT_PYRO,
    ELEMENT_HYDRO,
    ELEMENT_ELECTRO,
    ELEMENT_CRYO,
    ELEMENT_DENDRO,
    ELEMENT_ANEMO,
    ELEMENT_GEO,
    ELEMENT_PHYSICS,
    ELEMENT_STRONG
  } eElementType;

  typedef enum damageType
  {
    DAMAGE_UNSURE = 0,
    DAMAGE_ATTACK,
    DAMAGE_CHARGE_ATTACK,
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
   * @param AttackDmg[level][segment]
   */
  typedef struct attackDmg
  {
    char name[32];
    eElementType element;
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
    char name[32];
    eElementType element;
    float cooldown[15];
    float rate[15][16];
  } tSkill;
  /**
   * A struct use to define character elemental burst info
   * @param rate[level][segmentRate]
   */
  typedef struct burst
  {
    char name[32];
    eElementType element;
    float energy;
    float cooldown[15];
    float rate[15][16];
  } tBurst;
  /**
   * A struct use to define basic attribute that used commonly
   */
  typedef struct basicAttribute
  {
    float atk;
    float def;
    float hp;
    float critRate;
    float critDmg;
    float elementalMastery;
    float recharge;
    // float stamina;
  } tAttribute;
  /**
   * A struct use to define extra Fixed value bonus, which come from artifact all
   * skill/burst now there are only atk hp def have fix value
   */
  typedef struct attributeFixAdd
  {
    float atkFix;
    float defFix;
    float hpFix;
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
    float defIgnor;
    float cdReduce;
    float normalAtkSpeed;
    float staminaReduce;
    float moveSpeed;

  } tBuff;

  /**
   * A struct use to define all kinds of bonus/resistance E.g.
   * element/physics/skill/burst/Attack All the value should Addition and
   * subtraction operations
   */
  typedef struct BonusResistanceIndependentRate
  {
    float pyro;
    float hydro;
    float electro;
    float cryo;
    float dendro;
    float anemo;
    float geo;
    float physical;
    float attack;
    float chargeAttack;
    float plunge;
    float skill;
    float burst;
  } tBonus, tRes, tIndepMult, tExtraRate;
  ;
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
    float crushingice;
    float electroCharged;
    float overloaded;
    float burning;
    float bloom;
    float burgeon;
    float hyperbloom;
    float spread;
    float aggravate;
    float crystallize;
    // float frozen;
  } tReactFactor;

  typedef struct infomation
  {
    char name[32];
    eRarityType rarity;
    int level;
    eElementType element;
    eWeaponType weapon;
    eTextType breakthroughText;
    // eArtifactKind artifact;
  } tInfo;
  typedef struct allAttribute
  {
    tInfo info;
    tAttributeFix attrB;
    tAttributeFix attrF;
    tAttribute attr;
    tRes res;
    tBonus bonus;
    tReactFactor reactFactor;
    tBuff buff;
    tAttack attack;
    tSkill skill;
    tBurst burst;
    tIndepMult indepMult;
    tExtraRate extraRate;
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
    static float changeAttribute(tAllAttr *obj, eTextType type, float value);

    static float logText(tAllAttr *obj, eTextType type);

  protected:
  private:
  };

} // namespace genShinImpact
#endif
