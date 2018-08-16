/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 16:34:40 by xwang             #+#    #+#             */
/*   Updated: 2018/08/11 19:51:53 by xwang            ###   ########.fr       */
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

    i = 0;
    x = 0;
    y = 0;
	width = 0;
	height = 0;
	recordlock = 0;
	while (read(0, &buf,  1))
    {
		if (buf != '\n')
		{
			x++;
			if (recordlock)
			{
				bottomleft = buf;	//record bottomleft
			}
		}
		if (buf == '\n')
		{
			if (y == 0)
			{
				width = x;
				topright = buf;		//record topright
			}
			else if (width != x)
			{
				write(1, "aucune\n", 7);
				return (1);
			}
			y++;
			x = 0;
			recordlock = 1;
		}
	}
	height = y;
	if (topright == 'o')
		printf("Rush00");
	else if (topright == '\\')
		printf("Rush01");
	else if (topright == 'A')
		printf("Rush02");
	else if (topright == 'C' && bottomleft == 'A')
		printf("Rush03");
	else if (topright == 'C' && bottomleft == 'C')
		printf("Rush04");
	printf("Width: %d\n", width);
	printf("Height: %d\n", height);
	

    i = 0;
    while (arr[i])
    {
        ft_putstr(arr[i]);
        i++;
    }
    return (0);
}
