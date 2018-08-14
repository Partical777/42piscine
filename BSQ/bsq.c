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
//===
//Get Each Line 是否等寬
//Get Width
    int howwidth;
    int width;
    int differentwidth;
    int k;

    k = 0;
    howwidth = 0;
    differentwidth = 0;
    while (k < linenumber)
    {
        width = 0;
        while (arr[k][width] == nothingchar || arr[k][width] == obstaclechar || arr[k][width] == fillinsidechar)
        {
            width++;
        }

        if (howwidth != 0 && howwidth != width)
        {
            differentwidth = 1;
            break;
        }
        else
        {
            howwidth = width;
        }
        k++;
    }


//===test
    printf("%d\n", width);
    int i, j;
    i = 0;
    j = 0;
    for(i = 0 ; i < linenumber ; i++){
        for(j = 0 ; j < width ; j++){
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }


    if(differentwidth){
        printf("map error\n");
    }
    else
    { //if each line is same
//=====logic and change+

    int biggestsofar; //目前找到最大的
    int obstacle;
    int pointx; //目前找到最大的點x值
    int pointy; //目前找到最大的點y值
    int x;
    int y;
    int testbiggest;
    int testx;
    int testy;

    biggestsofar = 0;
    obstacle = 0;
    pointx = 0;
    pointy = 0;
    x = 0;
    while (x < (linenumber - biggestsofar))
    {
        y = 0;
        while (y < (width - biggestsofar))
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
                    pointx = x;
                    pointy = y;
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
    printf("[%d, %d]\n", pointx, pointy);
//===
    int a;
    int b;

    a = pointx;
    while (a < pointx + biggestsofar)
    {
        b = pointy;
        while (b < (pointy + biggestsofar))
        {
            arr[a][b] = fillinsidechar;
            b++;
        }
        a++;
    }
//===
    i = 0;
    while (i < linenumber)
    {
        j = 0;
        while (j < width)
        {
            printf("%c", arr[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
//=====logic and change-
    
    } //if each line is same


    return 0;
}
