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
const float ART_VALUE_MAIN_FIX_HP = 4780.0f;
const float ART_VALUE_MAIN_FIX_ATK = 311.0f;
const float ART_VALUE_MAIN_ELEMENTAL_MASTERY = 187.0f;
const float ART_VALUE_MAIN_RECHARGE = 0.518;
const float ART_VALUE_SUB_HP = 0.058f;
const float ART_VALUE_SUB_ATK = 0.058f;
const float ART_VALUE_SUB_DEF = 0.073f;
const float ART_VALUE_SUB_CRIT_RATE = 0.039f;
const float ART_VALUE_SUB_CRIT_DMG = 0.078f;
const float ART_VALUE_SUB_RECHARGE = 0.065;
const float ART_VALUE_SUB_FIX_HP = 299.0f;
const float ART_VALUE_SUB_FIX_ATK = 19.0f;
const float ART_VALUE_SUB_FIX_DEF = 23.0f;
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
    SUB=0,
    ADD=1
}eAddOrSub;

namespace genShinImpact
{
    class artifact : public origin
    {
    public:
        tAllAttr base;
        artifact();
        ~artifact();
        float changeOneText(eAddOrSub add, eTextType text, float fortune);

    protected:
    private:
    };
}

#endif

// /**
//  * A struct use to define one piece of artifact
//  * This should only use in class artifact and it only a number of /artifactAttribute/
//  * @param subtext type of Corresponding subtext
//  * @param totalFortune value of Corresponding subtext should be a float like 3.4=1.0+0.9+0.8+0.7
//  */
// typedef struct onePieceArtifact
// {
// 	int level;
// 	int rare;
// 	string name;
// 	int position;
// 	int maintext;
// 	int subtext[4];
// 	float totalFortune[4]; // 10 9 8 7
// } tOneArtifact;
// /**
//  * A struct use to define whole artifact set such as set_2/set_4
//  * This struct can be use to transfer data between object to simplize operate steps
//  * @param setRes  	[0]is set_2 effect [1]is set_4 effect.
//  * 					If there is a Probabilistic trigger event, the content will be the expectation
//  * 					If there are 2 set_2 the [0]and[1] stand for 2 different set_2 effect
//  * following are same with /setRes/
//  */
// typedef struct artifactAttribute
// {
// 	int level;
// 	int rare;
// 	string name;
// 	tOneArtifact pieces[5];
// 	// u8 artifactType;
// 	tAttribute mainText;
// 	tAttributeFix mainTextFix;
// 	tBonus mainBonus;
// 	tAttribute subText;
// 	tAttributeFix subTextFix;

// 	tRes setRes[2];
// 	tBuff setBuff[2];
// 	tBonus setBonus[2];
// 	tReactFactor setReactFactor[2];
// 	tAttribute setAttribute[2];
// 	tAttributeFix setAttributeFix[2];
// } tArtifact, *pArtifact;