#include "origin.h"
#ifndef CHARACTER_H
#define CHARACTER_H

namespace genShinImpact
{
    class character : public virtual origin
    {
    public:
        typedef enum characterList
        {
            TEST_A,
            TEST_B
        } eCharacterList;

        character();
        character(eCharacterList characterNum, int level, int breakthrough);

    protected:
        void breakthrough(eCharacterList characterNum, int time);

    private:
        tAllAttr characterArr[2]{
            {
                {
                    .name = "test-character-0",
                    .rarity = RARITY_STAR_5,
                    .level = 90,
                    .element = ELEMENT_ANEMO,
                    .weapon = WEAPON_BOW,
                }, /*info*/
                {
                    .atkFix = 300,
                    .defFix = 600,
                    .hpFix = 13000,
                },  /*attrB*/
                {}, /*attrF*/
                {
                    .atk = 0,
                    .def = 0,
                    .hp = 0,
                    .critRate = 0.05,
                    .critDmg = 0.5,
                    .elementalMastery = 0,
                    .recharge = 1.0,
                },  /*attr*/
                {}, /*res*/
                {
                    .pyro = 0,
                    .hydro = 0,
                    .electro = 0,
                    .cryo = 0,
                    .dendro = 0,
                    .anemo = 0,
                    .geo = 0,
                    .physical = 0,
                    .attack = 0,
                    .chargeAttack = 0,
                    .plunge = 0,
                    .skill = 0,
                    .burst = 0,
                },  /*bonus*/
                {}, /* reactFactor*/
                {}, /* buff*/
                {
                    .name = "default-attack-name",
                    .element = ELEMENT_PHYSICS,
                    {
                        {0.5, 0.4, 0.5},
                        {0.5, 0.6, 0.5},
                    }, /*NormalAttackDmg[15][16]*/
                    {
                        {0.5, 0.4, 0.5},
                        {0.5, 0.6, 0.5},
                    },            /*chargeAttackDmg[15][16]*/
                    {25, 25, 25}, /*chargeAttackStaminaCost[15]*/
                    {8, 7, 6},    /*plungeDmg[15]*/
                    {8, 7, 6},    /*lowPlungeDmg[15]*/
                    {8, 7, 6},    /*highPlungeDmg[15]*/
                },                /* attack*/
                {
                    .name = "default-skill-name",
                    .element = ELEMENT_ANEMO,
                    {8, 7, 6}, /*cooldown[15]*/
                    {
                        {0.5, 0.4, 0.5},
                        {0.5, 0.6, 0.5},
                    }, /*rate[15][16]*/
                },     /* skill*/
                {
                    .name = "default-burst-name",
                    .element = ELEMENT_ANEMO,
                    .energy = 80,
                    {8, 7, 6}, /*cooldown[15]*/
                    {
                        {0.5, 0.4, 0.5},
                        {0.5, 0.6, 0.5},
                    }, /*rate[15][16]*/
                },     /* burst*/
                {},    /* indepMult*/
                {}     /* extraRate*/
            },

        };
    };
}

#endif
