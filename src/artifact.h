#include "origin.h"
#ifndef ARTIFACT_H
#define ARTIFACT_H

const float ART_VALUE_MAIN_HP = 0.466f;
const float ART_VALUE_MAIN_DEF = 0.583f;
const float ART_VALUE_MAIN_ATK = 0.466f;
const float ART_VALUE_MAIN_CRIT_RATE = 0.311f;     // head			24;
const float ART_VALUE_MAIN_CRIT_DMG = 0.622f;      // head			48;
const float ART_VALUE_MAIN_ELEMENT_BONUS = 0.466f; // cup 583*0.8;
const float ART_VALUE_MAIN_PHYSIC_BONUS = 0.583f;  // cup;
const float ART_VALUE_MAIN_HP_FIX = 4780.0f;
const float ART_VALUE_MAIN_ATK_FIX = 311.0f;
const float ART_VALUE_MAIN_ELEMENTAL_MASTERY = 187.0f;
const float ART_VALUE_MAIN_RECHARGE = 0.518;

const float ART_VALUE_SUB_HP = 0.058f;
const float ART_VALUE_SUB_ATK = 0.058f;
const float ART_VALUE_SUB_DEF = 0.073f;
const float ART_VALUE_SUB_CRIT_RATE = 0.039f;
const float ART_VALUE_SUB_CRIT_DMG = 0.078f;
const float ART_VALUE_SUB_RECHARGE = 0.065;
const float ART_VALUE_SUB_HP_FIX = 299.0f;
const float ART_VALUE_SUB_ATK_FIX = 19.0f;
const float ART_VALUE_SUB_DEF_FIX = 23.0f;
const float ART_VALUE_SUB_ELEMENTAL_MASTERY = 23.0f;

#define STARTS_5_RATIO 1.0f
#define STARTS_5_MAX_SUBTEXT_NUM 9     //(4+5)
#define STARTS_5_MAX_ONE_SUBTEXT_NUM 6 //(1+5)

#define STARTS_4_RATIO 0.8f
#define STARTS_4_MAX_SUBTEXT_NUM 7     //(3+4)
#define STARTS_4_MAX_ONE_SUBTEXT_NUM 4 //(1+3)

#define MAX_LUCK_VALUE 1.0f
#define MIN_LUCK_VALUE 0.7f
typedef enum addOrSub
{
    SUB = 0,
    ADD = 1
} eAddOrSub;

namespace genShinImpact
{
    class artifact : public origin
    {
    public:
        artifact();

        void resetArtifact();
        float changeOneSubText(eAddOrSub add, eTextType text, float fortune);

        float changeFlowerOfLife(eAddOrSub add, eRarityType rarity);
        float changePlumeOfDeath(eAddOrSub add,eRarityType rarity);
        float changeSandOfEon(eAddOrSub add,eRarityType rarity, eTextType mainText);
        float changeGobletOfEonothem(eAddOrSub add,eRarityType rarity, eTextType mainText);
        float changeCircletOfLogos(eAddOrSub add,eRarityType rarity, eTextType mainText);

    protected:
        tAllAttr base;

        float calRarityFactor(eRarityType rarity);
        float posOrNeg(eAddOrSub add);
    private:
    };
}

#endif
