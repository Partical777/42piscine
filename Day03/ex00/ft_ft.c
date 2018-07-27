#include <stdio.h>

void ft_ft();
int main(void) {
  ft_ft();
  return 0;
}

void ft_ft(){
  int *b = 42;
  printf("%d\n", *&b) ;
}
