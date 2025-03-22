/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakarabu <bakarabu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:01:51 by bakarabu          #+#    #+#             */
/*   Updated: 2025/03/22 09:31:21 by bakarabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_verstree(t_list **stack_a, t_list **stack_b, char *actions)
{
	if (ft_strcmp(actions, "rr") == 0)
	{
		rotate_stack(stack_a);
		rotate_stack(stack_b);
		write(1, "rr\n", 3);
	}
	else if (ft_strcmp(actions, "rra") == 0)
	{
		reverse_rotate(stack_a);
		write(1, "rra\n", 4);
	}
	else if (ft_strcmp(actions, "rrb") == 0)
	{
		reverse_rotate(stack_b);
		write(1, "rrb\n", 4);
	}
	else if (ft_strcmp(actions, "rrr") == 0)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		write(1, "rrr\n", 4);
	}
}

static void	ft_verstwo(t_list **stack_a, t_list **stack_b, char *actions)
{
	if (ft_strcmp(actions, "pa") == 0)
	{
		push_stack(stack_a, stack_b);
		write(1, "pa\n", 3);
	}
	else if (ft_strcmp(actions, "pb") == 0)
	{
		push_stack(stack_b, stack_a);
		write(1, "pb\n", 3);
	}
	else if (ft_strcmp(actions, "ra") == 0)
	{
		rotate_stack(stack_a);
		write(1, "ra\n", 3);
	}
	else if (ft_strcmp(actions, "rb") == 0)
	{
		rotate_stack(stack_b);
		write(1, "rb\n", 3);
	}
	else
		ft_verstree(stack_a, stack_b, actions);
}

void	ft_actions(t_list **stack_a, t_list **stack_b, char *actions)
{
	if (ft_strcmp(actions, "sa") == 0)
	{
		swap_stack(stack_a);
		write(1, "sa\n", 3);
	}
	else if (ft_strcmp(actions, "sb") == 0)
	{
		swap_stack(stack_b);
		write(1, "sb\n", 3);
	}
	else if (ft_strcmp(actions, "ss") == 0)
	{
		swap_stack(stack_a);
		swap_stack(stack_b);
		write(1, "ss\n", 3);
	}
	else
		ft_verstwo(stack_a, stack_b, actions);
}
