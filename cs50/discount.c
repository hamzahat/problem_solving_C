// subject:
/*
take a price + percent from the user and return there discount
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

float discount(float price, float percent)
{
	return (price * (100 - percent) / 100);
}
int main (void)
{
	ssize_t readen;
	char *price = malloc(11);
	if (!price)
		return (1);
	char *percent = malloc(5);
	if (!percent)
		return(free(price), 1);
	printf ("price: ");
	fflush(stdout);
	readen = read(0, price, 10);
	if (readen <= 0)
		return(free(price), free(percent), 1);
	price[readen -1] = 0;
	printf("percentage: ");
	fflush(stdout);
	readen = read(0, percent, 4);
	if (readen <= 0)
		return (free(price), free(percent), 1);
	percent[readen - 1] = 0;
	float price_nb = atof(price);
	float percent_nb = atof(percent);
	float result = discount(price_nb, percent_nb);
	printf ("the new price is: %.2f dh\n", result);
	free(price);
	free(percent);
	return (0);
}