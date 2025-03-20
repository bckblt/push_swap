/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakarabu <bakarabu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:02:15 by bakarabu          #+#    #+#             */
/*   Updated: 2025/03/20 19:47:58 by bakarabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freed(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (stack_a)
	{
		while (*stack_a)
		{
			tmp = (*stack_a)->next;
			free(*stack_a);
			*stack_a = tmp;
		}
		free(stack_a);
	}
	if (stack_b)
	{
		while (*stack_b)
		{
			tmp = (*stack_b)->next;
			free(*stack_b);
			*stack_b = tmp;
		}
		free(stack_b);
	}
	exit (1);
}

void	split_freed(char **split_arr)
{
	int	i;

	i = 0;
	if (split_arr)
	{
		while (split_arr[i])
		{
			free(split_arr[i]);
			i++;
		}
		free(split_arr);
	}
}

void	ft_cheker(t_list **stack_a, t_list **stack_b)
{
	if (ft_sameint(stack_a))
		ft_freed(stack_a, stack_b);
	if (ft_maxmin(stack_a) == 0)
		ft_freed(stack_a, stack_b);
	if (ft_serial(stack_a))
		ft_freed(stack_a, stack_b);
}

int	ft_numchk(char **str)
{
	int i;
	int j;

	j = 0;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			if (str[j][i] >= '0' && str[j][i] <= '9')
			{
				if (str[j][i + 1] && !(str[j][i + 1] >= '0' && str[j][i + 1] <= '9'))
				{
					if (str[j][i + 1] && str[j][i + 1] != ' ' && str[j][i + 1] != '\0')
						return (1);
				}
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		size;
	char	**split_av;
	char	*arg;
	t_list	**stack_a;
	t_list	**stack_b;

	if (ac == 1 || !av[1])
		return (0);
	if(av[1][0] == '\0')
	{
		write(2, "Error\n", 6);
		return (0);
	}
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	arg = ft_makeone(av);
	if (!ft_intchk(arg))
		ft_freed(stack_a, stack_b);
	split_av = ft_split(arg, ' ');
	if (!split_av)
		ft_freed(stack_a, stack_b);
	if(ft_numchk(split_av))
	{
		write(2, "Error\n", 6);
		ft_freed(stack_a, stack_b);
	}
	stack_a = ft_list_doldur(stack_a, split_av);
	ft_cheker(stack_a, stack_b);
	size = index_cfg(stack_a);
	ft_sort(stack_a, stack_b, size);
	ft_freed(stack_a, stack_b);
	return (0);
}
