#-----------------VARIABLES------------------
#--------------------------------------------
# VARIABLES FOR DOT C
MAIN = main.cpp Span.cpp
# VARIABLES FOR DOT O
MAIN_OBJ = $(MAIN:.cpp=.o)
# VARIABLES FOR DO A COMPILATION
CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = span
RM = rm -rf
#--------------------------------------------
#-----------------EXECUTING------------------
#--------------------------------------------
all : $(NAME)
%.o : %.cpp
	@$(CC) $(CXXFLAGS) -c $< -o $@
$(NAME) : $(MAIN_OBJ)
	$(CC) $(CXXFLAGS) $(MAIN_OBJ) -o $(NAME)

clean :
	$(RM) $(MAIN_OBJ)

fclean :	clean
	$(RM) $(NAME)

re :	fclean all

.PHONY :	all clean fclean re
#--------------------------------------------