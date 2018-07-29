#include <stdio.h>

int ft_iterative_factorial(int nb) {
  int a = 1;
  int sum = 1;
  if(nb > 0){
    while(a <= nb){
      sum = sum * a; 
      a++;
    }
  }else{
    sum = 1;
  }
  
  printf("%d", sum);
  return sum;
}
