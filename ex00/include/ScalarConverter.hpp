#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cerrno>

class ScalarConverter
{
    private:
        static char    _char;
        static int     _int;
        static float   _float;
        static double  _double;
        static bool    _invalid;
    private:
        static void ft_print_float(std::string &type);
        static void ft_print_double(std::string &type);
        static void ft_print_char(std::string &type);
        static void ft_print_int(std::string &type);

        static void ft_cast_nan(std::string &type);
        static void ft_cast_int(std::string &type);
        static void ft_cast_char(std::string &type);
        static void ft_cast_float(std::string &type);
        static void ft_cast_double(std::string &type);
        
        static int ft_isint(std::string &type);
        static int ft_isflout(std::string &type);
        static int ft_isdouble(std::string &type);
        static int ft_ischar(std::string &type);
        static int ft_invalid_input(std::string &type);
        
        ScalarConverter();
        ScalarConverter(ScalarConverter const &other);
        ScalarConverter &operator=(ScalarConverter const &other);
        ~ScalarConverter();
    public:
        static void convert(std::string type);
};

int ft_float_nan(std::string &n);
int ft_double_nan(std::string &n);
#endif