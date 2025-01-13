SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

OBJS = $(SRCS:.cpp=.o)

CPP = @c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Bureaucrat

YELLOW = \033[1;33m

RED = \033[1;31m

GREEN = \033[1;32m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Compiling $(NAME)..."
	@$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled successfully!"
	
clean:
	@rm -f $(OBJS)
	@echo "$(YELLOW)$(NAME) object files removed!"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) removed!"

re: fclean all

.PHONY: all clean fclean re