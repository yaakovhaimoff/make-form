#pragma once

// class template:
template <class T>
class RangeValidator : public BaseFieldValidators<T>
{
public:
    RangeValidator(const int, const int);
    bool validate(const int&, const int&)override;

private:
    int m_min, m_max;
};
//________________
template <class T>
bool RangeValidator<T>::validate(const int& year, const int&)
{
    return year >= m_min && year <= m_max;
}
