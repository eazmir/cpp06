#include "../include/Serializer.hpp"


Serializer::Serializer()
{}

Serializer::Serializer(Serializer const &other)
{
    (void)other; //Nothing To CP
}

Serializer::~Serializer()
{}

Serializer &Serializer::operator=(Serializer const &other)
{
    if (this != &other)  
    {
        //Nothing To CP
    }
    return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
   return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}