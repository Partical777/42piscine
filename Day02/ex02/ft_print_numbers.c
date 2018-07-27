#include <stdio.h>

void  ft_print_numbers(void);
int main () {
    ft_print_numbers();   
   return(0);
}
void  ft_print_numbers () {
  char letter;
   for(letter = '0' ; letter <= '9' ; letter++) {
      putchar(letter);
   }
}
