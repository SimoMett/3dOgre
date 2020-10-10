//
// Created by matteo on 05/02/20.
//

#include "DffObject.h"

DffObject::DffObject(const string & file)
{
    ifstream dffFile;
    dffFile.open(file);
    if(!dffFile.good())
        cerr << "Warning: invalid dff file"<<endl;
    else
    {
        dffFile.seekg(0,dffFile.end);
        unsigned int size=dffFile.tellg();
        dffFile.seekg(0,dffFile.beg);
        char * buffer=new char[size];
        dffFile.read(buffer,size);
        dffFile.close();

        unsigned int bytesToRead=size;
        while (bytesToRead!=0)
        {
            cout << "reading from byte "<<(size-bytesToRead)<<endl;
            mainSections.push_back(unique_ptr<dff::Section>(dff::Section::parseSectionFromData(buffer+(size-bytesToRead),bytesToRead)));
            if(bytesToRead!=0)
            {
                cout << "bytesToRead= "<<bytesToRead<<endl;
            }
        }

        cout << "read complete: "<< mainSections.size()<<endl;

        delete[] buffer;
    }

    dffFile.close();
}

/*void DffObject::findClumpSections(char *buffer, unsigned int size)
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
}*/