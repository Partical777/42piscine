/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 16:18:27 by wweng             #+#    #+#             */
/*   Updated: 2018/07/31 16:38:52 by wweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
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
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			dest[i] = str[i] - 32;
		}
		i++;
	}
	dest[i] = '\0';
	str = dest;
	return (str);
}
