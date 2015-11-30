// Unit.hpp

#ifndef UINT_HPP_INCLUDED
#define UINT_HPP_INCLUDED

#include <iostream>
#include <string>

template <class T>
bool are_equal(T a, T b)
{
	return a == b;
}

template <class T>
bool verify(T got, T expected, const std::string& message)
{
	if (are_equal(got, expected))
	{
		std::cout << "Passed: " << message << std::endl;
		return true;
	}
	std::cout << "Failed! Expected: " << got << " Got: " << expected <<
		" - " << message << std::endl;
	return false;
}

#endif // UINT_HPP_INCLUDED