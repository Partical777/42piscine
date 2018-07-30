#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_atoi(char *str);

int ft_atoi(char *str){
  int sum = 0;
	int i = 0;	
  	while (str[i] != '\0'){
		if( str[i] >= 48 && str[i] <= 57){
     		 sum = sum*10 + str[i] - '0';
   		 }else{
     		 return 0;
   		 }
	i++;
  }

	return sum;
}
