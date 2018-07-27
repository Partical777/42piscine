#include <stdio.h>

void ft_print_reverse_alphabet(void);
int main () {
   ft_print_reverse_alphabet();   
   return(0);
}
void ft_print_reverse_alphabet () {
  char letter;
   for(letter = 'z' ; letter >= 'a' ; letter--) {
      putchar(letter);
   }
}
