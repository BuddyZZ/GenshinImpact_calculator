#include "origin.h"
#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

namespace genShinImpact
{
    class environment:public virtual origin
    {
    public:
        tAllAttr base;
        environment();
        ~environment();
        int loadTeamEffect(elementType type);

    protected:
    private:
    };
}

#endif
