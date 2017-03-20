#include <stdlib.h>
#include <unistd.h>
#include "my_printf.h"

void backslash()
{
  my_putstr("\n");
}

int my_printf(const char* str, ...)
{
  int i;
  i = 0;
  while (str[i + 1] != '\0')
    {
      if(str[i] == '\\' && str[i + 1] == 'n')
	backslash();
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
