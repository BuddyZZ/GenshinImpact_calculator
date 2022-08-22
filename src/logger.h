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

        void logAttribute(tAllAttr *obj, int type);
        void logAttributeFix(tAllAttr *obj, int type);
        void logRes(tAllAttr *obj, int damageType, int elementType);
        void logBonus(tAllAttr *obj, int type);
        void logIndepMult(tAllAttr *obj, int type);
        void logExtraRate(tAllAttr *obj, int type);
        void logReactFactor(tAllAttr *obj, int type);
        void logBuff(tAllAttr *obj, int type);

        void logInfo(tAllAttr *obj, int type);   // tInfo info;
        void logAttack(tAllAttr *obj, int type); // tAttack attack;
        void logBurst(tAllAttr *obj, int type);  // tBurst burst;
        void logSkill(tAllAttr *obj, int type);  // tSkill skill;
        
        		void printAllAttribute(void);

    private:
    };
}

#endif
