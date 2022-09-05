#include "enemy.h"
using namespace genShinImpact;
using namespace std;
enemy::enemy()
{

    INIT_STRUCT(base.res, tRes, float, 0.1);
    base.res.hit=0;
    base.res.burst=0;
    base.res.chargeHit=0;
    base.res.plunge=0;
    base.res.skill=0;
    
    base.info.level = 90;
    base.info.name = "Default Enemy";
    base.info.rarity = RARITY_UNSURE;
}
enemy::~enemy()
{
    memset(&base, '0', sizeof(tAllAttr));
}
