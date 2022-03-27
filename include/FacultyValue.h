#pragma once
#include <iostream>
#include <string>

// Faculty Value class
class FacultyValue
{
public:
	FacultyValue() = default;	//default constructor
	FacultyValue(const int val) : m_value(val) { ; }
	~FacultyValue() {}

	void setValue(const int);
	std::string getStrValue()const;	// Faculty Value name for ostream
	int getValue()const { return m_value; }

private:
	int m_value;
};

//___________________operators_________________________
// operator overloading for i/o stream for Faculty Value
std::istream& operator>>(std::istream&, FacultyValue&);
std::ostream& operator<<(std::ostream&, const FacultyValue&);
//boolian of Faculty Value
bool operator <=(const FacultyValue&, const FacultyValue&);
bool operator >=(const FacultyValue&, const FacultyValue&);
bool operator ==(const FacultyValue&, const FacultyValue&);
