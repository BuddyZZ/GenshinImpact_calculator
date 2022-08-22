#include "origin.h"
#include "artifact.h"
#include "character.h"
#include "enemy.h"
#include "environment.h"
#include "weapon.h"

#ifndef CALCULATE_H
#define CALCULATE_H

namespace genShinImpact
{
    class calculate : public character, enemy, weapon, artifact, environment
    {
    public:
        calculate();
        ~calculate();
        tAllAttr mAttacker;
        tAllAttr mSuffer;
        tAllAttr mWeapon;
        tAllAttr mArtifact;
        tAllAttr mEnvironment;

        void resetAll();
        void loadALL();

        float calDamage(float rate, eReactType reactType, TextType mainAttr, eCalType calType, eDamageType damageType, eElementType elementType);
        
        float calHp();
        float calAtk();
        float calDef();
        float calCritRate();
        float calCritDmg();
        float calDefFactor();
        float calLevelFactor();
        float calElmentalMastery();
        float calReactFactor(eReactType reactType, float elementalMastery);
        float calResFactor(eDamageType damageType, eElementType elementType);
        float calBonus(eDamageType damageType, eElementType elementType);
        float calIndepMult(eDamageType damageType, eElementType elementType);
        float calExtraRate(eDamageType damageType, eElementType elementType);
    protected:


        void loadAttacker();
        void loadSuffer();
        void loadWeapon();
        void loadArtifact();
        void loadEnvironment();

    private:

    };
}

#endif
