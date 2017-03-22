CC =			gcc

NAME =			my_printf

SRC =			main.c 				\
			func.c				\
			libmy_03/libmy.a

OBJ =			$(SRC:%.c=%.o)

RM =			rm -f

CFLAGS =		-Wall -Werror -Wpedantic

LIB =			-L./libmy

all:			$(NAME)

$(NAME):		compil $(OBJ)
				$(CC) $(CFLAGS) $(SRC) $(LIB) -o $(NAME)

compil:
			cd libmy_03; make fclean; make; cd -;

clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

run:
			./my_printf

.PHONY:			all clean fclean re
