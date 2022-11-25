#include "fileHandler.h"
#include <fstream>
using namespace genShinImpact;
using namespace std;

fileHandler::fileHandler()
{
    mFileName = DEFAULT_NAME;
}
bool fileHandler::importOneAttr(string path, ePart part, tAllAttr *attr)
{
    ifstream file;
    if (checkName(path, part))
    {
        file.open(path, ios::in | ios::binary);
        if (!file)
        {
            cout << "open fail" << endl;
            return false;
        }
        else
        {
            file.read(reinterpret_cast<char *>(attr), sizeof(tAllAttr));
            file.close();
            return true;
        }
    }
    else
        return false;
}

bool fileHandler::exportOneAttr(ePart part, tAllAttr *attr)
{
    ofstream file;
    string tempFile = generateFullPath(part);
    file.open(tempFile, ios::out | ios::binary);
    if (!file)
    {
        cout << "open fail -- " << tempFile << endl;
        return false;
    }
    else
    {
        file.write(reinterpret_cast<char *>(attr), sizeof(tAllAttr));
        file.close();
        return true;
    }
}
bool fileHandler::exportAllAttr(tAllAttr *character, tAllAttr *weapon, tAllAttr *artifact, tAllAttr *environment, tAllAttr *enemy)
{
    bool retVal = true;
    if (character != NULL)
        retVal &= exportOneAttr(PART_CHARACTER, character);
    if (weapon != NULL)
        retVal &= exportOneAttr(PART_WEAPON, weapon);
    if (artifact != NULL)
        retVal &= exportOneAttr(PART_ARTIFACT, artifact);
    if (environment != NULL)
        retVal &= exportOneAttr(PART_ENVIRONMRNT, environment);
    if (enemy != NULL)
        retVal &= exportOneAttr(PART_ENEMY, enemy);

    return retVal;
}

bool fileHandler::exportCalResult(string path)
{
    return 0;
}

string fileHandler::generateFullPath(ePart part)
{
    switch (part)
    {
    case PART_CHARACTER:
        return DEFAULT_ATTR_PATH + mFileName + ".cha";
    case PART_WEAPON:
        return DEFAULT_ATTR_PATH + mFileName + ".wep";
    case PART_ARTIFACT:
        return DEFAULT_ATTR_PATH + mFileName + ".art";
    case PART_ENVIRONMRNT:
        return DEFAULT_ATTR_PATH + mFileName + ".evr";
    case PART_ENEMY:
        return DEFAULT_ATTR_PATH + mFileName + ".enm";
    case PART_RESULT:
        return DEFAULT_RESULT_PATH + mFileName + ".rst";
    case PART_CONFIGURATION:
        DEFAULT_CONFIGURATION_PATH + mFileName + ".conf";
    default:
        return mFileName + ".wrong";
    }
}
bool fileHandler::checkName(string name, ePart part)
{
    string aim, find;
    switch (part)
    {
    case PART_CHARACTER:
        aim = ".cha";
        break;
    case PART_WEAPON:
        aim = ".wep";
        break;
    case PART_ARTIFACT:
        aim = ".art";
        break;
    case PART_ENVIRONMRNT:
        aim = ".evr";
        break;
    case PART_RESULT:
        aim = ".rst";
        break;
    case PART_CONFIGURATION:
        aim = ".conf";
        break;

        break;
    default:
        return false;
    }
    find = name.substr(name.find_last_of(".") + 1);
    if (aim == find)
        return true;
    else
        return false;
}

