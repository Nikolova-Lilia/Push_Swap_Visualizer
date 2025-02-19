#include "push_swap.h"
//functions that deal with updating string - argv to numbers

int ft_check_number(char *str)
{
    int flag;

    flag = 0;
    while (*str != '\0')
    {
        if (*str == '-' || *str == '+')
        {
            str++;
            flag++;
            if (flag > 1)
                return (1);
        }
        if (*str >= 48 && *str <= 57)
            str++;
        else
            return (1);
    }
    return (0);
}

long    ft_atol(const char *str)
{
    int     i;
    int     sign;
    long    number;

    i = 0;
    sign = 0;
    number = 0;
    while(str[i] != '\0')
    {
        if ((str[i] >= 9 && str[i] <= 13) || (str[i] == '+'))
            i++;
        else if (str[i] == '-')
            sign++;
        else if (str[i] >= 48 && str[i] <= 57)
        {
            number = (number * 10) + ((long)str[i] - 48);
        }
        i++;
    }
    if (sign % 2 == 1)
        number = number * (-1);
    return (number);
}

int ft_find_space(char *str)
{
    while (*str != '\0')
    {
        if (*str == 32)
            return (0);
        str++;
    }
    return (1);
}

bool ft_numbers_check(t_list **stack_a, char **argv, int argc)
{
    int     k;

    k = 0;
    while (k < argc)
    {
        if (ft_check_number(argv[k]) == 0)
        {
            if (ft_convert_to_nbr(argv[k], stack_a) == false)
                return (false);
        }
        else if (ft_find_space(argv[k]) == 0)
        {
            if (ft_check_sub_numbers(stack_a, argv[k]) == false)
                return (false);
        }
        else
        {
            write(1, "Error\n", 6);
            return (false);
        }
        k++;
    }
    return (true);
}

bool    ft_check_sub_numbers(t_list **stack, char *argv)
{
    char    **temp;
    int     temp_len;
    bool    result;

    temp = ft_split(argv, ' ');
    temp_len = ft_split_length(temp);
    result = ft_numbers_check(stack, temp, temp_len);
    ft_dealloc(temp, temp_len);
    return (result);
}
