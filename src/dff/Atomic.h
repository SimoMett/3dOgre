//
// Created by matteo on 04/10/20.
//

#ifndef INC_3DOGRE_ATOMIC_H
#define INC_3DOGRE_ATOMIC_H

namespace dff
{
    class Atomic
    {
    private:
        struct rwAtomicStruct {
            unsigned int frameIndex;    // Index of the frame within the clump's frame list.
            unsigned int geometryIndex; // Index of geometry within the clump's geometry list.
            unsigned int flags;         // See below.
            unsigned int unused;        // Typically 0.
        };
    };
}


#endif //INC_3DOGRE_ATOMIC_H
