#include "../include/ScalarConverter.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: ./ScalarConverter <literal>" << std::endl;
        return (1);
    }
    ScalarConverter::convert(argv[1]);
    return (0);
}

// int main(void)
// {
//     std::string type;
//     void *test;
//     float    _float;
//     type = "112";
//     char *end = NULL;


//     _float = std::strtof(type.c_str(),&end);
//     // if (_float > std::numeric_limits<float>::max() || _float < std::numeric_limits<float>::min())
//     //     std::cout<<"overflow"<<std::endl;
//     std::cout <<std::fixed<<"fixed: " << std::setprecision(1) << _float<<std::endl;
//     // std::cout<<"cout :  " <<_float<<std::endl;
// }