#include "FacultyValue.h"

//________________________________________________________________
std::istream &operator>>(std::istream& input, FacultyValue& value)
{
	int num;
	input >> num;
	value.setValue(num);
	return input;
}
//_______________________________________________________________________
std::ostream& operator<<(std::ostream& output, const FacultyValue& value)
{
	output << value.getValue();
	return output;
}
//__________________________________________
void FacultyValue::setValue(const int value)
{
	m_value = value;
}
//_______________________________
int FacultyValue::getValue()const
{
	return m_value;
}
//_________________________________________________
void FacultyValue::printName(std::string name)const
{
	std::cout << name;
}
//__________________________________________________________________
bool operator <=(const FacultyValue& value, const FacultyValue& max)
{
	return value.getValue() <= max.getValue();
}
//__________________________________________________________________
bool operator >=(const FacultyValue& value, const FacultyValue& min)
{
	return value.getValue() >= min.getValue();
}
//______________________________________________________________________
bool operator ==(const FacultyValue& value1, const FacultyValue& value2)
{
	return value1.getValue() == value2.getValue();
}