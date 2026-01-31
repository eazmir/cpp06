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
        char    _char;
        int     _int;
        float   _float;
        double  _double;
        bool    _invalid;
    public:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &other);
        ScalarConverter &operator=(ScalarConverter const &other);
        ~ScalarConverter();
        
        static void convert(std::string type);

        void ft_print_float(std::string &type);
        void ft_print_double(std::string &type);
        void ft_print_char(std::string &type);
        void ft_print_int(std::string &type);

        void ft_cast_nan(std::string &type);
        void ft_cast_int(std::string &type);
        void ft_cast_char(std::string &type);
        void ft_cast_float(std::string &type);
        void ft_cast_double(std::string &type);
        
        int ft_isint(std::string &type);
        int ft_isflout(std::string &type);
        int ft_isdouble(std::string &type);
        int ft_ischar(std::string &type);
};

int ft_invalid_input(std::string &type);
#endif 