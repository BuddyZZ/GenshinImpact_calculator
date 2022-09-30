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
	switch (type)
	{
	case ENVIRONMENT_DOUBLE_PYRO:
		*getAttributeAddr(&base, TEXT_ATK) += 0.25;
		break;
	case ENVIRONMENT_DOUBLE_HYDRO:
		*getAttributeAddr(&base, TEXT_HP) += 0.25;
		break;
	case ENVIRONMENT_DOUBLE_ELECTRO:
		break;
	case ENVIRONMENT_DOUBLE_CRYO:
		*getAttributeAddr(&base, TEXT_CRIT_RATE) += 0.15;
		break;
	case ENVIRONMENT_DOUBLE_DENDRO:
		*getAttributeAddr(&base, TEXT_ELEMENTAL_MASTERY) += 80;
		break;
	case ENVIRONMENT_DOUBLE_ANEMO:
		*getBuffAddr(&base, BUFF_STAMINA_REDUCE) += 0.1;
		*getBuffAddr(&base, BUFF_CD_REDUCE) += 0.05;
		*getBuffAddr(&base, BUFF_MOVE_SPEED) += 0.1;
		break;
	case ENVIRONMENT_DOUBLE_GEO:
		*getBuffAddr(&base, BUFF_SHELD_STRENGTH) += 0.15;
		*getBonusAddr(&base, KIND_DAMAGE, DAMAGE_ATTACK) += 0.15;
		*getBonusAddr(&base, KIND_DAMAGE, DAMAGE_CHARGE_ATTACK) += 0.15;
		*getBonusAddr(&base, KIND_DAMAGE, DAMAGE_PLUNGE) += 0.15;
		*getBonusAddr(&base, KIND_DAMAGE, DAMAGE_SKILL) += 0.15;
		*getBonusAddr(&base, KIND_DAMAGE, DAMAGE_BURST) += 0.15;
		break;
	}
}
