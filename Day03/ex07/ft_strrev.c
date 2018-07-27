#include <stdio.h>
#include <string.h>

void ft_strrev();

int main(){
    
    ft_strrev();
    return 0;
}

void ft_strrev(){
    char array[100];
    char output[100];

    printf("Enter string: ");
    gets(array);

    for(int x = 0 ; x < strlen(array) ; x++){
        output[strlen(array) - x] = array[x];
    }

    printf("%s\n", output);
}
