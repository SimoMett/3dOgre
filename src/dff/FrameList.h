//
// Created by matteo on 04/10/20.
//

#ifndef INC_3DOGRE_FRAMELIST_H
#define INC_3DOGRE_FRAMELIST_H



class FrameList
{
private:
    unsigned int numFrames;

    struct Frame
    {
        //float[3][3] rotationMat
        //float[3] pos
        unsigned int currentFrameIndex;
        unsigned int matrixFlags;
    };

    //vector<Frame>
};


#endif //INC_3DOGRE_FRAMELIST_H
