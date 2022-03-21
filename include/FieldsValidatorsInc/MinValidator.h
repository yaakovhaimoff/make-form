#pragma once

// class template:
template <class T>
class MinValidator : public BaseFieldValidators<T>
{
public:
    MinValidator(T element) : m_minElement(element){}
    bool validate(const short&, const short&)override;
    bool validate(const std::string&, const std::string&)override;

private:
    T m_minElement;
};
//________________
template <class T>
bool MinValidator<T>::validate(const short& numOfCousre, const short& validator)
{
    return m_minElement < numOfCousre;
}
//________________
template <class T>
bool MinValidator<T>::validate(const std::string& numOfCousre, const std::string& validator)
{
    return m_minElement < numOfCousre;
}
