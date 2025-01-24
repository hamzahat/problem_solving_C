int	ft_strlen(const char *str)
{
	int count = 0;
	while (*(str++))
		count++;
	return count;
}
