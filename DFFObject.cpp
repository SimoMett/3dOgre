//
// Created by matteo on 05/02/20.
//

#include "DFFObject.h"

DFFObject::DFFObject(const string & file)
{
    ifstream dffFile;
    dffFile.open(file);
    if(!dffFile.good())
        cerr << "Warning: invalid dff file"<<endl;

    dffFile.close();
}