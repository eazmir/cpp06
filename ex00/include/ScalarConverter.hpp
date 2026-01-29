#ifndef SCALARCONVERTER_HPP
    #define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <iomanip>

class ScalarConverter
{
    private:
        static char    _cv;
        static int     _vi;
        static float   _fv;
        static double  _dv;
    public:
       enum Type
        {
            CHAR,
            INT,
            FLOAT,
            DOUBLE,
            ERROR
        };
        ScalarConverter();
        ScalarConverter(ScalarConverter const &other);
        ScalarConverter &operator=(ScalarConverter const &other);
        ~ScalarConverter();
        
        static void print_float(std::string &type);
        static void print_double(std::string &type);
        static void print_char(std::string &type);
        static void print_int(std::string &type);
        static void ft_cast(std::string &type);
        static Type detected_type(std::string &input);
        static void convert(std::string type);
        static int isInt(std::string &type);
        static int isFlout(std::string &type);
        static int isDouble(std::string &type);
        static int isChar(std::string &type);
        
};
#endif 