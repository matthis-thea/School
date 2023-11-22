#-----------------VARIABLES------------------
#--------------------------------------------
# VARIABLES FOR DOT C
FORMS = main.cpp  Bureaucrat.cpp Form.cpp
# VARIABLES FOR DOT O
FORMS_OBJ = $(FORMS:.cpp=.o)
# VARIABLES FOR DO A COMPILATION
CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = form
RM = rm -rf
#--------------------------------------------
#-----------------EXECUTING------------------
#--------------------------------------------
all : $(NAME)
%.o : %.cpp
	@$(CC) $(CXXFLAGS) -c $< -o $@
$(NAME) : $(FORMS_OBJ)
	$(CC) $(CXXFLAGS) $(FORMS_OBJ) -o $(NAME)

clean :
	$(RM) $(FORMS_OBJ)

fclean :	clean
	$(RM) $(NAME)

re :	fclean all

.PHONY :	all clean fclean re
#--------------------------------------------