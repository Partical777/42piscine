/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainlogic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 20:58:08 by wweng             #+#    #+#             */
/*   Updated: 2018/08/15 22:20:24 by wweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	fillanswer(char **arr, char fillinsidechar, int *fl)
{
	int a;
	int b;

	a = fl[2];
	while (a < fl[2] + fl[0])
	{
		b = fl[3];
		while (b < (fl[3] + fl[0]))
		{
			arr[a][b] = fillinsidechar;
			b++;
		}
		a++;
	}
}

void	printanswer(char **arr, int linenumber, int width)
{
	int i;
	int j;

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

void	fgr(int *fm)
{
	fm[2] = fm[4];
	fm[3] = fm[5];
	fm[0] = fm[6];
}

int		insidemainlogic(int *fm, char **arr, char obstaclechar)
{
	fm[1] = 0;
	fm[7] = 0;
	while (fm[7] < fm[6])
	{
		fm[8] = 0;
		while (fm[8] < fm[6])
		{
			if (arr[fm[4] + fm[7]][fm[5] + fm[8]] == obstaclechar)
			{
				fm[1] = 1;
				break ;
			}
			fm[8]++;
		}
		if (fm[1] == 1)
			break ;
		fm[7]++;
	}
	if (fm[1] == 0)
	{
		fgr(fm);
		return (0);
	}
	fm[6]--;
	return (1);
}
