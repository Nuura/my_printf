/*
** func.c for  in /home/nuura/Desktop/printf/my_printf/trunk
** 
** Made by SANCHEZ Pierre
** Login   <sanche_p@etna-alternance.net>
** 
** Started on  Thu Mar 23 08:48:45 2017 SANCHEZ Pierre
** Last update Thu Mar 23 08:48:47 2017 SANCHEZ Pierre
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "my_printf.h"

void print_octal(va_list random)
{
  unsigned long octal;
  int i;
  unsigned long entier;
  entier = va_arg(random, unsigned long);
  octal = 0;
  i = 0;
  while (entier != 0)
    {
      my_putstr("oui");
      octal = octal + (entier % 8) * i;
      entier = entier/8;
      i = i*10;
    }
  my_put_nbr(entier);
}

void print_pourcent(va_list random)
{
  my_putchar('%');
}
