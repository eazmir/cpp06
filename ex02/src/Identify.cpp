#include "../include/Identify.hpp"

Base::~Base() {} 

Base *a()
{
    return (new A());
}

Base *b()
{
    return (new B());
}

Base *c()
{
    return (new C());
}

Base* generate(void)
{
    Base *(*generate[])() = 
    {
        &a,
        &b,
        &c
    };
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    return (generate[std::rand() % 3]());
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout<<"* → asterisk → pointer-to type  A"<<std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout<<"* → asterisk → pointer-to type  B"<<std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout<<"* → asterisk → pointer-to type  C"<<std::endl;
    else
        std::cout << "Cannot identify pure Base object" << std::endl;
}

void identify(Base& p)
{
    int count = 0;
    try
    {
        (void)dynamic_cast<A&>(p);
         std::cout << "& → ampersand → reference-to type A"<< std::endl;
         return;
    }
    catch(const std::exception& e){count++;}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "& → ampersand → reference-to type B"<< std::endl;
        return;
    }
    catch(const std::exception& e){count++;}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "& → ampersand → reference-to type C" <<std::endl;
        return;
    }
    catch(const std::exception& e){count++;}
    if (count == 3)
        std::cout << "Cannot identify pure Base object" << std::endl;
}