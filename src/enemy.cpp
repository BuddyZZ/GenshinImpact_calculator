#include "enemy.h"
#include "para.h"
using namespace genShinImpact;
using namespace std;
enemy::enemy()
{
    memset(&mEnemy, '\0', sizeof(tEnemy));
    mEnemy.level = 90;
    INIT_STRUCT(mEnemy.res, tRes, float, 0.1);
}

enemy::enemy(tEnemy temp)
{
}
