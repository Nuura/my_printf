CC =			gcc

NAME =			my_printf

SRC =			main.c 				\
			libmy_03/libmy.a

OBJ =			$(SRC:%.c=%.o)

RM =			rm -f

CFLAGS =		-Wall -Werror -Wpedantic

LIB =			-L./libmy

all:			$(NAME)

$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) $(SRC) $(LIB) -o $(NAME)

clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re