#pragma once
#include "Field.h"

// class template:
template <class T>
class FacultyValue : public Field<T>
{
public:
	FacultyValue(const int year, int numOfCourses) : m_year(year),
		m_numOfCourses(numOfCourses) {}

private:
	int m_year;
	int m_numOfCourses;
};