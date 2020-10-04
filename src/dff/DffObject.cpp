//
// Created by matteo on 05/02/20.
//

#include <vector>
#include "DffObject.h"

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

        this->mainSection=DffSection((unsigned char *)buffer,size);

        delete[] buffer;
    }

    dffFile.close();
}