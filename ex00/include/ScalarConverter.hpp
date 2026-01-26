#ifndef SCALARCONVERTER_HPP
    #define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
    public:
       enum Type
        {
            CHAR,
            INT,
            FLOAT,
            DOUBLE,
            UNKNOWN
        };
        ScalarConverter();
        ScalarConverter(ScalarConverter const &other);
        ScalarConverter &operator=(ScalarConverter const &other);
        ~ScalarConverter();
        
        // std::string check_type(std::string &type);
        static Type detected_type(std::string input);
        static void convert(std::string type);
        static int isInt(std::string &type);
        static int isFlout(std::string &type);
        static int isDouble(std::string &type);
        static int isChar(std::string &type);
        
};
#endif 