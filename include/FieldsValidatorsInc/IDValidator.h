#pragma once 
#include "FieldsValidatorsInc/BaseFieldValidators.h"
#include <string>
#include <cstdint> // for uint32_t

class IDValidator : public BaseFieldValidators<uint32_t>
{
public:
	IDValidator() {}
	bool validate(const uint32_t&)const;
	void printError()const { std::cout << std::string(N - 30, ' ') << "Wrong control digit\n" << std::string(N, '-'); }
};