#pragma once 
#include "FieldsValidatorsInc/BaseFieldValidators.h"
#include <string>

class NoDigitValidator : public BaseFieldValidators<std::string>
{
public:
	NoDigitValidator() {}
	bool validate(const std::string&)const;
	void printError()const { std::cout << std::string(N -30, ' ')  << "Can't contain digits\n" << std::string(N, '-'); }
};