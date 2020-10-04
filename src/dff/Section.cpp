//
// Created by matteo on 04/10/20.
//

#include "Section.h"

dff::Section::Section(): data(nullptr){}

dff::Section::Section(unsigned char *data, unsigned int size)
{
    // copy first 3 integers in 'header'
    header.sectionType= static_cast<eDffSectionType>(((int*)data)[0]);
    header.dataSize=static_cast<eDffSectionType>(((int*)data)[1]);
    header.timeStamp=static_cast<eDffSectionType>(((int*)data)[2]);

    // copy the rest in 'data'
    this->data=new unsigned char[header.dataSize-12];
    for(int i=12;i<size;i++)
        this->data[i-12];
}

unsigned int dff::Section::getDataSectionSize() const
{
    return header.dataSize;
}

dff::eDffSectionType dff::Section::getType() const
{
    return header.sectionType;
}

unsigned short dff::Section::getTimeStamp() const
{
    return header.timeStamp;
}
