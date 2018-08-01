/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 21:46:11 by wweng             #+#    #+#             */
/*   Updated: 2018/07/31 21:53:33 by wweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int x;
	int i;
	int door;
	char dest[100];

	x = 0;
	i = 0;
	door = 0;
	while (str[i] != '\0')
	{
		if (door == 0)
		{
			if (str[i] >= 48 && str[i] <= 57)
			{
				dest[i] = str[i];
				door = 1;
			}
			else if (str[i] >= 'a' && str[i] <= 'z')
			{
				dest[i] = str[i] - 32;
				door = 1;
			}
			else
			{
				dest[i] = str[i];
			}
		}
		else
		{
			if (str[i] < 'a' || str[i] > 'z')
			{
				if (str[i] >= 48 & str[i] <= 57)
				{
					dest[i] = str[i];
					door = 1;
				}
				else if (str[i] == 32)
				{
					dest[i] = 32;
					door = 0;
				}
				else
				{
					dest[i] = str[i];
					door = 0;
				}
			}
			else
			{
				dest[i] = str[i];
			}
		}
		i++;
	}
	dest[i] = '\0';
	str = dest;
	return (str);
}
