SRCS			=	main.cpp\
					Fixed.cpp
OBJS			= $(SRCS:.cpp=.o)

CXX				= g++ -std=c++98
CXXFLAGS		= -Wall -Wextra -Werror
INC				= -I.

RM				= rm -f

NAME			= a.out

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) $(INC) $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
