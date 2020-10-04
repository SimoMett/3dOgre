//
// Created by matteo on 04/10/20.
//

#ifndef INC_3DOGRE_TEXTURE_H
#define INC_3DOGRE_TEXTURE_H


namespace dff
{
    class Texture
    {
    private:
        struct TextureStruct
        {
            unsigned char texFilterMode;
            unsigned char UVAddr;//4+4 bit
            unsigned short mipLvlPadding;//1bit Does texture use mip levels - 15bits padding
        };
    };
}


#endif //INC_3DOGRE_TEXTURE_H
