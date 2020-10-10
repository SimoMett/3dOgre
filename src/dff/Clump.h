//
// Created by matteo on 04/10/20.
//

#ifndef INC_3DOGRE_CLUMP_H
#define INC_3DOGRE_CLUMP_H


#include <list>
#include <vector>
#include "Atomic.h"
#include "Section.h"
#include "FrameList.h"
#include "GeometryList.h"

using std::list;
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

        ClumpStruct clumpStruct;
        FrameList frameList;
        GeometryList geometryList;
        list<Atomic> atomicsList;

        //vector<unsigned int> lightFrameIds;
        //list<Light> lightsList;

        //camera stuff

        //Extension extension
    };
}


#endif //INC_3DOGRE_CLUMP_H
