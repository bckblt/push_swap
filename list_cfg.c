#include "push_swap.h"

long	ft_atoi(const char *str)
{
	int	i;
	int	c;
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
    result *= c;

	return (result);
}

t_list **ft_list_doldur(t_list **stack, char **str)
{
    int i;
    t_list *new_node;
    t_list *current;
    
    i = 0;

    if (str[i])
    {
        *stack = (t_list *)malloc(sizeof(t_list));
        if (!*stack)
            return NULL;
        (*stack)->data = ft_atoi(str[i]);
		(*stack)->index = i + 1;
        (*stack)->next = NULL;
        current = *stack;
        i++;
    }

    while (str[i])
    {
        new_node = (t_list *)malloc(sizeof(t_list)); 
        if (!new_node)
        {
            while (*stack)
            {
                current = (*stack)->next;
                free(*stack);
                *stack = current;
            }
            return NULL;
        }
        new_node->data = ft_atoi(str[i]);
		new_node->index = i + 1;
        new_node->next = NULL;
        current->next = new_node;
        current = current->next;
        i++;
    }

    return stack;
}

void index_utils(t_list **stack, int size, int *arr)
{
    int i;
    int j;
    t_list *tmp;
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
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            j++;
        }
        i++;
    }

}

int index_cfg(t_list **stack)
{
    t_list *tmp;
    int *arr;
    int size;
    int i;
    size = 0;
    tmp = (*stack);
    while (tmp)
    {
        size++;
        tmp = tmp->next;
    }

    arr = malloc(sizeof(int) * size);
    if (!arr)
        return 0;
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
                break;
            }
            i++;
        }
        tmp = tmp->next;
    }
    free(arr);
    return (size);
}

void stack_yazdir(t_list **stack)
{
	t_list *tmp;
	tmp = *stack;
	while(tmp != NULL) 
	{
		printf("%ld || %d\n", tmp->data, tmp->index);
		tmp = tmp->next;
	}	
}
