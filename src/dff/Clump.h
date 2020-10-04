//
// Created by matteo on 04/10/20.
//

#ifndef INC_3DOGRE_CLUMP_H
#define INC_3DOGRE_CLUMP_H


#include <vector>
#include "Atomic.h"
#include "Section.h"

using std::vector;

namespace dff
{
    class Clump: public Section
    {
    public:
        Clump();
        Clump(unsigned char * _data, unsigned int size);


    private:
        struct ClumpStruct
        {
            unsigned int numberOfAtomics;
            unsigned int numberOfLights;
            unsigned int numberOfCameras;
        };

        //vector<Atomic> atomics;
        //vector<Light> lights;
        //no camera vector
    };
}


#endif //INC_3DOGRE_CLUMP_H
