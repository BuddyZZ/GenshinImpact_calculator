#include "origin.h"
#ifndef CHARACTER_H
#define CHARACTER_H

namespace genShinImpact
{
    typedef enum characterList
    {
        TEST_A,
        TEST_B
    } eCharacterList;
    typedef enum constellation
    {
        CONSTELLATION_0 = 0,
        CONSTELLATION_1,
        CONSTELLATION_2,
        CONSTELLATION_3,
        CONSTELLATION_4,
        CONSTELLATION_5,
        CONSTELLATION_6
    } eConstellation;
    class character : public virtual origin
    {
    public:
        character();
        character(eCharacterList characterNum, int level, int constellation);

    protected:
        void breakthrough(eCharacterList characterNum, int time);

    private:
    };
}

#endif
