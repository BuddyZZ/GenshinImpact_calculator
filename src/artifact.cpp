#include "artifact.h"
#include "para.h"

using namespace genShinImpact;
using namespace std;

artifact::artifact(int mainSand, int mainGoblet, int mainCirclet, int rarity)
{
	memset(&mArtifact, '\0', sizeof(tArtifact));

	mArtifact.pieces[0].name = "piece_0";
	mArtifact.pieces[0].level = 20;
	mArtifact.pieces[0].rare = rarity;
	mArtifact.pieces[0].position = ARTIFACT_FLOWER_OF_LIFE;
	mArtifact.pieces[0].maintext = ART_TEXT_MAIN_HP;

	mArtifact.pieces[1].name = "piece_1";
	mArtifact.pieces[1].level = 20;
	mArtifact.pieces[1].rare = rarity;
	mArtifact.pieces[1].position = ARTIFACT_PLUME_OF_DEATH;
	mArtifact.pieces[1].maintext = ART_TEXT_MAIN_ATK;

	mArtifact.pieces[2].name = "piece_2";
	mArtifact.pieces[2].level = 20;
	mArtifact.pieces[2].rare = rarity;
	mArtifact.pieces[2].position = ARTIFACT_SANDS_OF_EON;
	mArtifact.pieces[2].maintext = mainSand;

	mArtifact.pieces[3].name = "piece_3";
	mArtifact.pieces[3].level = 20;
	mArtifact.pieces[3].rare = rarity;
	mArtifact.pieces[3].position = ARTIFACT_GOBLET_OF_EONOTHEM;
	mArtifact.pieces[3].maintext = mainGoblet;

	mArtifact.pieces[4].name = "piece_4";
	mArtifact.pieces[4].level = 20;
	mArtifact.pieces[4].rare = rarity;
	mArtifact.pieces[4].position = ARTIFACT_CIRCLET_OF_LOGOS;
	mArtifact.pieces[4].maintext = mainCirclet;

	// mArtifact.pieces[0].subtext[0]=IS_ARTIFACT_TEXT;
	// mArtifact.pieces[0].totalFortune[0]=1.0;
	// mArtifact.pieces[0].subtext[1]=IS_ARTIFACT_TEXT;
	// mArtifact.pieces[0].totalFortune[0]=0.9;
	// mArtifact.pieces[0].subtext[2]=IS_ARTIFACT_TEXT;
	// mArtifact.pieces[0].totalFortune[0]=0.8;
	// mArtifact.pieces[0].subtext[3]=IS_ARTIFACT_TEXT;
	// mArtifact.pieces[0].totalFortune[0]=0.7;
	if (!checkMainText())
	{
		DEBUG_LOG("wrong checkMainText\n");
	}
}

artifact::artifact(tArtifact paraArtifact) : mArtifact(paraArtifact)
{
}
artifact::artifact()
{
}

