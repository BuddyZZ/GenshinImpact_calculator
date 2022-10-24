#include "weapon.h"
#include "origin.h"
using namespace genShinImpact;
using namespace std;
weapon::weapon()
{
	char tempName[] = "Default Weapon";
	memcpy(base.info.name, tempName, sizeof(tempName));
	base.attrB.atkFix = 568;
	base.attr.critDmg = 0.886;
	base.attr.hp = 0.2;
	base.bonus.hydro = 0.2;
}
weapon::~weapon()
{
}