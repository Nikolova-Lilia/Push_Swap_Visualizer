#include "push_swap.h"
//more functions used by split

size_t  ft_strlen(const char *str)
{
    unsigned int    i;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return ((size_t)i);
}

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    char    *d;
    char    *s;
    size_t  i;

    d = (char *)dest;
    s = (char *)src;
    i = 0;
    while (i < n)
    {
        d[i] = s[i];
        i++;
    }
    return (d);
}

int ft_split_length(char **temp)
{
    int len;

    len = 0;
    while (*temp != NULL)
    {
        len++;
        temp++;
    }
    return (len);
}
