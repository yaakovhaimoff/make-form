#pragma once 
#include "FormValidatorsInc/FormValidators.h"
#include "FieldInc/BaseField.h"

template <class T1, class T2>
class Faculty2YearValidator : public FormValidators
{
public:
	Faculty2YearValidator(T1* faculty, T2* year) : m_faculty(faculty), m_year(year) {}
	bool validateForm()const override;

private:
	T1* m_faculty = nullptr;
	T2* m_year = nullptr;
};
//___________________________
template <class T1, class T2>
bool Faculty2YearValidator<T1, T2>::validateForm()const
{
	std::cout << "\nm_faculty->getElement(): " << m_faculty->getElement() << std::endl;
	std::cout << "\nm_year->getElement(): " << m_year->getElement() << std::endl;
	if (m_faculty->getElement() <= 1)
		return  m_year->getElement() <= 4;
	else if(m_faculty->getElement() <= 2)
		return m_year->getElement() <= 3;
	else if(m_faculty->getElement() <= 3)
		return m_year->getElement() <= 7;
}
