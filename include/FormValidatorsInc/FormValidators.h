#pragma once 
#include <vector>
#include "FieldInc/BaseField.h"

class FormValidators
{
public:
	FormValidators(const BaseField*, const BaseField*);
	~FormValidators() = default;

private:
	std::vector<BaseField*> m_baseField;
};
FormValidators::FormValidators(const BaseField* field1, const BaseField* field2)
{
	m_baseField.emplace_back(field1);
	m_baseField.emplace_back(field2);
}
