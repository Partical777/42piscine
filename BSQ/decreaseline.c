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
    int xforinitial;
    int yforinitial;
    int malloctmpvar;
    int choose;
    int fopen;

    xforinitial = -1;
    yforinitial = 0;
    malloctmpvar = 0;
    choose = 0;
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

void fillanswer(char **arr, int biggestsofar, char fillinsidechar, int pointx, int pointy)
{
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
}

void printanswer(char **arr, int linenumber, int width)
{
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
}

void mainlogic(char **arr, int width, int linenumber, int obstaclechar, int fillinsidechar)
{
    int biggestsofar;
    int obstacle;
    int pointx;
    int pointy;
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
                        break;
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
    fillanswer(arr, biggestsofar, fillinsidechar, pointx, pointy);
    printanswer(arr, linenumber, width);
}

void mainfunction(char *argv)
{
    int     linenumber;
    char    nothingchar; //.
    char    obstaclechar; //o
    char    fillinsidechar; //x
    char    **arr;
    int     width;
    int     differentwidth;

    linenumber = 0;
    arr = getquestion(argv, &linenumber, &nothingchar, &obstaclechar, &fillinsidechar);
    getwidth(arr, &width, &differentwidth, linenumber, nothingchar, obstaclechar, fillinsidechar);
    if(differentwidth)
        write(1, "map error\n", 10);
    else
        mainlogic(arr, width, linenumber, obstaclechar, fillinsidechar);
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

