#include "enemy.h"
using namespace genShinImpact;
using namespace std;
enemy::enemy()
{
    INIT_STRUCT(base.res, tRes, float, 0.1);
    base.res.attack = 0;
    base.res.burst = 0;
    base.res.chargeAttack = 0;
    base.res.plunge = 0;
    base.res.skill = 0;

    base.info.level = 90;
    char tempName[] = "Default Enemy";
	memcpy(base.info.name, tempName, sizeof(tempName));
    base.info.rarity = RARITY_UNSURE;
}
