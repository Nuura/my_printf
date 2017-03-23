CC =			gcc

NAME =			libmy_printf_`uname -m`-`uname -s`

SRC =			my_printf.c 				\
			func.c					\
			my_putstr.c				\
			my_putchar.c				\
			my_put_nbr.c

TRASH =			libmy_printf_x86_64-Linux.a		\
			libmy_printf_x86_64-Linux.so

RM =			rm -rf

CFLAGS =		-Wall -Werror -Wpedantic

LIB =			-L./libmy

all:			my_printf_static my_printf_dynamic

my_printf_static:
			gcc -c $(SRC) $(CFLAGS)
			ar -rc $(NAME).a *.o
			ranlib $(NAME).a

my_printf_dynamic:
			$(CC) -fPIC -shared $(SRC) $(CFLAGS) -o $(NAME).so

clean:
			$(RM) *.o

fclean:			clean
			$(RM) $(TRASH)

re:			fclean all

.PHONY:			all clean fclean