bool artifact::checkMainText()
{
	int allHave = ART_TEXT_MAIN_HP | ART_TEXT_MAIN_ATK | ART_TEXT_MAIN_DEF | ART_TEXT_MAIN_ELEMENTAL_MASTERY;

	for (int i = 0; i < 5; i++)
	{

		switch (mArtifact.pieces[i].position)
		{
		case ARTIFACT_FLOWER_OF_LIFE:
			mArtifact.mainTextFix.hpFix += ART_VALUE_MAIN_FIX_HP; //*mArtifact.pieces[i].rare*mArtifact.pieces[i].level;
			break;
		case ARTIFACT_PLUME_OF_DEATH:
			mArtifact.mainTextFix.atkFix += ART_VALUE_MAIN_FIX_ATK; //*mArtifact.pieces[i].rare*mArtifact.pieces[i].level;
			break;
		case ARTIFACT_SANDS_OF_EON:
			// 		printf("allHave==%8X\n",allHave);
			// printf("(allHave | ART_TEXT_MAIN_RECHARGE)==%8X\n",(allHave | ART_TEXT_MAIN_RECHARGE));
			// printf("&==%8X\n",(mArtifact.pieces[i].maintext & (allHave | ART_TEXT_MAIN_RECHARGE)));
			if (CHECK(mArtifact.pieces[i].maintext, (allHave | ART_TEXT_MAIN_RECHARGE), IS_ARTIFACT_TEXT))
			{
				loadTextValue(mArtifact.pieces[i].maintext, 0, mainTextLevelFactor(20)); //*mArtifact.pieces[i].rare*mArtifact.pieces[i].level;mArtifact
			}
			else
			{
				DEBUG_LOG("wrong ARTIFACT_SANDS_OF_EON with %8X\n", mArtifact.pieces[i].maintext);
				return false;
			}
			break;
		case ARTIFACT_GOBLET_OF_EONOTHEM:
			if (CHECK(mArtifact.pieces[i].maintext, (allHave | ART_TEXT_MAIN_ELEMENT_BONUS), IS_ARTIFACT_TEXT))
			{
				loadTextValue(mArtifact.pieces[i].maintext, 0, mainTextLevelFactor(20)); //*mArtifact.pieces[i].rare*mArtifact.pieces[i].level;
			}
			else
			{
				DEBUG_LOG("wrong ARTIFACT_GOBLET_OF_EONOTHEM with %8X\n", mArtifact.pieces[i].maintext);
				return false;
			}
			break;
		case ARTIFACT_CIRCLET_OF_LOGOS:
			if (CHECK(mArtifact.pieces[i].maintext, (allHave | ART_TEXT_MAIN_CRIT_RATE | ART_TEXT_MAIN_CRIT_DMG), IS_ARTIFACT_TEXT))

			{
				loadTextValue(mArtifact.pieces[i].maintext, 0, mainTextLevelFactor(20)); //*mArtifact.pieces[i].rare*mArtifact.pieces[i].level;
			}
			else
			{
				DEBUG_LOG("wrong ARTIFACT_CIRCLET_OF_LOGOS with %8X\n", mArtifact.pieces[i].maintext);
				return false;
			}
			break;
		default:
			DEBUG_LOG("wrong mArtifact.pieces[%d].position=%8X\n", i, mArtifact.pieces[i].position);
			return false;
			break;
		}
	}
	return true;
}
float artifact::getTextValue(int text, float luck, float levelFactor)
{
	switch (text)
	{
	case ART_TEXT_SUB_FIX_HP:
		return ART_VALUE_SUB_FIX_HP * luck;
	case ART_TEXT_SUB_FIX_ATK:
		return ART_VALUE_SUB_FIX_ATK * luck;
	case ART_TEXT_SUB_FIX_DEF:
		return ART_VALUE_SUB_FIX_DEF * luck;
	case ART_TEXT_SUB_HP:
		return ART_VALUE_SUB_HP * luck;
	case ART_TEXT_SUB_ATK:
		return ART_VALUE_SUB_ATK * luck;
	case ART_TEXT_SUB_DEF:
		return ART_VALUE_SUB_DEF * luck;
	case ART_TEXT_SUB_CRIT_RATE:
		return ART_VALUE_SUB_CRIT_RATE * luck;
	case ART_TEXT_SUB_CRIT_DMG:
		return ART_VALUE_SUB_CRIT_DMG * luck;
	case ART_TEXT_SUB_RECHARGE:
		return ART_VALUE_SUB_RECHARGE * luck;
	case ART_TEXT_SUB_ELEMENTAL_MASTERY:
		return ART_VALUE_SUB_ELEMENTAL_MASTERY * luck;
	case ART_TEXT_MAIN_HP:
		return ART_VALUE_MAIN_HP * levelFactor;
	case ART_TEXT_MAIN_ATK:
		return ART_VALUE_MAIN_ATK * levelFactor;
	case ART_TEXT_MAIN_DEF:
		return ART_VALUE_MAIN_DEF * levelFactor;
	case ART_TEXT_MAIN_CRIT_RATE:
		return ART_VALUE_MAIN_CRIT_RATE * levelFactor;
	case ART_TEXT_MAIN_CRIT_DMG:
		return ART_VALUE_MAIN_CRIT_DMG * levelFactor;
	case ART_TEXT_MAIN_ELEMENTAL_MASTERY:
		return ART_VALUE_MAIN_ELEMENTAL_MASTERY * levelFactor;
	case ART_TEXT_MAIN_RECHARGE:
		return ART_VALUE_MAIN_RECHARGE * levelFactor;
	case ART_TEXT_MAIN_ELEMENT_BONUS_PYRO:
	case ART_TEXT_MAIN_ELEMENT_BONUS_HYDRO:
	case ART_TEXT_MAIN_ELEMENT_BONUS_DENDRO:
	case ART_TEXT_MAIN_ELEMENT_BONUS_ELECTRO:
	case ART_TEXT_MAIN_ELEMENT_BONUS_ANEMO:
	case ART_TEXT_MAIN_ELEMENT_BONUS_CRYO:
	case ART_TEXT_MAIN_ELEMENT_BONUS_GEO:
		return ART_VALUE_MAIN_ELEMENT_BONUS * levelFactor;
	case ART_TEXT_MAIN_ELEMENT_BONUS_PHYSICS:
		return ART_VALUE_MAIN_PHYSIC_BONUS * levelFactor;

	default:
		DEBUG_LOG("getTextValue %X\n", text);
		return 0;
	}
}
void artifact::loadTextValue(int text, float luck, float levelFactor)
{
	switch (text)
	{
	// case ART_TEXT_SUB_FIX_HP:
	// 	return ART_VALUE_SUB_FIX_HP;
	// case ART_TEXT_SUB_FIX_ATK:
	// 	return ART_VALUE_SUB_FIX_ATK;
	// case ART_TEXT_SUB_FIX_DEF:
	// 	return ART_VALUE_SUB_FIX_DEF;
	// case ART_TEXT_SUB_HP:
	// 	return ART_VALUE_SUB_HP;
	// case ART_TEXT_SUB_ATK:
	// 	return ART_VALUE_SUB_ATK;
	// case ART_TEXT_SUB_DEF:
	// 	return ART_VALUE_SUB_DEF;
	// case ART_TEXT_SUB_CRIT_RATE:
	// 	return ART_VALUE_SUB_CRIT_RATE;
	// case ART_TEXT_SUB_CRIT_DMG:
	// 	return ART_VALUE_SUB_CRIT_DMG;
	// case ART_TEXT_SUB_RECHARGE:
	// 	return ART_VALUE_SUB_RECHARGE;
	// case ART_TEXT_SUB_ELEMENTAL_MASTERY:
	// 	return ART_VALUE_SUB_ELEMENTAL_MASTERY;
	case ART_TEXT_MAIN_HP:
		mArtifact.mainText.hp += getTextValue(text, luck, levelFactor);
		break;
	case ART_TEXT_MAIN_ATK:
		mArtifact.mainText.atk += getTextValue(text, luck, levelFactor);
		break;
	case ART_TEXT_MAIN_DEF:
		mArtifact.mainText.def += getTextValue(text, luck, levelFactor);
		break;
	case ART_TEXT_MAIN_CRIT_RATE:
		mArtifact.mainText.critRate += getTextValue(text, luck, levelFactor);
		break;
	case ART_TEXT_MAIN_CRIT_DMG:
		mArtifact.mainText.critDmg += getTextValue(text, luck, levelFactor);
		break;
	case ART_TEXT_MAIN_ELEMENTAL_MASTERY:
		mArtifact.mainText.elementalMastery += getTextValue(text, luck, levelFactor);
		break;
	case ART_TEXT_MAIN_RECHARGE:
		mArtifact.mainText.rechage += getTextValue(text, luck, levelFactor);
		break;
	case ART_TEXT_MAIN_ELEMENT_BONUS_PYRO:
		mArtifact.mainBonus.pyro = getTextValue(text, luck, levelFactor);
		break;
	case ART_TEXT_MAIN_ELEMENT_BONUS_HYDRO:
		mArtifact.mainBonus.hydro = getTextValue(text, luck, levelFactor);
		break;
	case ART_TEXT_MAIN_ELEMENT_BONUS_DENDRO:
		mArtifact.mainBonus.dendro = getTextValue(text, luck, levelFactor);
		break;
	case ART_TEXT_MAIN_ELEMENT_BONUS_ELECTRO:
		mArtifact.mainBonus.electro = getTextValue(text, luck, levelFactor);
		break;
	case ART_TEXT_MAIN_ELEMENT_BONUS_ANEMO:
		mArtifact.mainBonus.anemo = getTextValue(text, luck, levelFactor);
		break;
	case ART_TEXT_MAIN_ELEMENT_BONUS_CRYO:
		mArtifact.mainBonus.cryo = getTextValue(text, luck, levelFactor);
		break;
	case ART_TEXT_MAIN_ELEMENT_BONUS_GEO:
		mArtifact.mainBonus.geo = getTextValue(text, luck, levelFactor);
		break;
	case ART_TEXT_MAIN_ELEMENT_BONUS_PHYSICS:
		mArtifact.mainBonus.physical += getTextValue(text, luck, levelFactor);
		break;
	default:
		break;
	}
}
float artifact::mainTextLevelFactor(int level)
{
	return 1;
}

// bool artifact::checkSubtext(tOneArtifact paraOneArtifact)
// {
// 	// u8 maxSubtextNum = 0;
// 	// u8 maxOneSubtextNum = 0;
// 	// u8 minSubtextNum = 0;
// 	// u8 totalSubtextType=0;
// 	// switch (paraOneArtifact.rare)
// 	// {
// 	// case STAR_5:
// 	// 	maxSubtextNum = 9;
// 	// 	maxOneSubtextNum = 6;
// 	// 	minSubtextNum = maxSubtextNum - 1;
// 	// 	break;
// 	// case STAR_4:
// 	// 	maxSubtextNum = 8;
// 	// 	maxOneSubtextNum = 5;
// 	// 	minSubtextNum = maxSubtextNum - 1;
// 	// 	break;
// 	// }

// 	// if(paraOneArtifact.subtext&ART_TEXT_SUB_HP)
// 	// {

// 	// }
// 	// else if(paraOneArtifact.subtext&ART_TEXT_SUB_HP)
// }