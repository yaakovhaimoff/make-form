#pragma once 
#include "FieldsValidatorsInc/BaseFieldValidators.h"
#include <string>

class NoDigitValidator : public BaseFieldValidators<std::string>
{
public:
	NoDigitValidator() {}
	bool validate(const std::string&);
	void printError()const { std::cout << "Can't contain digits!\n"; }


};