
// ft_factorial while:
/*
int ft_factorial(int nb)
{
    int x = nb;
    if (nb < 0)
        return (0);
    if (nb == 0)
        return (1);
    while (--x)
        nb *= x;
    return (nb);
}
*/

// ft_factorial recursion:
int ft_factorial(int nb)
{
    if(nb <= 1)
        return (nb >= 0);
    return (nb*ft_factorial(nb-1));
}

// #include <stdio.h>
// int main (void)
// {
//     printf("%d\n",ft_factorial(0));
// }