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

#include <iomanip>

using namespace std;
using namespace genShinImpact;
//    A a(1);  //栈中分配
//    A b = A(1);  //栈中分配
//    A* c = new A(1);  //堆中分配

int main()
{

  calculate *testCalculate = new calculate();
  testCalculate->loadAll();
  memset(&testCalculate->mWeapon, '0', sizeof(tAllAttr));
  memset(&testCalculate->mEnvironment, '0', sizeof(tAllAttr));
  memset(&testCalculate->mArtifact, '0', sizeof(tAllAttr));

  testCalculate->mSuffer.info.level = 87;
  testCalculate->mSuffer.res.electro = 0.1;

  testCalculate->mEnvironment.bonus.hydro = 954 / 100 * 0.04; // 38.16

  testCalculate->mAttacker.info.level = 90;

  testCalculate->mAttacker.attrB.atkFix = 296;
  testCalculate->mAttacker.attrB.defFix = 799;
  testCalculate->mAttacker.attrB.hpFix = 13103;
  // 36128 37573 39018 40463 41908
  testCalculate->mAttacker.attr.critDmg = 0.5;
  testCalculate->mAttacker.attr.critRate = 0.05;
  testCalculate->mAttacker.attr.elementalMastery =0;
  testCalculate->mAttacker.attr.rechage = 0;

  testCalculate->mAttacker.bonus.electro =0 ;

  testCalculate->mAttacker.attack.NormalAttackDmg[9][0]=0.397;
  testCalculate->mAttacker.attack.chargeAttackDmg[0][0] = 0.1968;
  testCalculate->mAttacker.skill.rate[13][0] = 0.857;
  testCalculate->mAttacker.skill.rate[13][1] = 1.43;
  testCalculate->mAttacker.skill.rate[13][2] = 1.43;

  testCalculate->mAttacker.burst.rate[13][0] = 0.1035;

  float damage = testCalculate->calDamage(2.88, REACT_UNSURE, TEXT_ATK, CAL_MIN, DAMAGE_HIT, ELEMENT_ELECTRO);
  //                                         REACT_VAPORIZE_A TEXT_HP,   CAL_MAX         DAMAGE_CHARGE_HIT,
  //                                         REACT_VAPORIZE_B TEXT_ATK,  CAL_MIN         DAMAGE_SKILL,
  //                                         REACT_UNSURE     TEXT_DEF,  CAL_EXPECTANCE  DAMAGE_BURST,
//                                           REACT_AGGRAVATE 
//                                          REACT_SPREAD
  //                            calDamage(float rate, eReactType reactType, TextType mainAttr, eCalType calType, eDamageType damageType, eElementType elementType)

  cout << "damage==" << fixed << setprecision(2) << damage << endl;
}
