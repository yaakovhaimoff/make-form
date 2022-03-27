#pragma once 
#include "BaseFieldValidator.h"

// ID Validator class - inherite from template BaseFieldValidator class 
class IDValidator : public BaseFieldValidator<uint32_t>
{
public:
	IDValidator() : BaseFieldValidator("Wrong control digit\n") {}
	bool validate(const uint32_t&)const;
};