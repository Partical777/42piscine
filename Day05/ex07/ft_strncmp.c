/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 15:20:24 by wweng             #+#    #+#             */
/*   Updated: 2018/07/31 15:26:30 by wweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	strncmp(char *s1, char *s2, unsigned int n)
{
	if (n == 0)
	{
		return (0);
	}
	if (*s1 != *s2++)
	{
		return (*(unsigned char *)s1 - *(unsigned char *)--s2);
	}
	if (*s1++ == 0)
	{
		break ;
	}
	while (--n != 0)
	{
		if (*s1 != *s2++)
		{
			return (*(unsigned char *)s1 - *(unsigned char *)--s2);
		}
		if (*s1++ == 0)
		{
			break ;
		}
	}
	return (0);
}
