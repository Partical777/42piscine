/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getquestion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 20:57:52 by wweng             #+#    #+#             */
/*   Updated: 2018/08/15 22:19:48 by wweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	**mapmalloc(int *fq, int *linenumber, char *nothingchar, char buf)
{
	char **arr;

	fq[0] = 8352100 / *linenumber;
	arr = malloc(sizeof(char*) * *linenumber);
	while (fq[3] < *linenumber)
	{
		arr[fq[3]] = malloc(sizeof(char) * fq[0]);
		fq[3]++;
	}
	*nothingchar = buf;
	fq[4]++;
	return (arr);
}

void	choosecharacter(char **arr, int *fq, char *fcs, char buf)
{
	if (fq[4] == 2)
	{
		fcs[1] = buf;
		fq[4]++;
	}
	else if (fq[4] == 3)
	{
		fcs[2] = buf;
		fq[4]++;
	}
	else if (fq[4] == 4)
	{
		if (buf != '\n')
		{
			arr[fq[1]][fq[2]] = buf;
			fq[2]++;
		}
		else if (buf == '\n')
		{
			fq[1]++;
			fq[2] = 0;
		}
	}
}

char	**getquestion(char *argv, int *linenumber, char *fcs)
{
	char	**arr;
	char	buf;
	int		fgq[6];

	fgq[1] = -1;
	fgq[2] = 0;
	fgq[3] = 0;
	fgq[4] = 0;
	fgq[5] = open(argv, O_RDONLY);
	while (read(fgq[5], &buf, 1))
	{
		if (buf >= '0' && buf <= '9')
		{
			*linenumber = (*linenumber * 10) + (buf - '0');
			fgq[4] = 1;
		}
		else if (fgq[4] == 1)
			arr = mapmalloc(fgq, linenumber, &fcs[0], buf);
		else
			choosecharacter(arr, fgq, fcs, buf);
	}
	return (arr);
}
