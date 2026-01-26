#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}
ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
    {
        (void) other;
    }
}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
    if (this != &other)
    {
        // No thing to Assign
    }
    return (*this);
}


int ScalarConverter::isChar(std::string &type)
{
    for (size_t i = 0; i < type.length();i++)
    {
        char c = type[i];
        if (std::isalpha(c))
        {
            if (type[0] == '\'' && type[type.length() - 1] == '\'')
                return (1);
            return (1);
        }
    }
    return (0);
}

int  ScalarConverter::isFlout(std::string &type)
{
    for (size_t i = 0; i < type.length();i++)
    {
        char c = type[i];
        if (std::isdigit(c) && type.find('.') != std::string::npos)
        {
            if (type[type.length() - 1] == 'f')
                return (1);
        }
    }
    return (0);
}

int ScalarConverter::isDouble(std::string &type)
{
    for (size_t i = 0; i < type.length();i++)
    {
        char c = type[i];
        if (std::isdigit(c) && type.find('.') != std::string::npos)
        {
            return (1);
        }
    }
    return (0);
}

int ScalarConverter::isInt(std::string &type)
{
    for (size_t i = 0; i < type.length();i++)
    {
        char c = type[i];
        if (std::isdigit(c))
            return (1);
    }
    return (0);
}

ScalarConverter::Type ScalarConverter::detected_type(std::string input)
{
    if (isChar(input))
        return (CHAR);
    else if (isInt(input))
        return (INT);
    else if (isFlout(input))
        return (FLOAT);
    else if (isDouble(input))
        return (DOUBLE);
    return (UNKNOWN);
}

void ScalarConverter::convert(std::string type)
{
    std::string F;
    std::string D;

    F = type + ".0f";
    D = type + ".0";
    Type t = detected_type(type);
    switch(t)
    {
        case CHAR:
            std::cout<<"char: "<<type<<std::endl;
        case INT:
            std::cout<<"int: "<<type<<std::endl;
        case FLOAT:
            std::cout<<"flout: "<<F<<std::endl;
        case DOUBLE:
            std::cout<<"double: "<<D<<std::endl;
            break;
        case UNKNOWN:
            std::cout<<"Error"<<std::endl;
    }
}

// void ScalarConverter::convert(std::string type)
// {
//     std::string dot = ".0";
//     std::string f = "f"; 
//     std::string cctype[] = 
//     {
//         "char: ",
//         "int: ",
//         "flout: ",
//         "double: "
//     };
//     int (*Check_type[])(std::string&) =
//     {
//             &ScalarConverter::isChar,
//             &ScalarConverter::isInt,
//             &ScalarConverter::isFlout,
//             &ScalarConverter::isDouble
//     };
//     for (int i = 0; i < 4;i++)
//     {
//         if (Check_type[i](type))
//         {
//             if (isFlout(type) || isDouble(type))
//             {
//                 if (isDouble(type))
//                     std::cout<<cctype[i]<<type<<dot<<std::endl;
//                 else if (isFlout(type))
//                 {
//                     std::cout<<cctype[i]<<type<<dot<<f<<std::endl;
//                 }
//             }
//             std::cout<<cctype[i]<<type<<std::endl;
//         }
//     }
// }