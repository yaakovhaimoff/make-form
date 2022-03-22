#pragma once 
#include "FormValidatorsInc/FormValidators.h"
#include "FieldInc/BaseField.h"

template <class T1, class T2>
class Faculty2YearValidator : public FormValidators
{
public:
	Faculty2YearValidator(const BaseField* field1, const BaseField* field2) : FormValidators(field1, field2) {}
};