/*
** my_printf.c for  in /home/nuura/Desktop/printf/my_printf/trunk
** 
** Made by SANCHEZ Pierre
** Login   <sanche_p@etna-alternance.net>
** 
** Started on  Thu Mar 23 08:49:02 2017 SANCHEZ Pierre
** Last update Thu Mar 23 11:58:38 2017 SANCHEZ Pierre
*/

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

t_argument argu[9] =
  {
    {'s', print_string},
    {'c', print_char},
    {'i', print_int},
    {'d', print_int},
    {'o', print_octal},
    {'%', print_pourcent},
    {'x', print_small_hexa},
    {'X', print_big_hexa},
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
