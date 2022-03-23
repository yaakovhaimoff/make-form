#pragma once
#include "FieldsValidatorsInc/BaseFieldValidators.h"
#include "FacultyValue.h"

// class template:
template <class T>
class RangeValidator : public BaseFieldValidators<T>
{
public:
    RangeValidator(const T& min, const T& max) : m_min(min), m_max(max) {}
    bool validate(const T&)const;
    void printError()const { std::cout << std::string(N - 30, ' ') << "Out of range\n" << std::string(N, '-'); }

private:
    T m_min{}, m_max{};
};
//________________
template <class T>
bool RangeValidator<T>::validate(const T& value)const
{
    return value >= m_min && value <= m_max;
}
