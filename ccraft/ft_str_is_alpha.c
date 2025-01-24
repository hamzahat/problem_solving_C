int ft_str_is_alpha(char *str)
{
    int i;

    i = 0;
    if (*str == 0)
        return (-1);
    while (*str)
    {
        if (!((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')))
            return (0);
        str++;
    }
    return (1);
}
