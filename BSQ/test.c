/*

Test Command

echo "9.ox\n............ooo............\n....o....o.................\n.....ooo....o...oo.........\nooo.............oo.........\n....o...........oo..o......\n.......ooooo...o.......o...\n.oo........................\n......o....................\n..o.......o................" | ./a.out

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) 
{
	int linenumber;
	int linenumber2;
	char buf;
	char nothingchar; //.
	char obstaclechar; //o
	char fillinsidechar; //x

	char **arr;

	int x = 0;
	int y = 0;
	int malloctmpvar = 0;

	int choose = 0;
	while (read(0, &buf,  1))
    {
    	if (choose == 0)
    	{
    		linenumber = buf - '0';
    		linenumber2 = 8352100 / linenumber;
    		arr = malloc(sizeof(char*)*linenumber);
    		while (malloctmpvar < linenumber)
    		{
    			arr[malloctmpvar] = malloc(sizeof(char)*linenumber2);
    			malloctmpvar++;
    		}
    	}
    	else if (choose == 1)
    	{
    		nothingchar = buf;
    	}
    	else if (choose == 2)
    	{
			obstaclechar = buf;
    	}
    	else if (choose == 3)
    	{
    		fillinsidechar = buf;
    	}
    	else if (choose == 5)
    	{
    		if (buf != '\n')
    		{
    			arr[x][y] = buf;
    			y++;
    		}
    		else if (buf == '\n')
    		{
    			x++;
    			y = 0;
    		}
    	}

    	if (choose < 5){
            choose++;
        }
	}
	
	write(1, "\n", 1);
	write(1, &                                                                      linenumber, 1);
	write(1, &nothingchar, 1);
	write(1, &obstaclechar, 1);
	write(1, &fillinsidechar, 1);
	write(1, "\n", 1);
	//input data to array;
	int i;
	int j;
	i = 0;
	j = 0;
	for(i = 0 ; i < 9 ; i++){
		for(j = 0 ; j < 27 ; j++){
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	
}
