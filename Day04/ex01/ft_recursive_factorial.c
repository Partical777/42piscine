#include <stdio.h>

int sum = 1;
int ft_recursive_factorial(int nb) {
  
  if(nb > 0){
    ft_recursive_factorial(nb-1);
    sum = sum * nb;
  }else{
    return 1;
  }

  return sum;
}
