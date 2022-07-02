//============================================================================
// Name        : test.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "para.h"

#include "weapon.h"
#include "artifact.h"
#include "character.h"
#include "enemy.h"
#include "calculate.h"

// #include <iostream>
#include <bitset> //输出二进制的头文件
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

	character *testCharacter = new character();

	enemy *testEnemy = new enemy();
	weapon *testWeapon = new weapon();
	artifact *testArtifact = new artifact(ART_TEXT_MAIN_ATK, ART_TEXT_MAIN_ELEMENT_BONUS_CRYO, ART_TEXT_MAIN_CRIT_RATE, STAR_5); // ART_TEXT_MAIN_ELEMENT_BONUS

	testCharacter->mCharacter.attribute.elementalMastery =187;
	testCharacter->mCharacter.level = 90;
	testCharacter->mCharacter.basic.atk = 948;
	testCharacter->mCharacter.basic.critDmg = 1.356;
	testCharacter->mCharacter.basic.critRate = 0.331;
	testCharacter->mCharacter.bonus.electro = 0.12;
	testCharacter->mCharacter.bonus.skill=0.36;
	testCharacter->mCharacter.attributeFix.atkFix = 83;
	// testCharacter->mCharacter.reactFactor.vaporize_b = 0.15;
	testEnemy->mEnemy.level = 85;//6172
	testEnemy->mEnemy.res.electro = 0.1;

	testCharacter->printAllAttribute();

	calculate *testCalculate = new calculate(testCharacter->mCharacter, testEnemy->mEnemy);
	cout <<"indep=="<<(1+testCharacter->mCharacter.attribute.elementalMastery*0.0015)*1.706 * testCalculate->calExpectance(IS_REACT, DAMAGE_TYPE_ELECTRO|DAMAGE_TYPE_SKILL) << endl;

	testCalculate->attributeConvert(ATTRIBUTE_ELEMENTAL_MASTERY,ATTRIBUTE_ELEMENT_BONUS_ELECTRO,0.0015,0,999999);
	cout <<"inc=="<<1.706 * testCalculate->calExpectance(IS_REACT, DAMAGE_TYPE_ELECTRO|DAMAGE_TYPE_SKILL) << endl;
	//REACT_TYPE_VAPORIZE_A
}
