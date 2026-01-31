CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

DIR_SRC = src 
DIR_MAIN = main 

NAME =  Serializer

FILES =  \
	$(DIR_MAIN)/main.cpp\
	$(DIR_SRC)/DIR_SRC   \

OBJS = $(FILES:cpp=.o)

all:$(NAME)

$(NAME):$(OBJS)
	$(CXX) $(CXXFLAGS)  $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)
	
fclean:clean
	rm -f $(NAME)

re:fclean all
.PHONY:clean fclean all re
