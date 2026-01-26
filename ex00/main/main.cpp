#include "../include/ScalarConverter.hpp"

int main(int argc,char *argv[])
{   
    // if (argc != 2)
    //     throw -1;
    (void)argc;
    ScalarConverter::convert(argv[1]);
    return (0);
}

// int main(void)
// {

// }