#include "Serializer.hpp"



int main(void){

    Data data;

    data.id  = 21;
    data.name = "youssef";

    Data *ptr = &data;

    uintptr_t raw = Serializer::serialize(ptr);

    Data *newptr = Serializer::deserialize(raw);

    std::cout << "Original pointer: " << ptr << std::endl;
    std::cout << "Serialized: " << raw << std::endl;
    std::cout << "Deserialized pointer: " << newptr << std::endl;

    std::cout << "Data id: " << newptr->id << std::endl;
    std::cout << "Data name: " << newptr->name << std::endl;

    return (0);
}