#include "origin.h"
#ifndef WEAPON_H
#define WEAPON_H

namespace genShinImpact
{

  class weapon : public virtual origin
  {
  public:
    typedef enum weaponList
    {
      WEAPON_A,
      WEAPON_B,
    } eWeaponlist;
    weapon();
    weapon(eWeaponlist weaponNum, int level, int breakThrough);

  protected:
    tAllAttr base;

  private:
  };
} // namespace genShinImpact

#endif
