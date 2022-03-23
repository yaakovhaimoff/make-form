#pragma once
#include "FieldsValidatorsInc/BaseFieldValidators.h"

// class template:
template <class T>
class MinValidator : public BaseFieldValidators<T>
{
public:
	MinValidator(const T&);
	MinValidator() = default;
	bool validate(const T&)const override;

private:
	T m_minElement{};
};
//________________
template <class T>
MinValidator<T>::MinValidator(const T& element)
	: BaseFieldValidators<T>("Out of range\n"), m_minElement(element)
{}
//________________
template <class T>
bool MinValidator<T>::validate(const T& numOfCousre)const
{
	return m_minElement < numOfCousre;
}
