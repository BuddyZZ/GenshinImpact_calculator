#include "origin.h"
#ifndef ENEMY_H
#define ENEMY_H

namespace genShinImpact {
class enemy : public virtual origin {
public:
  enemy();
  float setResistance(eKind kind, int type, float resValue);
  int setLevel(int level);
protected:
  tAllAttr base;

private:

};
} // namespace genShinImpact

#endif