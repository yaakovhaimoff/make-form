#pragma once
#include "FieldsValidatorsInc/BaseFieldValidators.h"

// class template:
template <class T>
class MinValidator : public BaseFieldValidators<T>
{
public:
    MinValidator(T element) : m_minElement(element){}
    bool validate(const T&)override;

private:
    T m_minElement;
};
//________________
template <class T>
bool MinValidator<T>::validate(const T& numOfCousre)
{
    return m_minElement < numOfCousre;
}
