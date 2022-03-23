#pragma once
#include <iostream>
#include <string>

class FacultyValue
{
public:
	FacultyValue() : m_value(0) { ; }
	~FacultyValue() {}
	void setValue(const int);
	int getValue()const;
	void printName(const std::string)const;

private:
	int m_value =0;
};
std::istream &operator>>(std::istream&, FacultyValue&);
std::ostream& operator<<(std::ostream&, const FacultyValue&);
bool operator <(const FacultyValue& value, const int max)
{
	return value.getValue() <= max;
}
bool operator >(const FacultyValue& value, const int min)
{
	return value.getValue() >= min;
}