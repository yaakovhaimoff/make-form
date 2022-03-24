#pragma once 
#include "FormValidatorsInc/FormValidators.h"
#include "FieldInc/BaseField.h"

template <class T1, class T2>
class Faculty2YearValidator : public FormValidators
{
public:
	Faculty2YearValidator(T1* faculty, T2* year) : FormValidators("Faculty and year don't match"),
		m_faculty(faculty), m_year(year) {}
	bool validateForm()const override;

private:
	T1* m_faculty = nullptr;
	T2* m_year = nullptr;
};
//___________________________
template <class T1, class T2>
bool Faculty2YearValidator<T1, T2>::validateForm()const
{
	if ((m_faculty->getElement() == CS && m_year->getElement() <= 4) ||
		(m_faculty->getElement() == Liteture && m_year->getElement() <= 3) ||
		(m_faculty->getElement() == Medicine && m_year->getElement() == 7))
	{
		//setFormValid(true);
		return true;
	}
	m_faculty->setValid(false);
	m_year->setValid(false);
	return false;
}