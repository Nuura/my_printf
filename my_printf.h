#define _MAIN_H_

typedef struct s_argument {
  char arg;
  char (*argument)(va_list random);
}    t_argument;

void		my_putstr(char *str);
void		my_putchar(char c);
void		print_string();
void		print_char();
void		print_int();
int		my_strlen(char *str);
char		*my_strdup(char *str);
