#include "origin.h"
#ifndef ENEMY_H
#define ENEMY_H

namespace genShinImpact {
class enemy : public virtual origin {
public:
  tAllAttr base;
  enemy();
  ~enemy();

protected:
private:
};
} // namespace genShinImpact

#endif