#include "origin.h"
#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

namespace genShinImpact
{
    typedef enum environmentList
    {
        BAN_NI_TER,
        SHEN_HE,
        YUN_JIN,
        WAN_YE,
        ZHONG_LI,

        ENVIRONMENT_DOUBLE_PYRO,
        ENVIRONMENT_DOUBLE_HYDRO,
        ENVIRONMENT_DOUBLE_ELECTRO,
        ENVIRONMENT_DOUBLE_CRYO,
        ENVIRONMENT_DOUBLE_DENDRO,
        ENVIRONMENT_DOUBLE_ANEMO,
        ENVIRONMENT_DOUBLE_GEO,
    } eEnvironmentList;
    typedef struct environmentBuff
    {
        eEnvironmentList type;
        int level;
        float mainAttrValue;
    } tEnvironmentBuff;

    class environment : public virtual origin
    {
    public:
        environment();
        environment(tEnvironmentBuff *environmentBuffList);

    protected:
        tAllAttr base;
        void loadTeamEffect(eEnvironmentList type);
        void loadSkillEffect(eEnvironmentList type, int level, float mainAttrValue);

    private:
    };
}

#endif
