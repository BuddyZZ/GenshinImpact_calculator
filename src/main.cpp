
#include "origin.h"
#include "calculate.h"
#include "character.h"
#include "enemy.h"
#include "environment.h"
#include "fileHandler.h"

#include <bitset> //输出二进制的头文件
#include <iostream>
// cout<<hex/oct/dec/bin<<num<<endl;
// cout<<bitset<sizeof(a)*8>(a)<<endl;

#include <iomanip>
#include <vector>
#include <fstream>

#include <stdio.h>
using namespace std;
using namespace genShinImpact;

int main()
{
  string temp = "C:\\Users\\z004c38h\\Desktop\\GenshinTest.txt";
  string tempLinux = "/home/buddy/GenshinImpact_calculator/src/test";
  calculate *testCalculate = new calculate();
  fileHandler *testFileHandler = new fileHandler();

  tAllAttr *test = new tAllAttr;

  // // float rate[3];
  // // eTextType text[3];
  // // rate[0]=0.5;
  // // text[0]=TEXT_HP;
  // // testCalculate->findMaxGreed(32, 0.9, rate, text, DAMAGE_SKILL, ELEMENT_HYDRO, REACT_VAPORIZE_A, 0.33);

  // cout << testCalculate->mAttacker.info.name << endl;


  cout << test->info.name << endl;

  // bool exportOneAttr(ePart part, tAllAttr *attr);
  testFileHandler->exportAllAttr(&testCalculate->mAttacker, &testCalculate->mWeapon, &testCalculate->mArtifact, &testCalculate->mEnvironment, &testCalculate->mSuffer);

  // bool importOneAttr(string path, ePart part, tAllAttr * attr);
}
