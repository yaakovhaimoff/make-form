#pragma once
#include <vector>
#include "FieldInc/BaseField.h"
#include "FieldsValidatorsInc/BaseFieldValidators.h"
#include "FacultyValue.h"
#include <iostream>

// class template:
template <class T>
class Field : public BaseField
{
public:
    Field(const std::string message) : BaseField(message){}
    void addValidator(const BaseFieldValidators<T>*);
    bool checkValidator();
    void readElement() override;
    void printElement()const;
    void printError()const;
private:
    T m_element;
    std::vector<BaseFieldValidators<T>*> m_validator;
    //BaseFieldValidators<T>* m_validator;
};
//________________
template <class T>
void Field<T>::addValidator(const BaseFieldValidators<T>* validator)
{
    m_validator.emplace_back(validator);
}
