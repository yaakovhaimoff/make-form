#pragma once
#include <vector>
#include "FieldInc/BaseField.h"
#include "FieldsValidatorsInc/BaseFieldValidators.h"

// class template:
template <class T>
class Field : public BaseField
{
public:
    Field(const std::string message) : BaseField(message){}
    void addValidator(const BaseFieldValidators<T>*);

private:
    T m_element;
    std::vector<BaseFieldValidators<T>*> m_validator;
};

template <class T>
void Field<T>::addValidator(const BaseFieldValidators<T>* validator)
{
    m_validator.push_back(validator);
}
