#pragma once
#include <string>
#include <cstdint>
#include <memory>
#include <iostream>

class BaseField
{
public:
    BaseField(const std::string message) : m_message(message){}
    void show() { std::cout << m_message << std::endl; }

private:
    std::string m_message;
}; 
