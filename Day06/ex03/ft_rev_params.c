/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 17:07:32 by wweng             #+#    #+#             */
/*   Updated: 2018/08/01 17:07:37 by wweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	my_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int i;

	i = 1;
	while (argv[i] != NULL)
	{
		i++;
	}
	while (i > 0)
	{
		my_putstr(argv[i]);
		ft_char('\n');
		i--;
	}
	return (0);
}
