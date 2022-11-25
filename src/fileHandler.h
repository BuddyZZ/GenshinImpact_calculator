#include "origin.h"
#include <string>

#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

namespace genShinImpact
{
    typedef enum part
    {
        PART_CHARACTER,
        PART_WEAPON,
        PART_ARTIFACT,
        PART_ENVIRONMRNT,
        PART_ENEMY,
        PART_RESULT,
        PART_CONFIGURATION
    } ePart;

    class fileHandler : public origin
    {
    public:
        fileHandler();

        bool importOneAttr(string path, ePart part, tAllAttr *attr);
        bool exportOneAttr(ePart part, tAllAttr *attr);
        bool exportAllAttr(tAllAttr *character, tAllAttr *weapon, tAllAttr *artifact, tAllAttr *environment, tAllAttr *enemy);
        bool exportCalResult(string path);

        bool importSetting();
        bool exportSetting();

    protected:
        string mFileName;
        const string DEFAULT_NAME = "default";

#define LINUX
#ifdef LINUX
        const string DEFAULT_ATTR_PATH = "./attribute/";
        const string DEFAULT_RESULT_PATH = "./result/";
        const string DEFAULT_CONFIGURATION_PATH = "./setting/";
#else
        const string DEFAULT_ATTR_PATH = ".\\attribute\\";
        const string DEFAULT_RESULT_PATH = ".\\result\\";
        const string DEFAULT_CONFIGURATION_PATH = ".\\setting\\";
#endif
        string attrPath;
        string resultPath;
        string generateFullPath(ePart part);
        bool checkName(string name, ePart part);

        // void addSignature();
        // void checkSignature();
    private:
    };
}

#endif
