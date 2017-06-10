#pragma once

#if false

///Standard Libararies
///http://en.cppreference.com/w/cpp/header
///===================
///---Containers---
#include <algorithm> 	//Algorithms that operate on containers e.g. std_foreach
#include <iterator> 	//Container iterators
//#include <execution>	//(C++17) Predefined execution policies for parallel versions of the algorithms 
#include <array>		//(since C++11) 	std::array container
#include <vector> 		//std::vector container //dynamic array
#include <list> 		//std::list container //doubly linked list
//#include <forward_list> //(since C++11) 	std::forward_list container //singly linked list
//#include <stack> 		//std::stack container adaptor //LIFO
//#include <queue> 		//std::queue and std::priority_queue container adaptors //FIFO
//#include <deque> 		//std::deque container //double sided queue
//#include <set> 			//std::set and std::multiset associative containers
//#include <map> 			//std::map and std::multimap associative containers
//#include <unordered_set>//(since C++11) 	std::unordered_set and std::unordered_multiset unordered associative containers
//#include <unordered_map>//(since C++11) 	std::unordered_map and std::unordered_multimap unordered associative containers
///---Math---
#include <cmath> 		//Common mathematics functions
//#include <complex> 		//Complex number type
//#include <valarray> 	//Class for representing and manipulating arrays of values
#include <random>		//(since C++11) 	Random number generators and distributions
///---utility---
//#include <cstdlib>		//General purpose utilities: program control, dynamic memory allocation, random numbers, sort and search
//#include <utility>		//Various utility components
#include <chrono>		//(since C++11) time utilities
///---Exception handling---
//#include <exception>	//Exception handling utilities
//#include <stdexcept>	//Standard exception objects
///---possibly usefull---
//#include <cstdarg>		//variable-lengh argument-lists for functions (variadic functions)
//#include <bitset>		//Various utility components
//#include <regex>		//(since C++11) 	Classes, algorithms and iterators to support regular expression processing
///---In-/Output---
#include <iostream>		//several standard stream objects 
#include <iomanip>		//formatting IO
#include <fstream>		//filestream
#include <sstream>		//stringstream
#include <cstring> 		//various narrow character string handling functions
#include <cwchar> 		//various wide and multibyte string handling functions
//#include <cuchar>		//(since C++11) C - style Unicode character conversion functions
//#include <filesystem> //(since C++17) 	std::path class and supporting functions
///---parallelism---
//#include <atomic>				//(since C++11) 	Atomic operations library
//#include <thread>				//(since C++11) 	std::thread class and supporting functions
//#include <mutex>				//(since C++11) 	mutual exclusion primitives
//#include <shared_mutex>			//(since C++14) 	shared mutual exclusion primitives
//#include <future>				//(since C++11) 	primitives for asynchronous computations
//#include <condition_variable>	//(since C++11) 	thread waiting conditions

#endif