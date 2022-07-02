#ifndef CHARACTER_H
#define CHARACTER_H
#include "para.h"
#include "weapon.h"
#include "artifact.h"



namespace genShinImpact
{
	class character
	{
	public:
		character();
		character(const tCharacter temp);

		tCharacter mCharacter;

		void resetCharacter(void);
		bool loadWeapon(const tWeapon *tempWeapon);
		bool loadArtifactMainText(const tArtifact *tempArtifact);
		bool loadArtifactSubText(const tArtifact *tempArtifact);
		// bool loadArtifactEffect(const tArtifact *tempArtifact, int set);
		bool loadTeamEffect(int type);

		void printAllAttribute(void);
		
		// not implement---------------------------------------------------------
		bool loadBreakThroughAttr(int level);

	protected:
		tAttributeFix mAttributeFix;
		bool weaponLoaded;
		bool artifactMainTextLoaded;
		bool artifactSubTextLoaded;
		bool artifactEffectLoaded;
		bool teamEffectLoaded;

	private:
	};

}
#endif