/*

Test Command

echo "9.ox\n............ooo............\n....o....o.................\n.....ooo....o...oo.........\nooo.............oo.........\n....o...........oo..o......\n.......ooooo...o.......o...\n.oo........................\n......o....................\n..o.......o................" | ./a.out

echo "15.ox\n............ooo............\n....o....o.................\n.....ooo....o...oo.........\nooo.............oo.........\n....o...........oo..o......\n.......ooooo...o.......o...\n.oo........................\n......o....................\n..o.......o................\n..o.......o...ooooooooooooo\n..o.......o...ooooooooooooo\n..o.......o...ooooooooooooo\n..o.......o...ooooooooooooo\n..o.......o...ooooooooooooo\n..o.......o...ooooooooooooo" | ./a.out

echo "9.ox\n............ooo............ooo\n............ooo............ooo\n............ooo............ooo\n............ooo............ooo\n............ooo............ooo\n............ooo............ooo\n............ooo............ooo\n............ooo............ooo\n............ooo............ooo" | ./a.out


./mapgen.pl 200 200 10 | ./a.out


*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) 
{
	int linenumber = 0;
	int linenumber2;
	char buf;
	char nothingchar; //.
	char obstaclechar; //o
	char fillinsidechar; //x

	char **arr;

	int xforinitial = -1;
	int yforinitial = 0;
	int malloctmpvar = 0;

	int choose = 0;
	while (read(0, &buf,  1))
    {
    	if (buf >= '0' && buf <= '9')
    	{
    		linenumber = (linenumber * 10) + (buf - '0');
    		choose = 1;
    	}
    	else if (choose == 1)
    	{
    		linenumber2 = 8352100 / linenumber;
    		arr = malloc(sizeof(char*)*linenumber);
    		while (malloctmpvar < linenumber)
    		{
    			arr[malloctmpvar] = malloc(sizeof(char)*linenumber2);
    			malloctmpvar++;
    		}

    		nothingchar = buf;
    		choose++;
    	}
    	else if (choose == 2)
    	{
			obstaclechar = buf;
			choose++;
    	}
    	else if (choose == 3)
    	{
    		fillinsidechar = buf;
    		choose++;
    	}
    	else if (choose == 4)
    	{
    		if (buf != '\n')
    		{
    			arr[xforinitial][yforinitial] = buf;
    			yforinitial++;
    		}
    		else if (buf == '\n')
    		{
    			xforinitial++;
    			yforinitial = 0;
    		}
    	}
	}
	int howwidth1;
	int howwidth2;
	int differentwidth;
	int k;

	k = 0;
	howwidth1 = 0;
	differentwidth = 0;
	while (k < linenumber)
	{
		howwidth2 = 0;
		while (arr[k][howwidth2] == nothingchar || arr[k][howwidth2] == obstaclechar || arr[k][howwidth2] == fillinsidechar)
		{
			howwidth2++;
		}

		if (howwidth1 != 0 && howwidth1 != howwidth2)
		{
			differentwidth = 1;
			break;
		}
		else
		{
			howwidth1 = howwidth2;
		}
		k++;
	}
	printf("%d\n", howwidth2);

//===
	
	write(1, "\n", 1);
	write(1, &linenumber, 1);
	write(1, &nothingchar, 1);
	write(1, &obstaclechar, 1);
	write(1, &fillinsidechar, 1);
	write(1, "\n", 1);
	
	if(differentwidth){
		printf("map error\n");
	}
	else
	{
		//input data to array;
		int i;
		int j;
		i = 0;
		j = 0;
		for(i = 0 ; i < linenumber ; i++){
			for(j = 0 ; j < howwidth2 ; j++){
				printf("%c", arr[i][j]);
			}
			printf("\n");
		}
	}
	
}
