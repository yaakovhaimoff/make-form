#include "Form.h"

//_________________________________________
void Form::addField(const BaseField* field)
{
	m_baseField.emplace_back(field);
}
//__________________________________________________________
void Form::addValidator(const FormValidators* formValidator)
{
	m_formValidators.emplace_back(formValidator);
}
//_______________________
bool Form::validateForm()
{
	bool validate = true;
	for (auto field : m_baseField)
		if (!field->checkValidator())
			validate = false;
	return validate;
}
//___________________
void Form::fillForm()
{
	for (auto field : m_baseField)
		if (!field->getValid())
		{
			field->readElement();
		}
}
