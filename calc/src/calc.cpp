/**
 * \file calc.cpp
 * \brief the C++ file with example calculation library
 */

//! Example C++ calculation. This function return number.
int getNumber() {
	return 1234;
}

#include <boost/python.hpp>

using namespace boost::python;

/**
 * Python wrapper using Boost.Python
 */
BOOST_PYTHON_MODULE( calc )
{
	//! exports getNumber to Python
    boost::python::def( "getNumber", getNumber );
}
