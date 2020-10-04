//
// Created by matteo on 04/10/20.
//

#include <fstream>
#include <exception>

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/exception/exception.hpp>

#include "../src/dff/DffSection.h"

BOOST_AUTO_TEST_CASE(my_test)
{
    using namespace std;
    try
    {
        ifstream dffFile;
        dffFile.open("SimpleCube.dff");
            if(!dffFile.good()) throw "file not good";

        unsigned int size=dffFile.tellg();
        char * buffer=new char[size];
        dffFile.read(buffer,size);


        dffFile.close();
        delete[] buffer;
    }
    catch (exception & e)
    {
        cerr << e.what() << endl;
    }
}
