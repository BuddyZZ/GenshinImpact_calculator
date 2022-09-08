//============================================================================
// Name        : test.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "origin.h"

#include "calculate.h"
#include "character.h"
#include "enemy.h"
#include "environment.h"
#include "logger.h"

#include <bitset> //输出二进制的头文件
#include <iostream>
// cout<<hex/oct/dec/bin<<num<<endl;
// cout<<bitset<sizeof(a)*8>(a)<<endl;
#include <cstring>

#include<iomanip>

using namespace std;
using namespace genShinImpact;
//    A a(1);  //栈中分配
//    A b = A(1);  //栈中分配
//    A* c = new A(1);  //堆中分配

int main()
{

  calculate *testCalculate = new calculate();
  memset(&testCalculate->mWeapon, '0', sizeof(tAllAttr));
  memset(&testCalculate->mEnvironment, '0', sizeof(tAllAttr));
  memset(&testCalculate->mArtifact, '0', sizeof(tAllAttr));

  testCalculate->mSuffer.info.level = 88;
  testCalculate->mSuffer.res.hydro = -0.3;

testCalculate->mEnvironment.bonus.hydro=954/100*0.04;//38.16

  testCalculate->mAttacker.info.level = 90;

  testCalculate->mAttacker.attrB.atkFix = 1132;
  testCalculate->mAttacker.attrB.defFix = 9;
  testCalculate->mAttacker.attrB.hpFix = 34394;
//36128 37573 39018 40463 41908
  testCalculate->mAttacker.attr.critDmg = 2.415;
  testCalculate->mAttacker.attr.critRate = 0.779;
  testCalculate->mAttacker.attr.elementalMastery = 35;
  testCalculate->mAttacker.attr.recharge = 0;

  testCalculate->mAttacker.bonus.hydro = 0.816;

  testCalculate->mAttacker.attack.chargeAttackDmg[0][0] = 0.1968;
  testCalculate->mAttacker.skill.rate[13][0] = 0.4806;
  testCalculate->mAttacker.burst.rate[13][0] = 0.1035;

 testCalculate->findMaxGreed(40, 1.0, 0.4806, TEXT_HP, DAMAGE_SKILL, ELEMENT_HYDRO, REACT_UNSURE, 1/3);

  // calDamage(eCalType calType, float rate, TextType mainAttr, eDamageType damageType, eElementType elementType, eReactType reactType);

  // float damage = testCalculate->calDamage(2.11, REACT_UNSURE, TEXT_ATK, CAL_MIN, DAMAGE_CHARGE_HIT, ELEMENT_HYDRO);
  //                                         REACT_VAPORIZE_A TEXT_HP,   CAL_MAX         DAMAGE_CHARGE_HIT,
  //                                         REACT_VAPORIZE_B TEXT_ATK,  CAL_MIN         DAMAGE_SKILL,
  //                                         REACT_UNSURE     TEXT_DEF,  CAL_EXPECTANCE  DAMAGE_BURST,

  //                            calDamage(float rate, eReactType reactType, TextType mainAttr, eCalType calType, eDamageType damageType, eElementType elementType)
  
  // cout << "damage==" <<fixed<< setprecision(2)<<damage << endl;
}
