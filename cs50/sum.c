// make a programe that take 2 numbers and ruturn there sum.
// the complix code : 
#include <stdlib.h>
#include <unistd.h>

// ft_check_nb
int ft_check_nb(char *num)
{
	if (*num == '-' || *num == '+')
		num++;
	if (*num == 0)
		return (1);
	while (*num)
	{
		if (!(*num >= '0' && *num <= '9'))
			return (1);
		num++;
	}
	return (0);
}
// ft_putstr:
void ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

// ft_putnbr:
void ft_putnbr(int num)
{
	long nb = num;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	char c = ((nb % 10) + 48);
	write(1, &c, 1);
}

// ft_atoi:
int	ft_atoi(char *num)
{
	int sign = 1;
	int nb = 0;
	while ((*num >= 9 && *num <= 13) || *num == 32)
		num++;
	if (*num == '-' || *num == '+')
	{
		if (*num == '-')
			sign = -sign;
		num++;
	}
	while (*num >= '0' && *num <= '9')
		nb = (nb * 10) + (*num++ - 48);
	return (nb * sign);
}

// main:
int main (void)
{
	ssize_t readen;
	char *num_1;
	char *num_2;
	int	nb_1 = 0;
	int	nb_2 = 0;
	if (!(num_1 = malloc(12)))
	{
		ft_putstr("malloc_1 fail\n");
		return (1);
	}
	if (!(num_2 = malloc(12)))
	{
		ft_putstr("malloc_2 fail\n");
		free(num_1);
		return (1);
	}
	ft_putstr("number 1: ");
	readen = read(0, num_1, 10);
	if (readen <= 0)
	{
		ft_putstr("read_1 fail\n");
		free(num_1);
		free(num_2);
		return(1);
	}
	num_1[readen - 1] = 0;
	ft_putstr("number 2: ");
	readen = read(0, num_2, 10);
	if (readen <= 0)
	{
		ft_putstr("read_2 fail\n");
		free(num_1);
		free(num_2);
		return (1);
	}
	num_2[readen - 1] = 0;
	if (ft_check_nb(num_1)|| ft_check_nb(num_2))
	{
		ft_putstr("invalid input!\n");
		free(num_1);
		free(num_2);
		return (1);
	}
	nb_1 = ft_atoi(num_1);
	nb_2 = ft_atoi(num_2);
	ft_putstr("the sum of ");
	ft_putstr(num_1);
	ft_putstr(" and ");
	ft_putstr(num_2);
	ft_putstr(" is: ");
	ft_putnbr(nb_1 + nb_2);
	write(1, "\n", 1);
	free(num_1);
	free(num_2);
	return (0);
}
