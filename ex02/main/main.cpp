#include "../include/Identify.hpp"

void my_sleep(unsigned int seconds) 
{
    std::time_t start = std::time(NULL);
    while (std::time(NULL) - start < seconds) 
    {}
}

int main(void)
{
    int i;
    int size;
    {
        Base *invalid = new Base();
        std::cout << "==Testing Invalid/Pure Base: \n";
        identify(*invalid);
        identify(invalid);
        delete invalid;
    }
    std::cout<<"---------------------------------"<<std::endl;
    {
        i = 0;
        size = 6;
        while (i < size)
        {
            Base *ptr = generate();
            identify(ptr);
            my_sleep(1);
            delete  ptr;
            i++;
        }
    }
    std::cout<<"---------------------------------"<<std::endl;
    {
        i = 0;
        while (i < size)
        {
            Base *ptr = generate();
            identify(*ptr);
            my_sleep(1);
            delete ptr;
            i++;
        }
    }
    return (0);
}