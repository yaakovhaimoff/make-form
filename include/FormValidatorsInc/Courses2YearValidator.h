#pragma once 
#include "FormValidatorsInc/FormValidators.h"

template <class T1, class T2>
class Courses2YearValidator : public FormValidators
{
public:
	Courses2YearValidator(T1* course, T2* year) : FormValidators("Course and year don't match\n"),
		m_course(course), m_year(year) {}
	bool validateForm() override;

private:
	T1* m_course = nullptr;
	T2* m_year = nullptr;
};
//___________________________
template <class T1, class T2>
bool Courses2YearValidator<T1, T2>::validateForm()
{
	if ((m_year->getElement() <= 2 && m_course->getElement() <= MaxFirstYear) ||
		(m_year->getElement() <= 4 && m_course->getElement() <= MaxSecondYear) ||
		(m_year->getElement() <= 7 && m_course->getElement() <= MaxThirdYear))
	{
		setFormValid(false);
		return true;
	}
	std::cout << "heed\n";
	setFormValid(true);
	m_course->setValid(false);
	m_year->setValid(false);
	return false;
}