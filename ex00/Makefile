NAME = bin
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = src/Bureaucrat.cpp src/main.cpp 

all : $(NAME)
$(NAME) : $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	rm -rf $(NAME)
fclean : clean

re : clean all