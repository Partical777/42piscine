#include <stdio.h>

int main(void) {
  int arr[9][9];
  int *bigblockarr[9][9];
  int bigblock = 0;

  for (int  i = 0 ; i < 9 ; i++){
    for (int j = 0 ; j < 9 ; j++){
      bigblockarr[bigblock][j % 3 + 3 * (i % 3)] = &arr[j][i];
      arr[j][i] = 0;
      printf("%d%d|", j , i);
      printf("%d%d | ", bigblock, j % 3 + 3 * (i % 3));
      if(j % 3 == 2){
        bigblock++;
      }
      if(j % 3 == 2 && j == 8){
        if(i < 2){
          bigblock = 0;
        }else if(i < 5){
          bigblock = 3;
        }else{
          bigblock = 6;
        }
      }
    }
    printf("\n\n");
  }
  arr[1][1] = 9;
  printf("%d", *bigblockarr[0][4]);
  return 0;
}
