#include "push_swap.h"
//function related to split

char    **ft_split(char const *s, char c)
{
    char    **str;
    int     i;
    int     len;

    i = 0;
    if (!s)
        return (NULL);
    str = (char **)malloc((ft_strcount(s, c) + 1) * sizeof(char *));
    if (!str)
        return (NULL);
    while (*s != '\0')
    {
        if (*s != c)
        {
            len = ft_array_sorting(s, c);
            str[i++] = ft_substr(s, 0, len);
            if (str[i - 1] == NULL)
                return (ft_dealloc(str, i));
            s += len + ft_check_null(len, s);
        }
        else
            s++;
    }
    str[i] = NULL;
    return (str);
}

size_t   ft_strcount(char const *s, char c)
{
    size_t  n;
    int     count;

    count = 0;
    n = 0;
    while (*s != '\0')
    {
        if (*s == c)
        {
            if (count > 0)
            {
                n++;
                count = 0;
            }
        }
        else
            count++;
        s++;
    }
    if (count > 0)
        n++;
    return (n);
}

size_t   ft_array_sorting(char const *s, char c)
{
    size_t len;

    len = 0;
    while (*s != '\0')
    {
        if (*s == c)
            return (len);
        else
            len++;
        s++;
    }
    return (len);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char            *p;
    unsigned int    i;

    i = 0;
    if (!s)
        return (0);
    if (ft_strlen(s) < start)
        len = 0;
    if (ft_strlen(s + start) < len)
        len = ft_strlen(s + start);
    while (*s != '\0' && i < start)
    {
        s++;
        i++;
    }
    p = (char *)malloc((len + 1) * sizeof(char));
    if (p != NULL)
    {
        ft_memcpy(p, s, len);
        p[len] = '\0';
    }
    return (p);
}

int  ft_check_null(size_t len, char const *s)
{
    if (s[len] == '\0')
        return (0);
    else
        return (1);
}
