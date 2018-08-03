/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scrambler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 22:37:05 by wweng             #+#    #+#             */
/*   Updated: 2018/08/02 22:37:09 by wweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_scrambler(int ***a, int *b, int *******c, int ****d)
{
	int tmpa;
	int tmpb;
	int tmpc;
	int tmpd;

	tmpa = ***a;
	tmpb = *b;
	tmpc = *******c;
	tmpd = ****d;
	*******c = tmpa;
	****d = tmpc;
	*b = tmpd;
	***a = tmpb;
}
