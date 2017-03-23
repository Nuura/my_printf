/*
** func.c for  in /home/nuura/Desktop/printf/my_printf/trunk
** 
** Made by SANCHEZ Pierre
** Login   <sanche_p@etna-alternance.net>
** 
** Started on  Thu Mar 23 08:48:45 2017 SANCHEZ Pierre
** Last update Thu Mar 23 11:58:56 2017 SANCHEZ Pierre
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "my_printf.h"

void			print_octal(va_list random)
{
  unsigned long		entier;
  unsigned long		octal;
  char			tab[11];
  int			j;
  
  entier = va_arg(random, unsigned long);
  octal = 0;
  j = 0;
  while (entier != 0)
    {
      octal = (entier % 8);
      entier /= 8;
      tab[j] = octal;  
      j++;
    }
  j--;
  while (tab[j] != 0)
    {
      my_putchar(tab[j] + 48);
      j--;
    }
}

void print_pourcent(va_list random)
{
  my_putchar('%');
}

void			print_small_hexa(va_list random)
{
  unsigned long         entier;
  unsigned long         hexa;
  char                  tab[11];
  int                   j;

  entier = va_arg(random, unsigned long);
  hexa = 0;
  j = 0;
  while (entier != 0)
    {
      hexa = (entier % 16);
      entier /= 16;
      if (hexa > 9)
	tab[j] = hexa - 10 + 'a';
      else
	tab[j] = hexa + 48;
      j++;
    }
  tab[j] = '\0';
  j--;
  while (j >= 0)
    {
      my_putchar(tab[j]);
      j--;
    }
}

void                    print_big_hexa(va_list random)
{
  unsigned long         entier;
  unsigned long         hexa;
  char                  tab[11];
  int                   j;

  entier = va_arg(random, unsigned long);
  hexa = 0;
  j = 0;
  while (entier != 0)
    {
      hexa = (entier % 16);
      entier /= 16;
      if (hexa > 9)
	tab[j] = hexa - 10 + 'A';
      else
	tab[j] = hexa + 48;
      j++;
    }
  tab[j] = '\0';
  j--;
  while (j >= 0)
    {
      my_putchar(tab[j]);
      j--;
    }
}
