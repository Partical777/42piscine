/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 22:58:19 by wweng             #+#    #+#             */
/*   Updated: 2018/08/06 23:27:58 by wweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_foreach(int *tab, int length, void(*f)(int))
{
	int i;
   
	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++:
	}
}
