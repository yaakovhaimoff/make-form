#pragma once
#include "BaseField.h"
#include "FormValidator.h"

// Form class - holds 2 vectors of Fields & Validators
class Form
{
public:
	Form() : m_validForm(false) {}

	void addField(BaseField*);
	void addValidator(FormValidator*);

	bool validateForm();	//Form validation functions
	bool validateFields();
	void validateFormWithValidator();
	bool checkFormValidators()const;

	void fillForm();
	void printField(size_t place)const;
	void printFormErrors()const;
	size_t fieldsNum()const { return m_baseField.size(); }

private:
	std::vector<BaseField*> m_baseField;
	std::vector<FormValidator*> m_formValidators;
	bool m_validForm;
};

// Form Ostream operator
std::ostream& operator<<(std::ostream&, const Form&);
