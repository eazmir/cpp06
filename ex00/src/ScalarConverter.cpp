#include "../include/ScalarConverter.hpp"
#include <limits>
#include <cmath>
#include <cerrno>

namespace
{
    bool g_invalid = false;
}

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
        return (1);
    if (type.length() == 1 && !std::isdigit(type[0]))
        return (1);
    return (0);
}

int ScalarConverter::isFlout(std::string &type)
{
    if (type.length() < 2 || type[type.length() - 1] != 'f')
        return (0);
    std::string base = type.substr(0, type.length() - 1);
    if (base.empty())
        return (0);
    char *end = NULL;
    errno = 0;
    std::strtof(base.c_str(), &end);
    if (errno == ERANGE || end == base.c_str() || *end != '\0')
        return (0);
    return (1);
}

int ScalarConverter::isDouble(std::string &type)
{
    if (type.find('.') == std::string::npos
        && type.find('e') == std::string::npos
        && type.find('E') == std::string::npos)
        return (0);
    char *end = NULL;
    errno = 0;
    std::strtod(type.c_str(), &end);
    if (errno == ERANGE || end == type.c_str() || *end != '\0')
        return (0);
    return (1);
}

int ScalarConverter::isInt(std::string &type)
{
    char *end = NULL;
    errno = 0;
    std::strtol(type.c_str(), &end, 10);
    if (errno == ERANGE || end == type.c_str() || *end != '\0')
        return (0);
    return (1);
}

int ft_float_nan(std::string &n)
{
    return (n == "-inff" || n == "+inff" || n == "nanf");
}

int ft_check_double_nan(std::string &n)
{
    return (n == "nan" || n == "-inf" || n == "+inf");
}

void ScalarConverter::ft_cast(std::string &type)
{
    g_invalid = false;
    _cv = 0;
    _vi = 0;
    _fv = 0.0f;
    _dv = 0.0;

    if (ft_check_double_nan(type) || ft_float_nan(type))
    {
        if (type[0] == '-')
            _dv = -std::numeric_limits<double>::infinity();
        else if (type[0] == '+')
            _dv = std::numeric_limits<double>::infinity();
        else
            _dv = std::numeric_limits<double>::quiet_NaN();
        _fv = static_cast<float>(_dv);
        return;
    }

    if (isChar(type))
    {
        char cv = (type.length() == 1) ? type[0] : type[1];
        _cv = cv;
        _vi = static_cast<int>(cv);
        _fv = static_cast<float>(cv);
        _dv = static_cast<double>(cv);
        return;
    }

    if (isFlout(type))
    {
        std::string base = type.substr(0, type.length() - 1);
        char *end = NULL;
        errno = 0;
        _fv = std::strtof(base.c_str(), &end);
        if (errno == ERANGE || end == base.c_str() || *end != '\0')
        {
            g_invalid = true;
            return;
        }
        _dv = static_cast<double>(_fv);
        _vi = static_cast<int>(_dv);
        _cv = static_cast<char>(_dv);
        return;
    }

    if (isDouble(type))
    {
        char *end = NULL;
        errno = 0;
        _dv = std::strtod(type.c_str(), &end);
        if (errno == ERANGE || end == type.c_str() || *end != '\0')
        {
            g_invalid = true;
            return;
        }
        _fv = static_cast<float>(_dv);
        _vi = static_cast<int>(_dv);
        _cv = static_cast<char>(_dv);
        return;
    }

    if (isInt(type))
    {
        char *end = NULL;
        errno = 0;
        long v = std::strtol(type.c_str(), &end, 10);
        if (errno == ERANGE || end == type.c_str() || *end != '\0')
        {
            g_invalid = true;
            return;
        }
        _vi = static_cast<int>(v);
        _cv = static_cast<char>(v);
        _fv = static_cast<float>(v);
        _dv = static_cast<double>(v);
        return;
    }

    g_invalid = true;
}

void ScalarConverter::print_float(std::string &type)
{
    (void)type;
    if (g_invalid)
    {
        std::cout << "float: impossible" << std::endl;
        return;
    }
    if (std::isnan(_fv))
    {
        std::cout << "float: nanf" << std::endl;
        return;
    }
    if (std::isinf(_fv))
    {
        std::cout << "float: " << (_fv < 0 ? "-" : "+") << "inff" << std::endl;
        return;
    }
    double intpart;
    bool is_integer = (std::modf(_fv, &intpart) == 0.0);
    std::ostringstream out;
    if (is_integer)
        out << std::fixed << std::setprecision(1) << _fv;
    else
        out << std::setprecision(std::numeric_limits<float>::digits10) << _fv;
    std::cout << "float: " << out.str() << "f" << std::endl;
}

void ScalarConverter::print_double(std::string &type)
{
    (void)type;
    if (g_invalid)
    {
        std::cout << "double: impossible" << std::endl;
        return;
    }
    if (std::isnan(_dv))
    {
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (std::isinf(_dv))
    {
        std::cout << "double: " << (_dv < 0 ? "-" : "+") << "inf" << std::endl;
        return;
    }
    double intpart;
    bool is_integer = (std::modf(_dv, &intpart) == 0.0);
    std::ostringstream out;
    if (is_integer)
        out << std::fixed << std::setprecision(1) << _dv;
    else
        out << std::setprecision(std::numeric_limits<double>::digits10) << _dv;
    std::cout << "double: " << out.str() << std::endl;
}

void ScalarConverter::print_char(std::string &type)
{
    (void)type;
    if (g_invalid || std::isnan(_dv) || std::isinf(_dv))
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    if (_dv < std::numeric_limits<char>::min() || _dv > std::numeric_limits<char>::max())
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    if (!std::isprint(static_cast<unsigned char>(_cv)))
    {
        std::cout << "char: Non displayable" << std::endl;
        return;
    }
    std::cout << "char: " << _cv << std::endl;
}

void ScalarConverter::print_int(std::string &type)
{
    (void)type;
    if (g_invalid || std::isnan(_dv) || std::isinf(_dv))
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    if (_dv < static_cast<double>(std::numeric_limits<int>::min())
        || _dv > static_cast<double>(std::numeric_limits<int>::max()))
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    std::cout << "int: " << _vi << std::endl;
}

void ScalarConverter::convert(std::string type)
{
    ft_cast(type);
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