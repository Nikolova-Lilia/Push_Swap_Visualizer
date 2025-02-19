#include "push_swap.h"
//includes small functions helpers for finding best rotation to execute

void ft_case1(t_list *node, int rr_best1)
{
    node->num_rot = rr_best1;
    ft_trim_rot(node, (node->ra - node->rr), (node->rb - node->rr), node->rr);
    ft_trim_rev_rot(node, 0, 0, 0);
}

void ft_case2(t_list *node, int rrr_best2)
{
    node->num_rot = rrr_best2;
    ft_trim_rot(node, 0, 0, 0);
    ft_trim_rev_rot(node, (node->rra - node->rrr), (node->rrb - node->rrr), node->rrr);
}

void ft_case3(t_list *node, int no)
{
    node->num_rot = no;
    ft_trim_rot(node, node->ra, 0, 0);
    ft_trim_rev_rot(node, 0, node->rrb, 0);
}

void ft_case4(t_list *node, int on)
{
    node->num_rot = on;
    ft_trim_rot(node, 0, node->rb, 0);
    ft_trim_rev_rot(node, node->rra, 0, 0);
}

bool ft_convert_to_nbr(char *argv, t_list **stack)
{
    long nbr;

    nbr = ft_atol(argv);
    if (nbr > INT_MAX)
    {
        write(1, "Error\n", 6);
        return (false);
    }
    if (ft_create_node(stack, nbr) == false)
        return (false);
    return (true);
}
