#include "../include/ScalarConverter.hpp"

char ScalarConverter::_char = 0;
int ScalarConverter::_int = 0;
float ScalarConverter::_float = 0.0f;
double ScalarConverter::_double = 0.0;
bool ScalarConverter::_invalid = false;

ScalarConverter::ScalarConverter()
{}

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
  ft_cast_nan(type);
  ft_cast_char(type);
  ft_cast_int(type);
  ft_cast_float(type);
  ft_cast_double(type);
  if (!ft_invalid_input(type))
    _invalid = true;
  ft_print_char(type);
  ft_print_int(type);
  ft_print_float(type);
  ft_print_double(type);
}