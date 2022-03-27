#include "Form.h"

// add new Field
//___________________________________
void Form::addField(BaseField* field)
{
	m_baseField.emplace_back(field);
}
// add new validator
//___________________________________________________
void Form::addValidator(FormValidator* formValidator)
{
	m_formValidators.emplace_back(formValidator);
}
//_______________________
bool Form::validateForm()
{
	if (validateFields())
		validateFormWithValidator();
	return m_validForm;
}
//_________________________
bool Form::validateFields()
{
	m_validForm = true;
	for (auto field : m_baseField)
	{
		if (field->getValid())
			continue;
		else if (!field->checkValidator())
			m_validForm = false;
	}
	return m_validForm;
}
//____________________________________
void Form::validateFormWithValidator()
{
	for (auto formValidator : m_formValidators)
	{
		if (!formValidator->validateForm())
			m_validForm = false;
	}
}
//___________________
void Form::fillForm()
{
	for (auto field : m_baseField)
	{
		if (!field->getValid())
			field->readElement();
	}
}
//______________________________________________________________
std::ostream& operator<<(std::ostream& output, const Form& form)
{
	for (size_t i = 0; i < form.fieldsNum(); i++)
		form.printField(i);
	form.printFormErrors();
	return output;
}
//______________________________________
void Form::printField(size_t place)const
{
	m_baseField[place]->show();
	std::cout << " = ";
	m_baseField[place]->printElement();

	if (!m_baseField[place]->getValid() && checkFormValidators())
		m_baseField[place]->printError();
	else
		std::cout << std::endl << std::string(N, '-') << std::endl;
}
//_______________________________
void Form::printFormErrors()const
{
	for (auto formValidator : m_formValidators)
		if (formValidator->getFormValid())
			formValidator->printFormError();
}
//___________________________________
bool Form::checkFormValidators()const
{
	for (auto formValidator : m_formValidators)
		if (formValidator->getFormValid())
			return false;
	return true;
}