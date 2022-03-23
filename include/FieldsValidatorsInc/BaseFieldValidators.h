#pragma once 
#include <iostream>

template <class T >
class BaseFieldValidators
{
public:
	BaseFieldValidators(){}
	virtual ~BaseFieldValidators() = default;
	virtual bool validate(const T&) = 0;
	virtual void printError()const = 0;
};