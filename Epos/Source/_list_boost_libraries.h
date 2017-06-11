#pragma once

#if false

///Boost Libararies
///http://www.boost.org/doc/libs/1_64_0/libs/libraries.htm
///===================
///--- basics ---
//#include <boost/foreach.hpp> //foreach loop //std::algorithm std_foreach
//#include <boost/smart_ptr.hpp> //smart pointer //c++14 has std:: smartpointers
//#include <boost/filesystem.hpp> //filesystem
//#include <boost/any.hpp> //a varialbe that can hold any type
//#include <boost/swap.hpp> //for swapping two values
//#include <boost/logic/tribool.hpp> //bool with 3 states
//#include <boost/tuple/tuple.hpp> //for functions returning multiple types
//#include <boost/typeof/typeof.hpp> //typeof operator
#include <boost/uuid/uuid.hpp> //unique ID
///--- Math / Graphics ---
#include <boost/geometry.hpp> //provides geometric algorithms, primitives and spatial index
#include <boost/gil/gil_all.hpp> //image library
#include <boost/qvm/all.hpp> //quaternions, vectors and matrices of static size with the emphasis on 2, 3 and 4-dimensional operations needed in graphics, video games and simulation applications
//#include <boost/math/quaternion.hpp> //math e.g. quaternions (or stuff like greatest common divisor in other headers)
//#include <boost/random.hpp> // A complete system for random number generation
//#include <boost/sort/sort.hpp> //high performance sorting //in std::
//#include <boost/numeric/ublas/storage_sparse.hpp> //math-notation, readable, vectors, matrices and sparse matrices
///--- containers ---
//#include <boost/multi_array.hpp> //multidimensional arrays
//#include <boost/statechart/state_machine.hpp> //State machines
//#include <boost/graph/graphviz.hpp> //all kinds of graphs and algorithms on them
//#include <boost/circular_buffer.hpp> //ring-buffer
//#include <boost/unordered/unordered_set.hpp> //unordered associative sets and maps
///--- Output Input ---
//#include <boost/algorithm/string.hpp> //algorithms on strings
//#include <boost/program_options.hpp> //for generating key-value files like user config!!!
//#include <boost/serialization/array.hpp> //Serialization for persistence and marshalling, from Robert Ramey
//#include <boost/format.hpp> //like printf, but: supports all user-defined types
//#include <boost/lexical_cast.hpp> //convert types to string
//#include <boost/log/core.hpp> //Logging
//#include <boost/regex.hpp> //RegEx
//#include <boost/xpressive/xpressive.hpp> //RegEx that works in code
///--- scripting ---
//#include <python.h> //requires pythong to be linked to the project!
//#include <boost/python.hpp> //allows you to quickly and seamlessly expose C++ classes functions and objects to Python, and vice-versa, using no special tools -- just your C++ compiler
///--- utility ---
//#include <boost/date_time.hpp> //time
//#include <boost/timer.hpp> //Event timer, progress timer, and progress display classes
//#include <boost/system/config.hpp> //operating system support
//#include <boost/utility.hpp> //templates for classes and iterators
///--- threading ---
//#include <boost/thread.hpp> //multithreading
//#include <boost/process.hpp> //generate processes

//#include <boost/static_assert.hpp> //compile time assertion
//#include <boost/pool/pool.hpp> //memory pool management
//#include <boost/hana.hpp> //(requires strict C++14) C++ template metaprogramming. A programm can use a programm as input? //http://www.boost.org/doc/libs/1_64_0/libs/hana/doc/html/index.html
//#include <boost/msm/common.hpp> //UML state machines
//#include <boost/function.hpp> //deferred function calls or callbacks
//#include <boost/asio.hpp> //network
//#include <boost/dynamic_bitset.hpp> //runtime sized std::bitset
//#include <boost/exception/all.hpp> //exceptions transport between threads
//#include <boost/flyweight.hpp> //allowing for the management of large amounts of entities within reasonable memory limits.

#endif