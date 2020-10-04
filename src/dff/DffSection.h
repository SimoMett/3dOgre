//
// Created by matteo on 04/10/20.
//

#ifndef INC_3DOGRE_DFFSECTION_H
#define INC_3DOGRE_DFFSECTION_H

#include <memory>

enum eDffSectionType
{
    rwDATA=1,
    rwSTRING=2,
    rwEXTENSION=3,
    rwTEXTURE=6,
    rwMATERIAL=7,
    rwMATERIALLIST=8,
    rwFRAMELIST=14,
    rwGEOMETRY=15,
    rwCLUMP=16,
    rwATOMIC=20,
    rwGEOMETRYLIST=26,
    rwMATERIALSPLIT=1294,
    rwFRAME=39056126
};

class DffSection
{
public:
    DffSection();
    /*
     * data := header+data bytes, size := size of 'data'
     * */
    DffSection(unsigned char * data,unsigned int size);

    eDffSectionType getType();
    unsigned int getDataSectionSize();
    unsigned short getVersion();

private:
    eDffSectionType sectionType;
    unsigned int dataSize;
    unsigned char header[12];
    unsigned char * data;

};


#endif //INC_3DOGRE_DFFSECTION_H
