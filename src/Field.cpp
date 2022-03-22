#include "FieldInc/Field.h"

//________________
template <class T>
bool Field<T>::checkValidator()
{
	m_validator->validator(m_element);
}
//________________
template <class T>
void Field<T>::readElement()
{
	show();
	std::cin >> m_element;
}