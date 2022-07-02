#ifndef ARTIFACT_H
#define ARTIFACT_H

#include "para.h"
#define ART_VALUE_MAIN_HP 0.466f			// all			36
#define ART_VALUE_MAIN_DEF 0.583f			// all			45
#define ART_VALUE_MAIN_ATK 0.466f			// all
#define ART_VALUE_MAIN_CRIT_RATE 0.311f		// head			24
#define ART_VALUE_MAIN_CRIT_DMG 0.622f		// head			48
#define ART_VALUE_MAIN_ELEMENT_BONUS 0.466f // cup 583*0.8
#define ART_VALUE_MAIN_PHYSIC_BONUS 0.583f	// cup
#define ART_VALUE_MAIN_FIX_HP 4780.0f
#define ART_VALUE_MAIN_FIX_ATK 311.0f
#define ART_VALUE_MAIN_ELEMENTAL_MASTERY 187.0f //					14440
#define ART_VALUE_MAIN_RECHARGE 0.518			//					40
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
#define STARTS_5_MAX_SUBTEXT_NUM 9	   //(4+5)
#define STARTS_5_MAX_ONE_SUBTEXT_NUM 6 //(1+5)

#define STARTS_4_RATIO 0.8f
#define STARTS_4_MAX_SUBTEXT_NUM 7	   //(3+4)
#define STARTS_4_MAX_ONE_SUBTEXT_NUM 4 //(1+3)

#define MAX_LUCK_VALUE 1.0f
#define MIN_LUCK_VALUE 0.7f
namespace genShinImpact
{
	class artifact
	{
	public:
		artifact(int mainSand, int mainGoblet, int mainCirclet, int rarity);
		artifact(tArtifact paraArtifact);
		artifact();
		// s8 loadOneArt(u8 position, u8 mainText, u8 start);
		// s8 loadOneSubText(u8 position, u8 start, u16 typs, u16 times);
		tArtifact mArtifact;
		bool checkMainText();

	protected:
		bool checkSubtext(tOneArtifact paraOneArtifact);
		float getTextValue(int text, float luck, float levelFactor);
		void loadTextValue(int text, float luck, float levelFactor);
		float mainTextLevelFactor(int level);
		// s8 checkOneSubText(u8 start, u16 typs, u16 times);
		// s8 checkOneMainText(u8 position, u8 mainText);

		// float calArtAtk(float extra_fix, float add_main, s8 time_fix, s8 time_percent);
		// float calArtDef(float extra_fix, float add_main, s8 time_fix, s8 time_percent);
		// float calArtHp(float extra_fix, float add_main, s8 time_fix, s8 time_percent);
		// float calArtCritRate(float add_main, s8 time_percent);
		// float calArtCritDmg(float add_main, s8 time_percent);
		// float calElementalMaster(float add_main, s8 time_percent);
		// float calArtReCharge(float add_main, s8 time_percent);

	private:
	};

}
#endif