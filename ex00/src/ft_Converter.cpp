#include "../include/ScalarConverter.hpp"

int ScalarConverter::ft_ischar(std::string &type)
{
    if (type.length() == 3 && type[0] == '\'' && type[2] == '\'')
        return (1);
    if (type.length() == 1 && !std::isdigit(type[0]))
        return (1);
    return (0);
}

int ScalarConverter::ft_isflout(std::string &type)
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

int ScalarConverter::ft_isdouble(std::string &type)
{
    if (type.find('.') == std::string::npos && type.find('e') == std::string::npos && type.find('E') == std::string::npos)
        return (0);
    char *end = NULL;
    errno = 0;
    std::strtod(type.c_str(), &end);
    if (errno == ERANGE || end == type.c_str() || *end != '\0')
        return (0);
    return (1);
}

int ScalarConverter::ft_isint(std::string &type)
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

int ft_double_nan(std::string &n)
{
    return (n == "nan" || n == "-inf" || n == "+inf");
}

int ft_invalid_input(std::string &type)
{
    ScalarConverter check_input;
    return (
        check_input.ft_ischar(type) == 1 || check_input.ft_isint(type) == 1 || check_input.ft_isflout(type) == 1 || check_input.ft_isdouble(type) == 1 || ft_float_nan(type) || ft_double_nan(type));
}

void ScalarConverter::ft_cast_nan(std::string &type)
{
    if (ft_double_nan(type) || ft_float_nan(type))
    {
        if (type[0] == '-')
            _double = -std::numeric_limits<double>::infinity();
        else if (type[0] == '+')
            _double = std::numeric_limits<double>::infinity();
        else
            _double = std::numeric_limits<double>::quiet_NaN();
        _float = static_cast<float>(_double);
        return;
    }
}

void ScalarConverter::ft_cast_char(std::string &type)
{
    if (this->ft_ischar(type))
    {
        char cv = (type.length() == 1) ? type[0] : type[1];
        this->_char = cv;
        this->_int = static_cast<int>(cv);
        this->_float = static_cast<float>(cv);
        this->_double = static_cast<double>(cv);
        return;
    }
}
void ScalarConverter::ft_cast_float(std::string &type)
{
    if (ft_isflout(type))
    {
        std::string base = type.substr(0, type.length() - 1);
        char *end = NULL;
        errno = 0;
        _float = std::strtof(base.c_str(), &end);
        if (errno == ERANGE || end == base.c_str() || *end != '\0')
        {
            _invalid = true;
            return;
        }
        _double = static_cast<double>(_float);
        _int = static_cast<int>(_float);
        _char = static_cast<char>(_float);
        return;
    }
}

void ScalarConverter::ft_cast_double(std::string &type)
{
    if (ft_isdouble(type))
    {
        char *end = NULL;
        errno = 0;
        _double = std::strtod(type.c_str(), &end);
        if (errno == ERANGE || end == type.c_str() || *end != '\0')
        {
            _invalid = true;
            return;
        }
        _float = static_cast<float>(_double);
        _int = static_cast<int>(_double);
        _char = static_cast<char>(_double);
        return;
    }
}
void ScalarConverter::ft_cast_int(std::string &type)
{
    if (ft_isint(type))
    {
        char *end = NULL;
        errno = 0;
        long v = std::strtol(type.c_str(), &end, 10);
        if (errno == ERANGE || end == type.c_str() || *end != '\0')
        {
            _invalid = true;
            return;
        }
        _int = static_cast<int>(v);
        _char = static_cast<char>(v);
        _float = static_cast<float>(v);
        _double = static_cast<double>(v);
        return;
    }
}

void ScalarConverter::ft_print_float(std::string &type)
{
    (void)type;
    if (_invalid)
    {
        std::cout << "float: impossible" << std::endl;
        return;
    }
    if (std::isnan(_float))
    {
        std::cout << "float: nanf" << std::endl;
        return;
    }
    if (std::isinf(_float))
    {
        std::cout << "float: " << (_float < 0 ? "-" : "+") << "inff" << std::endl;
        return;
    }
    double intpart;
    bool is_integer = (std::modf(_float, &intpart) == 0.0);
    std::ostringstream out;
    if (is_integer)
        out << std::fixed << std::setprecision(1) << _float;
    else
        out << std::setprecision(std::numeric_limits<float>::digits10) << _float;
    std::cout << "float: " << out.str() << "f" << std::endl;
}

void ScalarConverter::ft_print_double(std::string &type)
{
    (void)type;
    if (_invalid)
    {
        std::cout << "double: impossible" << std::endl;
        return;
    }
    if (std::isnan(_double))
    {
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (std::isinf(_double))
    {
        std::cout << "double: " << (_double < 0 ? "-" : "+") << "inf" << std::endl;
        return;
    }
    double intpart;
    bool is_integer = (std::modf(_double, &intpart) == 0.0);
    std::ostringstream out;
    if (is_integer)
        out << std::fixed << std::setprecision(1) << _double;
    else
        out << std::setprecision(std::numeric_limits<double>::digits10) << _double;
    std::cout << "double: " << out.str() << std::endl;
}

void ScalarConverter::ft_print_char(std::string &type)
{
    (void)type;
    if (_invalid || std::isnan(_double) || std::isinf(_double))
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    if (_char < std::numeric_limits<char>::min() || _char > std::numeric_limits<char>::max())
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    if (!std::isprint(static_cast<unsigned char>(_char)))
    {
        std::cout << "char: Non displayable" << std::endl;
        return;
    }
    std::cout << "char: " << _char << std::endl;
}

void ScalarConverter::ft_print_int(std::string &type)
{
    (void)type;
    if (_invalid || std::isnan(_double) || std::isinf(_double))
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    if (_double < static_cast<double>(std::numeric_limits<int>::min()) || _double > static_cast<double>(std::numeric_limits<int>::max()))
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    std::cout << "int: " << _int << std::endl;
}
