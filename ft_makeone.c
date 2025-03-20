/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makeone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakarabu <bakarabu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:02:09 by bakarabu          #+#    #+#             */
/*   Updated: 2025/03/20 12:55:25 by bakarabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	total_size(char **av)
{
	int		i;
	int		j;
	int		x;

	i = 1;
	j = 0;
	x = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			x++;
			j++;
		}
		x++;
		i++;
	}
	return (x);
}

char	*ft_makeone(char **av)
{
	int		i;
	int		j;
	int		x;
	char	*res;

	x = total_size(av);
	res = malloc(sizeof(char) * (x + 1));
	if (!res)
		return (NULL);
	i = 1;
	x = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
			res[x++] = av[i][j++];
		i++;
		if (av[i])
			res[x] = ' ';
		x++;
	}
	res[x] = '\0';
	return (res);
}
