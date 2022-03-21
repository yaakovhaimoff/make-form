#pragma once

class FacultyValue
{
public:
	FacultyValue() {}
	/*FacultyValue(const int year, int numOfCourses) : m_year(year),
		m_numOfCourses(numOfCourses) {}*/

private:
	int m_year = 0;
	int m_numOfCourses = 0;
};
std::ostream& operator<<(std::ostream&, const std::string&);