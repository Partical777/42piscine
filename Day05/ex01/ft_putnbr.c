#include <stdio.h>
#include <unistd.h>

void ft_putnbr(int nb);
void ft_putchar(char);




void ft_putnbr(int nb){
  int i = 0;
  char abc[100];
  int tmp = 1;
  int x = 0;
  while(i < 100 && nb > 0){
    tmp = nb%10;
    abc[i] = tmp + '0';
    nb = nb/10;
    i++;
    abc[i+1] = '\0';
  }
  while(x < i || abc[x] != '\0'){
    ft_putchar(abc[x]);
    x++;
  }
  
}
