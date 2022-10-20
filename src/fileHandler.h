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

        int importOneAttr(ePart part, char *attr);
        int importAllAttr();
        int exportOneAttr(ePart part, tAllAttr *attr);
        int exportAllAttr();
        int exportOneCalResult(ePart part, tAllAttr *attr);
        int exportAllCalResult();

    protected:
        string mFileName;
        tAllAttr temp;
        string getSuffix(ePart part);
        // void addSignature();
        // void checkSignature();
    private:
    };
}

#endif
