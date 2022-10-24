#include "character.h"
using namespace genShinImpact;
using namespace std;
character::character()
{
    base.info.level = 90;
    char tempName[] = "Default Character";
	memcpy(base.info.name, tempName, sizeof(tempName));
    base.attrB.hpFix = 15000;
    base.attrB.atkFix = 350;
    base.attrB.defFix = 650;

    base.attr.critRate = 0.05 + 0.184;

    base.attr.hp = 0.4;
}
// character::~character()
// {
// }