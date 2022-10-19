#include "origin.h"
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
        PART_RESULT,
    }ePart;

    class fileHandler : public origin
    {
    public:
        fileHandler();
        fileHandler(string name);

        void importOneAttr(ePart part, tAllAttr *attr);
        void importAllAttr();
        void exportOneAttr(ePart part, tAllAttr *attr);
        void exportAllAttr();
        void exportOneCalResult(ePart part, tAllAttr *attr);
        void exportAllCalResult();

    protected:
    string mFileName;
        // void encrypt();
        // void decrypt();
        // void calibrate();
    private:
    };
}

#endif
