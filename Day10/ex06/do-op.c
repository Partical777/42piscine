/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:33:53 by wweng             #+#    #+#             */
/*   Updated: 2018/08/07 16:04:37 by wweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	chartoint(char *num)
{
	int i;
	int sum;

	i = 0;
	sum = 0;
	while (num[i] != '\0')
	{
		sum = sum * 10 + (num[i] - '0');
		i++;
	}
	return (sum);
}

int	main(int argc, char **argv)
{
	int x;
	int y;

	if (argc == 4)
	{
		x = chartoint(argv[1]);
		y = chartoint(argv[3]);
		if (*argv[2] == '+')
		{
			printf("%d\n", x + y);
		}
		else if (*argv[2] == '-')
		{
			printf("%d\n", x - y);
		}
		else if (*argv[2] == '*')
		{
			printf("%d\n", x * y);
		}
		else if (*argv[2] == '/')
		{
			printf("%d\n", x / y);
		}
	}
	return (0);
}
