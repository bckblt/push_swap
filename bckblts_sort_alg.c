/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bckblts_sort_alg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakarabu <bakarabu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:02:04 by bakarabu          #+#    #+#             */
/*   Updated: 2025/03/20 18:48:08 by bakarabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_max(t_list **stack_a, t_list **stack_b, int max, int min)
{
	while ((*stack_a)->index + 1 != (*stack_a)->next->index)
	{
		ft_actions(stack_a, stack_b, "sa");
		if ((*stack_a)->index == min)
		{
			ft_actions(stack_a, stack_b, "pb");
			if (ft_serial(stack_a) && ft_revserial(stack_b))
			{
				while ((*stack_b))
					ft_actions(stack_a, stack_b, "pa");
			}
			min++;
		}
		else if ((*stack_a)->index != max - 1)
			ft_actions(stack_a, stack_b, "ra");
	}
	max--;
	return (max);
}

void	index_tmp_max(t_list **stack_a, t_list **stack_b, int tmp_max)
{
	if ((tmp_max == 3) && !((*stack_a)->index - 2 == (*stack_a)->next->index))
	{
		ft_actions(stack_a, stack_b, "sa");
		if (ft_serial(stack_a))
		{
			if(!(*stack_b))
				exit(1);
			else if(ft_serial(stack_a) && ft_revserial(stack_b))
			{
				while ((*stack_b))
					ft_actions(stack_a, stack_b, "pa");
				return ;
			}
		}
	}
	if (tmp_max == 5 && ((*stack_a)->next->index == 4
			|| (*stack_a)->next->index == 1))
	{
		ft_actions(stack_a, stack_b, "sa");
	}
	else
		ft_actions(stack_a, stack_b, "rra");
}

int	index_min(t_list **stack_a, t_list **stack_b, int min)
{
	ft_actions(stack_a, stack_b, "pb");
	if (ft_serial(stack_a) && ft_revserial(stack_b))
	{
		while ((*stack_b))
			ft_actions(stack_a, stack_b, "pa");
	}
	min++;
	return (min);
}

void	ft_short_sort(t_list **stack_a, t_list **stack_b, int max)
{
	int	min;
	int	tmp_max;

	min = 1;
	tmp_max = max;
	while (max)
	{
		if (ft_serial(stack_a) && ft_revserial(stack_b))
		{
			while ((*stack_b))
				ft_actions(stack_a, stack_b, "pa");
			return ;
		}
		else if ((*stack_a)->index == tmp_max)
		{
			index_tmp_max(stack_a, stack_b, tmp_max);
			max = tmp_max - 1;
		}
		else if ((*stack_a)->index == max)
			max = index_max(stack_a, stack_b, max, min);
		else if ((*stack_a)->index == min)
			min = index_min(stack_a, stack_b, min);
		else
			ft_actions(stack_a, stack_b, "rra");
	}
}
