/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakarabu <bakarabu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:02:19 by bakarabu          #+#    #+#             */
/*   Updated: 2025/03/20 12:28:45 by bakarabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	if (!stack || !*stack)
		return (0);
	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	ft_radix_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	i;
	int	j;
	int	max_bits_len;

	if (!stack_a || !*stack_a)
		return ;
	i = 0;
	max_bits_len = max_bits(stack_a);
	while (i < max_bits_len)
	{
		j = 0;
		while (*stack_a && j++ < size)
		{
			if (((*stack_a)->index >> i) & 1)
				ft_actions(stack_a, stack_b, "ra");
			else
				ft_actions(stack_a, stack_b, "pb");
		}
		while (*stack_b)
			ft_actions(stack_a, stack_b, "pa");
		i++;
	}
}

void	ft_sort(t_list **stack_a, t_list **stack_b, int size)
{
	if (size < 10)
		ft_short_sort(stack_a, stack_b, size);
	else
		ft_radix_sort(stack_a, stack_b, size);
}
