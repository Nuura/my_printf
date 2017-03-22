#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "my_printf.h"

void print_octal(va_list random)
{
  int octal;
  int i;
  unsigned long entier;
  entier = va_arg(random, unsigned long);
  octal = 0;
  i = 0;
  while (entier != 0)
    {
      octal = octal + (entier % 8) * i;
      entier = entier/8;
      i = i*10;
    }
  my_put_nbr(entier);
}
