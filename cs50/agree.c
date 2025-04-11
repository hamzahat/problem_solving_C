// ask the user if he is agree or not 
#include <unistd.h>
#include <stdlib.h>

// ft_putstr
void ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

// ft_strcmp
int ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	while((s1[i] != 0) && (s2[i] != 0) && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

int main (void)
{
	ssize_t readen;
	char *answer = malloc(5);
	if (!answer)
		return (1);
	ft_putstr("are you agree?(yes/no|y/n) ");    
	readen = read(0, answer, 4);
	if (readen <= 0)
		return (ft_putstr("Error: failed to read input\n"),free(answer), 1);
	answer[readen - 1] = 0;
	if (!(ft_strcmp(answer, "yes")) || !(ft_strcmp(answer, "y")) || !(ft_strcmp(answer, "Y")) || !(ft_strcmp(answer, "YES")) || !(ft_strcmp(answer, "Yes")))
		ft_putstr("you are agree :)\n");
	else if (!(ft_strcmp(answer, "no")) || !(ft_strcmp(answer, "n")) || !(ft_strcmp(answer, "NO")) || !(ft_strcmp(answer, "N")) || !(ft_strcmp(answer, "No")))
		ft_putstr("you are not agree :(\n");
	else
		ft_putstr("Erorre: invalid input\n");
	return (free(answer), 0);
}
