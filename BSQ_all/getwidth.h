/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getwidth.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 20:58:27 by wweng             #+#    #+#             */
/*   Updated: 2018/08/15 22:19:38 by wweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	getwidth(char **arr, int *fint, int linenumber, char *fcs)
{
	int howwidth;
	int k;

	k = 0;
	howwidth = 0;
	fint[2] = 0;
	while (k < linenumber)
	{
		fint[1] = 0;
		while (arr[k][fint[1]] == fcs[0]
				|| arr[k][fint[1]] == fcs[1]
				|| arr[k][fint[1]] == fcs[2])
			(fint[1])++;
		if ((howwidth != 0 && howwidth != fint[1]) || fint[1] == 0)
		{
			fint[2] = 1;
			break ;
		}
		else
			howwidth = fint[1];
		k++;
	}
}
