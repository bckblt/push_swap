/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vers2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakarabu <bakarabu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:02:25 by bakarabu          #+#    #+#             */
/*   Updated: 2025/03/22 12:37:38 by bakarabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	error_ft(char *str)
{
	write (2, "Error\n", 6);
	free(str);
	return (0);
}

int	ft_stclen(t_list **stack)
{
	int		i;
	t_list	*tmp;

	tmp = (*stack);
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_stctoarr(t_list **stack, int *arr)
{
	int		i;
	t_list	*tmp;

	tmp = (*stack);
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->data;
		tmp = tmp->next;
	}
}
