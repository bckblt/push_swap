/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_cfg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakarabu <bakarabu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:02:12 by bakarabu          #+#    #+#             */
/*   Updated: 2025/03/22 15:35:44 by bakarabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atoi(const char *str)
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
		new_node->index = -1;
		new_node->next = NULL;
		current->next = new_node;
		current = current->next;
		i++;
	}
}

t_list	**ft_list_fill(t_list **stack, char **str)
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
		(*stack)->index = -1;
		(*stack)->next = NULL;
		current = *stack;
	}
	ft_list_handle(stack, str, current);
	split_freed(str);
	return (stack);
}

static t_list	*find_min(t_list **stack_a)
{
	t_list	*head;
	t_list	*min;

	min = NULL;
	head = *stack_a;
	while (head)
	{
		if ((min == NULL || head->data < min->data) && head->index == -1)
			min = head;
		head = head->next;
	}
	return (min);
}

int	index_cfg(t_list **stack)
{
	t_list	*head;
	int		i;

	i = 1;
	head = find_min(stack);
	while (head)
	{	
		head->index = i;
		i++;
		head = find_min(stack);
	}
	return (ft_stclen(stack));
}
