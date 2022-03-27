#pragma once 
#include "BaseFieldValidator.h"

// No digit Validator class - inherite from template BaseFieldValidator class 
class NoDigitValidator : public BaseFieldValidator<std::string>
{
public:
	NoDigitValidator() : BaseFieldValidator("Can't contain digits\n") {}
	bool validate(const std::string&)const;
};