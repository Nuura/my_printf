#define _MAIN_H_

typedef struct s_argument {
  char arg;
  void (*argument)(va_list random);
}    t_argument;

void		my_putstr(char *str);
void		my_putchar(char c);
void		my_put_nbr(int n);
void		print_string(va_list random);
void		print_char(va_list random);
void		print_int(va_list random);
void		print_octal(va_list random);
void		print_pourcent(va_list random);
/*int		my_strlen(char *str);*/
/*char		*my_strdup(char *str);*/
