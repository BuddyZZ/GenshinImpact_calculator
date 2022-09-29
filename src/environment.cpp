#include "environment.h"
using namespace genShinImpact;
using namespace std;
environment::environment()
{
	base.info.name = "Default Environment";
}
environment::environment(tEnvironmentBuff *environmentBuffList)
{
	tEnvironmentBuff *temp = environmentBuffList;
	while (temp->type == ENVIRONMENT_DOUBLE_HYDRO)
	{
		// load all
		temp++;
	}
}

void environment::loadTeamEffect(eEnvironmentList type)
{
	tBonus temp;

	switch (type)
	{
	case ENVIRONMENT_DOUBLE_PYRO:
		base.attr.atk += 0.25;
		break;
	case ENVIRONMENT_DOUBLE_HYDRO:
		base.buff.incomingHelthingBonus += 0.3;
		break;
	case ENVIRONMENT_DOUBLE_ELECTRO:
		break;
	case ENVIRONMENT_DOUBLE_CRYO:
		base.attr.critRate += 0.15;
		break;
	case ENVIRONMENT_DOUBLE_DENDRO:
		break;
	case ENVIRONMENT_DOUBLE_ANEMO:
		base.buff.staminaReduce = 0.1;
		base.buff.cdReduce = 0.05;
		base.buff.moveSpeed = 0.1;
		break;
	case ENVIRONMENT_DOUBLE_GEO:
		base.buff.sheldStrength += 0.15;
		INIT_STRUCT(temp, tBonus, float, 0.15);
		temp.attack = 0;
		temp.chargeAttack = 0;
		temp.plunge = 0;
		temp.skill = 0;
		temp.burst = 0;
		LOAD_STRUCT(base.bonus, temp, tBonus, float);
		// enemy geo res down 0.2
		break;
	default:
		INIT_STRUCT(temp, tRes, float, 0.15);
		temp.attack = 0;
		temp.chargeAttack = 0;
		temp.plunge = 0;
		temp.skill = 0;
		temp.burst = 0;
		LOAD_STRUCT(base.res, temp, tRes, float);
	}
}
