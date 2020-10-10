//
// Created by matteo on 04/10/20.
//

#ifndef INC_3DOGRE_SECTION_H
#define INC_3DOGRE_SECTION_H

#include <vector>

namespace dff
{
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

    class Section
    {
    public:

        //static Section parseSectionFromData(unsigned char * data, unsigned int size);
        static Section parseSectionFromData(char * data, unsigned int & size);

        Section();
        /*
         * data := header+data bytes, size := size of 'data'
         */
        Section(unsigned char * data, unsigned int size);

        eDffSectionType getType() const;
        unsigned int getDataSectionSize() const;
        unsigned short getTimeStamp() const;

    protected:
        struct HeaderStruct
        {
            eDffSectionType sectionType;
            unsigned int dataSize;
            unsigned int timeStamp;
        };

        HeaderStruct header;
        unsigned char * data;
        //Section * parent;
        //std::vector<Section> children;
    };
}


#endif //INC_3DOGRE_SECTION_H
