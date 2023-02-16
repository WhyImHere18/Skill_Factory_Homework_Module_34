#include <iostream>
#include <concepts>
//#include <bits/stdc++.h>
#include <string>

template <typename T> concept ComplexConcept = requires(T v)
{
    {v.hash()} -> std::convertible_to<long>;
    {v.toString()} -> std::same_as<std::string>;
}&& std::has_virtual_destructor<T>::value == false;

struct HashableStruct
{
    int num{ 0 };
    int hash() const { return num << 3; };
    std::string toString() const { return std::to_string(this->hash()); };
};

void print(ComplexConcept auto& t)
{
    std::cout << t.toString() << std::endl;
}

int main()
{
    HashableStruct num{ 100 };
    print(num);

    return 0;
}