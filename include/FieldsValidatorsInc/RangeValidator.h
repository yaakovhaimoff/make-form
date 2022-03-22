#pragma once
#include "FieldsValidatorsInc/BaseFieldValidators.h"

// class template:
template <class T>
class RangeValidator : public BaseFieldValidators<T>
{
public:
    RangeValidator(const int, const int);
    bool validate(const T&, const T&)override;

private:
    int m_min, m_max;
};
//________________
template <class T>
bool RangeValidator<T>::validate(const T& year, const T&)
{
    //return year >= m_min && year <= m_max;
    return true;
}
////________________
//template <class T>
//bool operator <=(const T& year1, const int year2)
//{
//    return (int*)year1 <= year2;
//}
////________________
//template <class T>
//bool operator >=(const T& year1, const int year2)
//{
//    return (int*)year1 >= year2;
//}