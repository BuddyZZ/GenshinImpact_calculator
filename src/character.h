#include "origin.h"
#ifndef CHARACTER_H
#define CHARACTER_H

namespace genShinImpact
{
    class character:public virtual origin
    {
    public:
        tAllAttr base;
        character();
        // ~character();

    protected:
    private:
    };
}

#endif

// /**
//  * A struct use to define a whole character, and it is consist of some other struct defined before
//  * This struct can be use to transfer data between object to simplize operate steps
//  * @param basic character basic attribute that should not change after initiate
//  * @param attribute addition attribute form weapon/artifact/
//  *
//  */
// typedef struct characterAttribute
// {
//     int level;
//     int rare;
//     string name;
//     int weaponType;
//     int element;
//     tAttribute basic;           // character basic value
//     tAttribute attribute;       // add percent and such as element master
//     tAttributeFix attributeFix; // add fix Atk Hp Def basicAtk
//     tBonus bonus;
//     tRes res;
//     tBuff buff;
//     tReactFactor reactFactor;
//     tSkill skill;
//     tBurst burst;
//     tAttack attack;
// } tCharacter, *pCharacter;