/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 16:34:40 by xwang             #+#    #+#             */
/*   Updated: 2018/08/12 10:59:13 by wweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void    ft_putstr(char *str)
{
    int     i;
    i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        	i++;
    }
}

int     main(void)
{
    char    **arr;
    int     x;
    int     y;
    char    buf;
    int     i;
	int		width;
	int		height;
	char	topright;
	char	bottomleft;
	int		recordlock;
	int		recordlocktoponlyfirstline;

    i = 0;
    x = 0;
    y = 0;
	width = 0;
	height = 0;
	recordlocktoponlyfirstline = 1;
	recordlock = 0;
	while (read(0, &buf,  1))
    {
		if (buf != '\n')
		{
			x++;
			if (recordlocktoponlyfirstline)
			{
				topright = buf;		//record topright
			}
			if (recordlock)
			{
				bottomleft = buf;	//record bottomleft
				recordlock = 0;
			}
			arr[i] = buf;
			i++;
		}
		if (buf == '\n')
		{
			if (y == 0)
			{
				width = x;
			}
			else if (width != x)
			{
				write(1, "aucune\n", 7);
				return (1);
			}
			y++;
			x = 0;
			recordlocktoponlyfirstline = 0;
			recordlock = 1;
		}
	}
	arr[i] = '\n';
	height = y;

	i = 0;
    while (arr[i])
    {
        ft_putstr(arr[i]);
        i++;
    }

	if (width == 1 && height == 1 && topright == 'A')
		printf("Rush02 || Rush03 || Rush04\n");
	else if (width == 1 && bottomleft == 'C')
		printf("Rush02 || Rush04\n");
	else if (height == 1 && topright == 'C')
		printf("Rush03 || Rush04\n");
	else if (topright == 'o')
		printf("Rush00\n");
	else if (topright == '\\')
		printf("Rush01\n");
	else if (topright == 'A')
		printf("Rush02\n");
	else if (topright == 'C' && bottomleft == 'A')
		printf("Rush03\n");
	else if (topright == 'C' && bottomleft == 'C')
		printf("Rush04\n");
	printf("Width: %d\n", width);
	printf("Height: %d\n", height);
	
    return (0);
}
