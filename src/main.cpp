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
using namespace std;
using namespace genShinImpact;
//    A a(1);  //栈中分配
//    A b = A(1);  //栈中分配
//    A* c = new A(1);  //堆中分配

int main()
{

  calculate *testCalculate = new calculate();
  testCalculate->loadAttacker();
  testCalculate->loadSuffer();
  testCalculate->loadEnvironment();
  testCalculate->loadArtifact();
  testCalculate->loadWeapon();

  cout << "calHp()                ==" << testCalculate->calHp() << endl;
  cout << "calAtk()               ==" << testCalculate->calAtk() << endl;
  cout << "calDef()               ==" << testCalculate->calDef() << endl;
  cout << "calCritRate()          ==" << testCalculate->calCritRate() << endl;
  cout << "calCritDmg()           ==" << testCalculate->calCritDmg() << endl;
  cout << "calDefFactor()         ==" << testCalculate->calDefFactor() << endl;
  cout << "calLevelFactor()       ==" << testCalculate->calLevelFactor() << endl;
  cout << "calElementalMastery()  ==" << testCalculate->calElementalMastery() << endl;
  cout << "calReactFactor()       ==" << testCalculate->calReactFactor(REACT_VAPORIZE_A, testCalculate->calElementalMastery()) << endl;
  cout << "calResFactor()         ==" << testCalculate->calResFactor(DAMAGE_HIT, ELEMENT_PYRO) << endl;
  cout << "calBonus()             ==" << testCalculate->calBonus(DAMAGE_HIT, ELEMENT_PYRO) << endl;
  cout << "calIndepMult()         ==" << testCalculate->calIndepMult(DAMAGE_HIT, ELEMENT_PYRO) << endl;
  cout << "calExtraRate()         ==" << testCalculate->calExtraRate(DAMAGE_HIT, ELEMENT_PYRO) << endl;
  float damage = testCalculate->calDamage(1.0f, REACT_VAPORIZE_A, TEXT_ATK, CAL_EXPECTANCE, DAMAGE_HIT, ELEMENT_PYRO);
  cout << "damage==" << damage << endl;
}
