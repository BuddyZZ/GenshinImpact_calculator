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

#include <iostream>
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
	artifact *testArtifact = new artifact(ART_TEXT_MAIN_ATK, ART_TEXT_MAIN_ELEMENT_BONUS, ART_TEXT_MAIN_CRIT_RATE, STAR_5); // ART_TEXT_MAIN_ELEMENT_BONUS
	if (testArtifact->checkMainText() == false)
	{
		printf("checkMainText wrong\n");
		return 0;
	}
	//testCharacter->printAllAttribute();
	testCharacter->loadArtifactMainText(&(testArtifact->mArtifact));
	//testCharacter->printAllAttribute();

	calculate *testCalculate = new calculate(testCharacter->mCharacter, testEnemy->mEnemy);
	// testCalculate.calMaxGreed(int reactType, int damageType, int maxSubtextNum, float luckValue);
	// #define REACT_TYPE_BURNING 0x0020
	// #define REACT_TYPE_VAPORIZE_A 0x0040
	// testCalculate->calMaxGreed(0,0,1,1.0f);
	testCalculate->calMaxGreed(REACT_TYPE_VAPORIZE_B,DAMAGE_TYPE_PYRO , 45, 1.0f);//REACT_TYPE_SWIRL  REACT_TYPE_MELT_A  REACT_TYPE_VAPORIZE_B
}													//DAMAGE_TYPE_PYRO
