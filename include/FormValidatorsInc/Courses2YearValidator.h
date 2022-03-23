#pragma once 
#include "FormValidatorsInc/FormValidators.h"

template <class T1, class T2>
class Courses2YearValidator : public FormValidators
{
public:
	Courses2YearValidator(T1* course, T2* year):m_course(course), m_year(year){}
	bool validateForm()const override;

private:
	T1* m_course = nullptr;
	T2* m_year = nullptr;
};
//___________________________
template <class T1, class T2>
bool Courses2YearValidator<T1, T2>::validateForm()const
{
	std::cout << "\nm_course->getElement(): " << m_course->getElement() << std::endl;
	if (m_year->getElement()<=2)
		return m_course->getElement() <=6;
	else if (m_year->getElement() <= 4)
		return m_course->getElement() <=10;
	else if (m_year->getElement() <= 7)
		return m_course->getElement() <=8;
}