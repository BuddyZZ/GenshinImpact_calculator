#include "enemy.h"
using namespace genShinImpact;
using namespace std;
enemy::enemy()
{

    INIT_STRUCT(base.res, tRes, float, 0.1);
    base.info.level = 90;
    base.info.name = "Default Enemy";
    base.info.rarity = RARITY_UNSURE;
}
enemy::~enemy()
{
    memset(&base, '0', sizeof(tAllAttr));
}
