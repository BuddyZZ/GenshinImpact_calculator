#include "origin.h"
#ifndef WEAPON_H
#define WEAPON_H

namespace genShinImpact {
class weapon : public virtual origin {
public:
  tAllAttr base;

  weapon();
  ~weapon();

protected:
private:
};
} // namespace genShinImpact

#endif

// /**
//  * A struct use to define a whole weapon attribute
//  * This struct can be use to transfer data between object to simplize operate
//  steps
//  */
// typedef struct weaponAttribute
// {
// 	int level;
// 	int rare;
// 	string name;
// 	int type;
// 	float basicAtk;
// 	tAttributeFix attributeFix;
// 	tAttribute attribute;
// 	tBonus bonus;
// 	tBuff buff;
// } tWeapon, *pWeapon;