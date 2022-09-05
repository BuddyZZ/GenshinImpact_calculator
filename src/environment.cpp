#include "environment.h"
using namespace genShinImpact;
using namespace std;
environment::environment()
{
	memset(&base, '0', sizeof(tAllAttr));
    INIT_STRUCT(base.extraRate, tExtraRate, float, 0.01);
    INIT_STRUCT(base.indepMult, tIndepMult, float, 0.01);

}
environment::~environment()
{
	memset(&base, '0', sizeof(tAllAttr));
}

void environment::loadTeamEffect(elementType type)
{
			tBonus temp;

	switch (type)
	{
	case ELEMENT_UNSURE:
		break;
	case ELEMENT_CRYO:
		base.attr.critRate += 0.15;
		break;
	case ELEMENT_PYRO:
		base.attr.atk += 0.25;
		break;
	case ELEMENT_HYDRO:
		base.buff.incomingHelthingBonus += 0.3;
		break;
	case ELEMENT_DENDRO:
		break;
	case ELEMENT_ELECTRO:
		break;
	case ELEMENT_ANEMO:
		base.buff.staminaReduce = 0.1;
		base.buff.cdReduce = 0.05;
		base.buff.moveSpeed = 0.1;
		break;
	case ELEMENT_GEO:
		base.buff.sheldStrength += 0.15;
		INIT_STRUCT(temp, tBonus, float, 0.15);
		temp.hit = 0;
		temp.chargeHit = 0;
		temp.plunge = 0;
		temp.skill = 0;
		temp.burst = 0;
		LOAD_STRUCT(base.bonus, temp, tBonus, float);
		// enemy geo res down 0.2
		break;
	default:
		INIT_STRUCT(temp, tRes, float, 0.15);
		temp.hit = 0;
		temp.chargeHit = 0;
		temp.plunge = 0;
		temp.skill = 0;
		temp.burst = 0;
		LOAD_STRUCT(base.res, temp, tRes, float);
	}
}
