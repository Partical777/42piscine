#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) 
{
	int linenumber; //行數
    int linenumber2;
    int biggestsofar; //目前找到最大的
    int obstacle;
    int pointX; //目前找到最大的點x值
    int pointY; //目前找到最大的點y值
    int x;
    int y;
    int testbiggest;
    int testx;
    int testy;
	//===
    char **arr;
    int xforinitial = 0;
    int yforinitial = 0;
    int malloctmpvar = 0;

	char buf;
	char nothingchar; //.
	char obstaclechar; //o
	char fillinsidechar; //x

	int choose = 0;
    while (read(0, &buf,  1))
    {
        if (choose == 0)
        {
            linenumber = buf - '0';
            linenumber2 = 8352100 / linenumber;
            arr = calloc(sizeof(char*)*linenumber);
            while (malloctmpvar < linenumber)
            {
                arr[malloctmpvar] = calloc(sizeof(char)*linenumber2);
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
                arr[xforinitial][yforinitial] = buf;
                yforinitial++;
            }
            else if (buf == '\n')
            {
                xforinitial++;
                yforinitial = 0;
            }
        }

        if (choose < 5){
            choose++;
        }
    }  
//===
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
//===

    linenumber = 9;
    biggestsofar = 0;
    obstacle = 0;
    pointX = 0;
    pointY = 0;
    x = 0;
    while (x < (linenumber - biggestsofar))
    {
        y = 0;
        while (y < (27 - biggestsofar))
        {
            testbiggest = (linenumber - x);
            while (testbiggest > biggestsofar)
            {
                obstacle = 0;
                testx = 0;
                while (testx < testbiggest)
                {
                    testy = 0 ;
                    while (testy < testbiggest)
                    {
                        if (arr[x + testx][y + testy] == obstaclechar)
                        {
                            obstacle = 1;
                            break;
                        }
                        testy++;
                    }
                    if (obstacle == 1)
                    {
                        break;
                    }
                    testx++;
                }
                if (obstacle == 0)
                {
                    pointX = x;
                    pointY = y;
                    biggestsofar = testbiggest;
                    break;
                }
                testbiggest--;
            }
            y++;
        }
        x++;
    }
//===
    printf("%d\n", biggestsofar);
    printf("[%d, %d]\n", pointX, pointY);
//===
    int a;
    int b;

    a = pointX;
    while (a < pointX + biggestsofar)
    {
        b = pointY;
        while (b < (pointY + biggestsofar))
        {
            arr[a][b] = fillinsidechar;
            b++;
        }
        a++;
    }
//===
    i = 0;
    while (i < 9)
    {
        j = 0;
        while (j < 27)
        {
            printf("%c", arr[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}