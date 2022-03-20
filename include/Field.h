#pragma once

// class template:
template <class T>
class Field
{
public:
    Field(const T& arg) : m_element(arg) {}

private:
    T m_element;
};