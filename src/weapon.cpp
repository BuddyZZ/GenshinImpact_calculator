#include "weapon.h"
#include "origin.h"
#include <cstring>
using namespace genShinImpact;
using namespace std;
weapon::weapon()
{
    memset(&base,'0',sizeof(tAllAttr));
}
weapon::~weapon()
{
}