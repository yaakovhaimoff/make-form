#pragma once
#include <iostream>
#include <string>

class FacultyValue
{
public:
	FacultyValue() { ; }
	~FacultyValue() {}
	void setValue(const int);
	int getValue()const;
	void printName(const std::string)const;

private:
	int m_value;
};
std::istream &operator>>(std::istream&, FacultyValue&);
std::ostream& operator<<(std::ostream&, const FacultyValue&);