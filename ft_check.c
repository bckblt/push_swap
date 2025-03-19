#include "push_swap.h"

int ft_intchk(char *str)
{
	int i;
	i = 0;
	while(str[i])
	{
		if(str[i] == '-' && !(str[i + 1] <= '9' && str[i +1 ] >= '0'))
		{
			write(2, "Error\n", 6);
			return(0);
		}
		if(str[i] != 32 && !(str[i] <= '9' && str[i] >= '0') && str[i] != '-')
		{
			write(2, "Error\n", 6);
			return(0);
		}
		i++;
	}
	return(1);
}

int ft_sameint(t_list **list)
{
	t_list *first;
	t_list *second;
	first = (*list);
	second = first->next;

	while(first)
	{
		second = first->next;
		while(second)
		{
			if(first->data == second->data)
			{
				write(2, "Error\n", 6);
				return (1); // Hata kodu döndür
			}
			second = second->next;
		}
		first = first->next;
	}
	if(ft_serial(list))
		return (1);
	return (0);
}

int ft_serial(t_list **stack_a)
{
	t_list *tmp;
	if(!(*stack_a))
		return(1);
	tmp = (*stack_a);
	while(tmp->next)
	{
		if(tmp->data > tmp->next->data)
			return 0;
		tmp = tmp->next;
	}
	return (1);
}

int ft_revserial(t_list **stack_a)
{
	t_list *tmp;
	if(!(*stack_a))
		return(1);
	tmp = (*stack_a);
	while(tmp->next)
	{
		if(tmp->data < tmp->next->data)
			return 0;
		tmp = tmp->next;
	}
	return (1);
}

int ft_maxmin(t_list **stack)
{
	t_list *tmp;
	tmp = (*stack);
	while(tmp->next)
	{
		if(tmp->data < -2147483648 || tmp->data > 2147483647)
		{
			write(2, "Error\n", 6);
			return(0);
		}
		tmp = tmp->next;
	}
	return(1);
}