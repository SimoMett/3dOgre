//
// Created by matteo on 05/02/20.
//

#ifndef INC_3DOGRE_DFFOBJECT_H
#define INC_3DOGRE_DFFOBJECT_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Clump.h"

using namespace std;

class DffObject
{
public:
    DffObject(const string & file);

private:
    dff::Clump mainSection;
    vector<dff::Clump> clumps;

    void findClumpSections(char * buffer, unsigned int size);
};


#endif //INC_3DOGRE_DFFOBJECT_H
