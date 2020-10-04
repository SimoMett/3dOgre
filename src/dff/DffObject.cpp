//
// Created by matteo on 05/02/20.
//

#include <vector>
#include "DffObject.h"
#include "Section.h"

DffObject::DffObject(const string & file)
{
    ifstream dffFile;
    dffFile.open(file);
    if(!dffFile.good())
        cerr << "Warning: invalid dff file"<<endl;
    else
    {
        unsigned int size=dffFile.tellg();
        char * buffer=new char[size];
        dffFile.read(buffer,size);

        findClumpSections(buffer,size);
        this->mainSection=clumps[0];

        delete[] buffer;
    }

    dffFile.close();
}

void DffObject::findClumpSections(char *buffer, unsigned int size)
{
    unsigned int cursorPos=0;

    struct SectionHeader
    {
        unsigned int sectionType;
        unsigned int dataSize;
        unsigned int timeStamp;
    };

    bool bExit=false;
    while(!bExit)
    {
        SectionHeader sectionHeader=*(SectionHeader*)(buffer)[0];
        if(sectionHeader.sectionType==dff::eDffSectionType::rwCLUMP)
            dff::Clump clumpSection((unsigned char*)buffer,sectionHeader.dataSize);
        cursorPos+=sectionHeader.dataSize;

        if(sectionHeader.dataSize==0 || cursorPos==size)
            bExit=true;
    }
}