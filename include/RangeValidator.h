#pragma once
#include "BaseFieldValidator.h"
#include "FacultyValue.h"

// template class of Range Validator
template <class T>
class RangeValidator : public BaseFieldValidator<T>
{
public:
	RangeValidator(const T&, const T&);
	bool validate(const T&)const;

private:
	T m_min = {}, m_max = {};
};
// Range Validator constructor
//________________
template <class T>
RangeValidator<T>::RangeValidator(const T& min, const T& max)
	: BaseFieldValidator<T>("Out of range\n"), m_min(min), m_max(max)
{}
//________________
template <class T>
bool RangeValidator<T>::validate(const T& value)const
{
	return value >= m_min && value <= m_max;
}
