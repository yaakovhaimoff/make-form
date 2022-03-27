#include "IdValidator.h"

// verify check digit of ID input
//_________________________________________________
bool IDValidator::validate(const uint32_t& id)const
{
    std::string num = std::to_string(id);
    // Make sure ID is formatted properly
    if (num.size() != 9)
        return false;

    int sum = 0, incNum;
    for (int i = 0; i < num.size(); i++)
    {
        int number = i % 2 == 0 ? 1 : 2;
        incNum = number * ((int)num[i] - 48);  // Multiply number by 1 or 2
        sum += (incNum > 9) ? incNum - 9 : incNum;  // Sum the digits up and add to total
    }
    return sum % 10 == 0;
}
