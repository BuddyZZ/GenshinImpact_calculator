#include "enemy.h"
using namespace genShinImpact;
using namespace std;
enemy::enemy()
{

    INIT_STRUCT(base.res, tRes, float, 0.1);
    base.res.hit = 0;
    base.res.burst = 0;
    base.res.chargeHit = 0;
    base.res.plunge = 0;
    base.res.skill = 0;

    base.info.level = 90;
    base.info.name = "Default Enemy";
    base.info.rarity = RARITY_UNSURE;
}

float enemy::setResistance(eKind kind, int type, float resValue)
{
    return *getResAddr(&base, kind, type) = resValue;
}

int enemy::setLevel(int level)
{
    if (0 < level && level <= LEVEL_MAX)
        return base.info.level = level;
    else
        return 0;
}
