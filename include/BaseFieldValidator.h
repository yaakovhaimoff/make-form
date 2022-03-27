#pragma once 
#include <iostream>
#include <string>
#include <cstdint> // for uint32_t
#include "Macros.h"

// template Base Field Validator class - abstract class
template <class T >
class BaseFieldValidator
{
public:
	BaseFieldValidator(const std::string errorMessage) : m_errorMessage(errorMessage) { ; }
	virtual ~BaseFieldValidator() = default;

	virtual bool validate(const T&)const = 0;
	void printError()const {
		std::cout << std::string(30, ' ')
			<< m_errorMessage << std::string(N, '-') << std::endl;
	}

private:
	std::string m_errorMessage;
};