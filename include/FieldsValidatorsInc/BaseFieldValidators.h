#pragma once 

template <class T >
class BaseFieldValidators
{
public:
	BaseFieldValidators(){}
	virtual bool validate(const T&, const T&) { return true; }
};