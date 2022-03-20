#pragma once
#include <string>

// class template:
template <class T>
class Field
{
public:
    Field(const std::string);

private:
    T m_element;
};
