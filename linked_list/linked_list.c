#include <stdlib.h>
#include <stdio.h>

// node:
typedef struct	s_node
{
	int				nb;
	struct	s_node	*next;
}				t_node;


int main (void)
{
	t_node *node_1 = malloc(sizeof(t_node)), *node_2 = malloc(sizeof(t_node)), *node_3 = malloc(sizeof(t_node));
	
	node_1->nb = 42;
	node_2->nb = 1337;
	node_3->nb = 21;

	node_1->next = node_2;
	node_2->next = node_3;
	node_3->next = NULL;

	t_node *tmp = node_1;
	while (tmp)
	{
		printf("%d\n",tmp->nb);
		tmp = tmp->next;
	}
	tmp = NULL;
	while (node_1)
	{
		tmp = node_1->next;
		free(node_1);
		node_1 = tmp;
	}
	
	return (0);
}
