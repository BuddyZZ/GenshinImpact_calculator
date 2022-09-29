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
    };
}

#endif
