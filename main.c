#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "my_printf.h"

void print_string(va_list random)
{
  my_putstr(va_arg(random, char*));
}

void print_char(va_list random)
{
  my_putchar(va_arg(random, int));
}

void print_int(va_list random)
{
  my_put_nbr(va_arg(random, int));
}

t_argument argu[7] =
  {
    {'s', print_string},
    {'c', print_char},
    {'i', print_int},
    {'d', print_int},
    {'o', print_octal},
    {'%', print_pourcent},
    {0,0}
  };

int my_printf	(const char* str, ...)
{
  int		i;
  int		j;
  va_list	random;
  i = 0;
  j = 0;
  va_start(random, str);

  while (str[i] != '\0')
    {
      if (str[i] == '%')
	{
	  i++;
	  while (argu[j].arg != 0)
	    {
	      if (str[i] == argu[j].arg)
		{
		  argu[j].argument(random);
		}
	      j++;
	    }
	  j = 0;
	}
      else
	my_putchar(str[i]);
      i++;
    }
  va_end(random);
  return (0);
}

int main (int ac, char **av)
{
  my_printf("1 - une chaine\n");
  my_printf("2 - %s\n", "une autre chaine");
  my_printf("3 - %i\n", 42);
  my_printf("4 - %s %d %s %c", "avec", 4, "parametres", '\n');
  my_printf("6 - %d%%\n", 42);
  my_printf("5 - %o\n", 42);
  return (0);
}
