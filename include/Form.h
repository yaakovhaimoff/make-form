#pragma once

#include "FieldInc/BaseField.h"
#include "FormValidatorsInc/FormValidators.h"
#include <vector>

class Form 
{
public:
	Form() : m_validForm(false) {}
	void addField(BaseField*);
	void addValidator(FormValidators*);
	bool validateForm();
	void fillForm();
	void printField(size_t place)const;
	size_t fieldsNum()const { return m_baseField.size(); }
	
private:
	std::vector<BaseField*> m_baseField;
	std::vector<FormValidators*> m_formValidators;
	bool m_validForm;
};
std::ostream& operator<<(std::ostream&, const Form&);
