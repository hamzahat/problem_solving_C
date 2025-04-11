#include <stdio.h>

int main (void)
{
	int i = 4;
	while (i)
	{
		int j = i;
		while (j)
		{
			printf("#");
			j--;
		}
		printf("\n");
		i--;
	}
	return (0);
}
