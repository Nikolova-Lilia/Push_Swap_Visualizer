#include "push_swap.h"
//functions for checking and sorting

void    ft_check_order(t_list **stack_a)
{
    t_list  *node_max;
    t_list  *node_min;
    t_list  *node_start;
    t_list  *node_end;

    node_start = *stack_a;
    node_end = ft_find_last_node(*stack_a);
    node_min = ft_find_min_node(*stack_a);
    node_max = ft_find_biggest_node(*stack_a);

    if (node_start->value == node_min->value &&
    node_start->next->value == node_max->value)
        ft_sa(stack_a);
    else if (node_end->value == node_max->value &&
    node_end->prev->value == node_min->value)
        ft_sa(stack_a);
    else if (node_start->value == node_max->value &&
    node_end->value == node_min->value)
        ft_sa(stack_a);
}

void    ft_three_nbr_sort(t_list **stack_a)
{
    t_list  *biggest_node;

    biggest_node = ft_find_biggest_node(*stack_a);

    if (*stack_a == biggest_node)
        ft_ra(stack_a);
    else if ((*stack_a)->next == biggest_node)
        ft_rra(stack_a);
    if ((*stack_a)->value > (*stack_a)->next->value)
        ft_sa(stack_a);
}

bool    ft_stack_sorted(t_list *head)
{
    if (head == NULL)
        return (true);
    while (head->next != NULL)
    {
        if (head->value > head->next->value)
            return (false);
        head = head->next;
    }
    return (true);
}

int ft_stack_length(t_list *head)
{
    int i;

    if (head == NULL)
        return (0);
    i = 0;
    while (head != NULL)
    {
        i++;
        head = head->next;
    }
    return (i);
}

bool    ft_check_and_clean(t_list **stack, int value)
{
    int i;

    i = true;
    i = ft_check_node(*stack, value);
    if (i == false)
    {
        write(1, "Error\n", 6);
        ft_free_stack(stack);
        return (false);
    }
    else
        return (true);
}

