#include <stdio.h>
 
void ft_swap(int *a, int *b);
int main()
{ 
    int a = 2;
    int b = 6;
    ft_swap(&a, &b);
    return 0;
}

void ft_swap(int *a, int *b){
  int *x, *y, temp;
 
   printf("Before Swapping\nx = %d\ny = %d\n", *a, *b);
 
   x = *&a;
   y = *&b;
 
   temp = *y;
   *y = *x;
   *x = temp;
 
   printf("After Swapping\nx = %d\ny = %d\n", *a, *b);
}