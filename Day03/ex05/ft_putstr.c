#include <stdio.h>

void ft_putstr();
int main()
{
   ft_putstr();
   return 0;
}

void ft_putstr(){
  char array[25] = "42 is a coding hell!";
  printf("%s\n", array);
}
