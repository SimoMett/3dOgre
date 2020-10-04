//
// Created by matteo on 05/02/20.
//

#ifndef INC_3DOGRE_DFFOBJECT_H
#define INC_3DOGRE_DFFOBJECT_H

#include <iostream>
#include <fstream>
#include "DffSection.h"

using namespace std;

class DffObject
{
public:
    DffObject(const string & file);

private:
    DffSection mainSection;
};


#endif //INC_3DOGRE_DFFOBJECT_H
