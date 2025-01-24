int	ft_digit(int nb)
{
	int count = 1;
	if (nb < 0)
		nb = -nb;

	while (nb > 9)
	{
		nb /= 10;
		count++;
	}
	return (count);
}
