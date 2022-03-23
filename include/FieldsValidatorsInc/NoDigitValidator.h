#pragma once 
#include "FieldsValidatorsInc/BaseFieldValidators.h"
#include <string>

class NoDigitValidator : public BaseFieldValidators<std::string>
{
public:
	NoDigitValidator() : BaseFieldValidators("Can't contain digits\n"){}
	bool validate(const std::string&)const;
};