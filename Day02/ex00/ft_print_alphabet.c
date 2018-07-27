#include <stdio.h>

void ft_print_alphabet(void);
int main () {
   ft_print_alphabet();   
   return(0);
}
void ft_print_alphabet () {
  char letter;
   for(letter = 'a' ; letter <= 'z' ; letter++) {
      putchar(letter);
   }
}
