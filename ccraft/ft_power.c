#include <stdio.h>
int ft_power(int nb, int pw)
{
    int res = 1;
    if (pw < 0)
        return (-1);
    else if (pw == 0)
        return (1);
    while(pw--)
    {
        res = res * nb;
    }
    return (res);
}