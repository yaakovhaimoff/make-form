#pragma once
#include <string>
#include <cstdint>
#include <memory>
#include <iostream>
#include <vector>

//Base Field - abstract class
class BaseField
{
public:
    BaseField(const std::string message) : m_message(message), m_valid(false) {}
    virtual ~BaseField() = default;

    virtual bool checkValidator() = 0;
    virtual void readElement() = 0;
    virtual void printError()const = 0;
    virtual void printElement()const = 0;
    virtual bool getValid()const { return m_valid; }
    virtual void setValid(const bool valid) { m_valid = valid; }
    void show() { std::cout << m_message; }

private:
    std::string m_message;
    bool m_valid;
};
