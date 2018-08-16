/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 19:42:42 by wweng             #+#    #+#             */
/*   Updated: 2018/08/15 22:18:49 by wweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "getquestion.h"
#include "mainlogic.h"
#include "getwidth.h"

void	mainlogic(int *fint, char **arr, int obstaclechar, int fillinsidechar)
{
	int fl[9];

	while (fint[3] < 5)
	{
		fl[fint[3]] = 0;
		fint[3]++;
	}
	while (fl[4] < (fint[0] - fl[0]))
	{
		fl[5] = 0;
		while (fl[5] < (fint[1] - fl[0]))
		{
			fl[6] = (fint[0] - fl[4]);
			while (fl[6] > fl[0])
			{
				if (!(insidemainlogic(fl, arr, obstaclechar)))
					break ;
			}
			fl[5]++;
		}
		fl[4]++;
	}
	fillanswer(arr, fillinsidechar, fl);
	printanswer(arr, fint[0], fint[1]);
}

void	mainfunction(char *argv)
{
	char	fcs[3];
	char	**arr;
	int		fint[4];

	fint[0] = 0;
	fint[3] = 0;
	arr = getquestion(argv, &fint[0], fcs);
	getwidth(arr, fint, fint[0], fcs);
	if (fint[2])
		write(1, "map error\n", 10);
	else
		mainlogic(fint, arr, fcs[1], fcs[2]);
}

int		main(int argc, char **argv)
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
		write(1, "No Map Are You Kidding Me?\n", 27);
	return (0);
}
