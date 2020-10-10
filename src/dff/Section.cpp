//
// Created by matteo on 04/10/20.
//

#include <iostream>
#include "Section.h"

using namespace std;

dff::Section::Section(): data(nullptr){}

dff::Section::Section(unsigned char *data, unsigned int size): data(nullptr), header({})
{
    // copy first 3 integers in 'header'
    header.sectionType= static_cast<eDffSectionType>(((int*)data)[0]);
    header.dataSize=((int*)data)[1];
    header.timeStamp=((int*)data)[2];

    // copy the rest in 'data'
    this->data=new unsigned char[header.dataSize];
    for(int i=0;i<header.dataSize;i++)
        this->data[i]=data[i+12];
}

dff::Section dff::Section::parseSectionFromData(char *data, unsigned int & bytesToRead)
{
    dff::Section section((unsigned char*)data,bytesToRead);
    bytesToRead-=section.getDataSectionSize();
    return section;
}

/*
 * Returns number of bytes of header + data
 */
unsigned int dff::Section::getDataSectionSize() const
{
    return sizeof(HeaderStruct)+header.dataSize;
}

dff::eDffSectionType dff::Section::getType() const
{
    return header.sectionType;
}

unsigned short dff::Section::getTimeStamp() const
{
    return header.timeStamp;
}
