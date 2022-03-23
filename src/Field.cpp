#include "FieldInc/Field.h"

//________________
template <class T>
bool Field<T>::checkValidator()
{
	if (m_validator->validator(m_element))
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
	m_validator->printError();
}