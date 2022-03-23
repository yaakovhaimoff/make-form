#pragma once 
#include <iostream>
#include <string>

const int N = 60;

template <class T >
class BaseFieldValidators
{
public:
	BaseFieldValidators(const std::string errorMessage) : m_errorMessage(errorMessage) { ; }
	virtual ~BaseFieldValidators() = default;
	virtual bool validate(const T&)const = 0;
	void printError()const { std::cout << std::string(N - 30, ' ')  << m_errorMessage << std::string(N, '-') << std::endl; }

private :
	std::string m_errorMessage;
};