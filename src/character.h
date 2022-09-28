#include "origin.h"
#ifndef CHARACTER_H
#define CHARACTER_H

namespace genShinImpact
{
    class character : public virtual origin
    {
    public:
        character();
        // ~character();

    protected:
        tAllAttr base;

    private:
    };
}

#endif
