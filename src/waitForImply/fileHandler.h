#include "origin.h"
#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

namespace genShinImpact
{
    class fileHandler : public origin
    {
    public:
        fileHandler();
        ~fileHandler();

        bool writeTofile(int type); // log current character/weapon/artifact/result to one file
        void *loadFile();           // load one character/weapon/artifact/ generate by writeTofile
        bool loadData();            // load character/weapon/artifact dataBase
    protected:
    private:
    };
}

#endif
