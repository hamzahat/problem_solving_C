static int check(char *str)
{
    int i;
    int bo;

    i = 0;
    bo = 0;
    while (*str)
    {
        if (*str != '1' && *str != '0')
            bo = -1;
        i++;
        str++;
    }
    if (i != 8 || bo == -1)
        return (1);
    return (0);
}

int ft_bintdec(char *bin)
{
    int count = 0;
    int i = 0;
    int num = 128;

    if (check(bin))
        return (-1);
    while (bin[i] != 0)
    {
        if (bin[i++] == '1')
            count += num;
        num /= 2;
    }
    return (count);
}

// #include <stdio.h>

// int main (void)
// {
//     printf("%d\n",ft_bintdec("10000000"));  // expedted = 128
//     printf("%d\n",ft_bintdec("00000001"));  // expedted = 1
//     printf("%d\n",ft_bintdec("10101019"));  // expected = -1
//     printf("%d\n",ft_bintdec("101010100")); // expected = -1
// }