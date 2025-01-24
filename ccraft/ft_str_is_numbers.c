int ft_str_is_numbers(char *str)
{
    int i;

    i = 0;
    if (*str == 0)
        return (-1);
    while (*str)
    {
        if (!(*str >= '0' && *str <= '9'))
            return (0);
        str++;
    }
    return (1);
}