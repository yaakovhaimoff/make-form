#pragma once

#include "FieldInc/BaseField.h"
#include "FormValidatorsInc/FormValidators.h"
#include <vector>

class Form 
{
public:
	Form(){}
	void addField(const BaseField*);
	void addValidator(const FormValidators*);
	bool validateForm();
	void fillForm();
	
private:
	std::vector<BaseField*> m_baseField;
	std::vector<FormValidators*> m_formValidators;
	
};