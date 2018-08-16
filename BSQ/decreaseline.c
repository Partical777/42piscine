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

int insidemainlogic(int *fuckmainlogic, char **arr, char obstaclechar)
{
    fuckmainlogic[1] = 0;
    fuckmainlogic[7] = 0;
    while (fuckmainlogic[7] < fuckmainlogic[6])
    {
        fuckmainlogic[8] = 0 ;
        while (fuckmainlogic[8] < fuckmainlogic[6])
        {
            if (arr[fuckmainlogic[4] + fuckmainlogic[7]][fuckmainlogic[5] + fuckmainlogic[8]] == obstaclechar)
            {
                fuckmainlogic[1] = 1;
                break;
            }
            fuckmainlogic[8]++;
        }
        if (fuckmainlogic[1] == 1)
            break;
        fuckmainlogic[7]++;
    }
    if (fuckmainlogic[1] == 0)
    {
        fuckmainlogic[2] = fuckmainlogic[4];
        fuckmainlogic[3] = fuckmainlogic[5];
        fuckmainlogic[0] = fuckmainlogic[6];
        return 0;
    }
    fuckmainlogic[6]--;
    return 1;
}

void mainlogic(int defaultnumber, char **arr, int width, int linenumber, int obstaclechar, int fillinsidechar)
{
    int fuckmainlogic[9];

    while (defaultnumber < 5)
    {
        fuckmainlogic[defaultnumber] = 0;
        defaultnumber++;
    }
    while (fuckmainlogic[4] < (linenumber - fuckmainlogic[0]))
    {
        fuckmainlogic[5] = 0;
        while (fuckmainlogic[5] < (width - fuckmainlogic[0]))
        {
            fuckmainlogic[6] = (linenumber - fuckmainlogic[4]);
            while (fuckmainlogic[6] > fuckmainlogic[0])
            {
                if(!(insidemainlogic(fuckmainlogic, arr, obstaclechar)))
                    break;
            }
            fuckmainlogic[5]++;
        }
        fuckmainlogic[4]++;
    }
    fillanswer(arr, fuckmainlogic[0], fillinsidechar, fuckmainlogic[2], fuckmainlogic[3]);
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
    int     defaultnumber;

    linenumber = 0;
    defaultnumber = 0;
    arr = getquestion(argv, &linenumber, &nothingchar, &obstaclechar, &fillinsidechar);
    getwidth(arr, &width, &differentwidth, linenumber, nothingchar, obstaclechar, fillinsidechar);
    if(differentwidth)
        write(1, "map error\n", 10);
    else
        mainlogic(defaultnumber, arr, width, linenumber, obstaclechar, fillinsidechar);
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

