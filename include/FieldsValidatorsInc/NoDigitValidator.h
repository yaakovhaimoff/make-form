#pragma once 
#include "FieldsValidatorsInc/BaseFieldValidators.h"
#include <string>

class NoDigitValidator : public BaseFieldValidators<std::string>
{
public:
	NoDigitValidator() {}
	bool validate(const std::string&, const std::string&);

};