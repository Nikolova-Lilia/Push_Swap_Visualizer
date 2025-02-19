#include "push_swap.h"
//functions calculating rotations, checking what move would be better

void    ft_calc_rotations(t_list *node_a, t_list *stack_b)
{
    t_list  *target_node;

    target_node = ft_find_target1(stack_b, node_a);
    node_a->ra = 0;
    node_a->rb = 0;
    node_a->rra = 0;
    node_a->rrb = 0;
    node_a->rr = 0;
    node_a->rrr = 0;
    ft_calc_stack_a(node_a);
    ft_calc_stack_b(node_a, target_node);
}

t_list  *ft_find_target1(t_list *stack1, t_list *stack2)
{
    t_list  *node_start;
    t_list  *node_end;
    t_list  *temp;
    int     len;
    int     i;

    len = ft_stack_length(stack1);
    i = 0;
    node_start = stack1;
    node_end = ft_find_last_node(stack1);
    temp = ft_find_biggest_node(stack1);
    node_end->next = node_start;
    while (stack2->value < temp->value && i < len)
    {
        temp = temp->next;
        i++;
    }
    node_end->next = NULL;
    if (i == len)
    {
        if (stack2->value < ft_find_min_node(stack1)->value)
            return (ft_find_biggest_node(stack1));
        else
            return (ft_find_min_node(stack1));
    }
    return (temp);
}

void    ft_calc_stack_a(t_list *node_a)
{
    t_list  *temp;

    if (node_a->prev != NULL)
    {
        temp = node_a;
        while (temp->prev != NULL)
        {
            node_a->ra++;
            temp = temp->prev;
        }
        temp = node_a;
        while (temp != NULL)
        {
            node_a->rra++;
            temp = temp->next;
        }
    }
}

void    ft_calc_stack_b(t_list *node_a, t_list *target_node)
{
    t_list  *temp;

    if (target_node->prev != NULL)
    {
        temp = target_node;
        while (temp->prev != NULL)
        {
            node_a->rb++;
            temp = temp->prev;
        }
        temp = target_node;
        while (temp != NULL)
        {
            node_a->rrb++;
            temp = temp->next;
        }
    }
}

t_list  *ft_find_target2(t_list *stack1, t_list *stack2)
{
    t_list  *node_start;
    t_list  *node_end;
    t_list  *temp;
    int     len;
    int     i;

    len = ft_stack_length(stack1);
    i = 0;
    node_start = stack1;
    node_end = ft_find_last_node(stack1);
    temp = ft_find_min_node(stack1);
    node_end->next = node_start;
    while (stack2->value > temp->value && i < len)
    {
        temp = temp->next;
        i++;
    }
    node_end->next = NULL;
    if (i == len)
        return (ft_find_min_node(stack1));
    return (temp);
}
