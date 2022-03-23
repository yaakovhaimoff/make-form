#pragma once 
#include "FormValidatorsInc/FormValidators.h"
#include "FieldInc/BaseField.h"

template <class T1, class T2>
class Faculty2YearValidator : public FormValidators
{
public:
	Faculty2YearValidator(T1* faculty, T2* year) : m_faculty(faculty), m_year(year) {}

private:
	T1* m_faculty = nullptr;
	T2* m_year = nullptr;
};