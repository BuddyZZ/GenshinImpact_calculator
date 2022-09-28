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

  testCalculate->findMaxGreed(32, 0.9, 0.4806, TEXT_HP, DAMAGE_SKILL, ELEMENT_HYDRO, REACT_VAPORIZE_A, 0.33);
  // findMaxGreed(int TextAmount, float fortune, float rate, TextType mainAttr, eDamageType damageType, eElementType elementType, eReactType reactType, float reactRatio)

  // calDamage(eCalType calType, float rate, TextType mainAttr, eDamageType damageType, eElementType elementType, eReactType reactType);

  // float damage = testCalculate->calDamage(2.11, REACT_UNSURE, TEXT_ATK, CAL_MIN, DAMAGE_CHARGE_HIT, ELEMENT_HYDRO);
//   float damage = testCalculate->calDamage(2.88, REACT_BURNING, TEXT_ATK, CAL_MIN, DAMAGE_HIT, ELEMENT_ELECTRO);

  //                                         REACT_VAPORIZE_A TEXT_HP,   CAL_MAX         DAMAGE_CHARGE_HIT,
  //                                         REACT_VAPORIZE_B TEXT_ATK,  CAL_MIN         DAMAGE_SKILL,
  //                                         REACT_UNSURE     TEXT_DEF,  CAL_EXPECTANCE  DAMAGE_BURST,
//                                           REACT_AGGRAVATE 
//                                            REACT_SPREAD
//                                            REACT_BURNING,
//                                            REACT_BLOOM,
//                                            REACT_BURGEON,
//                                            REACT_HYPERBLOOM,
  //                            calDamage(float rate, eReactType reactType, TextType mainAttr, eCalType calType, eDamageType damageType, eElementType elementType)
}
