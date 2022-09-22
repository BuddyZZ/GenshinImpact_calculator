#include "character.h"
using namespace genShinImpact;
using namespace std;
character::character()
{
    base.info.level = 90;
    base.info.name = "testCharacter";
    base.attrB.hpFix = 10000;
    base.attrB.atkFix = 350;
    base.attrB.defFix = 650;
}
// character::~character()
// {
// }