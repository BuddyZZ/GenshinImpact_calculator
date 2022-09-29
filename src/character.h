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
