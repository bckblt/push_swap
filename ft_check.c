/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakarabu <bakarabu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:02:06 by bakarabu          #+#    #+#             */
/*   Updated: 2025/03/22 14:12:48 by bakarabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_intchk(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] && !(str[i + 1] >= '0'
				&& str[i + 1] <= '9') && str[i + 1] != '-' && str[i + 1] != '+')
			return (error_ft(str));
		if (str[i] == '-'
			&& (!str[i + 1] || !(str[i + 1] >= '0' && str[i + 1] <= '9')))
			return (error_ft(str));
		if (str[i] == '+'
			&& (!str[i + 1] || !(str[i + 1] >= '0' && str[i + 1] <= '9')))
			return (error_ft(str));
		if (str[i] != 32 && !(str[i] <= '9' && str[i] >= '0')
			&& str[i] != '-' && str[i] != '+')
			return (error_ft(str));
		i++;
	}
	return (1);
}

int	ft_sameint(t_list **list)
{
	t_list	*first;
	t_list	*second;

	first = (*list);
	second = first->next;
	while (first)
	{
		second = first->next;
		while (second)
		{
			if (first->data == second->data)
			{
				write (2, "Error\n", 6);
				return (1);
			}
			second = second->next;
		}
		first = first->next;
	}
	return (0);
}

int	ft_serial(t_list **stack_a)
{
	t_list	*tmp;

	if (!(*stack_a))
		return (1);
	tmp = (*stack_a);
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_revserial(t_list **stack_a)
{
	t_list	*tmp;

	if (!(*stack_a))
		return (1);
	tmp = (*stack_a);
	while (tmp->next)
	{
		if (tmp->data < tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_maxmin(t_list **stack)
{
	t_list	*tmp;

	tmp = (*stack);
	while (tmp)
	{
		if (tmp->data < -2147483648 || tmp->data > 2147483647)
		{
			write (2, "Error\n", 6);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}
