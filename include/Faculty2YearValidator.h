#pragma once 
#include "FormValidator.h"
#include "BaseField.h"

//template class of courses to year validator - get two fields 
template <class T1, class T2>
class Faculty2YearValidator : public FormValidator
{
public:
	Faculty2YearValidator(T1* faculty, T2* year) : FormValidator("Faculty and year don't match\n"),
		m_faculty(faculty), m_year(year) {}

	bool validateForm() override;
	bool yearInRange(int);		//Range of year check

private:
	T1* m_faculty = nullptr;
	T2* m_year = nullptr;
};

//___________________________
template <class T1, class T2>
bool Faculty2YearValidator<T1, T2>::validateForm()
{
	if ((m_faculty->getElement() == CS && yearInRange(MaxCsYear)) ||
		(m_faculty->getElement() == Liteture && yearInRange(MaxLitetureYear)) ||
		(m_faculty->getElement() == Medicine && yearInRange(MaxMedicineYear)))
	{
		setFormValid(false);
		return true;
	}
	// setting setFormValid true, to show the form error message 
	setFormValid(true);
	// setting the fields to false to read them again
	m_faculty->setValid(false);
	m_year->setValid(false);
	return false;
}
//___________________________
template <class T1, class T2>
bool Faculty2YearValidator<T1, T2>::yearInRange(int max)
{
	return (m_year->getElement() <= max);
}