#include "push_swap.h"
//includes small functions helpers for finding best number to push

t_list  *ft_next_nbr(t_list *stack_a, t_list *stack_b)
{
    t_list  *node;

    node = stack_a;
    while (stack_a != NULL)
    {
        ft_calc_rotations(stack_a, stack_b);
        ft_find_index(stack_a);
        if (node->num_rot > stack_a->num_rot)
            node = stack_a;
        stack_a = stack_a->next;
    }
    return (node);
}

void    ft_find_index(t_list *node_a)
{
    int rr_best1;
    int rrr_best2;
    int no;
    int on;

    if (node_a->ra > node_a->rb)
        node_a->rr = node_a->rb;
    else
        node_a->rr = node_a->ra;
    if (node_a->rra > node_a->rrb)
        node_a->rrr = node_a->rrb;
    else
        node_a->rrr = node_a->rra;
    rr_best1 = (node_a->ra + node_a->rb) - node_a->rr;
    rrr_best2 = (node_a->rra + node_a->rrb) - node_a->rrr;
    no = (node_a->ra + node_a->rrb);
    on = (node_a->rra + node_a->rb);
    if (rr_best1 < rrr_best2 && rr_best1 < no && rr_best1 < on)
        ft_case1(node_a, rr_best1);
    else if (rrr_best2 < rr_best1 && rrr_best2 < no && rrr_best2 < on)
        ft_case2(node_a, rrr_best2);
    else if (no < rr_best1 && no < rrr_best2 && no < on)
        ft_case3(node_a, no);
    else
        ft_case4(node_a, on);
}

void    ft_trim_rot(t_list *node, int ra, int rb, int rr)
{
    node->ra = ra;
    node->rb = rb;
    node->rr = rr;
}

void    ft_trim_rev_rot(t_list *node, int rra, int rrb, int rrr)
{
    node->rra = rra;
    node->rrb = rrb;
    node->rrr = rrr;
}
