#pragma once 
#include <vector>
#include "FieldInc/BaseField.h"

class FormValidators
{
public:
	FormValidators() = default;
	~FormValidators() = default;
	virtual bool validateForm()const = 0;
};

