#include "push_swap.h"
//all functions related to swap and swap function itself

void    ft_swap(t_list **stack)
{
    int len;

    len = ft_stack_length(*stack);
    if (*stack == NULL || stack == NULL || len == 1)
        return ;
    *stack = (*stack)->next;
    (*stack)->prev->prev = *stack;
    (*stack)->prev->next = (*stack)->next;
    if ((*stack)->next)
        (*stack)->next->prev = (*stack)->prev;
    (*stack)->next = (*stack)->prev;
    (*stack)->prev = NULL;
}

void    ft_sa(t_list **stack_a)
{
    ft_swap(stack_a);
    write(1, "sa\n", 3);
}

void    ft_sb(t_list **stack_b)
{
    ft_swap(stack_b);
    write(1, "sb\n", 3);
}

void    ft_ss(t_list **stack_a, t_list **stack_b)
{
    ft_swap(stack_a);
    ft_swap(stack_b);
    write(1, "ss\n", 3);
}
