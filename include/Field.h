#pragma once
#include "BaseField.h"
#include "BaseFieldValidator.h"

// template Field class
template <class T>
class Field : public BaseField
{
public:
	Field(const std::string message) : BaseField(message) {}

	void addValidator(BaseFieldValidator<T>*);
	bool checkValidator();
	void readElement();
	void printElement()const;
	void printError()const;
	T getElement()const { return m_element; }

private:
	T m_element = {};
	std::vector<BaseFieldValidator<T>*> m_validator;
};

// add new validator to field
template <class T>
void Field<T>::addValidator(BaseFieldValidator<T>* validator)
{
	m_validator.emplace_back(validator);
}

//________________
template <class T>
bool Field<T>::checkValidator()
{
	for (auto validator : m_validator)
		if (validator->validate(m_element))
			setValid(true);

	return getValid();
}

//________________
template <class T>
void Field<T>::readElement()
{
	show();
	std::cout << std::endl;
	std::cin >> m_element;
}

//________________
template <class T>
void Field<T>::printElement()const
{
	std::cout << m_element;
}

//________________
template <class T>
void Field<T>::printError()const
{
	for (auto validator : m_validator)
		validator->printError();
}