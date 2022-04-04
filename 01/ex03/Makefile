SRCS			=	main.cpp\
OBJS			= $(SRCS:.cpp=.o)

CXX				= g++ -std=c++98
CXXFLAGS		= -Wall -Wextra -Werror -I.
RM				= rm -f

NAME			= Unnecessary-violence

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
