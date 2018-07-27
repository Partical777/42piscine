#include <stdio.h>

int n = 0;
void  ft_is_negative(int n);
int main () {
  printf("Enter a value : ");
  scanf( "%d" , &n);
  ft_is_negative(n);   
  return(0);
}
void  ft_is_negative (int n) {
  if(n >= 0) {
    printf("P");
  }else{
    printf("N");
  }
}
