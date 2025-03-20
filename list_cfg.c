/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_cfg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakarabu <bakarabu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:02:12 by bakarabu          #+#    #+#             */
/*   Updated: 2025/03/20 21:07:53 by bakarabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	int		i;
	int		c;
	long	result;

	result = 0;
	i = 0;
	c = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			c *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result *= c);
}

static void	ft_list_handle(t_list **stack, char **str, t_list *current)
{
	int		i;
	t_list	*new_node;

	i = 1;
	while (str[i])
	{
		new_node = (t_list *)malloc(sizeof(t_list));
		if (!new_node)
		{
			while (*stack)
			{
				current = (*stack)->next;
				free (*stack);
				*stack = current;
			}
			return ;
		}
		new_node->data = ft_atoi(str[i]);
		new_node->index = i + 1;
		new_node->next = NULL;
		current->next = new_node;
		current = current->next;
		i++;
	}
}

t_list	**ft_list_doldur(t_list **stack, char **str)
{
	t_list	*current;

	if (str[0])
	{
		*stack = (t_list *)malloc(sizeof(t_list));
		if (!*stack)
		{
			split_freed(str);
			return (NULL);
		}
		(*stack)->data = ft_atoi(str[0]);
		(*stack)->index = 1;
		(*stack)->next = NULL;
		current = *stack;
	}
	ft_list_handle(stack, str, current);
	split_freed(str);
	return (stack);
}

static void	index_utils(t_list **stack, int size, int *arr)
{
	int		i;
	int		j;
	int		x;
	t_list	*tmp;

	tmp = (*stack);
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->data;
		tmp = tmp->next;
	}
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				x = arr[i];
				arr[i] = arr[j];
				arr[j] = x;
			}
			j++;
		}
		i++;
	}
}

int	index_cfg(t_list **stack)
{
	t_list	*tmp;
	int		*arr;
	int		size;
	int		i;

	size = 0;
	tmp = (*stack);
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	index_utils(stack, size, arr);
	tmp = (*stack);
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] == tmp->data)
			{
				tmp->index = i + 1;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(arr);
	return (size);
}
