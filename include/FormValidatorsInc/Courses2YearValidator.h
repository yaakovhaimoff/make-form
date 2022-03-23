#pragma once 
#include "FormValidatorsInc/FormValidators.h"

template <class T1, class T2>
class Courses2YearValidator : public FormValidators
{
public:
	Courses2YearValidator(T1* course, T2* year):m_course(course), m_year(year){}

private:
	T1* m_course = nullptr;
	T2* m_year = nullptr;
};

