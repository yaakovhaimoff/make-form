#pragma once
#include <string>
#include <cstdint>
#include <memory>
#include <iostream>

class BaseField
{
public:
    BaseField(const std::string message) : m_message(message), m_valid(false){}
    void show() { std::cout << m_message; }
    virtual bool checkValidator() = 0;
    virtual void readElement() = 0;
    virtual bool getValid()const { return m_valid; }
    virtual void setValid(const bool valid) { m_valid = valid; }
    virtual void printError()const = 0;
    virtual void printElement()const = 0;
    virtual ~BaseField() = default;

private:
    std::string m_message;
    bool m_valid;
}; 
