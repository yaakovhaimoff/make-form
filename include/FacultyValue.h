#pragma once
#include <iostream>
#include <string>

class FacultyValue
{
public:
	FacultyValue(const int val) : m_value(val) { ; }
	FacultyValue() = default;
	~FacultyValue() {}
	void setValue(const int);
	int getValue()const;
	void printName(const std::string)const;

private:
	int m_value =0;
};
std::istream &operator>>(std::istream&, FacultyValue&);
std::ostream& operator<<(std::ostream&, const FacultyValue&);
bool operator <=(const FacultyValue& value, const FacultyValue& max)
{
	return value.getValue() <= max.getValue();
}
bool operator >=(const FacultyValue& value, const FacultyValue& min)
{
	return value.getValue() >= min.getValue();
}