#include <stdio.h> 

void ft_print_comb2(void);

int main(void) { 
  
  ft_print_comb2();
  
  return 0; 
}

void ft_print_comb2() {
  for (int x = 0 ; x < 99 ; x++){ 
    for (int y = 1 ; y < 100 ; y++){ 
      if(x < y){
        if(x < 10){
          printf("0%d ", x); 
        }else{
          printf("%d ", x); 
        }
        if(y < 10){
          printf("0%d, ", y); 
        }else{
          printf("%d, ", y); 
        }
        
      } 
    } 
  } 
}

