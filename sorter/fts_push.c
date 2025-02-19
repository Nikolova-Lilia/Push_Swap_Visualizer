#include "push_swap.h"
//all functions related to push and push function itself

void    ft_push(t_list **stack_a, t_list **stack_b)
{
    t_list  *node_to_push;

    if (stack_a == NULL)
        return ;
    node_to_push = *stack_a;
    *stack_a = (*stack_a)->next;
    if (*stack_a != NULL)
        (*stack_a)->prev = NULL;
    node_to_push->prev = NULL;
    if (*stack_b == NULL)
    {
        *stack_b = node_to_push;
        node_to_push->next = NULL;
    }
    else
    {
        node_to_push->next = *stack_b;
        node_to_push->next->prev = node_to_push;
        *stack_b = node_to_push;
    }
}

void    ft_pa(t_list **stack_a, t_list **stack_b)
{
    ft_push(stack_b, stack_a);
    write(1, "pa\n", 3);
}

void    ft_pb(t_list **stack_a, t_list **stack_b)
{
    ft_push(stack_a, stack_b);
    write(1, "pb\n", 3);
}
