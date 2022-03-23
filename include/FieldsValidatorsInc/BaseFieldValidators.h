#pragma once 

template <class T >
class BaseFieldValidators
{
public:
	BaseFieldValidators(){}
	virtual ~BaseFieldValidators() = default;
	virtual bool validate(const T&) = 0;

};