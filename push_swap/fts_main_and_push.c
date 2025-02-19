#include "push_swap.h"
//main and push function

void    ft_push_swap(t_list **stack_a, t_list **stack_b)
{
    t_list  *target_node;
    int     r;
    int     rr;

    ft_first_sort(stack_a, stack_b);
    ft_rotate_and_push_ba(stack_a, stack_b);
    if (ft_stack_sorted(*stack_a) != true)
    {
        r = 0;
        rr = 0;
        target_node = ft_find_min_node(*stack_a);
        ft_calc_r_and_rr(target_node, &r, &rr);
        if (rr < r)
            ft_rotate_stack(&rr, ft_rra, stack_a);
        else
            ft_rotate_stack(&r, ft_ra, stack_a);
    }
}

void    ft_first_sort(t_list **stack_a, t_list **stack_b)
{
    t_list *next_node;

    while (ft_stack_length(*stack_a) > 3 && ft_stack_length(*stack_b) < 2)
        ft_pb(stack_a, stack_b);
    if (ft_stack_sorted(*stack_b) == true && ft_stack_length(*stack_b) != 1)
        ft_sb(stack_b);
    while (ft_stack_length(*stack_a) > 3)
    {
        next_node = ft_next_nbr(*stack_a, *stack_b);
        ft_sort_rotation(next_node, stack_a, stack_b);
        ft_pb(stack_a, stack_b);
    }
    if (ft_stack_length(*stack_a) == 3)
        ft_check_order(stack_a);
}

int main(int argc, char **argv)
{
    t_list *stack_a;
    t_list  *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    if (argc == 1 || (argc == 2 && (!argv[1][0])))
        return (1);
    if (argc >= 2 && ft_numbers_check(&stack_a, argv + 1, argc - 1) == false)
    {
        ft_free_stack(&stack_a);
        return (1);
    }
    if (ft_stack_sorted(stack_a) != true)
    {
        if (ft_stack_length(stack_a) == 2)
            ft_sa(&stack_a);
        else if (ft_stack_length(stack_a) == 3)
            ft_three_nbr_sort(&stack_a);
        else
            ft_push_swap(&stack_a, &stack_b);
    }
    //ft_print(&stack_a);
    ft_free_stack(&stack_a);
    return (0);
}
/*
void    ft_print(t_list **stack)
{
    t_list *temp;
    t_list *final_stack;

    final_stack = *stack;
    temp = final_stack;
    while (temp != NULL)
    {
        printf("%ld\n", (temp->value));
        temp = final_stack->next;
        final_stack = temp;
    }
}*/
