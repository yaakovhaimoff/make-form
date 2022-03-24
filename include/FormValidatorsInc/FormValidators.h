#pragma once 
#include <vector>
#include <string>
#include <iostream>
#include "FieldInc/BaseField.h"

const int CS = 1;
const int Liteture = 2;
const int Medicine = 3;
const int MaxFirstYear = 6;
const int MaxSecondYear = 10;
const int MaxThirdYear = 8;

class FormValidators
{
public:
	FormValidators(std::string errorMessage) : m_errorMessage(errorMessage),
		m_formValid(false) {}
	void show()const { std::cout << m_errorMessage; }
	virtual bool validateForm()const = 0;
	virtual bool getFormValid() { return m_formValid; }
	virtual void setFormValid(const bool formValid) { m_formValid = formValid; }
	virtual ~FormValidators() = default;

private:
	std::string m_errorMessage;
	bool m_formValid;
};

