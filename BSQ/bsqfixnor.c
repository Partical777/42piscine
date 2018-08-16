/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsqfixnor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 19:42:42 by wweng             #+#    #+#             */
/*   Updated: 2018/08/15 17:47:13 by wweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char **getquestion(char *argv, int *linenumber, char *nothingchar, char *obstaclechar, char *fillinsidechar)
{
    char **arr;
    char buf;
    int linenumber2;
    int xforinitial = -1;
    int yforinitial = 0;
    int malloctmpvar = 0;

    int choose = 0;
    int fopen;

    fopen = open(argv, O_RDONLY);
    while (read(fopen, &buf,  1))
    {
        if (buf >= '0' && buf <= '9')
        {
            *linenumber = (*linenumber * 10) + (buf - '0');
            choose = 1;
        }
        else if (choose == 1)
        {
            linenumber2 = 8352100 / *linenumber;
            arr = malloc(sizeof(char*)**linenumber);
            while (malloctmpvar < *linenumber)
            {
                arr[malloctmpvar] = malloc(sizeof(char)*linenumber2);
                malloctmpvar++;
            }

            *nothingchar = buf;
            choose++;
        }
        else if (choose == 2)
        {
            *obstaclechar = buf;
            choose++;
        }
        else if (choose == 3)
        {
            *fillinsidechar = buf;
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
    return arr;
}

void getwidth(char **arr, int *width, int *differentwidth, int linenumber, int nothingchar, int obstaclechar, int fillinsidechar)
{
    int howwidth;
    int k;

    k = 0;
    howwidth = 0;
    *differentwidth = 0;
    while (k < linenumber)
    {
        *width = 0;
        while (arr[k][*width] == nothingchar || arr[k][*width] == obstaclechar || arr[k][*width] == fillinsidechar)
            (*width)++;
        if ((howwidth != 0 && howwidth != *width) || *width == 0)
        {
            *differentwidth = 1;
            break;
        }
        else
            howwidth = *width;
        k++;
    }
}

void mainlogic(char **arr, int width, int linenumber, int obstaclechar, int fillinsidechar)
{
     //if each line is same
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
    int i;
    int j ;

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
    
}

void mainfunction(char *argv)
{
    int linenumber;
    char nothingchar; //.
    char obstaclechar; //o
    char fillinsidechar; //x
    char **arr;

    linenumber = 0;
    //===
    //Get Read
    arr = getquestion(argv, &linenumber, &nothingchar, &obstaclechar, &fillinsidechar);   // 回傳arr
    //===
    //Get Each Line 是否等寬
    //Get Width
    int width;
    int differentwidth;

    getwidth(arr, &width, &differentwidth, linenumber, nothingchar, obstaclechar, fillinsidechar);

    //===test map error
    if(differentwidth)
    {
        write(1, "map error\n", 10);
    }
    else
    {
        mainlogic(arr, width, linenumber, obstaclechar, fillinsidechar);
    } //if each line is same
}

int main(int argc, char **argv) 
{
    int i;

    i = 1;
    if (argc >= 2)
    {
    	while (i < argc)
        {
            mainfunction(argv[i]);
            i++;
        }
    }
    else
    {
        write(1, "No Map Are You Kidding Me?\n", 27);
    }
    return 0;
}

