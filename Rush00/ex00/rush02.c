#include <stdio.h>
void rush(w, h){
  int x = 0 ;
  int y = 0 ;
  while(y < h){
    while(x < w){
      if((x == 0 && y == 0)||(x == w-1 && y == 0)){
        printf("A");
      }else if((x == w-1 && y == h-1)||(x == 0 && y == h-1)){
        printf("C");
      }else if(y == 0 || y == h-1 || x == 0 || x == w-1){
        printf("B");
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
