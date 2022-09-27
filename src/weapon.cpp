#include "weapon.h"
#include "origin.h"
#include <cstring>
using namespace genShinImpact;
using namespace std;
weapon::weapon()
{
	base.info.name = "Default Weapon";
	base.attrB.atkFix = 568;
	base.attr.critDmg = 0.886;
	base.attr.hp=0.2;
	base.bonus.hydro=0.2;
}
weapon::~weapon()
{
}