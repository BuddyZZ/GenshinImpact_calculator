#include "enemy.h"
using namespace genShinImpact;
using namespace std;
tAllAttr enemyArr[2] = {
    {
        {
            .name = "test-enemy-1",
            .rarity = RARITY_STAR_1,
            .level = 90,
            .element = ELEMENT_ANEMO,
            .weapon = WEAPON_BOW,
        },  /*info*/
        {}, /*attrB*/
        {}, /*attrF*/
        {}, /*attr*/
        {
            .pyro = 0.1,
            .hydro = 0.1,
            .electro = 0.1,
            .cryo = 0.1,
            .dendro = 0.1,
            .anemo = 0.1,
            .geo = 0.1,
            .physical = 0.1,
            .attack = 0,
            .chargeAttack = 0,
            .plunge = 0,
            .skill = 0,
            .burst = 0,
        }, /*res*/
    },
    {
        {
            .name = "test-enemy-2",
            .rarity = RARITY_STAR_1,
            .level = 90,
            .element = ELEMENT_ANEMO,
            .weapon = WEAPON_BOW,
        },  /*info*/
        {}, /*attrB*/
        {}, /*attrF*/
        {}, /*attr*/
        {
            .pyro = 0.1,
            .hydro = 0.1,
            .electro = 0.1,
            .cryo = 0.1,
            .dendro = 0.1,
            .anemo = 0.1,
            .geo = 0.1,
            .physical = 0.1,
            .attack = 0,
            .chargeAttack = 0,
            .plunge = 0,
            .skill = 0,
            .burst = 0,
        }, /*res*/
    },
};
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