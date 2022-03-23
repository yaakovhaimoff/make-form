#pragma once
#include <vector>
#include "FieldInc/BaseField.h"
#include "FieldsValidatorsInc/BaseFieldValidators.h"
#include <iostream>

// class template:
template <class T>
class Field : public BaseField
{
public:
	Field(const std::string message) : BaseField(message){}
	void addValidator(BaseFieldValidators<T>*);
	bool checkValidator();
	void readElement();
	void printElement()const;
	void printError()const;
	T getElement()const { return m_element; }

private:
	T m_element {};
	std::vector<BaseFieldValidators<T>*> m_validator;
};
//________________
template <class T>
void Field<T>::addValidator(BaseFieldValidators<T>* validator)
{
	m_validator.emplace_back(validator);
}
//________________
template <class T>
bool Field<T>::checkValidator()
{
	for (auto validator : m_validator)
		if (validator->validate(m_element))
		{
			setValid(true);
			return true;
		}
	return false;
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