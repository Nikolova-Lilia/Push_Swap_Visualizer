#include "push_swap.h"
//all functions related to reverse rotate and reverse rotate function itself

void    ft_reverse_rotate(t_list **stack)
{
    t_list  *last_node;
    int     len;

    len = ft_stack_length(*stack);
    if (stack == NULL || *stack == NULL || len == 1)
        return ;
    last_node = ft_find_last_node(*stack);
    last_node->prev->next = NULL;
    last_node->next = *stack;
    last_node->prev = NULL;
    *stack = last_node;
    last_node->next->prev = last_node;
}

void    ft_rra(t_list **stack_a)
{
    ft_reverse_rotate(stack_a);
    write(1, "rra\n", 4);
}

void    ft_rrb(t_list **stack_b)
{
    ft_reverse_rotate(stack_b);
    write(1, "rrb\n", 4);
}

void    ft_rrr(t_list **stack_a, t_list **stack_b)
{
    ft_reverse_rotate(stack_a);
    ft_reverse_rotate(stack_b);
    write(1, "rrr\n", 4);
}
