#pragma once 
#include "FormValidator.h"

//template class of courses to year validator - get two fields 
template <class T1, class T2>
class Courses2YearValidator : public FormValidator
{
public:
	Courses2YearValidator(T1* course, T2* year) : FormValidator("Course and year don't match\n"),
		m_course(course), m_year(year) {}

	bool validateForm() override;
	bool checkRange(int, int, int);		//Range check
private:
	T1* m_course = nullptr;
	T2* m_year = nullptr;
};
//___________________________
template <class T1, class T2>
bool Courses2YearValidator<T1, T2>::validateForm()
{
	if ((checkRange(2, MaxLitetureYear, m_year->getElement()) && checkRange(MinCoursesPerYear, MaxFirst, m_course->getElement())) ||
		(checkRange(3, MaxCsYear, m_year->getElement()) && checkRange(MinCoursesPerYear, MaxSecond, m_course->getElement())) ||
		(checkRange(5, MaxMedicineYear, m_year->getElement()) && checkRange(MinCoursesPerYear, MaxThird, m_course->getElement())))
	{
		setFormValid(false);
		return true;
	}
	// setting setFormValid true, to show the form error message 
	setFormValid(true);
	// setting the fields to false to read them again
	m_course->setValid(false);
	m_year->setValid(false);
	return false;
}
//___________________________
template <class T1, class T2>
bool Courses2YearValidator<T1, T2>::checkRange(int min, int max, int value)
{
	return (value >= min && value <= max);
}