CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 


NAME = Converter

DIR_MAIN = main
DIR_SRC  = src

FILES = \
	$(DIR_MAIN)/main.cpp \
	$(DIR_SRC)/ScalarConverter.cpp \
	$(DIR_SRC)/ft_Converter.cpp\

OBJS = $(FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
