//
// Created by matteo on 04/10/20.
//

#include <fstream>
#include <exception>

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/exception/exception.hpp>

#include "../src/dff/DffObject.h"


BOOST_AUTO_TEST_CASE(test_1)
{
    try
    {
        DffObject dffFile("SimpleCube.dff");


    }
    catch (exception & e)
    {
        cerr << e.what() << endl;
    }
}