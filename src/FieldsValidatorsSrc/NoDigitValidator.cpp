#include "FieldsValidatorsInc/NoDigitValidator.h"

bool NoDigitValidator::validate(const std::string& name)const
{
    for (int i = 0; i < name.size(); i++)
        if (isdigit(name[i]))
            return false;
    return true;
}
