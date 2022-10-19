#include "fileHandler.h"
#include <fstream>
using namespace genShinImpact;
using namespace std;

fileHandler::fileHandler()
{
    cout << "fileHandler nothing to do" << endl;
}
fileHandler::fileHandler(string name): m_fileName(name)
{
    string data;

    fstream file;
    // ofstream file;
    // ifstream file;

    cout << name << endl;
    file.open(name, ios::out);

    cout << "Writing to the file" << endl;
    //    cout << "Enter your name: ";
    //    cin.getline(data, 100);

    // 向文件写入用户输入的数据
    file << "test line 1" << endl;
    file << "test line 2" << endl;
    file.close();
    file.open(name);

    cout << "Reading from the file" << endl;
    file >> data;

    // 在屏幕上写入数据
    cout << data << endl;

    // 再次从文件读取数据，并显示它
    file >> data;
    cout << data << endl;

    // 关闭打开的文件
    file.close();
}
void fileHandler::importOneAttr(ePart part, tAllAttr attr);
void fileHandler::importAllAttr();
void fileHandler::exportOneAttr(ePart part, tAllAttr *attr)
{
    ofstream file;
    
    attr->attr.hp;
    attr->attr.atk;
    attr->attr.def;
    attr->attr.elementalMastery;
    attr->attr.critRate;
    attr->attr.critDmg;
    attr->attr.recharge;

    attr->attrF;
    attr->attrF. hpFix;
    attr->attrF. atkFix;
    attr->attrF. defFix;

    attr->attrB;
    attr->attrB. hpFix;
    attr->attrB. atkFix;
    attr->attrB. defFix;

    attr->res;


    attr->bonus;
    attr->indepMult;
    attr->extraRate;
    attr->reactFactor;
    attr->buff;
    attr->info;
    attr->attack;
    attr->skill;
    attr->burst;

}
void fileHandler::exportAllAttr();
void fileHandler::exportOneCalResult(ePart part, tAllAttr attr);
void fileHandler::exportAllCalResult();

