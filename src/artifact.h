#include "origin.h"
#ifndef ARTIFACT_H
#define ARTIFACT_H

namespace genShinImpact
{
    class artifact:public virtual origin
    {
    public:
        tAllAttr base;
        artifact();
        ~artifact();
        float changeOneText(bool isInc, eTextType text,float fortune);


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