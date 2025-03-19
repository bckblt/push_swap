#include "push_swap.h"

void swap_stack(t_list **stack)
{
    t_list *first;
    t_list *second;

    if (!(*stack) || !((*stack)->next))
        return;
    
    first = *stack;
    second = first->next;

    first->next = second->next;
    second->next = first;

    *stack = second;
}

void push_stack(t_list **stack_first, t_list **stack_second)
{
    t_list *tmp;

    if (!stack_first || !stack_second || !(*stack_second))
        return;

    tmp = *stack_second;
    *stack_second = tmp->next;
    tmp->next = *stack_first;
    *stack_first = tmp;
}

void rotate_stack(t_list **stack)
{
    t_list *first;
    t_list *last;

    if (!stack || !(*stack) || !((*stack)->next))
        return;

    first = *stack;
    last = *stack;

    while (last->next)
        last = last->next;

    *stack = first->next;
    first->next = NULL;
    last->next = first;
}

void reverse_rotate(t_list **stack)
{
    t_list *prev, *last;

    if (!stack || !(*stack) || !((*stack)->next))
        return;

    prev = NULL;
    last = *stack;

    while (last->next)
    {
        prev = last;
        last = last->next;
    }

    if (prev)
        prev->next = NULL;

    last->next = *stack;
    *stack = last;
}