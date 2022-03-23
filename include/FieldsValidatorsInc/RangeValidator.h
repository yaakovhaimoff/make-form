#pragma once
#include "FieldsValidatorsInc/BaseFieldValidators.h"
#include "FacultyValue.h"

// class template:
template <class T>
class RangeValidator : public BaseFieldValidators<T>
{
public:
    RangeValidator(const T&, const T&);
    bool validate(const T&)const;

private:
    T m_min, m_max;
    //T m_min{}, m_max{};
};
//________________
template <class T>
RangeValidator<T>::RangeValidator(const T& min, const T& max)
    : BaseFieldValidators<T>("Out of range\n"), m_min(min), m_max(max) {}
//________________
template <class T>
bool RangeValidator<T>::validate(const T& value)const
{
    return value >= m_min && value <= m_max;
}
