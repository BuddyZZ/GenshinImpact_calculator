#include "character.h"
using namespace genShinImpact;
using namespace std;
character::character()
{
    memset(&base,'0',sizeof(tAllAttr));
    base.attrB.hpFix=10000;
        cout<<"base.attrB.hpFix=="<<base.attrB.hpFix<<endl;

    cout<<"initial character"<<endl;
}
character::~character()
{
}