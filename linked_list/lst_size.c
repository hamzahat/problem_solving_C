// make a fun that count the size of a stuct ( number of nodes )
#include <stdlib.h>
#include <stdio.h>

// struct:
typedef struct	s_list
{
	void			*value;
	struct	s_list	*next;
}				t_list;

// fun:
int	lst_size(t_list *list)
{
	int counter = 0;
	while (list)
	{
		counter++;
		list = list->next;
	}
	return (counter);
}

t_list	*lst_new(void *content)
{
	t_list *tmp = malloc(sizeof(t_list));
	if (!(tmp))
		return (NULL);
	tmp->value = content;
	tmp->next = NULL;
	return(tmp);
}

// int main:
int main (void)
{
	t_list *list = NULL;
	t_list *node_1 = lst_new(&(int){1337});
	t_list *node_2 = lst_new(&(int){42});
	t_list *node_3 = lst_new(&(int){21});

	list = node_1;
	node_1->next = node_2;
	node_2->next = node_3;

	printf("%d\n", lst_size(list));
	return (0);
}