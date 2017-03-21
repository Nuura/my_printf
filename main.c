#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "my_printf.h"

void print_string(va_list random)
{
  my_putstr("oui");
}

t_argument argu[4] =
  {
    {'s', print_string},
    {'c', print_char},
    {'i', print_int},
    {'d', print_int},
    {0,0}
  };

int my_printf	(const char* str, ...)
{
  int		i;
  i = 0;
  while (str[i + 1] != '\0')
    {
      if (str[i] == '%')
	{
	  argu(str[i + 1]);
	  my_putstr(str[i + 1]);
	}
      else
	my_putchar(str[i]);    
      i++;
    }
  return 0;
}

int main (int ac, char **av)
{
  my_printf("1 - une chaine\n");
  return 0;
}
