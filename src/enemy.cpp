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
    base.info.name = "Default Enemy";
    base.info.rarity = RARITY_UNSURE;
}
enemy::enemy(eEnemyList enemyNum, int level)
{
    LOAD_STRUCT(base.res, enemyArr[enemyNum].res, tRes, float);
    base.info.level = level;
    base.info.element = enemyArr[enemyNum].info.element;
    base.info.name = enemyArr[enemyNum].info.name;
    base.info.rarity = enemyArr[enemyNum].info.rarity;
    base.info.weapon = enemyArr[enemyNum].info.weapon;
}