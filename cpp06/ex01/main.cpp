#include "Serialization.hpp"
#include <iostream>

int main()
{
    Data d;
    d.data_int = 42;
    d.data_string = "Vedat";

    std::cout << "Original Data pointer: " << &d << std::endl;

    // serialize
    uintptr_t raw = Serialization::serialize(&d);
    std::cout << "Serialized (uintptr_t): " << raw << std::endl;

    // deserialize
    Data* newPtr = Serialization::deserialize(raw);
    std::cout << "Deserialized Data pointer: " << newPtr << std::endl;

    if (newPtr == &d)
        std::cout << "Pointers are equal!" << std::endl;
    else
        std::cout << "Pointers are NOT equal!" << std::endl;

    // access data through newPtr
    std::cout << "Data values: id=" << newPtr->data_int << ", name=" << newPtr->data_string << std::endl;

    return 0;
}
