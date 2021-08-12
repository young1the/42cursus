NAME		=	minitalk

UTILS_SRC	=	utils/ft_itoa.c\
				utils/ft_atoi.c\
				utils/utils.c
UTILS_OBJ	=	$(UTILS_SRC:.c=.o)

SERVER		=	server
SERVER_SRC	=	server.c
SERVER_OBJ	=	$(SERVER_SRC:.c=.o)

CLIENT		=	client
CLIENT_SRC	=	client.c
CLIENT_OBJ	=	$(CLIENT_SRC:.c=.o)

FLAGS		=	-Wall -Werror -Wextra

all: $(SERVER) $(CLIENT)

$(SERVER) :	$(SERVER_OBJ) $(UTILS_OBJ)
			gcc $(FLAGS) $(SERVER_OBJ) $(UTILS_OBJ) -o $(SERVER)

$(CLIENT) :	$(CLIENT_OBJ)
			gcc $(FLAGS) $(CLIENT_OBJ) $(UTILS_OBJ) -o $(CLIENT)

clean :
		rm -rf *.o
		rm -rf utils/*.o

fclean : clean
		rm -rf $(SERVER)
		rm -rf $(CLIENT)

re : fclean all
