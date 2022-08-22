#include "origin.h"
#ifndef LOGGER_H
#define LOGGER_H
namespace genShinImpact
{
    class logger
    {
    public:
        logger();
        ~logger();

        int logType(int kind, int type);
        int logValue(tAllAttr *obj, int kind, int type);

    protected:
        // int logArtifactType(eArtifactType type);
        // int logElementType(eElementType type);
        // int logDamageType(eDamageType type);
        // int logReactType(eReactType type);
        // int logTextType(eTextType type);

        // int logElementValue(tAllAttr *obj, eElementType value);
        // int logDamageValue(tAllAttr *obj, eDamageType value);
        // int logReactValue(tAllAttr *obj, eReactType value);
        // int logTextValue(tAllAttr *obj, eTextType value);

        int logAttribute(tAllAttr *obj, int type);
        int logAttributeFix(tAllAttr *obj, int type);
        int logRes(tAllAttr *obj, int damageType, int elementType);
        int logBonus(tAllAttr *obj, int type);
        int logIndepMult(tAllAttr *obj, int type);
        int logExtraRate(tAllAttr *obj, int type);
        int logReactFactor(tAllAttr *obj, int type);
        int logBuff(tAllAttr *obj, int type);

        int logInfo(tAllAttr *obj, int type);   // tInfo info;
        int logAttack(tAllAttr *obj, int type); // tAttack attack;
        int logBurst(tAllAttr *obj, int type);  // tBurst burst;
        int logSkill(tAllAttr *obj, int type);  // tSkill skill;
        
        		void printAllAttribute(void);

    private:
    };
}

#endif
