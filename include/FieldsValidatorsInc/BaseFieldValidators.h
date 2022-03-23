#pragma once 
#include <iostream>

const int N = 60;

template <class T >
class BaseFieldValidators
{
public:
	BaseFieldValidators(){}
	virtual ~BaseFieldValidators() = default;
	virtual bool validate(const T&)const = 0;
	virtual void printError()const = 0;
};