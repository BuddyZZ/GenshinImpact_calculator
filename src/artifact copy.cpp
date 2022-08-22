#include "artifact.h"
using namespace genShinImpact;
using namespace std;
artifact::artifact()
{
    memset(&base,'0',sizeof(tAllAttr));
}
artifact::~artifact()
{    memset(&base,'0',sizeof(tAllAttr));

}