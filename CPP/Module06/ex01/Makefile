#-----------------VARIABLES------------------
#--------------------------------------------
# VARIABLES FOR DOT C
BUREAUCRAT = main.cpp Data.cpp
# VARIABLES FOR DOT O
BUREAUCRAT_OBJ = $(BUREAUCRAT:.cpp=.o)
# VARIABLES FOR DO A COMPILATION
CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = data
RM = rm -rf
#--------------------------------------------
#-----------------EXECUTING------------------
#--------------------------------------------
all : $(NAME)
%.o : %.cpp
	@$(CC) $(CXXFLAGS) -c $< -o $@
$(NAME) : $(BUREAUCRAT_OBJ)
	$(CC) $(CXXFLAGS) $(BUREAUCRAT_OBJ) -o $(NAME)

clean :
	$(RM) $(BUREAUCRAT_OBJ)

fclean :	clean
	$(RM) $(NAME)

re :	fclean all

.PHONY :	all clean fclean re
#--------------------------------------------