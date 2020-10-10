//
// Created by matteo on 05/02/20.
//

#ifndef INC_3DOGRE_DFFOBJECT_H
#define INC_3DOGRE_DFFOBJECT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <memory>
#include "Section.h"

using namespace std;

class DffObject
{
public:
    DffObject(const string & file);

private:

    std::list<unique_ptr<dff::Section>> mainSections;

};


#endif //INC_3DOGRE_DFFOBJECT_H
