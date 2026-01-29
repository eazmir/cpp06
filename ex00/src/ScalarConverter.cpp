#include "../include/ScalarConverter.hpp"

char ScalarConverter::_cv = 0;
int ScalarConverter::_vi = 0;
float ScalarConverter::_fv = 0.0f;
double ScalarConverter::_dv = 0.0;

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
    (void)other;
}

ScalarConverter::~ScalarConverter()
{
}

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
    if (type.length() == 3 && type[0] == '\'' && type[2] == '\'')
    {
        if (std::isprint(type[1]))
            return (1);
    }
    if (type.length() == 1 && std::isalpha(type[0]))
        return (1);
    return (0);
}

int ScalarConverter::isFlout(std::string &type)
{
    for (size_t i = 0; i < type.length(); i++)
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
    for (size_t i = 0; i < type.length(); i++)
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
    for (size_t i = 0; i < type.length(); i++)
    {
        char c = type[i];
        if (std::isdigit(c))
            return (1);
    }
    return (0);
}

int ft_float_nan(std::string &n)
{
    return (n == "-inff" || n == "+inff" || n == "nanf");
}

int ft_check_double_nan(std::string &n)
{
    return (n == "nan" || n == "-inf" || n == "+inf");
}

void ScalarConverter::ft_check_type(std::string &type)
{
    int iv;
    char cv;

     std::cout <<"--------------->"<<std::endl;
    std::stringstream cc(type);
    std::stringstream ss(type);
 
    ss >> iv;
    cc >> cv;

     if (ft_check_double_nan(type) || ft_check_double_nan(type))
    {
        if (type[0] == '-' || type[0] == '+')
        {
            _fv = -2;
            _dv = -2;
        }
        else
        {
            _vi = -1;
            _fv = -1;
            _dv = -1;
        }
        std::cout <<"------2--------->"<<std::endl;
        return;
    }
    std::cout <<"---------3------>"<<std::endl;
    if (isChar(type) && (!ft_check_double_nan(type) || !ft_float_nan(type)))
    {
        _cv = static_cast<char>(cv);
        _fv = static_cast<char>(cv);
        _dv = static_cast<char>(cv);
        _vi = static_cast<char>(cv);
        return;
    }
    else
    {
        _fv = static_cast<float>(iv);
        _dv = static_cast<double>(iv);
        _vi = static_cast<int>(iv);
        _cv = static_cast<char>(iv);
    }
}

void print_nan(std::string type, std::string input, int value)
{
    std::string result;

    if (input.find("nan") != std::string::npos)
    {
        if (type == "float")
            result = "nanf";
        else
            result = "nan";
    }
    else
    {
        if (ft_check_double_nan(input))
            result = "inff";
        else
            result = "inf";
    }

    if (value < 0 || value < 0)
    {
        if (input[0] == '-' || input[0] == '+')
            std::cout << type << ": "
                      << (value == -2 ? "-" : "+") << result << std::endl;
        else
            std::cout << type << ": " << result << std::endl;
    }
}

void ScalarConverter::print_float(std::string &type)
{
    if (_fv < 0)
        print_nan("float", type, _fv);
    else
        std::cout << "float: " << _fv << ".0f" << std::endl;
}

void ScalarConverter::print_double(std::string &type)
{
    if (_dv < 0)
        print_nan("double", type, _dv);
    else
        std::cout << "double: " << _dv << ".0" << std::endl;
}

void ScalarConverter::print_char(std::string &type)
{
    if (_cv < 0 || !std::isprint(_cv))
        std::cout << "char: " << "non" << std::endl;
    else if (ft_check_double_nan(type) || ft_float_nan(type))
        std::cout << "char: impossible" << std::endl;
    else if (isInt(type))
        std::cout << "char: " << static_cast<char>(_vi) << std::endl;
    else
        std::cout << "char: " << _cv << std::endl;
}

void ScalarConverter::print_int(std::string &type)
{
    (void)type;
    if (_dv < 0 || _dv < 0)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << _vi << std::endl;
}

void ScalarConverter::convert(std::string type)
{
    ScalarConverter::ft_check_type(type);
    print_char(type);
    print_int(type);
    print_float(type);
    print_double(type);
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