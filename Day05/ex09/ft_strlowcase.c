/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 16:39:27 by wweng             #+#    #+#             */
/*   Updated: 2018/07/31 16:40:49 by wweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char dest[100];
	int len;
	int x;
	int i;

	len = strlen(str);
	x = 0;
	i = 0;
	while (i < len && str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			dest[i] = str[i] + 32;
		}
		i++;
	}
	dest[i] = '\0';
	str = dest;
	return (str);
}
