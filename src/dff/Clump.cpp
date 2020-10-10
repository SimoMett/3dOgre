//
// Created by matteo on 04/10/20.
//
#include <iostream>

#include "Clump.h"


using namespace std;

dff::Clump::Clump(unsigned char *_data, unsigned int size) : Section(_data, size)
{

    cout << "clump"<<endl;
    cout << hex<<(int)this->data[0]<<endl;
}

dff::Clump::Clump(){}
