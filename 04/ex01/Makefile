SRCS			=	main.cpp\
					Animal.cpp\
					Cat.cpp\
					Dog.cpp\
					Brain.cpp
OBJS			= $(SRCS:.cpp=.o)

CXX				= c++ -std=c++98
CXXFLAGS		= -Wall -Wextra -Werror
INC				= -I.

RM				= rm -f

NAME			= brain

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) $(INC) $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
