#include "push_swap.h"

void ft_freed(t_list **stack_a, t_list **stack_b)
{
    t_list *tmp;

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
void split_freed(char **split_arr)
{
    int i = 0;
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
int main(int ac, char **av)
{
	if(ac == 1 || !av[1] || av[1][0] == '\0')
		return (0);
	char *arg;
	t_list **stack_a;
	t_list **stack_b;

	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));

	if (!stack_a || !stack_b)
		ft_freed(stack_a, stack_b);

	*stack_a = NULL;
	*stack_b = NULL;

	arg = ft_makeone(av);
	if(!ft_intchk(arg))
	{
		free(arg);
		ft_freed(stack_a, stack_b);
	}
	char **split_av;
	split_av = ft_split(arg, ' ');
	free(arg);
	if (!split_av)
		ft_freed(stack_a, stack_b);
	stack_a = ft_list_doldur(stack_a, split_av);
	split_freed(split_av);
	if (ft_sameint(stack_a))
		ft_freed(stack_a, stack_b);

	if(ft_serial(stack_a))
		ft_freed(stack_a, stack_b);
	if(!ft_maxmin(stack_a))
		ft_freed(stack_a, stack_b);
	int size = index_cfg(stack_a);
	ft_sort(stack_a, stack_b, size);
	ft_freed(stack_a, stack_b);
	return (0);
}