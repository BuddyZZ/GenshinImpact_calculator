#include "origin.h"
#ifndef ENEMY_H
#define ENEMY_H

namespace genShinImpact
{
    typedef enum enemyList
    {
        ENEMY_A,
        ENEMY_B
    } eEnemyList;
    class enemy : public virtual origin
    {
    public:
        enemy();
        enemy(eEnemyList enemyNum, int level);

        tAllAttr base;

    protected:
    private:
    };
} // namespace genShinImpact

#endif