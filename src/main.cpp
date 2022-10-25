
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
struct str
{
  int A;
  int B;
  int C;
  int D;
  int E;
};
int compare(struct str *arr, int num)
{
  int i;

  for (i = 0; i < num; i++)
  {
    if (arr[i].A == arr[num].A &&
        arr[i].B == arr[num].B &&
        arr[i].C == arr[num].C &&
        arr[i].D == arr[num].D &&
        arr[i].E == arr[num].E)
    {
      break;
    }
  }
  return i;
}
int accumulate(struct str *aim, struct str *now, int num)
{
  int i = 0;
  int j = 0;
  for (i = 0; i < num; i++)
  {
    memcpy(aim + j, now + i, sizeof(struct str));
    (aim + j)->A += 1;
    if (compare(aim, j) == j)
    {
      cout << "(aim +" << j << ")->A== " << (aim + j)->A << endl;
      cout << "(aim +" << j << ")->B== " << (aim + j)->B << endl;
      cout << "(aim +" << j << ")->C== " << (aim + j)->C << endl;
      cout << "(aim +" << j << ")->D== " << (aim + j)->D << endl;
      cout << "(aim +" << j << ")->E== " << (aim + j)->E << endl;
      j++;
    }
    memcpy(aim + j, now + i, sizeof(struct str));
    (aim + j)->B += 1;
    if (compare(aim, j) == j)
    {
      cout << "(aim +" << j << ")->A== " << (aim + j)->A << endl;
      cout << "(aim +" << j << ")->B== " << (aim + j)->B << endl;
      cout << "(aim +" << j << ")->C== " << (aim + j)->C << endl;
      cout << "(aim +" << j << ")->D== " << (aim + j)->D << endl;
      cout << "(aim +" << j << ")->E== " << (aim + j)->E << endl;
      j++;
    }

    memcpy(aim + j, now + i, sizeof(struct str));
    (aim + j)->C += 1;
    if (compare(aim, j) == j)
    {
      cout << "(aim +" << j << ")->A== " << (aim + j)->A << endl;
      cout << "(aim +" << j << ")->B== " << (aim + j)->B << endl;
      cout << "(aim +" << j << ")->C== " << (aim + j)->C << endl;
      cout << "(aim +" << j << ")->D== " << (aim + j)->D << endl;
      cout << "(aim +" << j << ")->E== " << (aim + j)->E << endl;
      j++;
    }

    memcpy(aim + j, now + i, sizeof(struct str));
    (aim + j)->D += 1;
    if (compare(aim, j) == j)
    {
      cout << "(aim +" << j << ")->A== " << (aim + j)->A << endl;
      cout << "(aim +" << j << ")->B== " << (aim + j)->B << endl;
      cout << "(aim +" << j << ")->C== " << (aim + j)->C << endl;
      cout << "(aim +" << j << ")->D== " << (aim + j)->D << endl;
      cout << "(aim +" << j << ")->E== " << (aim + j)->E << endl;
      j++;
    }

    memcpy(aim + j, now + i, sizeof(struct str));
    (aim + j)->E += 1;
    if (compare(aim, j) == j)
    {
      cout << "(aim +" << j << ")->A== " << (aim + j)->A << endl;
      cout << "(aim +" << j << ")->B== " << (aim + j)->B << endl;
      cout << "(aim +" << j << ")->C== " << (aim + j)->C << endl;
      cout << "(aim +" << j << ")->D== " << (aim + j)->D << endl;
      cout << "(aim +" << j << ")->E== " << (aim + j)->E << endl;
      j++;
    }
  }
  return j;
}

int main()
{
  // string temp = "C:\\Users\\z004c38h\\Desktop\\GenshinTest.txt";
  // string tempLinux = "/home/buddy/GenshinImpact_calculator/src/test";
  // calculate *testCalculate = new calculate();
  // fileHandler *testFileHandler = new fileHandler(tempLinux);

  // tAllAttr *test = new tAllAttr;

  // // // float rate[3];
  // // // eTextType text[3];
  // // // rate[0]=0.5;
  // // // text[0]=TEXT_HP;
  // // // testCalculate->findMaxGreed(32, 0.9, rate, text, DAMAGE_SKILL, ELEMENT_HYDRO, REACT_VAPORIZE_A, 0.33);

  // // cout << testCalculate->mAttacker.info.name << endl;

  // testFileHandler->exportOneAttr(tempLinux, PART_CHARACTER, &testCalculate->mAttacker);

  // testFileHandler->importOneAttr(tempLinux, PART_CHARACTER, test);

  // cout << test->info.name << endl;
  int i = 0;
  int totalNum_1 = 5;
  int totalNum_2 = 1;

  struct str all_1[10240];
  struct str all_2[10240];
  all_1[0].A = 1;
  all_1[1].B = 1;
  all_1[2].C = 1;
  all_1[3].D = 1;
  all_1[4].E = 1;

  while (i < 15)
  {
    if (i % 2 == 0)
    {
      totalNum_2 = accumulate(all_2, all_1, totalNum_1);
    }
    else
    {
      totalNum_1 = accumulate(all_1, all_2, totalNum_2);
    }
    cout << "num_1==" << totalNum_1 << "  num_2==" << totalNum_2 << endl;
    i++;
  }
}
