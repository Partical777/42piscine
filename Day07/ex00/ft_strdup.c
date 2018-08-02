/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 20:54:29 by wweng             #+#    #+#             */
/*   Updated: 2018/08/01 21:41:02 by wweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	size_t		i;
	size_t		len;
	char		*result;

	i = 0;
	len = strlen(src);
	*result = malloc(len + 1);
	while (i <= len)
	{
		result[i] = src[i];
	}
	return (result);
}
