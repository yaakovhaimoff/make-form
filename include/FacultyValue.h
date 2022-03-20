#pragma once

class FacultyValue
{
public:
	FacultyValue(const int year, int numOfCourses) : m_year(year),
		m_numOfCourses(numOfCourses) {}

private:
	int m_year = 0;
	int m_numOfCourses = 0;
};