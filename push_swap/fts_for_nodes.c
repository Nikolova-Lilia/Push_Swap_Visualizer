#include "push_swap.h"
//functions all about nodes

bool    ft_create_node(t_list **stack, long number)
{
    t_list  *node;
    t_list  *last_node;

    if (!stack)
        return (false);
    if (ft_check_and_clean(stack, number) == false)
        return (false);
    node = malloc(sizeof(t_list));
    if (!node)
        return (false);
    node->next = NULL;
    node->value = number;
    if (*stack == NULL)
    {
        *stack = node;
        node->prev = NULL;
    }
    else
    {
        last_node = ft_find_last_node(*stack);
        last_node->next = node;
        node->prev = last_node;
    }
    return (true);
}

t_list  *ft_find_last_node(t_list *head)
{
    if (head == NULL)
        return (NULL);
    while (head->next)
        head = head->next;
    return (head);
}

t_list  *ft_find_min_node(t_list *stack)
{
    t_list  *node_min;

    node_min = stack;
    while (stack != NULL)
    {
        if (stack->value < node_min->value)
            node_min = stack;
        stack = stack->next;
    }
    return (node_min);
}

t_list  *ft_find_biggest_node(t_list *head)
{
    int number;
    t_list  *biggest_node;

    if (head == NULL)
        return (NULL);
    number = head->value;
    biggest_node = head;
    head = head->next;
    while (head != NULL)
    {
        if (head->value > number)
        {
            number = head->value;
            biggest_node = head;
        }
        head = head->next;
    }
    return (biggest_node);
}

bool    ft_check_node(t_list *head, int value)
{
    while (head != NULL)
    {
        if (value == head->value)
            return (false);
        head = head->next;
    }
    return (true);
}
