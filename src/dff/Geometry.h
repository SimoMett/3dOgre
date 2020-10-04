//
// Created by matteo on 04/10/20.
//

#ifndef INC_3DOGRE_GEOMETRY_H
#define INC_3DOGRE_GEOMETRY_H

namespace dff
{
    class Geometry
    {
    private:
        unsigned int format;
        unsigned int numTriangles;
        unsigned int numVertices;
        unsigned int numMorphTargets;//always 1
    };

}
#endif //INC_3DOGRE_GEOMETRY_H
