#include "push_swap.h"
//functions to free memory

void    ft_free_stack(t_list **stack)
{
    t_list  *temp;
    t_list  *head;

    if (stack == NULL)
        return ;
    head = *stack;
    while (head != NULL)
    {
        temp = head->next;
        free(head);
        head = temp;
    }
    *stack = NULL;
}

char    **ft_dealloc(char **str, int i)
{
    int f;

    f = 0;
    while (f < i)
        free(str[f++]);
    free(str);
    return (NULL);
}
