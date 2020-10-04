//
// Created by matteo on 04/10/20.
//

#include "DffSection.h"

DffSection::DffSection(): data(nullptr)
{

}

DffSection::DffSection(unsigned char *data, unsigned int size): dataSize(size)
{
    int i=0;
    for(;i<12;i++)// copy first 12 bytes in 'header'
        header[i]=data[i];

    this->data=new unsigned char[dataSize-12];

    for(;i<size;i++)// copy the rest in 'data'
        this->data[i-12];
}