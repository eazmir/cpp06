#include "../include/ScalarConverter.hpp"

std::string ScalarConverter::non = "";
std::string ScalarConverter::vc  = "";
int         ScalarConverter::vi  = 0;
float       ScalarConverter::vf  = 0.0f;
double      ScalarConverter::vd  = 0.0;


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

ScalarConverter::Type ScalarConverter::detected_type(std::string &input)
{
    if (isChar(input))
        return (CHAR);
    else if (isInt(input))
        return (INT);
    else if (isFlout(input))
        return (FLOAT);
    else if (isDouble(input))
        return (DOUBLE);
    return (ERROR);
}

int ft_check_impossible_flout(std::string &n)
{
    return (n == "-inff" || n == "+inff" || n == "nanf");
}

int ft_check_impossible_double(std::string &n)
{
    return (n == "nan" || n == "-inf" || n == "+inf");
}

void ScalarConverter::ft_check_type(std::string &type)
{
    std::stringstream ss(type);

    int    iv;
    float  fv;
    double dv;
    ss >> iv;
    if (ss.fail())
    {
        non = "impossible";
        return;
    }
    fv = static_cast<float>(iv);
    dv = static_cast<double>(iv);
    iv = static_cast<int>(iv);
    vi = iv;
    vf = fv;
    vd = dv;
}

void ScalarConverter::print_float(std::string &type)
{
    if (ft_check_impossible_flout(type) || ft_check_impossible_double(type))
    {
        if (type == "nanf" || type=="nan")
            std::cout<<"float: "<<"nanf"<<std::endl;
        else
            std::cout<<"float: "<<(type[0] == '-' ? "-" : "+")<<"inff"<<std::endl;
    }
    else
        std::cout<<"float: "<<vf<<".0f"<<std::endl;
}

void  ScalarConverter::print_double(std::string &type)
{
    if (ft_check_impossible_double(type) || ft_check_impossible_flout(type))
    {
        if (type == "nan")
            std::cout<<"double: "<<"nan"<<std::endl;
        else
            std::cout<<"double: "<<(type[0] == '-' ? "-" : "+")<<"nanf"<<std::endl;
    }
    else
        std::cout<<"double: "<<vd<<".0"<<std::endl;
}

void ScalarConverter::print_char(std::string &type)
{
    if (ft_check_impossible_double(type) || ft_check_impossible_flout(type))
        std::cout<<"char: " <<"impossible"<<std::endl;
    else
         std::cout << "char: " << (!vc.empty() ? vc : non) << std::endl;
}

void ScalarConverter::print_int(std::string &type)
{
    if (ft_check_impossible_double(type) || ft_check_impossible_flout(type))
        std::cout<<"int: " <<"impossible"<<std::endl;
    else
         std::cout << "int: "<<vi<< std::endl;
}

void ScalarConverter::convert(std::string type)
{

    Type t = detected_type(type);
    ScalarConverter::ft_check_type(type);
    switch(t)
    {
        case CHAR:
            print_char(type);
        case INT:
            print_int(type);
        case FLOAT:
            print_float(type);
        case DOUBLE:
            print_double(type);
            break;
        case ERROR:
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