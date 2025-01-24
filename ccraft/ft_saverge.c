float	ft_saverge(float m, float pc, float eng, float ph)
{
	if ((m > 20 || m < 0 ) || (pc > 20 || pc < 0) || (eng > 20 || eng < 0) || (ph > 20 || ph < 0))
        return (-1);
    return ((((m * 4) + (pc * 3) + (eng * 2) + (ph * 2)) / 220) * 100);
}
