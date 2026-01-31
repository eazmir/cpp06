#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    _char = 0;
    _int = 0;
    _float = 0.0f;
    _double = 0.0;
    _invalid = false;
}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
    (void)other; // No thing to copy
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


void ScalarConverter::convert(std::string type)
{
    ScalarConverter *Convert = new (ScalarConverter);

    Convert->ft_cast_nan(type);
    Convert->ft_cast_char(type);
    Convert->ft_cast_int(type);
    Convert->ft_cast_float(type);
    Convert->ft_cast_double(type);
    if (!ft_invalid_input(type))
        Convert->_invalid = true;
    Convert->ft_print_char(type);
    Convert->ft_print_int(type);
    Convert->ft_print_float(type);
    Convert->ft_print_double(type);
    delete Convert;
}