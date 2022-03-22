#pragma once 
#include "FormValidatorsInc/FormValidators.h"

template <class T1, class T2>
class Courses2YearValidator : public FormValidators
{
public:
	Courses2YearValidator(const BaseField* field1, const BaseField* field2) : FormValidators(field1, field2){}
};