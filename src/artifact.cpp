#include "artifact.h"
using namespace genShinImpact;
using namespace std;
artifact::artifact()
{
    memset(&base,'0',sizeof(tAllAttr));
    base.attrF.atkFix=311;
    base.attrF.defFix=0;
    base.attrF.hpFix=4786;
    base.attr.atk=0.45;
    base.attr.critDmg=0.70;
    base.attr.critRate=0.35;
    base.attr.def=0.2;
    base.attr.elementalMastery=120;
    base.attr.hp=0.2;
    base.attr.rechage=0.5;
}
artifact::~artifact()
{    memset(&base,'0',sizeof(tAllAttr));

}