#include "Form.h"

//___________________________________
void Form::addField(BaseField* field)
{
	m_baseField.emplace_back(field);
}
//____________________________________________________
void Form::addValidator(FormValidators* formValidator)
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
	{
		if (!field->getValid())
		{
			field->readElement();
		}
	}
}

//_______________________________________________________________________
std::ostream& operator<<(std::ostream& output, const Form& form)
{
	for (size_t i = 0; i < form.fieldsNum(); i++)
	{
		form.printField(i);
	}
	return output;
}

void Form::printField(size_t place)const
{
	if (!m_baseField[place]->getValid())
	{
		m_baseField[place]->show();
		std::cout << " = ";
		m_baseField[place]->printElement();
		m_baseField[place]->printError();
	}
}