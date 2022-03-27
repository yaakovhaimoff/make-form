
#pragma once 
#include "BaseField.h"
#include "Macros.h"

// Form validator - Abstarct class
class FormValidator
{
public:
	FormValidator(std::string errorMessage) : m_errorMessage(errorMessage),
		m_formValid(false) {}
	virtual ~FormValidator() = default;

	void printFormError()const { std::cout << m_errorMessage; }
	virtual bool validateForm() = 0;
	virtual bool getFormValid() { return m_formValid; }
	virtual void setFormValid(const bool formValid) { m_formValid = formValid; }
private:
	std::string m_errorMessage;
	bool m_formValid;
};