// {
//    {
//        .name = "test-enemy-0",
//        .rarity = RARITY_STAR_5,
//        .level = 90,
//        .element = ELEMENT_ANEMO,
//        .weapon = WEAPON_BOW,
//				.breakthroughText=TEXT_CRIT_DMG,
//    }, /*info*/
//    {
//        .atkFix = 0,
//        .defFix = 0,
//        .hpFix = 0,
//    }, /*attrB*/
//    {
//        .atkFix = 0,
//        .defFix = 0,
//        .hpFix = 0,
//    }, /*attrF*/
//    {
//        .atk = 0,
//        .def = 0,
//        .hp = 0,
//        .critRate = 0,
//        .critDmg = 0,
//        .elementalMastery = 0,
//        .recharge = 0,
//    }, /*attr*/
//    {
//        .pyro = 0,
//        .hydro = 0,
//        .electro = 0,
//        .cryo = 0,
//        .dendro = 0,
//        .anemo = 0,
//        .geo = 0,
//        .physical = 0,
//        .attack = 0,
//        .chargeAttack = 0,
//        .plunge = 0,
//        .skill = 0,
//        .burst = 0,
//    }, /*res*/
//    {
//        .pyro = 0,
//        .hydro = 0,
//        .electro = 0,
//        .cryo = 0,
//        .dendro = 0,
//        .anemo = 0,
//        .geo = 0,
//        .physical = 0,
//        .attack = 0,
//        .chargeAttack = 0,
//        .plunge = 0,
//        .skill = 0,
//        .burst = 0,
//    }, /*bonus*/
//    {
//        .vaporize_a = 0,
//        .vaporize_b = 0,
//        .melt_a = 0,
//        .melt_b = 0,
//        .swirl = 0,
//        .superconduct = 0,
//        .crushingice = 0,
//        .electroCharged = 0,
//        .overloaded = 0,
//        .burning = 0,
//        .bloom = 0,
//        .burgeon = 0,
//        .hyperbloom = 0,
//        .spread = 0,
//        .aggravate = 0,
//        .crystallize = 0,
//    }, /* reactFactor*/
//    {
//        .healingBonus = 0,
//        .incomingHelthingBonus = 0,
//        .sheldStrength = 0,
//        .defIgnor = 0,
//        .cdReduce = 0,
//        .normalAtkSpeed = 0,
//        .staminaReduce = 0,
//        .moveSpeed = 0,
//    }, /* buff*/
//    {
//        .name = "default-skill-name",
//        .element = ELEMENT_PHYSICS,
//        {
//            {0.5, 0.4, 0.5},
//            {0.5, 0.6, 0.5},
//        }, /*NormalAttackDmg[15][16]*/
//        {
//            {0.5, 0.4, 0.5},
//            {0.5, 0.6, 0.5},
//        },            /*chargeAttackDmg[15][16]*/
//        {25, 25, 25}, /*chargeAttackStaminaCost[15]*/
//        {8, 7, 6},    /*plungeDmg[15]*/
//        {8, 7, 6},    /*lowPlungeDmg[15]*/
//        {8, 7, 6},    /*highPlungeDmg[15]*/
//    },                /* attack*/
//    {
//        .name = "default-name",
//        .element = ELEMENT_ANEMO,
//        {8, 7, 6}, /*cooldown[15]*/
//        {
//            {0.5, 0.4, 0.5},
//            {0.5, 0.6, 0.5},
//        }, /*rate[15][16]*/
//    },     /* skill*/
//    {
//        .name = "default-burst-name",
//        .element = ELEMENT_ANEMO,
//        .energy = 80,
//        {8, 7, 6}, /*cooldown[15]*/
//        {
//            {0.5, 0.4, 0.5},
//            {0.5, 0.6, 0.5},
//        }, /*rate[15][16]*/
//    },     /* burst*/
//    {
//        .pyro = 0,
//        .hydro = 0,
//        .electro = 0,
//        .cryo = 0,
//        .dendro = 0,
//        .anemo = 0,
//        .geo = 0,
//        .physical = 0,
//        .attack = 0,
//        .chargeAttack = 0,
//        .plunge = 0,
//        .skill = 0,
//        .burst = 0,
//    }, /* indepMult*/
//    {
//        .pyro = 0,
//        .hydro = 0,
//        .electro = 0,
//        .cryo = 0,
//        .dendro = 0,
//        .anemo = 0,
//        .geo = 0,
//        .physical = 0,
//        .attack = 0,
//        .chargeAttack = 0,
//        .plunge = 0,
//        .skill = 0,
//        .burst = 0,
//    } /* extraRate*/
//},

// LOAD_STRUCT(base.attr, characterArr[characterNum].attr, tAttribute, float);
// LOAD_STRUCT(base.attrF, characterArr[characterNum].attrF, tAttributeFix, float);
// LOAD_STRUCT(base.attrB, characterArr[characterNum].attrB, tAttributeFix, float);
// LOAD_STRUCT(base.res, characterArr[characterNum].res, tRes, float);
// LOAD_STRUCT(base.bonus, characterArr[characterNum].bonus, tBonus, float);
// LOAD_STRUCT(base.indepMult, characterArr[characterNum].indepMult, tIndepMult, float);
// LOAD_STRUCT(base.extraRate, characterArr[characterNum].extraRate, tExtraRate, float);
// LOAD_STRUCT(base.reactFactor, characterArr[characterNum].reactFactor, tReactFactor, float);
// LOAD_STRUCT(base.buff, characterArr[characterNum].buff, tBuff, float);
// base.info.level = level;
// base.info.element = characterArr[characterNum].info.element;
// base.info.name = characterArr[characterNum].info.name;
// base.info.rarity = characterArr[characterNum].info.rarity;
// base.info.weapon = characterArr[characterNum].info.weapon;

// base.attack.name = characterArr[characterNum].attack.name;
// base.attack.element = characterArr[characterNum].attack.element;
// LOAD_STRUCT(base.attack, characterArr[characterNum].attack, tAttack, float);

// base.skill.name = characterArr[characterNum].skill.name;
// base.skill.element = characterArr[characterNum].skill.element;
// LOAD_STRUCT(base.skill, characterArr[characterNum].skill, tSkill, float);

// base.burst.name = characterArr[characterNum].burst.name;
// base.burst.element = characterArr[characterNum].burst.element;
// LOAD_STRUCT(base.burst, characterArr[characterNum].burst, tBurst, float);

//     ofstream file;
// *getAttributeAddr(attr)
//     attr->attr.hp;
//     attr->attr.atk;
//     attr->attr.def;
//     attr->attr.elementalMastery;
//     attr->attr.critRate;
//     attr->attr.critDmg;
//     attr->attr.recharge;

//     attr->attrF.hpFix;
//     attr->attrF.atkFix;
//     attr->attrF.defFix;

//     attr->attrB.hpFix;
//     attr->attrB.atkFix;
//     attr->attrB.defFix;

//     attr->res;
//     float pyro;
//     float hydro;
//     float dendro;
//     float electro;
//     float anemo;
//     float cryo;
//     float geo;
//     float physical;
//     float hit;
//     float chargeHit;
//     float plunge;
//     float burst;
//     float skill;

//     attr->bonus;
//     float pyro;
//     float hydro;
//     float dendro;
//     float electro;
//     float anemo;
//     float cryo;
//     float geo;
//     float physical;
//     float hit;
//     float chargeHit;
//     float plunge;
//     float burst;
//     float skill;

//     attr->indepMult;
//         float burst;
//     float skill;
//     float hit;
//     float chargeHit;
//     float plunge;
//     float cryo;
//     float pyro;
//     float hydro;
//     float dendro;
//     float electro;
//     float anemo;
//     float geo;
//     float physical;

//     attr->extraRate;
//     attr->reactFactor;
//     attr->buff;
//     attr->info;
//     attr->attack;
//     attr->skill;
//     attr->burst;