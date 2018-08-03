/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 19:26:01 by wweng             #+#    #+#             */
/*   Updated: 2018/08/02 19:29:11 by wweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_takes_place(int hour)
{
	char *str;

	str = "THE FOLLOWING TAKES PLACE BETWEEN";
	if (hour == 0)
		printf("%s %d.00 A.M. AND %d.00 A.M.", str, 12, hour + 1);
	else if (hour == 24)
		printf("%s %d.00 A.M. AND %d.00 A.M.", str, 12, (hour + 1) % 12);
	else if (hour == 12)
		printf("%s %d.00 P.M. AND %d.00 P.M.", str, hour, (hour + 1) % 12);
	else if (hour == 11)
		printf("%s %d.00 A.M. AND %d.00 P.M.", str, hour, hour + 1);
	else if (hour == 23)
		printf("%s %d.00 P.M. AND %d.00 A.M.", str, hour % 12, 12);
	else if (hour > 12)
		printf("%s %d.00 P.M. AND %d.00 P.M.", str, hour % 12, (hour + 1) % 12);
	else
		printf("%s %d.00 A.M. AND %d.00 A.M.", str, hour, hour + 1);
}
