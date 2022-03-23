#pragma once
#include <iostream>
#include <string>

class FacultyValue
{
public:
	FacultyValue() = default;
	FacultyValue(const int val) : m_value(val) { ; }
	~FacultyValue() {}
	void setValue(const int);
	int getValue()const;
	void printName(const std::string)const;

private:
	int m_value;
};
std::istream &operator>>(std::istream&, FacultyValue&);
std::ostream& operator<<(std::ostream&, const FacultyValue&);
bool operator <=(const FacultyValue&, const FacultyValue&);
bool operator >=(const FacultyValue&, const FacultyValue&);