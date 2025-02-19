#include "push_swap.h"
//functions for stack posible rotations

void    ft_calc_r_and_rr(t_list *target_node, int *r, int *rr)
{
    t_list *temp;

    if (target_node->prev != NULL)
    {
        temp = target_node;
        while (temp->prev != NULL)
        {
            (*r)++;
            temp = temp->prev;
        }
        temp = target_node;
        while (temp != NULL)
        {
            (*rr)++;
            temp = temp->next;
        }
    }
}

void    ft_rotate_stack(int *node_int, void (*operation)(t_list **), t_list **stack)
{
    while (*node_int > 0)
    {
        operation(stack);
        (*node_int)--;
    }
}

void    ft_rotate_stack2(int *node_int, void (*operation)(t_list **, t_list **), t_list **stack, t_list **stack2)
{
    while (*node_int > 0)
    {
        operation(stack, stack2);
        (*node_int)--;
    }   
}

void    ft_sort_rotation(t_list *node, t_list **stack_a, t_list **stack_b)
{
    ft_rotate_stack(&(node->ra), ft_ra, stack_a);
    ft_rotate_stack(&(node->rb), ft_rb, stack_b);
    ft_rotate_stack(&(node->rra), ft_rra, stack_a);
    ft_rotate_stack(&(node->rrb), ft_rrb, stack_b);
    ft_rotate_stack2(&(node->rr), ft_rr, stack_a, stack_b);
    ft_rotate_stack2(&(node->rrr), ft_rrr, stack_a, stack_b);
}

void    ft_rotate_and_push_ba(t_list **stack_a, t_list **stack_b)
{
    t_list  *target_node;
    int     r;
    int     rr;

    while (*stack_b != NULL)
    {
        r = 0;
        rr = 0;
        target_node = ft_find_target2(*stack_a, *stack_b);
        ft_calc_r_and_rr(target_node, &r,&rr);
        if (rr < r)
            ft_rotate_stack(&rr, ft_rra, stack_a);
        else
            ft_rotate_stack(&r, ft_ra, stack_a);
        ft_pa(stack_a, stack_b);
    }
}
