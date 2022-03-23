#pragma once 
#include "FieldsValidatorsInc/BaseFieldValidators.h"
#include <string>
#include <cstdint> // for uint32_t

class IDValidator : public BaseFieldValidators<uint32_t>
{
public:
	IDValidator() {}
	bool validate(const uint32_t&)override;
	void printError()const { std::cout << "Wrong control digit\n"; }
};