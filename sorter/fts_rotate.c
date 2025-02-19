#include "push_swap.h"
//all functions related to rotate and rotate function itself

void    ft_rotate(t_list **stack)
{
    t_list  *last_node;
    int     len;

    len = ft_stack_length(*stack);
    if (stack == NULL || *stack == NULL || len == 1)
        return ;
    last_node = ft_find_last_node(*stack);
    last_node->next = *stack;
    (*stack) = (*stack)->next;
    (*stack)->prev = NULL;
    last_node->next->prev = last_node;
    last_node->next->next = NULL;
}

void    ft_ra(t_list **stack_a)
{
    ft_rotate(stack_a);
    write(1, "ra\n", 3);
}

void    ft_rb(t_list **stack_b)
{
    ft_rotate(stack_b);
    write(1, "rb\n", 3);
}

void    ft_rr(t_list **stack_a, t_list **stack_b)
{
    ft_rotate(stack_a);
    ft_rotate(stack_b);
    write(1, "rr\n", 3);
}
