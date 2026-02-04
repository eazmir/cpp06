#include "../include/Serializer.hpp"

bool compare(Data *a, Data *b)
{
    return (a == b);
}

int main(void)
{
    Data *data = new Data;
    data->id = 42;
    data->name = "eazmir";
    
    std::cout << "=== Original Data ===" << std::endl;
    std::cout << "Address: " << data << std::endl;
    std::cout << "Value: " << data->name << " _ " << data->id << std::endl;
    
    uintptr_t raw = Serializer::serialize(data);
    std::cout << "\n=== After Serialization ===" << std::endl;
    std::cout << "Raw (uintptr_t): " << raw << std::endl;
    
    Data *restored = Serializer::deserialize(raw);
    std::cout << "\n=== After Deserialization ===" << std::endl;
    std::cout << "Restored address: " << restored << std::endl;
    std::cout << "Restored value: " << restored->name << " _ " << restored->id << std::endl;
    
    std::cout << "\n=== Comparison ===" << std::endl;
    if (compare(data, restored))
        std::cout << "==OK: Pointers are equal" << std::endl;
    else
        std::cout << "==ERROR: Pointers are different" << std::endl;
    delete data;
    return (0);
}