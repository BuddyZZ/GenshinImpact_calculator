#include "origin.h"
#ifndef WEAPON_H
#define WEAPON_H

namespace genShinImpact
{
  class weapon : public virtual origin
  {
  public:
    weapon();
    ~weapon();

  protected:
    tAllAttr base;

  private:
  };
} // namespace genShinImpact

#endif
