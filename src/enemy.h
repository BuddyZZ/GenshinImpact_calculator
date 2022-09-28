#include "origin.h"
#ifndef ENEMY_H
#define ENEMY_H

namespace genShinImpact
{
    class enemy : public virtual origin
    {
    public:
        typedef enum enemyList
        {
            TEST_A,
            TEST_B
        } eEnemyList;
        enemy();
        enemy(eEnemyList enemyNum, int level);

        tAllAttr base;

    protected:
    private:
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
    };
} // namespace genShinImpact

#endif