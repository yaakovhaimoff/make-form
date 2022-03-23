#pragma once
#include "FieldsValidatorsInc/BaseFieldValidators.h"
#include "FacultyValue.h"

// class template:
template <class T>
class RangeValidator : public BaseFieldValidators<T>
{
public:
    RangeValidator(const int min, const int max) : m_min(min), m_max(max) {}
    bool validate(const T&)override;
    void printError()const { std::cout << "Out of range\n"; }

private:
    int m_min, m_max;
};
//________________
template <class T>
bool RangeValidator<T>::validate(const T& value)
{
    return value > m_min && value < m_max;
}
