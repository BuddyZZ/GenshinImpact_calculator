#include "character.h"
using namespace genShinImpact;
using namespace std;
character::character()
{
    memset(&base, '0', sizeof(tAllAttr));
    base.info.level=90;
    base.attrB.hpFix = 10000;
    base.attrB.atkFix = 350;
    base.attrB.defFix = 650;
    // INIT_STRUCT(base.bonus, tBonus, float, 0.01);
}
// character::~character()
// {
// }