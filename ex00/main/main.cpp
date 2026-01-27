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
//     std::string type;
//     float        fv;

//     type = "42";
//     std::stringstream f(type);
//     f >> fv;
//     fv = static_cast<float>(fv);
//     std::cout<<fv<<std::endl;
// }
// #include <iomanip>
// int main(void)
// {
//     std::string type = "42";
//     float fv;

//     std::stringstream ss(type);
//     ss >> fv;

//     if (fv == static_cast<int>(fv))
//         std::cout<<fv<<".0"<<std::endl;
//     else
//         std::cout<<fv<<std::endl;
// }