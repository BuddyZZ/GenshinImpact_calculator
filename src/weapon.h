#include "origin.h"
#ifndef WEAPON_H
#define WEAPON_H

namespace genShinImpact
{
  typedef enum weaponList
  {
    WEAPON_A,
    WEAPON_B,
  } eWeaponlist;
  typedef enum weaponRefine
  {
    WEAPON_REFINE_1 = 0,
    WEAPON_REFINE_2,
    WEAPON_REFINE_3,
    WEAPON_REFINE_4,
    WEAPON_REFINE_5,
  } eWeaponRefine;
  class weapon : public virtual origin
  {
  public:
    weapon();
    weapon(eWeaponlist weaponNum, int level, int refine);

  protected:
    tAllAttr base;

  private:
  };
} // namespace genShinImpact

#endif
