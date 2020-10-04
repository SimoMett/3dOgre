//
// Created by matteo on 04/10/20.
//

#ifndef INC_3DOGRE_MATERIAL_H
#define INC_3DOGRE_MATERIAL_H


namespace dff
{
    class Material
    {
    private:
        struct MaterialStruct
        {
            unsigned int flags;
            unsigned int color;//RGBA
            unsigned int unused;
            unsigned int isTextured;
        };
    };
}


#endif //INC_3DOGRE_MATERIAL_H
