#include <stdio.h>
void rush(w, h){
  int x = 0 ;
  int y = 0 ;
  while(y < h){
    while(x < w){
      if((x == 0 && y == 0)||(x == 0 && y == h-1)||(x == w-1 && y == 0)||(x == w-1 && y == h-1)){
        printf("o");
      }else if(y == 0 || y == h-1){
        printf("-");
      }else if(x == 0 || x == w-1){
        printf("|");
      }else{
        printf(" ");
      }
      x++;
    }
    printf("\n");
    y++;
    x = 0;
  }
}