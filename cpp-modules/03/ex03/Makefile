SRCS			=	main.cpp\
					ClapTrap.cpp\
					FragTrap.cpp\
					ScavTrap.cpp\
					DiamondTrap.cpp
OBJS			= $(SRCS:.cpp=.o)

CXX				= c++ -std=c++98
CXXFLAGS		= -Wall -Wextra -Werror
INC				= -I.

RM				= rm -f

NAME			= diamondtrap

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) $(INC) $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
