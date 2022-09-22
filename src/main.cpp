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
    // calculate testCalculate = calculate();
    // calculate testCalculate();

  memset(&testCalculate->mWeapon, '0', sizeof(tAllAttr));
  memset(&testCalculate->mEnvironment, '0', sizeof(tAllAttr));
  memset(&testCalculate->mArtifact, '0', sizeof(tAllAttr));

  testCalculate->mSuffer.info.level = 90;
  testCalculate->mSuffer.res.anemo = 0.1;

  testCalculate->mWeapon.attrB.atkFix = 608;
  testCalculate->mWeapon.bonus.anemo = 0.5;

  testCalculate->mAttacker.info.level = 90;

  testCalculate->mAttacker.attrB.atkFix = 305;
  testCalculate->mAttacker.attrB.defFix = 700;
  testCalculate->mAttacker.attrB.hpFix = 13000;
  testCalculate->mAttacker.attr.critDmg = 0.5;
  testCalculate->mAttacker.attr.critRate = 0.05;
  testCalculate->mAttacker.attr.elementalMastery = 0;
  testCalculate->mAttacker.attr.recharge = 0;

 

  testCalculate->findMaxGreed(5, 1.0, 0.4806, TEXT_HP, DAMAGE_SKILL, ELEMENT_ANEMO, REACT_UNSURE, 1 / 3);

  // calDamage(eCalType calType, float rate, TextType mainAttr, eDamageType damageType, eElementType elementType, eReactType reactType);

  // float damage = testCalculate->calDamage(2.11, REACT_UNSURE, TEXT_ATK, CAL_MIN, DAMAGE_CHARGE_HIT, ELEMENT_HYDRO);
  //                                         REACT_VAPORIZE_A TEXT_HP,   CAL_MAX         DAMAGE_CHARGE_HIT,
  //                                         REACT_VAPORIZE_B TEXT_ATK,  CAL_MIN         DAMAGE_SKILL,
  //                                         REACT_UNSURE     TEXT_DEF,  CAL_EXPECTANCE  DAMAGE_BURST,

  //                            calDamage(float rate, eReactType reactType, TextType mainAttr, eCalType calType, eDamageType damageType, eElementType elementType)

}
