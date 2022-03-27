#pragma once
#include "BaseFieldValidator.h"

// template Minimun Validator class
template <class T>
class MinValidator : public BaseFieldValidator<T>
{
public:
	MinValidator(const T&);
	MinValidator() = default;

	bool validate(const T&)const override;

private:
	T m_minElement = {};
};

//________________
template <class T>
MinValidator<T>::MinValidator(const T& element)
	: BaseFieldValidator<T>("Out of range\n"), m_minElement(element)
{}
//________________
template <class T>
bool MinValidator<T>::validate(const T& numOfCousre)const
{
	return m_minElement <= numOfCousre;
}
