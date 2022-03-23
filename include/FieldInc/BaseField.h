#pragma once
#include <string>
#include <cstdint>
#include <memory>
#include <iostream>

class BaseField
{
public:
    BaseField(const std::string message) : m_message(message), m_valid(false) {}
    void show() { std::cout << m_message << std::endl; }
    virtual bool checkValidator() = 0;
    virtual void readElement() = 0;
    virtual bool getValid()const { return m_valid; }
    virtual bool setValid(const bool valid) { m_valid = valid; }
    virtual ~BaseField() = default;

private:
    std::string m_message;
    bool m_valid;
}; 
