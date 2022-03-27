#include "FacultyValue.h"

//________________________________________________________________
std::istream& operator>>(std::istream& input, FacultyValue& value)
{
	int num;
	input >> num;
	value.setValue(num);
	return input;
}
//__________________________________________
void FacultyValue::setValue(const int value)
{
	m_value = value;
}
//_______________________________________________________________________
std::ostream& operator<<(std::ostream& output, const FacultyValue& value)
{
	output << value.getStrValue();
	return output;
}
//__________________________________________
std::string FacultyValue::getStrValue()const
{
	switch (m_value)
	{
	case 1:
		return "Computer Science";
	case 2:
		return "Medicine";
	case 3:
		return "Literature";
	default:
		return std::to_string(m_value);
	}
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